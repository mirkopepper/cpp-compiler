#include "arrayinitializer.h"
#include <iostream>

ArrayInitializer::ArrayInitializer(){

}

ArrayInitializer::ArrayInitializer(int limitI,int limitJ){
    this->limitI=limitI+1;
    this->limitJ=limitJ+1;
    /*se vuelve true solo si el formato de la inicializacion se corresponde con el de los limites*/
    matrizComplete=false;
    vector<vector<string>> aux(this->limitI, vector<string>(this->limitJ));
    matrix=aux;
    for (int m = 0; m < this->limitI; ++m) {
        for (int n = 0; n < this->limitJ; ++n) {
            matrix[m][n]="noValue";
        }
    }
    i=0;
    j=0;
}

void ArrayInitializer::setJ(int n){
    j=n;
}

void ArrayInitializer::setI(int n){
    i=n;
}

int ArrayInitializer::getI(){
    return i;
}

int ArrayInitializer::getJ(){
    return j;
}

void ArrayInitializer::setValue(string s){
    if(validPosition()){
        matrix[i][j]=s;
    }
    if(i+1==limitI && j+1==limitJ)
        matrizComplete=true;
}

bool ArrayInitializer::validPosition(){
    return i<limitI && j<limitJ;
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

bool ArrayInitializer::matrixComplete(){
    return matrizComplete;
}
