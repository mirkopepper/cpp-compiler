#include "parser.h"

Parser::Parser(SymbolsTable *ts, LexicalAnalyzer *lex, CodeGenerator * codGen,list<string> *err)
{
    this->symbolsTable=ts;
    this->lexicalAnalyzer=lex;
    this->codeGen=codGen;
    this->errors=err;
    error = false;
    conversionsAllowed=false;
    mainBlockConected=false;
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

/*segunda parte: tp3-4*/

void Parser::declareVariable (string varName, string prefix, string type, string use) {
    string longVarName = prefix + varName;
    if (symbolsTable->contains(longVarName)) {
        this->addErrorMessage("error semantico: variable redeclarada");
    } else {
        //se modifica la tabla que dio de alta el lexico
        Entry * e = symbolsTable->getEntry(varName);
        e->type = type;
        e->intValue = 0;
        e->doubleValue = 0;
        symbolsTable->setUse(varName,use);
        symbolsTable->modifyLexeme(varName, longVarName);
    }
}

void Parser::generateInitializationMatrixTree(string storage, string longMatName){
    string sentence="";
    string lastSentence="";
    for (int i = 0; i < array.getLimitI(); ++i) {
        for (int j = 0; j < array.getLimitI(); ++j) {
            /*genero arbol de: celda[expresion][expresion]*/
            string subIndex1=codeGen->crearNodo(std::to_string(i));
            string subIndex2=codeGen->crearNodo(std::to_string(j));
            string celda;
            if(storage=="rows")
                celda=codeGen->crearNodo(longMatName,subIndex1,subIndex2);
            else
                celda=codeGen->crearNodo(longMatName,subIndex2,subIndex1);
            /*genero subarbol de: sentencia de asignacion con ':='*/
            array.setI(i);
            array.setJ(j);
            string expression=codeGen->crearNodo(symbolsTable->getEntry(array.getValue())->getValue());
            string assignment=codeGen->crearNodo(":=",celda,expression);
            if(sentence==""){
                /*es la 1er asignacion de la matriz: matName[0][0]:=algo*/
                sentence=codeGen->crearNodo("@sentencia",assignment);
                if(codeGen->rootIsNull()){
                    /*ademas es la 1er declaracion de matriz con inicializacion*/
                    codeGen->setAsRootNode(sentence);
                }
                else{
                    /*no es la 1ra, ya se inicializo otra antes*/
                    string aux=codeGen->getLastBlock();
                    codeGen->addRightNode(aux,sentence);
                }
            }
            else{
                /*no es la 1er asignacion de la matriz: los subindices no son [0][0]*/
                sentence=codeGen->crearNodo("@sentencia",assignment);
                codeGen->addRightNode(lastSentence,sentence);
            }
            lastSentence=sentence;
        }
    }
    codeGen->setAsBlockSentenceNode(lastSentence);
}

void Parser::declareMatriz(string matName, string prefix, string type, string use, string optional){
    declareVariable(matName,prefix,type,use);
    Entry * e=symbolsTable->getEntry(prefix+matName);
    /*extraigo la forma de almacenamiento (filas o columnas): inicializacion+@+almacenamiento*/
    int posArroba=optional.find('@');
    e->storage=optional.substr(posArroba+1,optional.size());
    /*extraigo la inicializacion de optional y chequeo si efectivamente se hace o no*/
    if(optional.substr(0,posArroba)=="initialize")
        if(!array.matrixComplete())
            addErrorMessage("error de inicializacion: el formato de la inicializacion no se corresponde con los limites de la matriz");
        else{
            generateInitializationMatrixTree(e->storage,prefix+matName);
        }
}

string Parser::mangle (string varName, string type) {
    /*se completa el nombre de 'varName'*/
    string longVarName="";
    if (type=="matriz")
        longVarName="mat@"+varName;
    else
        if (type=="variable")
            longVarName="var@"+varName;
        else
            cout << "parametro tipo en mangle es erroneo: no es ni matriz, ni variable" << endl;
    /*chequeo si existe o no, en la tabla de simbolo*/
    if(!symbolsTable->contains(longVarName)){
        /*no se declaro previamente*/
        addErrorMessage("error con ID de variable o celda: no fue declarado previamente.");
        return "";
    }
    else
        symbolsTable->removeEntry(varName);
    return longVarName;
}

bool Parser::integerSubindex(QString subIndexType1, QString subIndexType2){
    if(subIndexType1=="DOUBLE" || subIndexType2=="DOUBLE"){
        addErrorMessage("error en celda: tipo incorrecto en subindices.");
        return false;
    }
    else
        return true;
}

string Parser::createOperatorNode(string parentNode,string leftNode,string rightNode){
    QString rightNodeType, leftNodeType;
    if (!lastTypes.empty())
        rightNodeType = lastTypes.pop();
    if (!lastTypes.empty())
        leftNodeType = lastTypes.pop();
    if (rightNodeType==leftNodeType) {
        if (rightNodeType=="INTEGER")
            lastTypes.push("INTEGER");
        else
            lastTypes.push("DOUBLE");
        return codeGen->crearNodo(parentNode,leftNode,rightNode);
    } else {
        //como stack es una pila, rightNodeType=factor leftNodeType=termino
        lastTypes.push("DOUBLE");
        if (rightNodeType=="INTEGER") {
            string conversion = codeGen->crearNodo("@conv",rightNode);
            return codeGen->crearNodo(parentNode,leftNode, conversion);
        } else {
            string conversion = codeGen->crearNodo("@conv",leftNode);
            return codeGen->crearNodo(parentNode, conversion,rightNode);
        }
    }
}

string Parser::createAssignmentNode(string assignmentOperator, string leftNode, string rightNode){

    QString rightNodeType,leftNodeType;
    if (!lastTypes.empty())
        rightNodeType = lastTypes.pop();
    else{
        //cout << "error!!!! En la derecha no hay nada. Revisar el pusheo de tipos" << endl;
        rightNodeType = "not a type";
    }
    if (!lastTypes.empty())
        leftNodeType = lastTypes.pop();
    else{
        //cout << "error!!! En la izquierda no hay nada. Revisar el pusheo de tipos" << endl;
        rightNodeType = "not a type";
    }
    /*leftNodeType=asig_izq rightNodeType=expresion*/
    if(leftNodeType==rightNodeType)/*si son del mismo tipo no hay conversiones*/
        return codeGen->crearNodo(assignmentOperator,leftNode,rightNode);
    else
        if(leftNodeType=="INTEGER" && rightNodeType=="DOUBLE" && !conversionsAllowed){/*son de distinto tipo e incompatibles*/
            addErrorMessage("Error en asignacion: conversion no permitida.");
            return codeGen->crearNodo(assignmentOperator,leftNode,rightNode);
        }else/*son de distinto tipo, pero se debe convertir lo del lado derecho*/
            return codeGen->crearNodo(assignmentOperator,leftNode,codeGen->crearNodo("@conv",rightNode));
}

string Parser::createConditionNode(string comparator, string leftExpression, string rightExpression){
    QString rightExpressionType, leftExpressionType;
    if (!lastTypes.empty())
        rightExpressionType = lastTypes.pop();
    if (!lastTypes.empty())
        leftExpressionType = lastTypes.pop();
    if (rightExpressionType!=leftExpressionType) {
        if (rightExpressionType=="INTEGER"){
            string conversion = codeGen->crearNodo("@conv", rightExpression);
            return codeGen->crearNodo(comparator, leftExpression, conversion);
        }else{//leftExpressionType=INTEGER
            string conversion = codeGen->crearNodo("@conv", leftExpression);
            return codeGen->crearNodo(comparator, conversion, rightExpression);
        }
    }
    else
        return codeGen->crearNodo(comparator,leftExpression,rightExpression);
}

void Parser::printSintacticTree(){
    if(hasError())
        cout << "--------------------IMPORTANTE------------------- " << endl << "Como existen errores lexicos,"
            " sintacticos y/o semanticos no hay generacion de codigo intermedio."<< endl;
    else
        codeGen->printSintacticTree();
}

string Parser::getLexeme(string symbolsTablePosition){
    return symbolsTable->getEntry(stoi(symbolsTablePosition))->getValue();
}

void Parser::updateArray(string lexeme){
    if(symbolsTable->getType(lexeme).toStdString()==type){
        if(array.validPosition()){
            array.setValue(lexeme);
        }
        else
            addErrorMessage("error en inicializacion: se quiere inicializar en una posicion fuera de rango.");
    }
    else
        addErrorMessage("error en inicializacion matriz: el tipo de dato es diferente al declarado.");
}

#define yyparse Parser::yyparse
#define yyerror Parser::yyerror
#include "y.tab.c" // yypase()
