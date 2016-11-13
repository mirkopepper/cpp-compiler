#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H
#include "node.h"
#include "pointerstable.h"
#include <QMap>
#include <QString>
#include "symbolstable.h"
#include <fstream>
class CodeGenerator
{
public:
    CodeGenerator(SymbolsTable * symbolsTable);

    //Crea nodo hoja y devuelve su clave
    string crearNodo(string dato);

    //Crea nodo con un hijo a la izquierda y devuelve su clave
    string crearNodo (string dato, string nodoIzquierda);

    //Crea nodo con dos hijos y devuelve su clave
    string crearNodo(string dato, string nodoIzquierda, string nodoDerecha);

    //Le asigna como hijo izquierdo el 2do paramtro al 1ro
    void addRightNode(string parentNode, string rightNode);

    //Dado un string, devuelve el nodo correspondiente
    Node * getNode(string key);

    /*se le pasa la clave de un nodo ya creado, ahora el puntero raiz apunta a dicho nodo*/
    void setAsRootNode(string keyNode);

    /*se le pasa la clave de un nodo perteneciente a un bloque:de inicializacion de matrices o bloque de sentencias*/
    void setAsBlockSentenceNode(string keyNode);

    /*retorna el ultimo bloque de sentencias*/
    string getLastBlock();

    /*chequea si el arbol ya tiene sentencias (TRUE) o si esta vacio (FALSE)*/
    bool rootIsNull();

    /*imprime arbol*/
    void printSintacticTree();

    PointersTable pointersTable;

    void generateAssembler(const char * ruta);

private:
    //<lexema, nombre_assembler> para asociar un lexema de una cte a su nombre usado en assembler
    QMap <QString,QString> constantes;

    //idem anterior pero con cadenas
    QMap <QString, QString> cadenas;

    /*Almacena los nombres de variables auxiliares que se generaron y de paso sirve
     * de indice para generar nuevas ( ver processNode). La variable @aux_0 estara
     * en la posicion 0. La variable @aux_1 estara en la 1*/
    QList<QString> variablesAuxiliares;


    SymbolsTable * symbolsTable;

    void mapearConstantesYCadenas();

    bool firstSentence();

    void setAsRoot(string tree);

    void mapearConstantesyCadenas ();

    QList<QString> getAssemblerVariables();

    QList<QString> getInstructions(Node * node);

    void processNode(Node * &node);

    QString declareAssemblerVariable(string lexeme);

    QString convertOperand(string op);

    QList<QString> generateCode();

    void  recorrerArbol (Node * &root, QList<QString> * instructions);

    bool tieneHijosHoja(Node * node);



    Node * root;

};

#endif // CODEGENERATOR_H
