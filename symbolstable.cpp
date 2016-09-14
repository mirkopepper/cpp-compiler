#include "symbolstable.h"
#include <vector>
#include <iostream>
#include <algorithm>

SymbolsTable::SymbolsTable()
{
    entries.clear();
    index.clear();
}

void SymbolsTable::put(string lexeme, Entry *e) {
    this->entries.insert(std::pair<string,Entry*>(lexeme,e));
    this->index.push_back(lexeme);
}

int SymbolsTable::indexOf(string lexeme) {
    std::vector<string>::iterator it;
    it=std::find(index.begin(),index.end(),lexeme);
    return distance(index.begin(),it);
}

bool SymbolsTable::contains(string lexeme) {
    std::map<string,Entry*>::iterator it=entries.find(lexeme);
    return it!=entries.end();
}

bool SymbolsTable::contains(int key) {
    return (key < this->size());
}

int SymbolsTable::size() {
    return this->entries.size();
}

vector<string> SymbolsTable::getKeys() {
    return index;
}

Entry * SymbolsTable::getEntry(const int index) {
    return this->entries.find(this->index.at(index))->second;
}

Entry * SymbolsTable::getEntry(const string lexeme) {
    return entries.find(lexeme)->second;
}

list<string> SymbolsTable::getSymbolsToPrint(){

    list<string> symbolsToPrint;
    symbolsToPrint.clear();
    for (int i = 0; i < index.size(); ++i) {
        Entry *e=entries.find(index.at(i))->second;
        string aux=std::to_string(i+1)+"    "+e->toString();
        symbolsToPrint.push_back(aux);
    }

    return symbolsToPrint;
}
