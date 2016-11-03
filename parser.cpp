#include "parser.h"

Parser::Parser(SymbolsTable *ts, LexicalAnalyzer *lex, CodeGenerator * codGen,list<string> *err)
{
    this->symbolsTable=ts;
    this->lexicalAnalyzer=lex;
    this->codeGen=codGen;
    this->errors=err;
    error = false;
}

list<string> Parser::getProgramComponents()
{
    return programComponents;
}

void Parser::addErrorMessage(string errorm)
{
    this->errors->push_back("\nError del parser: "+ errorm + ". (Linea: "+ std::to_string(lexicalAnalyzer->getLine())+").");
    error=true;
}

void Parser::addProgramComponent(string programComponent)
{
    this->programComponents.push_back("Se encontro " + programComponent + ". (Linea: " + std::to_string(lexicalAnalyzer->getLine()) +").");
}

int Parser::yylex()
{
    return this->lexicalAnalyzer->yylex();
}

void Parser::yyerror(string s)
{
    this->errors->push_back("\nError:"+ s + ". (Linea: "+ std::to_string(lexicalAnalyzer->getLine())+").");
}

bool Parser::hasError()
{
    return this->error;
}

void Parser::declareVariable (string var, string prefix, string tipo, string use) {
    string variable = prefix + var;
    if (symbolsTable->contains(variable)) {
        this->addErrorMessage("variable redeclarada");
    } else {
        //se modifica la tabla que dio de alta el lexico
        Entry * e = symbolsTable->getEntry(var);
        e->type = tipo;
        e->intValue = 0;
        e->doubleValue = 0;
        symbolsTable->setUse(var,use);
        symbolsTable->modifyLexeme(var, variable);
    }

}

//@TODO
string Parser::mangle (string var, string tipo) {
    /*se completa el nombre de 'var'*/
    string aux="";
    if (tipo=="matriz")
        "mat@"+var;
    else if (tipo=="variable")
        aux="var@"+var;
    /*chequeo si existe o no, en la tabla de simbolo*/
    if(!symbolsTable->contains(aux)){
        /*no se declaro previamente*/
        addErrorMessage("error con ID de variable o celda: no fue declarado previamente.");
    }
    return aux;
}

bool Parser::integerSubindex(QString tipo1,QString tipo2){
    if(tipo1=="DOUBLE" || tipo2=="DOUBLE"){
        addErrorMessage("error en celda: tipo incorrecto en subindices.");
        return false;
    }
    else
        return true;
}

string Parser::createOperatorNode(string parentNode,string leftNode,string rightNode){
    QString tipo1, tipo2;
    if (!lastTypes.empty())
        tipo1 = lastTypes.pop();
    if (!lastTypes.empty())
        tipo2 = lastTypes.pop();
    if (tipo1==tipo2) {
        if (tipo1=="INTEGER")
            lastTypes.push("INTEGER");
        else
            lastTypes.push("DOUBLE");
        return codeGen->crearNodo(parentNode,leftNode,rightNode);
    } else {
        //como stack es una pila, tipo1=factor tipo2=termino
        lastTypes.push("DOUBLE");
        if (tipo1=="INTEGER") {
            string conversion = codeGen->crearNodo("@conv",rightNode);
            return codeGen->crearNodo(parentNode,leftNode, conversion);
        } else {
            string conversion = codeGen->crearNodo("@conv",leftNode);
            return codeGen->crearNodo(parentNode, conversion,rightNode);
        }
    }
}

string Parser::createAssignmentNode(string assignmentOperator, string leftNode, string rightNode){
    QString tipo1,tipo2;
    if (!lastTypes.empty())
        tipo1 = lastTypes.pop();
    if (!lastTypes.empty())
        tipo2 = lastTypes.pop();
    /*tipo2=asig_izq tipo1=expresion*/
    if(tipo2==tipo1)/*si son del mismo tipo no hay conversiones*/
        return codeGen->crearNodo(assignmentOperator,leftNode,rightNode);
    else
        if(tipo2=="INTEGER" && tipo1=="DOUBLE" && !conversionsAllowed){/*son de distinto tipo e incompatibles*/
            addErrorMessage("Error en asignacion: conversion no permitida.");
            return codeGen->crearNodo(assignmentOperator,leftNode,rightNode);
        }else/*son de distinto tipo, pero se debe convertir lo del lado derecho*/
            return codeGen->crearNodo(assignmentOperator,leftNode,codeGen->crearNodo("@conv",rightNode));
}

