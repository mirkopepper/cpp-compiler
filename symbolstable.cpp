#include "symbolstable.h"
#include "list"

SymbolsTable::SymbolsTable()
{
    entries.clear();
//    index.clear();
}

void SymbolsTable::put(string lexeme, Entry *e) {
    this->entries.insert(std::pair<string,Entry*>(lexeme,e));
//    this->index.push_back(lexeme);
}

int SymbolsTable::indexOf(string lexeme) {
        return 0;
//    return this->index.indexOf(lexeme);
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
/*
list<string> SymbolsTable::getKeys() {
    return index;
} */
/*
Entry * SymbolsTable::getEntry(const int index) {
    return this->entries.value(this->index.value(index));
}
*/
Entry * SymbolsTable::getEntry(const string lexeme) {
    return entries.find(lexeme)->second;
}
