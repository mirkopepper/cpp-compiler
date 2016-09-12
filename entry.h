#ifndef ENTRY_H
#define ENTRY_H

using namespace std;

class Entry
{
public:
    Entry(String lexeme, String token, int token_id);
    String toString();
    String lexeme;
    String type; /*integer o double*/
    String token; /* Si es un ID, o una cadena, una CTE, etc */

    //solo se usara uno de los dos, segun el tipo (integer o double)
    int intValue;
    int doubleValue;
    int token_id;
};

#endif // ENTRY_H
