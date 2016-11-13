#ifndef SYMBOLSTABLE_H
#define SYMBOLSTABLE_H

#include "entry.h"
#include <QtCore/QVector>
#include <QtCore/QMap>

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
    QList<string> getKeys();

    Entry * getEntry (const string lexeme);
    Entry * getEntry (const int index);

    //imprime los elementos de la tabla
    list<string> getSymbolsToPrint();

    list<string> toListString();

    /** Segunda entrega **/

    /*se usa para cambiarle el nombre a una variable o matriz*/
    void modifyLexeme(string oldLexeme, string newLexeme);

    /*se usa para eliminar una entrada cuando ya se encuentra su verdadero nombre
     * en la TS: variable a: su nombre en TS es var@a, entonces elimino a de TS (a es agregada por el lexico)*/
    void removeEntry(string lexeme);

    QString getType(string lexeme);

    /*se usa para saber si una entrada es variable o matriz*/
    string getUse(string lexeme);

    /*asocia un lexeme con el uso que se le da*/
    void setUse(string lexeme,string use);

private:

    QMap<string, Entry*> entries;
    QVector <string> index;
    QMap<string,string> uses;
};

#endif // SYMBOLSTABLE_H
