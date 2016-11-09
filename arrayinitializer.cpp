#include "arrayinitializer.h"

ArrayInitializer::ArrayInitializer(){

}

ArrayInitializer::ArrayInitializer(int limitI,int limitJ){
    this->limitI=limitI;
    this->limitJ=limitJ;
    i=0;
    j=0;
    vector<vector<string>> aux(limitI, vector<string>(limitJ));
    matrix=aux;
}

void ArrayInitializer::setJ(int n){
    j=n;
}

void ArrayInitializer::setI(int n){
    i=n;
}

void ArrayInitializer::setValue(string s){
    if(validPosition())
        matrix[i][j]=s;
}

bool ArrayInitializer::validPosition(){
    return i<=limitI && j<=limitJ;
}

void ArrayInitializer::increaseI(){
    i++;
}

void ArrayInitializer::increaseJ(){
    j++;
}

int ArrayInitializer::getLimitI(){
    return limitI;
}

int ArrayInitializer::getLimitJ(){
    return limitJ;
}

string ArrayInitializer::getValue(){
    if(validPosition())
        return matrix[i][j];
    else
        return "";
}
