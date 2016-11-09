#include "symbolstable.h"
#include <iostream>
#include <algorithm>
#include <QtCore/QString>

SymbolsTable::SymbolsTable()
{
    entries.clear();
    index.clear();
}

void SymbolsTable::put(string lexeme, Entry *e) {
    this->entries.insert(lexeme,e);
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

QList<string> SymbolsTable::getKeys() {
    return entries.keys();
}

Entry * SymbolsTable::getEntry(const int index) {
    return this->entries.value(this->index.value(index));
}

Entry * SymbolsTable::getEntry(const string lexeme) {
    return entries.value(lexeme);
}

list<string> SymbolsTable::getSymbolsToPrint(){

    list<string> symbolsToPrint;
    symbolsToPrint.clear();
    for (int i=0; i<index.size(); i++) {
            Entry * e = entries.value(index.at(i));
            string aux = "\nNro. Entrada: " + (QString::number(i+1)).toStdString() + " | ";
            aux+=e->toString();
            symbolsToPrint.push_back(aux);
        }
    return symbolsToPrint;
}

/** Segunda entrega **/

void SymbolsTable::modifyLexeme(string oldLexeme, string newLexeme) {
    Entry * e = this->entries.value(oldLexeme);
    index.remove(this->indexOf(oldLexeme));
    entries.remove(oldLexeme);
    e->lexeme=newLexeme;
    this->put(newLexeme, e);
}

QString SymbolsTable::getType(string lexeme) {
    Entry * e = this->entries.value(lexeme);

    return QString::fromStdString(e->type);
}

QString SymbolsTable::getType(QString lexeme) {
    return this->getType(lexeme.toStdString());
}

void SymbolsTable::setUse(string lexeme,string use){
    uses.insert(lexeme,use);
}
