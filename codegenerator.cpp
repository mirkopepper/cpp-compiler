#include "codegenerator.h"
#include <iostream>

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
    if(nodoIzquierda=="root")
        nodo->hijoIzquierdo=root;
    else{
        nodo->hijoIzquierdo=pointersTable.getNode(nodoIzquierda);
    }
    return pointersTable.registerNode(nodo);
}

void CodeGenerator::addRightNode(string parentNode, string rightNode){
    if(parentNode!=""){
        Node * parent=pointersTable.getNode(parentNode);
        parent->hijoDerecho=pointersTable.getNode(rightNode);
    }
}

void CodeGenerator::setAsRootNode(string keyNode){
    root=pointersTable.getNode(keyNode);
}

void CodeGenerator::setAsBlockSentenceNode(string keyNode){
    pointersTable.registerBlock(keyNode);
}

string CodeGenerator::getLastBlock(){
    return pointersTable.getLastBlock();
}

bool CodeGenerator::rootIsNull(){
    return root==NULL;
}

void CodeGenerator::printSintacticTree(){
    cout << "Codigo intermedio: Arbol Sintactico" << endl << endl << root->preOrderPrint("");
}
