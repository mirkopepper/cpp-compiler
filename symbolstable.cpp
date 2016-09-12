#include "symbolstable.h"

SymbolsTable::SymbolsTable()
{
    entries.clear();
    index.clear();
}

void SymbolsTable::put(String lexeme, Entry *e) {
    this->entries.insert(lexeme, e);
    this->index.push_back(lexeme);
}

int SymbolsTable::indexOf(String lexeme) {
    return this->index.indexOf(lexeme);
}

bool SymbolsTable::contains(String lexeme) {
   return this->entries.contains(lexeme);
}

bool SymbolsTable::contains(int key) {
    return (key < this->size());
}

int SymbolsTable::size() {
    return this->entries.size();
}

List<String> SymbolsTable::getKeys() {
    return this->entries.keys();
}

Entry * SymbolsTable::getEntry(const int index) {
    return this->entries.value(this->index.value(index));
}

Entry * SymbolsTable::getEntry(const String lexeme) {
    return this->entries.value(lexeme);
}

