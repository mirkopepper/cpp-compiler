#include "pointerstable.h"


PointersTable::PointersTable()
{
    nodos.clear();
    blockSentences.clear();
}

string PointersTable::registerNode(Node * nodo) {
    nodos.push_back(nodo);
    return std::to_string(nodos.size()-1);
}

string PointersTable::registerBlock(string keyNode){
    blockSentences.push_back(keyNode);
    return std::to_string(blockSentences.size()-1);
}

string PointersTable::getLastBlock(){
    if(!blockSentences.isEmpty()){
        string keyBlockNode=blockSentences.last();
        blockSentences.pop_back();
        return keyBlockNode;
    }
    else
        return "";
}

Node * PointersTable::getNode(string key) {
    int keyNumber = stoi (key);
    list<Node*>::iterator it = nodos.begin();
    for (int i=0; i<keyNumber; i++) {
        it++;

    }
    return *it;
}

int PointersTable::getSize(){
    return nodos.size();
}
