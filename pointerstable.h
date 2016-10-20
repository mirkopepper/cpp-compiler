#ifndef POINTERSTABLE_H
#define POINTERSTABLE_H
#include "node.h"
#include <list>
#include <string>
using namespace std;

class PointersTable
{
public:
    PointersTable();

    string registerNode(Node * nodo);
    Node * getNode (string key);
private:
    list <Node *> nodos;


};

#endif // POINTERSTABLE_H
