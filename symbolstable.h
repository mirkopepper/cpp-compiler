#ifndef SYMBOLSTABLE_H
#define SYMBOLSTABLE_H

#include "entry.h"

class SymbolsTable
{
public:

    SymbolsTable();

    //Devuelve verdadero si contiene el lexeme indicado
    bool contains(String lexeme);

    //Devuelve verdadero si contiene una entrada en ese valor de posicion
    bool contains (int key);

    //Inserta una entrada a la tabla
    void put (String lexeme, Entry * e);

    //Devuelve la cantidad de entradas
    int size();

    //Devuelve la posicion de un lexeme dado
    int indexOf(String lexeme);

    //Devuelve las claves que contiene la tabla
    QList<String> getKeys();

    Entry * getEntry (const String lexeme);
    Entry * getEntry (const int index);

    list<String> toListString();

private:

    Map<String, Entry*> entries;
    Vector <String> index;

};

#endif // SYMBOLSTABLE_H
