#include <iostream>
#include "lexicalanalyzer.h"
#include "symbolstable.h"
#include "parser.h"

using namespace std;

static list<string> warnings, errors, tokens;
static SymbolsTable symbolsTable;

void printSymbolsTable() {
    cout << "Tabla de Simbolos\n\n";
    list<string> symbols=symbolsTable.getSymbolsToPrint();
    if(symbols.size()==0)
        cout<<"Tabla de simbolos vacia"<<endl;
    else{
        for (std::list<string>::iterator it =symbols.begin(); it !=symbols.end(); it++) {
            cout<<*it<<endl;
        }
        cout<<endl;
    }
}

void printLexicalErrors() {
    cout << "Errores Lexicos\n\n";
    if (errors.size()>0) {
        for (list<string>::iterator it = errors.begin(); it!= errors.end(); it++) {
            cout << it->c_str();
        }
    }
    else
        cout<<"No hay errores lexicos"<<endl;
    cout << endl;

}

void printLexicalWarnings() {
    cout << "Warnings Lexicos\n\n";
    if (warnings.size()>0) {
        for (list<string>::iterator it = warnings.begin(); it!= warnings.end(); it++) {
            cout << it->c_str();
        }
    }
    else
        cout<<"No hay warnings lexicas"<<endl;
    cout << "\n";

}

void printTokens() {
    cout << "\n\nTokens identificados:\n\n";
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
    lex->reconocerTokens();

//    Parser * parser = new Parser (&symbolsTable,lex, &errors);
    /*Se ejecuta el yyparse*/
    //int resultado = parser->yyparse();

    cout << "\n\nCodigo fuente analizado: " << argv[1] << endl;



    /*Ahora se imprimen todos los resultados*/
    tokens = lex->getTokens();

    printTokens();
    printSymbolsTable();
    printLexicalErrors();
    printLexicalWarnings();
    //imprimirReglas();
}

