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

void Parser::addProgramComponent(const char * programComponent)
{
    this->programComponents.push_back("Se encontro " + string(programComponent) + ". (Linea: " + std::to_string(lexicalAnalyzer->getLine()) +").");
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



#define yyparse Parser::yyparse
#define yyerror Parser::yyerror
#include "y.tab.c" // yypase()
