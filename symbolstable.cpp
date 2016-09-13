#include "symbolstable.h"
#include "list"

SymbolsTable::SymbolsTable()
{
    entries.clear();
    index.clear();
}

void SymbolsTable::put(string lexeme, Entry *e) {
    this->entries.insert(std::map<string,*Entry>::value_type(lexeme, e));
    this->index.push_back(lexeme);
}

int SymbolsTable::indexOf(string lexeme) {
    return this->index.indexOf(lexeme);
}

bool SymbolsTable::contains(string lexeme) {
   return this->entries.contains(lexeme);
}

bool SymbolsTable::contains(int key) {
    return (key < this->size());
}

int SymbolsTable::size() {
    return this->entries.size();
}

list<string> SymbolsTable::getKeys() {
    return this->entries.keys();
}

Entry * SymbolsTable::getEntry(const int index) {
    return this->entries.value(this->index.value(index));
}

Entry * SymbolsTable::getEntry(const string lexeme) {
    return this->entries.value(lexeme);
}

