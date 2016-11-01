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

string Parser::createOperatorNode(string fatherNode,string leftNode,string rightNode){
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
        return codeGen->crearNodo(fatherNode,leftNode,rightNode);
    } else {
        //como stack es una pila, tipo1=factor tipo2=termino
        lastTypes.push("DOUBLE");
        if (tipo1=="INTEGER") {
            string conversion = codeGen->crearNodo("@conv",rightNode);
            return codeGen->crearNodo(fatherNode,leftNode, conversion);
        } else {
            string conversion = codeGen->crearNodo("@conv",leftNode);
            return codeGen->crearNodo(fatherNode, conversion,rightNode);
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
    if(tipo2=="INTEGER" && tipo1=="DOUBLE" && !conversionsAllowed){
        addErrorMessage("Error en asignacion: conversion no permitida.");
        return codeGen->crearNodo(assignmentOperator,leftNode,rightNode);
    }else
        return createOperatorNode(assignmentOperator,leftNode,rightNode);
}

#define yyparse Parser::yyparse
#define yyerror Parser::yyerror
#include "y.tab.c" // yypase()
