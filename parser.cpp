#include "parser.h"

Parser::Parser(SymbolsTable *ts, LexicalAnalyzer *lex, list<string> *err)
{
    this->symbolsTable=ts;
    this->lexicalAnalyzer=lex;
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

nodo * Parser::crearNodo(string s){
    nodo * aux = new nodo;
    aux->dato=s;
    aux->hijoIzquierdo=NULL;
    aux->hijoDerecho=NULL;
    aux->entrySymbolsTable=NULL;
    return aux;
}


nodo* Parser::nodoSentencia(){
    return crearNodo("++sentencia");
}

nodo* Parser::nodoCondicion(){
    return crearNodo("++condicion");
}

nodo* Parser::nodoCuerpo(){
    return crearNodo("++cuerpo");
}

nodo* Parser::nodoThen(){
    return crearNodo("++then");
}

nodo* Parser::nodoElse(){
    return crearNodo("++else");

}

nodo* Parser::nodoIf(){
    nodo* then= nodoThen();
    nodo* cuerpo= nodoCuerpo();
    nodo* els= nodoElse();
    nodo* condicion= nodoCondicion();
    nodo* vacio= crearNodo("++if");
    vacio->hijoIzquierdo=condicion;
    cuerpo->hijoIzquierdo=then;
    cuerpo->hijoDerecho=els;
    vacio->hijoDerecho=cuerpo;
    return vacio;

}

nodo* Parser:: nodoWhile(){
    nodo* cuerpo= nodoCuerpo();
    nodo* condicion= nodoCondicion();
    nodo* vacio= crearNodo("++while");
    vacio->hijoIzquierdo=condicion;
    vacio->hijoIzquierdo=cuerpo;
    return vacio;
}

nodo* Parser:: nodoExpresion(string exp, string op){
    nodo* expresion=new nodo;
    expresion->dato=exp;
    expresion->entrySymbolsTable = this->symbolsTable->getEntry(op);
}

nodo* Parser:: nodoExpresion(string exp, nodo* exp1, nodo* exp2){
    nodo* expresion=crearNodo(exp);
    expresion->hijoIzquierdo=exp1;
    expresion->hijoDerecho=exp2;
}

Parser:: sentenciaAsignacion(){

}



#define yyparse Parser::yyparse
#define yyerror Parser::yyerror
#include "y.tab.c" // yypase()
