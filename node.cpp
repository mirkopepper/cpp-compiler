#include "node.h"

Node::Node()
{

}

QString Node::preOrderPrint(){
    QString toPrint=this->dato+"\n";
    if(this->hijoIzquierdo!=NULL)
        toPrint+=this->hijoIzquierdo->preOrderPrint()+"\n";
    if(this->hijoDerecho!=NULL)
        toPrint+=this->hijoDerecho->preOrderPrint()+"\n";
    return toPrint;
}
