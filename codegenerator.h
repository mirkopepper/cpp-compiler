#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H
#include "node.h"
#include "pointerstable.h"
class CodeGenerator
{
public:
    CodeGenerator();

    //Crea nodo hoja y devuelve su clave
    string crearNodo(string dato);

    //Crea nodo con un hijo a la izquierda y devuelve su clave
    string crearNodo (string dato, string nodoIzquierda);

    //Crea nodo con dos hijos y devuelve su clave
    string crearNodo(string dato, string nodoIzquierda, string nodoDerecha);

    //Le asigna como hijo izquierdo el 2do paramtro al 1ro
    void addRightNode(string parentNode, string rightNode);

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

private:

    Node * root;

};

#endif // CODEGENERATOR_H
