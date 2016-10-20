#include "pointerstable.h"


PointersTable::PointersTable()
{
    nodos.clear();
}

string PointersTable::registerNode(Node * nodo) {
    nodos.push_back(nodo);
    return std::to_string(nodos.size()-1);
}

Node * PointersTable::getNode(string key) {
    int keyNumber = stoi (key);
    list<Node*>::iterator it = nodos.begin();
    for (int i=0; i<keyNumber; i++) {
        it++;

    }
    return *it;
}
