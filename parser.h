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
    bool error;

    /*Sólo para imprimir al final */
    list<string> programComponents;

    //para determinar si las conversiones estan o no permitidas: allow double to integer
    bool conversionsAllowed = false;

    //ultimo tipo mencionado (para saber de que tipo son las variables que se declararon)
    string type;

    //Contiene los tipos lanzados por id, cte y las operaciones con expresiones, terminos y factores
    QStack<QString> lastTypes;

    /*se encarga de generar las asignaciones de la inicializacion y agregarlas al arbol*/
    ArrayInitializer array;

    /*sirve para saber si se debe unir la inicializacion de matriz con el main block*/
    bool mainBlockConected;

    void addErrorMessage (string msg);
    void addProgramComponent (string msg);
    void yyerror(string s);

    int yylex();

    /** Segunda entrega **/

    /*completa el nombre de la variable,actualiza la TS y le setea el tipo y uso*/
    void declareVariable (string varName, string prefix, string type,string use);

    /*le agrega al declareVariable: guarda la alineacion de la matriz(filas o columnas), direccion base, los limites e inicializa*/
    void declareMatriz(string matName, string prefix, string type, string use,string optional);

    /*convierte la inicializacion de una matriz de nxm en una concatenacion de nxm asignaciones que conforman un arbol sintactico*/
    void generateInitializationMatrixTree(string storage, string longMatName);

    /*se le pasa por parametro +,-,*,/ o op de asignacion. Para todos funciona igual. Crea el nodo padre con las
     * expresiones/terminos/factores como hijos, agregando cuando sea necesario un nodo de conversion a DOUBLE*/
    string createOperatorNode (string parentNode,string leftNode,string rightNode);

    /*crea el nodo padre con el operador, y las expresiones como hijos, agregando cuando sea necesario un nodo de conversion a DOUBLE*/
    string createConditionNode(string comparator,string leftExpresion,string rightExpresion);

    /*crea el nodo padre con el operador, y la expresion como hijo derecho y la variable como izquierdo. Chequea compatibilidad de tipos*/
    string createAssignmentNode(string assignmentOperator,string leftNode,string rightNode);

    /*a partir del tipo de dato (variable o matriz), construye el nombre completo y se fija si se encuentra en la TS
    y si no esta informa el error*/
    string mangle (string varName, string type);

    /*a partir de la posicion dada por parametro, se busca la entrada en la TS, y se devuelve el valor*/
    string getLexeme(string symbolsTablePosition);

    /*chequea que los subindices de una matriz sean del tipo requerido, en caso contrario informa error*/
    bool integerSubindex(QString subIndexType1, QString subIndexType2);

    /*dado el lexema, guarda el valor en la posicion i,j*/
    void updateArray(string lexeme);

public:
    Parser(SymbolsTable * ts, LexicalAnalyzer * lex, CodeGenerator * codGen,list<string> * err);
    list <string> getProgramComponents();
    bool hasError();
    int yyparse();

    /*imprime el arbol*/
    void printSintacticTree();

};

#endif // PARSER_H
