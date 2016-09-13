#include <iostream>
#include "lexicalanalyzer.h"
#include "symbolstable.h"
using namespace std;

static list<string> warnings, errors, tokens;
static SymbolsTable symbolsTable;

void printTokens() {
    cout << "\n\nTokens identificados: \n";
    cout <<     "****** ************** \n\n";
    if (tokens.size()>0) {
        for (list<string>::iterator it = tokens.begin(); it!= tokens.end(); it++) {
            cout << it->c_str();
        }
    }
    cout << "\n";
}

int main(int argc, char *argv[])
{
    LexicalAnalyzer * lex = new LexicalAnalyzer(argv[1], &warnings, &errors, &symbolsTable);

    //Parser * parser = new Parser (&tablaDeSimbolos,lex, &errores);
    /*Se ejecuta el yyparse*/
    //int resultado = parser->yyparse();

    cout << "\n\nCodigo fuente analizado: " << argv[1] << endl;

    /*Ahora se imprimen todos los resultados*/
    tokens = lex->getTokens();
    printTokens();
    //imprimirTabladeSimbolos();
    //imprimirErrores();
    //imprimirWarnings();
    //imprimirReglas();
}

