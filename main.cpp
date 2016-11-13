#include <iostream>
#include "lexicalanalyzer.h"
#include "symbolstable.h"
#include "parser.h"
#include "codegenerator.h"

using namespace std;

static list<string> warnings, errors, tokens,programComponents;
static SymbolsTable symbolsTable;
static CodeGenerator codeGen(&symbolsTable);

void printProgramComponents() {

    cout <<"Elementos de Programa Encontrados\n\n";
    if(programComponents.size()==0)
        cout<<"No se reconocio ningun componente en el programa!.\n\n";
    else{
        for (std::list<string>::iterator it =programComponents.begin(); it !=programComponents.end(); it++) {
            cout<<*it<<endl;
        }
        cout<<endl;
    }
}

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

    cout << "Errores \n\n";
    if (errors.size()>0) {
        for (list<string>::iterator it = errors.begin(); it!= errors.end(); it++) {
            cout << it->c_str();
        }
    }
    else
        cout<<"No hay errores "<<endl;
    cout << endl;

}

void printLexicalWarnings() {

    cout << "Warnings \n\n";
    if (warnings.size()>0) {
        for (list<string>::iterator it = warnings.begin(); it!= warnings.end(); it++) {
            cout << it->c_str();
        }
    }
    else
        cout<<"No hay warnings"<<endl;
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

    Parser * parser = new Parser (&symbolsTable,lex, &codeGen, &errors);
    /*Se ejecuta el yyparse*/
    int outcome = parser->yyparse();

    cout <<"resultado del yyparse: "<<outcome<<endl;

    cout << "\n\nCodigo fuente analizado: " << argv[1] << endl;



    /*Ahora se imprimen todos los resultados*/
    tokens = lex->getTokens();
    programComponents = parser->getProgramComponents();

/*  Estos metodos, ya no son requeridos para esta entrega!!!
    printTokens();
    printProgramComponents();
    */
    printLexicalErrors();
    printLexicalWarnings();
    printSymbolsTable();
    parser->printSintacticTree();

    return 0;
}

