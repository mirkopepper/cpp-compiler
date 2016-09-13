#ifndef SYMBOLSTABLE_H
#define SYMBOLSTABLE_H

#include "entry.h"
#include "list"
#include "map"

class SymbolsTable
{
public:

    SymbolsTable();

    //Devuelve verdadero si contiene el lexeme indicado
    bool contains(string lexeme);

    //Devuelve verdadero si contiene una entrada en ese valor de posicion
    bool contains (int key);

    //Inserta una entrada a la tabla
    void put (string lexeme, Entry * e);

    //Devuelve la cantidad de entradas
    int size();

    //Devuelve la posicion de un lexeme dado
    int indexOf(string lexeme);

    //Devuelve las claves que contiene la tabla
    list<string> getKeys();

    Entry * getEntry (const string lexeme);
    Entry * getEntry (const int index);

    list<string> toListString();

private:

    map<string, Entry*> entries;
    list <string> index;

};

#endif // SYMBOLSTABLE_H
