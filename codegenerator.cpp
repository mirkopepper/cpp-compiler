#include "codegenerator.h"

CodeGenerator::CodeGenerator()
{
    root=NULL;
}

string CodeGenerator::crearNodo(string dato){
    Node * nodo = new Node;
    nodo->dato=dato;
    nodo->hijoDerecho=NULL;
    nodo->hijoIzquierdo=NULL;
    return pointersTable.registerNode(nodo);
}

string CodeGenerator::crearNodo(string dato, string nodoIzquierda){
    Node * nodo = new Node;
    nodo->dato=dato;
    nodo->hijoDerecho=NULL;
    nodo->hijoIzquierdo=pointersTable.getNode(nodoIzquierda);
    return pointersTable.registerNode(nodo);
}

string CodeGenerator::crearNodo(string dato, string nodoIzquierda, string nodoDerecha){
    Node * nodo = new Node;
    nodo->dato=dato;
    nodo->hijoDerecho=pointersTable.getNode(nodoDerecha);
    nodo->hijoIzquierdo=pointersTable.getNode(nodoIzquierda);
    return pointersTable.registerNode(nodo);
}

void CodeGenerator::setAsRootNode(string keyNode){
    root=pointersTable.getNode(keyNode);
}
