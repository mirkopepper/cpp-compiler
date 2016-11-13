#ifndef ARRAYINITIALIZER_H
#define ARRAYINITIALIZER_H
using namespace std;
#include <string>
#include <vector>

class ArrayInitializer
{
private:
    int i,j,limitI,limitJ;
    vector<vector<string>> matrix;
    bool matrizComplete;
public:
    ArrayInitializer();
    ArrayInitializer(int limitI,int limitJ);
    void setI(int n);
    void setJ(int n);
    void setValue(string s);
    string getValue();
    bool validPosition();
    void increaseI();
    void increaseJ();
    int getLimitI();
    int getLimitJ();
    int getI();
    int getJ();
    bool matrixComplete();
};

#endif // ARRAYINITIALIZER_H
