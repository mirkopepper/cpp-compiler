#include "entry.h"
#include <string>
#include <iostream>
#include "y.tab.h"
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
        if (this->type=="INTEGER")
            toString.append(std::to_string(this->intValue));
        else if (this->type=="DOUBLE")
            toString.append(std::to_string(this->doubleValue));
    }
    return toString;
}

string Entry::getValue(){
    if(token_id==ID || token_id==CADENA)
        return lexeme;
    else
        if(type=="INTEGER")
            return std::to_string(intValue);
        else
            if(type=="DOUBLE")
                return std::to_string(doubleValue);
            else
                {
                    cout << "error con carga de token: si token_id no es ID, y type no es CADENA, INTEGER o DOUBLE" << endl;
                    return "";
                }
}
