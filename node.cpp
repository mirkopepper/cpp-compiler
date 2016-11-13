#include "node.h"

Node::Node()
{

}

string Node::preOrderPrint(string prefix){
    string toPrint=prefix+dato.toStdString()+"\n";
    if(this->hijoIzquierdo!=NULL)
        toPrint+=this->hijoIzquierdo->preOrderPrint(prefix+". . ");
    if(this->hijoDerecho!=NULL)
           toPrint+=this->hijoDerecho->preOrderPrint(prefix+". . ");
    return toPrint;
}
