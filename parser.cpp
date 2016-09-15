#include "parser.h"

Parser::Parser(SymbolsTable *ts, LexicalAnalyzer *lex, list<string> *err)
{
    this->symbolsTable=ts;
    this->lexicalAnalyzer=lex;
    this->errors=err;
    error = false;
}

list<string> Parser::getRules()
{
    return rules;
}

void Parser::addErrorMessage(string errorm)
{
    //this->errors->push_back("\nError del parser: "+ errorm + ". (Linea: "+ std::to_string(lexicalAnalyzer->lineaActual())+").");
    error=true;
}

void Parser::addRule(const char * rule)
{
    //this->rules.push_back("Se encontro " + string(rule) + ". (Linea: " + string::number(lexicalAnalyzer->lineaActual()) +").");
}

int Parser::yylex()
{
    return this->lexicalAnalyzer->yylex();
}

void Parser::yyerror(string s)
{
    //this->errors->push_back("\nError:"+ s + ". (Linea: "+ string::number(lexicalAnalyzer->lineaActual())+").");
}

bool Parser::hasError()
{
    return this->error;
}



#define yyparse Parser::yyparse
#define yyerror Parser::yyerror
//#include "y.tab.c" // yypase()
