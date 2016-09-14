#ifndef PARSER_H
#define PARSER_H
#include "symbolstable.h"
#include "lexicalanalyzer.h"


class Parser
{
private:
    SymbolsTable * symbolsTable;
    LexicalAnalyzer * lexicalAnalyzer;
    list<string> * errors;
    bool error;

    /*Sólo para imprimir al final */
    list<string> rules;

    void addErrorMessage (string msg);
    void addRule (const char * msg);
    void yyerror(string s);

    int yylex();


public:
    Parser(SymbolsTable * ts, LexicalAnalyzer * lex, list<string> * err);
    list <string> getRules();
    bool hasError();
    int yyparse();

};


#endif // PARSER_H


