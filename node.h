#ifndef NODE_H
#define NODE_H
using namespace std;
#include <QString>
class Node
{
public:
    Node();
    QString dato;
    Node *hijoIzquierdo;
    Node *hijoDerecho;

    /*impresion pre-order del codigo intermedio*/
    QString preOrderPrint();
};

#endif // NODE_H
