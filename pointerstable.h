#ifndef POINTERSTABLE_H
#define POINTERSTABLE_H
#include "node.h"
#include <QList>
#include <string>
using namespace std;

class PointersTable
{
public:
    PointersTable();

    string registerNode(Node * nodo);
    Node * getNode (string key);
    int getSize();
    string registerBlock(string keyNode);
    string getLastBlock();
private:
    list <Node *> nodos;
    QList <string> blockSentences;


};

#endif // POINTERSTABLE_H
