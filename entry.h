#ifndef ENTRY_H
#define ENTRY_H

#include <string>
#include <qstring.h>
#include <qlist.h>

using namespace std;

class Entry
{
public:
    Entry(string lexeme, string token, int token_id);
    string toString();
    string lexeme;
    string type; /*integer o double*/
    string token; /* Si es un ID, o una cadena, una CTE, etc */

    //solo se usara uno de los dos, segun el tipo (integer o double)
    int intValue;
    double doubleValue;
    int token_id;

    /*solo se usa para matrices*/
    int limit1,limit2;
    string storage;

    /*matrices en assembler*/
    QList<QString> matInstructions;

    string getValue();
};

#endif // ENTRY_H
