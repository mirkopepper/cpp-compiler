#ifndef PARSER_H
#define PARSER_H
#include "symbolstable.h"
#include "lexicalanalyzer.h"
#include "codegenerator.h"
#include <QtCore/QStack>
#include "arrayinitializer.h"


class Parser
{
private:
    SymbolsTable * symbolsTable;
    LexicalAnalyzer * lexicalAnalyzer;
    list<string> * errors;
    CodeGenerator * codeGen;
    ArrayInitializer array;
    bool error;

    /*Sólo para imprimir al final */
    list<string> programComponents;

    void addErrorMessage (string msg);
    void addProgramComponent (string msg);
    void yyerror(string s);

    int yylex();

    /** Segunda entrega **/

    /*completa el nombre de la variable,actualiza la TS y le setea el tipo y uso*/
    void declareVariable (string var, string prefix, string tipo,string use);

    /*le agrega al declareVariable: guarda la alineacion de la matriz(filas o columnas), direccion base y los limites*/
    void declareMatriz(string mat, string prefix, string tipo, string use,string optional);

    /*se le pasa por parametro +,-,*,/ o op de asignacion. Para todos funciona igual. Crea el nodo padre con las
     * expresiones/terminos/factores como hijos, agregando cuando sea necesario un nodo de conversion a DOUBLE*/
    string createOperatorNode (string parentNode,string leftNode,string rightNode);

    /**/
    void updateArray(string s);

    string createConditionNode(string comparator,string leftExpresion,string rightExpresion);

    string createAssignmentNode(string assignmentOperator,string leftNode,string rightNode);

    /*a partir del tipo de dato (variable o matriz), construye el nombre completo y se fija si se encuentra en la TS
    y si no esta informa el error*/
    string mangle (string var, string tipo);

    /*chequea que los subindices de una matriz sean del tipo requerido, en caso contrario informa error*/
    bool integerSubindex(QString tipo1, QString tipo2);

    //ultimo tipo mencionado (para saber de que tipo son las variables que se declararon)
    string type;

    //para determinar si las conversiones estan o no permitidas
    bool conversionsAllowed = false;

    //Contiene los tipos lanzados por las operaciones
    QStack<QString> lastTypes;


public:
    Parser(SymbolsTable * ts, LexicalAnalyzer * lex, CodeGenerator * codGen,list<string> * err);
    list <string> getProgramComponents();
    bool hasError();
    int yyparse();

};


#endif // PARSER_H


