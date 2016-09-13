#include "entry.h"
#include <string>
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
            toString.append(std::to_string(this->intValue));
        else if (this->type=="double")
            toString.append(std::to_string(this->doubleValue));
    }
    return toString;
}
