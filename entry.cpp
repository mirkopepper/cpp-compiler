#include "entry.h"

Entry::Entry(string lexeme, string token,int token_id)
{
    this->lexeme=lexeme;
    this->token=token;
    this->token_id=token_id;
}

string Entry::toString(){
    string toString = "";

    toString.append("lexeme: " + this->lexeme + " | Token: " + this->token + " | Tipo: " + this->type);

    if (this->token!="CADENA") {
        toString.append(" | Valor: ");
        if (this->type=="integer")
            toString.append(string::number(this->intValue));
        else if (this->type=="double")
            toString.append(string::number(this->doubleValue));
    }
    return toString;
}