string Parser::createConditionNode(string comparator, string leftExpresion, string rightExpresion){
    QString tipo1, tipo2;
    if (!lastTypes.empty())
        tipo1 = lastTypes.pop();
    if (!lastTypes.empty())
        tipo2 = lastTypes.pop();
    if (tipo1!=tipo2) {
        if (tipo1=="INTEGER"){
            string conversion = codeGen->crearNodo("@conv", rightExpresion);
            return codeGen->crearNodo(comparator, leftExpresion, conversion);
        }else{//tipo2=INTEGER
            string conversion = codeGen->crearNodo("@conv", leftExpresion);
            return codeGen->crearNodo(comparator, conversion, rightExpresion);
        }
    }
}

void Parser::declareMatriz(string mat, string prefix, string type, string use, string optional){
    declareVariable(mat,prefix,type,use);
    Entry * e=symbolsTable->getEntry(prefix+mat);
    /*extraigo la forma de almacenamiento (filas o columnas): @+inicializacion+@+almacenamiento+@*/
    e->storage=optional.substr(optional.find('@',1)+1,optional.size()-2);
    /*extraigo la inicializacion de optional y chequeo si efectivamente se hace o no*/
    if(optional.substr(1,optional.find('@',1))=="initialization"){
        string sentence="";
        for (int i = 0; i <= array.getLimitI(); ++i) {
            for (int j = 0; j <= array.getLimitI(); ++j) {
                /*genero arbol de: celda[expresion][expresion]*/
                string subIndex1=codeGen->crearNodo(std::to_string(i));
                string subIndex2=codeGen->crearNodo(std::to_string(j));
                string celda=codeGen->crearNodo(prefix+mat,subIndex1,subIndex2);
                /*genero subarbol de: sentencia de asignacion con ':='*/
                array.setI(i);
                array.setJ(j);
                string assignment=codeGen->crearNodo(":=",celda,array.getValue());
                if(sentence=="")
                    sentence=codeGen->crearNodo("@setencia",assignment);
                else
                    sentence=codeGen->crearNodo("@sentencia",sentence,assignment);
            }
        }
        codeGen->setAsRootNode(sentence);
    }
    /* para [1][1] inicializo: {0,1;2,3}
     * en almacenamiento por filas      ->      [0][0]=0; [0][1]=1;
     *                                          [1][0]=2; [1][1]=3;
     *
     * en almacenamiento por columnas   ->      [0][0]=0; [0][1]=2;
     *                                          [1][0]=1; [1][1]=3;
     *
     * para [2][2] inicializo: {0,1,2;3,4,5;6,7,8}
     * en almacenamiento pot filas      ->      [0][0]=0; [0][1]=1; [0][2]=2;
     *                                          [1][0]=3; [1][1]=4; [1][2]=5;
     *                                          [2][0]=6; [2][1]=7; [2][2]=8;
     *
     * en almacenamiento por columnas   ->      [0][0]=0; [0][1]=3; [0][2]=6;
     *                                          [1][0]=1; [1][1]=4; [1][2]=7;
     *                                          [2][0]=2; [2][1]=5; [2][2]=8;
     *
     * tengo la sentencia 'mat[1][2]:=2;' y se almacena por columnas
     * como se almacena por columnas en realidad estoy haciendo 'mat[2][1]:=2;'?? impacta en el arbol de alguna forma??
     * osea: 1 seria hijo izquierdo de la celda y 2 el derecho is ordeno por filas, pero si lo hago por columnas
     * cambian de lugar o quedan como estaban??
     * LA PREGUNTA SERIA... EN EL TP3, CUAL ES LA DIFERENCIA ENTRE ALMACENAR POR
     * FILAS O COLUMNAS??
     *
     */
}

void Parser::updateArray(string s){
    if(symbolsTable->getType(s).toStdString()==type)
        if(array.validPosition())
            array.setValue(s);
        else
            addErrorMessage("error en inicializacion: se quiere inicializar en una posicion fuera de rango.");
    else
        addErrorMessage("error en inicializacion matriz: el tipo de dato es diferente al declarado.");
}


#define yyparse Parser::yyparse
#define yyerror Parser::yyerror
#include "y.tab.c" // yypase()
