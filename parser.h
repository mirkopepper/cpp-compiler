#ifndef PARSER_H
#define PARSER_H
#include "symbolstable.h"
#include "lexicalanalyzer.h"

struct nodo{
   string dato;
   nodo *hijoIzquierdo;
   nodo *hijoDerecho;
   Entry * entrySymbolsTable;
};

class Parser
{
private:
    SymbolsTable * symbolsTable;
    LexicalAnalyzer * lexicalAnalyzer;
    list<string> * errors;
    bool error;
    list<*nodo> * pila;
    nodo* raizArbol;





    /*Sólo para imprimir al final */
    list<string> programComponents;

    void addErrorMessage (string msg);
    void addProgramComponent (string msg);
    void yyerror(string s);

    int yylex();


public:
    Parser(SymbolsTable * ts, LexicalAnalyzer * lex, list<string> * err);
    list <string> getProgramComponents();
    bool hasError();

    nodo * crearNodo(string s);
    nodo* nodoElse();
    nodo* nodoThen();
    nodo* nodoCondicion();
    nodo* nodoIf();
    nodo* nodoCuerpo();
    nodo* nodoSentencia();
    nodo* nodoWhile();
    nodo* nodoExpresion(string exp, string op);
    nodo* nodoExpresion(string exp, nodo * exp1, nodo* exp2);

    sentenciaAsignacion();


    int yyparse();

};


#endif // PARSER_H


