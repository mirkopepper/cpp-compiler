#include "entry.h"

Entry::Entry(String lexeme, String token,int token_id)
{
    this->lexeme=lexeme;
    this->token=token;
    this->token_id=token_id;
}

String Entry::toString(){
    String tostring = "";

    tostring.append("lexeme: " + this->lexeme + " | Token: " + this->token + " | Tipo: " + this->type);

    if (this->token!="CADENA") {
        tostring.append(" | Valor: ");
        if (this->type=="integer")
            tostring.append(String::number(this->intValue));
        else if (this->type=="double")
            tostring.append(String::number(this->doubleValue));
    }
    return tostring;
}
