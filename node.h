#ifndef NODE_H
#define NODE_H
using namespace std;
#include <string>
class Node
{
public:
    Node();
    string dato;
    Node *hijoIzquierdo;
    Node *hijoDerecho;

    /*impresion pre-order del codigo intermedio*/
    string preOrderPrint(string prefix);
};

#endif // NODE_H
