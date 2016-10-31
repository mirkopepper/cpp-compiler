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

    PointersTable pointersTable;

private:

    Node * root;

};

#endif // CODEGENERATOR_H
