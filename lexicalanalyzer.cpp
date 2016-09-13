#include "lexicalanalyzer.h"
#include <fstream>

LexicalAnalyzer::LexicalAnalyzer(const char * textFile, list<string> * warnings, list<string> * errors, SymbolsTable * symbolsTable) {
    lines=1;
    file.clear();
    recognizedTokens.clear();
    reservedWords.clear();
    this->symbolsTable = symbolsTable;
    (this->warnings)=warnings;
    (this->errors)=errors;




    ifstream arch (textFile);
    if (!arch.is_open()) {
        error("ERROR al abrir el archivo. Verificar los parametros");
    } else {
        char c;
        while (arch.get(c)) {
           file.push_back(c);
        }
        arch.close();
    }

    initReservedWords();
    initState();

}


/*Apuntará a la entrada de la tabla de simbolos en cada token con lexema no unico*/
extern int yylval;


void LexicalAnalyzer::error(string str) {
    //TODO
}

void LexicalAnalyzer::initReservedWords() {
    reservedWords.insert(std::map<string,int>::value_type("if", IF));
    reservedWords.insert(std::map<string,int>::value_type("else", ELSE));
    reservedWords.insert(std::map<string,int>::value_type("endif", ENDIF));
    reservedWords.insert(std::map<string,int>::value_type("print", PRINT));
    reservedWords.insert(std::map<string,int>::value_type("integer", INTEGER));
    reservedWords.insert(std::map<string,int>::value_type("double", DOUBLE));
    reservedWords.insert(std::map<string,int>::value_type("matrix", matrix));
    reservedWords.insert(std::map<string,int>::value_type("while", WHILE));
    reservedWords.insert(std::map<string,int>::value_type("allow", allow));
    reservedWords.insert(std::map<string,int>::value_type("to", TO));
}


void LexicalAnalyzer::initState(){


    /* Fila 0 */
        semanticActions[0][0]=&LexicalAnalyzer::ASA;
        semanticActions[0][1]=&LexicalAnalyzer::ASTI;
        semanticActions[0][2]=&LexicalAnalyzer::ASA;
        semanticActions[0][3]=&LexicalAnalyzer::ASA;
        semanticActions[0][4]=&LexicalAnalyzer::ASA;
        semanticActions[0][5]=&LexicalAnalyzer::ASA;
        semanticActions[0][6]=&LexicalAnalyzer::ASTI;
        semanticActions[0][7]=&LexicalAnalyzer::ASA;
        semanticActions[0][8]=&LexicalAnalyzer::ASA;
        semanticActions[0][9]=&LexicalAnalyzer::ASV;
        semanticActions[0][10]=&LexicalAnalyzer::ASL;
        semanticActions[0][11]=&LexicalAnalyzer::AS_opSimple;
        semanticActions[0][12]=&LexicalAnalyzer::AS_opSimple;
        semanticActions[0][13]=&LexicalAnalyzer::ASA;
        semanticActions[0][14]=&LexicalAnalyzer::ASTI;
        semanticActions[0][15]=&LexicalAnalyzer::ASA;
        semanticActions[0][16]=&LexicalAnalyzer::ASA;
        semanticActions[0][17]=&LexicalAnalyzer::ASA;
        semanticActions[0][18]=&LexicalAnalyzer::ASA;
        semanticActions[0][19]=&LexicalAnalyzer::ASA;
        semanticActions[0][20]=&LexicalAnalyzer::AS_opSimple;
        semanticActions[0][21]=&LexicalAnalyzer::ASTI;
        semanticActions[0][22]=&LexicalAnalyzer::AS_opSimple;

    /* Fila 1 */
        semanticActions[1][0]=&LexicalAnalyzer::ASA;
        semanticActions[1][1]=&LexicalAnalyzer::ASA;
        semanticActions[1][2]=&LexicalAnalyzer::ASA;
        semanticActions[1][3]=&LexicalAnalyzer::ASA;
        semanticActions[1][4]=&LexicalAnalyzer::ASA;
        semanticActions[1][5]=&LexicalAnalyzer::ASA;
        semanticActions[1][6]=&LexicalAnalyzer::AS_id_pr;
        semanticActions[1][7]=&LexicalAnalyzer::AS_id_pr;
        semanticActions[1][8]=&LexicalAnalyzer::ASA;
        semanticActions[1][9]=&LexicalAnalyzer::AS_id_pr;
        semanticActions[1][10]=&LexicalAnalyzer::AS_id_pr;
        semanticActions[1][11]=&LexicalAnalyzer::AS_id_pr;
        semanticActions[1][12]=&LexicalAnalyzer::AS_id_pr;
        semanticActions[1][13]=&LexicalAnalyzer::AS_id_pr;
        semanticActions[1][14]=&LexicalAnalyzer::AS_id_pr;
        semanticActions[1][15]=&LexicalAnalyzer::AS_id_pr;
        semanticActions[1][16]=&LexicalAnalyzer::AS_id_pr;
        semanticActions[1][17]=&LexicalAnalyzer::AS_id_pr;
        semanticActions[1][18]=&LexicalAnalyzer::AS_id_pr;
        semanticActions[1][19]=&LexicalAnalyzer::AS_id_pr;
        semanticActions[1][20]=&LexicalAnalyzer::AS_id_pr;
        semanticActions[1][21]=&LexicalAnalyzer::AS_id_pr;
        semanticActions[1][22]=&LexicalAnalyzer::AS_id_pr_EOF;

    /* Fila 2 */
        semanticActions[2][0]=&LexicalAnalyzer::ASEPN;
        semanticActions[2][1]=&LexicalAnalyzer::ASEPN;
        semanticActions[2][2]=&LexicalAnalyzer::ASEPN;
        semanticActions[2][3]=&LexicalAnalyzer::ASA;
        semanticActions[2][4]=&LexicalAnalyzer::ASA;
        semanticActions[2][5]=&LexicalAnalyzer::ASEPN;
        semanticActions[2][6]=&LexicalAnalyzer::ASEPN;
        semanticActions[2][7]=&LexicalAnalyzer::ASEPN;
        semanticActions[2][8]=&LexicalAnalyzer::ASEPN;
        semanticActions[2][9]=&LexicalAnalyzer::ASEPN;
        semanticActions[2][10]=&LexicalAnalyzer::ASEPN;
        semanticActions[2][11]=&LexicalAnalyzer::ASEPN;
        semanticActions[2][12]=&LexicalAnalyzer::ASEPN;
        semanticActions[2][13]=&LexicalAnalyzer::ASEPN;
        semanticActions[2][14]=&LexicalAnalyzer::ASEPN;
        semanticActions[2][15]=&LexicalAnalyzer::ASEPN;
        semanticActions[2][16]=&LexicalAnalyzer::ASEPN;
        semanticActions[2][17]=&LexicalAnalyzer::ASEPN;
        semanticActions[2][18]=&LexicalAnalyzer::ASEPN;
        semanticActions[2][19]=&LexicalAnalyzer::ASEPN;
        semanticActions[2][20]=&LexicalAnalyzer::ASEPN;
        semanticActions[2][21]=&LexicalAnalyzer::ASEPN;
        semanticActions[2][22]=&LexicalAnalyzer::ASEPN;

    /* Fila 3 */
        semanticActions[3][0]=&LexicalAnalyzer::ASEE;
        semanticActions[3][1]=&LexicalAnalyzer::ASA;
        semanticActions[3][2]=&LexicalAnalyzer::ASEE;
        semanticActions[3][3]=&LexicalAnalyzer::ASEE;
        semanticActions[3][4]=&LexicalAnalyzer::ASEE;
        semanticActions[3][5]=&LexicalAnalyzer::ASEE;
        semanticActions[3][6]=&LexicalAnalyzer::ASEE;
        semanticActions[3][7]=&LexicalAnalyzer::ASA;
        semanticActions[3][8]=&LexicalAnalyzer::ASEE;
        semanticActions[3][9]=&LexicalAnalyzer::ASEE;
        semanticActions[3][10]=&LexicalAnalyzer::ASEE;
        semanticActions[3][11]=&LexicalAnalyzer::ASEE;
        semanticActions[3][12]=&LexicalAnalyzer::ASEE;
        semanticActions[3][13]=&LexicalAnalyzer::ASEE;
        semanticActions[3][14]=&LexicalAnalyzer::ASEE;
        semanticActions[3][15]=&LexicalAnalyzer::ASEE;
        semanticActions[3][16]=&LexicalAnalyzer::ASEE;
        semanticActions[3][17]=&LexicalAnalyzer::ASEE;
        semanticActions[3][18]=&LexicalAnalyzer::ASEE;
        semanticActions[3][19]=&LexicalAnalyzer::ASEE;
        semanticActions[3][20]=&LexicalAnalyzer::ASEE;
        semanticActions[3][21]=&LexicalAnalyzer::ASEE;
        semanticActions[3][22]=&LexicalAnalyzer::ASEE;

    /* Fila 4 */
        semanticActions[4][0]=&LexicalAnalyzer::ASE;
        semanticActions[4][1]=&LexicalAnalyzer::ASA;
        semanticActions[4][2]=&LexicalAnalyzer::ASE;
        semanticActions[4][3]=&LexicalAnalyzer::ASE;
        semanticActions[4][4]=&LexicalAnalyzer::ASE;
        semanticActions[4][5]=&LexicalAnalyzer::ASE;
        semanticActions[4][6]=&LexicalAnalyzer::ASE;
        semanticActions[4][7]=&LexicalAnalyzer::ASE;
        semanticActions[4][8]=&LexicalAnalyzer::ASE;
        semanticActions[4][9]=&LexicalAnalyzer::ASE;
        semanticActions[4][10]=&LexicalAnalyzer::ASE;
        semanticActions[4][11]=&LexicalAnalyzer::ASE;
        semanticActions[4][12]=&LexicalAnalyzer::ASE;
        semanticActions[4][13]=&LexicalAnalyzer::ASE;
        semanticActions[4][14]=&LexicalAnalyzer::ASE;
        semanticActions[4][15]=&LexicalAnalyzer::ASE;
        semanticActions[4][16]=&LexicalAnalyzer::ASE;
        semanticActions[4][17]=&LexicalAnalyzer::ASE;
        semanticActions[4][18]=&LexicalAnalyzer::ASE;
        semanticActions[4][19]=&LexicalAnalyzer::ASE;
        semanticActions[4][20]=&LexicalAnalyzer::ASE;
        semanticActions[4][21]=&LexicalAnalyzer::ASE;
        semanticActions[4][22]=&LexicalAnalyzer::ASE_EOF;

    /* Fila 5 */
        semanticActions[5][0]=&LexicalAnalyzer::ASED;
        semanticActions[5][1]=&LexicalAnalyzer::ASA;
        semanticActions[5][2]=&LexicalAnalyzer::ASED;
        semanticActions[5][3]=&LexicalAnalyzer::ASED;
        semanticActions[5][4]=&LexicalAnalyzer::ASED;
        semanticActions[5][5]=&LexicalAnalyzer::ASED;
        semanticActions[5][6]=&LexicalAnalyzer::ASA;
        semanticActions[5][7]=&LexicalAnalyzer::ASA;
        semanticActions[5][8]=&LexicalAnalyzer::ASED;
        semanticActions[5][9]=&LexicalAnalyzer::ASED;
        semanticActions[5][10]=&LexicalAnalyzer::ASED;
        semanticActions[5][11]=&LexicalAnalyzer::ASED;
        semanticActions[5][12]=&LexicalAnalyzer::ASED;
        semanticActions[5][13]=&LexicalAnalyzer::ASED;
        semanticActions[5][14]=&LexicalAnalyzer::ASED;
        semanticActions[5][15]=&LexicalAnalyzer::ASED;
        semanticActions[5][16]=&LexicalAnalyzer::ASED;
        semanticActions[5][17]=&LexicalAnalyzer::ASED;
        semanticActions[5][18]=&LexicalAnalyzer::ASED;
        semanticActions[5][19]=&LexicalAnalyzer::ASED;
        semanticActions[5][20]=&LexicalAnalyzer::ASED;
        semanticActions[5][21]=&LexicalAnalyzer::ASED;
        semanticActions[5][22]=&LexicalAnalyzer::ASED;

    /* Fila 6 */
        semanticActions[6][0]=&LexicalAnalyzer::ASED;
        semanticActions[6][1]=&LexicalAnalyzer::ASA;
        semanticActions[6][2]=&LexicalAnalyzer::ASED;
        semanticActions[6][3]=&LexicalAnalyzer::ASED;
        semanticActions[6][4]=&LexicalAnalyzer::ASED;
        semanticActions[6][5]=&LexicalAnalyzer::ASED;
        semanticActions[6][6]=&LexicalAnalyzer::ASA;
        semanticActions[6][7]=&LexicalAnalyzer::ASED;
        semanticActions[6][8]=&LexicalAnalyzer::ASED;
        semanticActions[6][9]=&LexicalAnalyzer::ASED;
        semanticActions[6][10]=&LexicalAnalyzer::ASED;
        semanticActions[6][11]=&LexicalAnalyzer::ASED;
        semanticActions[6][12]=&LexicalAnalyzer::ASED;
        semanticActions[6][13]=&LexicalAnalyzer::ASED;
        semanticActions[6][14]=&LexicalAnalyzer::ASED;
        semanticActions[6][15]=&LexicalAnalyzer::ASED;
        semanticActions[6][16]=&LexicalAnalyzer::ASED;
        semanticActions[6][17]=&LexicalAnalyzer::ASED;
        semanticActions[6][18]=&LexicalAnalyzer::ASED;
        semanticActions[6][19]=&LexicalAnalyzer::ASED;
        semanticActions[6][20]=&LexicalAnalyzer::ASED;
        semanticActions[6][21]=&LexicalAnalyzer::ASED;
        semanticActions[6][22]=&LexicalAnalyzer::ASED;

    /* Fila 7 */
        semanticActions[7][0]=&LexicalAnalyzer::ASE;
        semanticActions[7][1]=&LexicalAnalyzer::ASA;
        semanticActions[7][2]=&LexicalAnalyzer::ASE;
        semanticActions[7][3]=&LexicalAnalyzer::ASD;
        semanticActions[7][4]=&LexicalAnalyzer::ASA;
        semanticActions[7][5]=&LexicalAnalyzer::ASA;
        semanticActions[7][6]=&LexicalAnalyzer::ASD;
        semanticActions[7][7]=&LexicalAnalyzer::ASD;
        semanticActions[7][8]=&LexicalAnalyzer::ASD;
        semanticActions[7][9]=&LexicalAnalyzer::ASD;
        semanticActions[7][10]=&LexicalAnalyzer::ASD;
        semanticActions[7][11]=&LexicalAnalyzer::ASD;
        semanticActions[7][12]=&LexicalAnalyzer::ASD;
        semanticActions[7][13]=&LexicalAnalyzer::ASD;
        semanticActions[7][14]=&LexicalAnalyzer::ASD;
        semanticActions[7][15]=&LexicalAnalyzer::ASD;
        semanticActions[7][16]=&LexicalAnalyzer::ASD;
        semanticActions[7][17]=&LexicalAnalyzer::ASD;
        semanticActions[7][18]=&LexicalAnalyzer::ASD;
        semanticActions[7][19]=&LexicalAnalyzer::ASD;
        semanticActions[7][20]=&LexicalAnalyzer::ASD;
        semanticActions[7][21]=&LexicalAnalyzer::ASD;
        semanticActions[7][22]=&LexicalAnalyzer::ASD_EOF;

    /* Fila 8 */
        semanticActions[8][0]=&LexicalAnalyzer::ASED;
        semanticActions[8][1]=&LexicalAnalyzer::ASA;
        semanticActions[8][2]=&LexicalAnalyzer::ASED;
        semanticActions[8][3]=&LexicalAnalyzer::ASED;
        semanticActions[8][4]=&LexicalAnalyzer::ASED;
        semanticActions[8][5]=&LexicalAnalyzer::ASED;
        semanticActions[8][6]=&LexicalAnalyzer::ASED;
        semanticActions[8][7]=&LexicalAnalyzer::ASA;
        semanticActions[8][8]=&LexicalAnalyzer::ASED;
        semanticActions[8][9]=&LexicalAnalyzer::ASED;
        semanticActions[8][10]=&LexicalAnalyzer::ASED;
        semanticActions[8][11]=&LexicalAnalyzer::ASA;
        semanticActions[8][12]=&LexicalAnalyzer::ASED;
        semanticActions[8][13]=&LexicalAnalyzer::ASED;
        semanticActions[8][14]=&LexicalAnalyzer::ASED;
        semanticActions[8][15]=&LexicalAnalyzer::ASED;
        semanticActions[8][16]=&LexicalAnalyzer::ASED;
        semanticActions[8][17]=&LexicalAnalyzer::ASED;
        semanticActions[8][18]=&LexicalAnalyzer::ASED;
        semanticActions[8][19]=&LexicalAnalyzer::ASED;
        semanticActions[8][20]=&LexicalAnalyzer::ASED;
        semanticActions[8][21]=&LexicalAnalyzer::ASED;
        semanticActions[8][22]=&LexicalAnalyzer::ASED;

    /* Fila 9 */
        semanticActions[9][0]=&LexicalAnalyzer::ASD;
        semanticActions[9][1]=&LexicalAnalyzer::ASA;
        semanticActions[9][2]=&LexicalAnalyzer::ASD;
        semanticActions[9][3]=&LexicalAnalyzer::ASD;
        semanticActions[9][4]=&LexicalAnalyzer::ASD;
        semanticActions[9][5]=&LexicalAnalyzer::ASD;
        semanticActions[9][6]=&LexicalAnalyzer::ASD;
        semanticActions[9][7]=&LexicalAnalyzer::ASD;
        semanticActions[9][8]=&LexicalAnalyzer::ASD;
        semanticActions[9][9]=&LexicalAnalyzer::ASD;
        semanticActions[9][10]=&LexicalAnalyzer::ASD;
        semanticActions[9][11]=&LexicalAnalyzer::ASD;
        semanticActions[9][12]=&LexicalAnalyzer::ASD;
        semanticActions[9][13]=&LexicalAnalyzer::ASD;
        semanticActions[9][14]=&LexicalAnalyzer::ASD;
        semanticActions[9][15]=&LexicalAnalyzer::ASD;
        semanticActions[9][16]=&LexicalAnalyzer::ASD;
        semanticActions[9][17]=&LexicalAnalyzer::ASD;
        semanticActions[9][18]=&LexicalAnalyzer::ASD;
        semanticActions[9][19]=&LexicalAnalyzer::ASD;
        semanticActions[9][20]=&LexicalAnalyzer::ASD;
        semanticActions[9][21]=&LexicalAnalyzer::ASD;
        semanticActions[9][22]=&LexicalAnalyzer::ASD;

    /* Fila 10 */
        semanticActions[10][0]=&LexicalAnalyzer::ASED;
        semanticActions[10][1]=&LexicalAnalyzer::ASA;
        semanticActions[10][2]=&LexicalAnalyzer::ASED;
        semanticActions[10][3]=&LexicalAnalyzer::ASED;
        semanticActions[10][4]=&LexicalAnalyzer::ASED;
        semanticActions[10][5]=&LexicalAnalyzer::ASED;
        semanticActions[10][6]=&LexicalAnalyzer::ASED;
        semanticActions[10][7]=&LexicalAnalyzer::ASED;
        semanticActions[10][8]=&LexicalAnalyzer::ASED;
        semanticActions[10][9]=&LexicalAnalyzer::ASED;
        semanticActions[10][10]=&LexicalAnalyzer::ASED;
        semanticActions[10][11]=&LexicalAnalyzer::ASED;
        semanticActions[10][12]=&LexicalAnalyzer::ASED;
        semanticActions[10][13]=&LexicalAnalyzer::ASED;
        semanticActions[10][14]=&LexicalAnalyzer::ASED;
        semanticActions[10][15]=&LexicalAnalyzer::ASED;
        semanticActions[10][16]=&LexicalAnalyzer::ASED;
        semanticActions[10][17]=&LexicalAnalyzer::ASED;
        semanticActions[10][18]=&LexicalAnalyzer::ASED;
        semanticActions[10][19]=&LexicalAnalyzer::ASED;
        semanticActions[10][20]=&LexicalAnalyzer::ASED;
        semanticActions[10][21]=&LexicalAnalyzer::ASED;
        semanticActions[10][22]=&LexicalAnalyzer::ASED;

    /* Fila 11 */
        semanticActions[11][0]=&LexicalAnalyzer::ASOP;
        semanticActions[11][1]=&LexicalAnalyzer::ASOP;
        semanticActions[11][2]=&LexicalAnalyzer::ASOP;
        semanticActions[11][3]=&LexicalAnalyzer::ASOP;
        semanticActions[11][4]=&LexicalAnalyzer::ASOP;
        semanticActions[11][5]=&LexicalAnalyzer::ASOP;
        semanticActions[11][6]=&LexicalAnalyzer::ASOP;
        semanticActions[11][7]=&LexicalAnalyzer::ASOP;
        semanticActions[11][8]=&LexicalAnalyzer::ASOP;
        semanticActions[11][9]=&LexicalAnalyzer::ASOP;
        semanticActions[11][10]=&LexicalAnalyzer::ASOP;
        semanticActions[11][11]=&LexicalAnalyzer::ASOP;
        semanticActions[11][12]=&LexicalAnalyzer::ASOP;
        semanticActions[11][13]=&LexicalAnalyzer::ASOP;
        semanticActions[11][14]=&LexicalAnalyzer::ASOP;
        semanticActions[11][15]=&LexicalAnalyzer::ASOP;
        semanticActions[11][16]=&LexicalAnalyzer::ASOP;
        semanticActions[11][17]=&LexicalAnalyzer::ASOP;
        semanticActions[11][18]=&LexicalAnalyzer::ASOP;
        semanticActions[11][19]=&LexicalAnalyzer::ASOP;
        semanticActions[11][20]=&LexicalAnalyzer::ASOPD;
        semanticActions[11][21]=&LexicalAnalyzer::ASOP;
        semanticActions[11][22]=&LexicalAnalyzer::ASOP_EOF;

    /* Fila 12 */
        semanticActions[12][0]=&LexicalAnalyzer::ASOP;
        semanticActions[12][1]=&LexicalAnalyzer::ASOP;
        semanticActions[12][2]=&LexicalAnalyzer::ASOP;
        semanticActions[12][3]=&LexicalAnalyzer::ASOP;
        semanticActions[12][4]=&LexicalAnalyzer::ASOP;
        semanticActions[12][5]=&LexicalAnalyzer::ASOP;
        semanticActions[12][6]=&LexicalAnalyzer::ASOP;
        semanticActions[12][7]=&LexicalAnalyzer::ASOP;
        semanticActions[12][8]=&LexicalAnalyzer::ASOP;
        semanticActions[12][9]=&LexicalAnalyzer::ASOP;
        semanticActions[12][10]=&LexicalAnalyzer::ASOP;
        semanticActions[12][11]=&LexicalAnalyzer::ASOP;
        semanticActions[12][12]=&LexicalAnalyzer::ASOP;
        semanticActions[12][13]=&LexicalAnalyzer::ASOP;
        semanticActions[12][14]=&LexicalAnalyzer::ASOP;
        semanticActions[12][15]=&LexicalAnalyzer::ASOP;
        semanticActions[12][16]=&LexicalAnalyzer::ASOP;
        semanticActions[12][17]=&LexicalAnalyzer::ASOP;
        semanticActions[12][18]=&LexicalAnalyzer::ASOP;
        semanticActions[12][19]=&LexicalAnalyzer::ASOP;
        semanticActions[12][20]=&LexicalAnalyzer::ASOPD;
        semanticActions[12][21]=&LexicalAnalyzer::ASOP;
        semanticActions[12][22]=&LexicalAnalyzer::ASOP;

    /* Fila 13 */
        semanticActions[13][0]=&LexicalAnalyzer::ASOP;
        semanticActions[13][1]=&LexicalAnalyzer::ASOP;
        semanticActions[13][2]=&LexicalAnalyzer::ASOP;
        semanticActions[13][3]=&LexicalAnalyzer::ASOP;
        semanticActions[13][4]=&LexicalAnalyzer::ASOP;
        semanticActions[13][5]=&LexicalAnalyzer::ASOP;
        semanticActions[13][6]=&LexicalAnalyzer::ASOP;
        semanticActions[13][7]=&LexicalAnalyzer::ASOP;
        semanticActions[13][8]=&LexicalAnalyzer::ASOP;
        semanticActions[13][9]=&LexicalAnalyzer::ASOP;
        semanticActions[13][10]=&LexicalAnalyzer::ASOP;
        semanticActions[13][11]=&LexicalAnalyzer::ASOP;
        semanticActions[13][12]=&LexicalAnalyzer::ASOP;
        semanticActions[13][13]=&LexicalAnalyzer::ASOP;
        semanticActions[13][14]=&LexicalAnalyzer::ASOP;
        semanticActions[13][15]=&LexicalAnalyzer::ASOP;
        semanticActions[13][16]=&LexicalAnalyzer::ASOP;
        semanticActions[13][17]=&LexicalAnalyzer::ASOP;
        semanticActions[13][18]=&LexicalAnalyzer::ASOP;
        semanticActions[13][19]=&LexicalAnalyzer::ASOP;
        semanticActions[13][20]=&LexicalAnalyzer::ASOPD;
        semanticActions[13][21]=&LexicalAnalyzer::ASOP;
        semanticActions[13][22]=&LexicalAnalyzer::ASOP;

    /* Fila 14 */
        semanticActions[14][0]=&LexicalAnalyzer::ASTI;
        semanticActions[14][1]=&LexicalAnalyzer::ASTI;
        semanticActions[14][2]=&LexicalAnalyzer::ASTI;
        semanticActions[14][3]=&LexicalAnalyzer::ASTI;
        semanticActions[14][4]=&LexicalAnalyzer::ASTI;
        semanticActions[14][5]=&LexicalAnalyzer::ASTI;
        semanticActions[14][6]=&LexicalAnalyzer::ASTI;
        semanticActions[14][7]=&LexicalAnalyzer::ASTI;
        semanticActions[14][8]=&LexicalAnalyzer::ASTI;
        semanticActions[14][9]=&LexicalAnalyzer::ASTI;
        semanticActions[14][10]=&LexicalAnalyzer::ASTI;
        semanticActions[14][11]=&LexicalAnalyzer::ASTI;
        semanticActions[14][12]=&LexicalAnalyzer::ASTI;
        semanticActions[14][13]=&LexicalAnalyzer::ASTI;
        semanticActions[14][14]=&LexicalAnalyzer::ASTI;
        semanticActions[14][15]=&LexicalAnalyzer::ASTI;
        semanticActions[14][16]=&LexicalAnalyzer::ASTI;
        semanticActions[14][17]=&LexicalAnalyzer::ASTI;
        semanticActions[14][18]=&LexicalAnalyzer::ASTI;
        semanticActions[14][19]=&LexicalAnalyzer::ASTI;
        semanticActions[14][20]=&LexicalAnalyzer::ASOPD;
        semanticActions[13][21]=&LexicalAnalyzer::ASTI;
        semanticActions[13][22]=&LexicalAnalyzer::ASTI;

    /* Fila 15 */
        semanticActions[15][0]=&LexicalAnalyzer::ASTI;
        semanticActions[15][1]=&LexicalAnalyzer::ASTI;
        semanticActions[15][2]=&LexicalAnalyzer::ASTI;
        semanticActions[15][3]=&LexicalAnalyzer::ASTI;
        semanticActions[15][4]=&LexicalAnalyzer::ASTI;
        semanticActions[15][5]=&LexicalAnalyzer::ASTI;
        semanticActions[15][6]=&LexicalAnalyzer::ASTI;
        semanticActions[15][7]=&LexicalAnalyzer::ASTI;
        semanticActions[15][8]=&LexicalAnalyzer::ASTI;
        semanticActions[15][9]=&LexicalAnalyzer::ASTI;
        semanticActions[15][10]=&LexicalAnalyzer::ASTI;
        semanticActions[15][11]=&LexicalAnalyzer::ASTI;
        semanticActions[15][12]=&LexicalAnalyzer::ASTI;
        semanticActions[15][13]=&LexicalAnalyzer::ASTI;
        semanticActions[15][14]=&LexicalAnalyzer::ASTI;
        semanticActions[15][15]=&LexicalAnalyzer::ASTI;
        semanticActions[15][16]=&LexicalAnalyzer::ASTI;
        semanticActions[15][17]=&LexicalAnalyzer::ASTI;
        semanticActions[15][18]=&LexicalAnalyzer::ASTI;
        semanticActions[15][19]=&LexicalAnalyzer::ASTI;
        semanticActions[15][20]=&LexicalAnalyzer::ASOPD;
        semanticActions[15][21]=&LexicalAnalyzer::ASTI;
        semanticActions[15][22]=&LexicalAnalyzer::ASTI;

    /* Fila 16 */
        semanticActions[16][0]=&LexicalAnalyzer::ASA;
        semanticActions[16][1]=&LexicalAnalyzer::ASA;
        semanticActions[16][2]=&LexicalAnalyzer::ASA;
        semanticActions[16][3]=&LexicalAnalyzer::ASA;
        semanticActions[16][4]=&LexicalAnalyzer::ASA;
        semanticActions[16][5]=&LexicalAnalyzer::ASA;
        semanticActions[16][6]=&LexicalAnalyzer::ASA;
        semanticActions[16][7]=&LexicalAnalyzer::ASA;
        semanticActions[16][8]=&LexicalAnalyzer::ASA;
        semanticActions[16][9]=&LexicalAnalyzer::ASA;
        semanticActions[16][10]=&LexicalAnalyzer::ASEC;
        semanticActions[16][11]=&LexicalAnalyzer::ASA;
        semanticActions[16][12]=&LexicalAnalyzer::ASA;
        semanticActions[16][13]=&LexicalAnalyzer::ASA;
        semanticActions[16][14]=&LexicalAnalyzer::ASA;
        semanticActions[16][15]=&LexicalAnalyzer::ASCAD;
        semanticActions[16][16]=&LexicalAnalyzer::ASA;
        semanticActions[16][17]=&LexicalAnalyzer::ASA;
        semanticActions[16][18]=&LexicalAnalyzer::ASA;
        semanticActions[16][19]=&LexicalAnalyzer::ASA;
        semanticActions[16][20]=&LexicalAnalyzer::ASA;
        semanticActions[16][21]=&LexicalAnalyzer::ASA;
        semanticActions[16][22]=&LexicalAnalyzer::ASEC_EOF;

    /* Fila 17 */
        semanticActions[17][0]=&LexicalAnalyzer::ASA;
        semanticActions[17][1]=&LexicalAnalyzer::ASA;
        semanticActions[17][2]=&LexicalAnalyzer::ASA;
        semanticActions[17][3]=&LexicalAnalyzer::ASA;
        semanticActions[17][4]=&LexicalAnalyzer::ASA;
        semanticActions[17][5]=&LexicalAnalyzer::ASA;
        semanticActions[17][6]=&LexicalAnalyzer::ASA;
        semanticActions[17][7]=&LexicalAnalyzer::ASA;
        semanticActions[17][8]=&LexicalAnalyzer::ASA;
        semanticActions[17][9]=&LexicalAnalyzer::ASA;
        semanticActions[17][10]=&LexicalAnalyzer::ASA;
        semanticActions[17][11]=&LexicalAnalyzer::ASA;
        semanticActions[17][12]=&LexicalAnalyzer::ASA;
        semanticActions[17][13]=&LexicalAnalyzer::ASA;
        semanticActions[17][14]=&LexicalAnalyzer::ASA;
        semanticActions[17][15]=&LexicalAnalyzer::ASA;
        semanticActions[17][16]=&LexicalAnalyzer::ASA;
        semanticActions[17][17]=&LexicalAnalyzer::ASA;
        semanticActions[17][18]=&LexicalAnalyzer::ASA;
        semanticActions[17][19]=&LexicalAnalyzer::ASA;
        semanticActions[17][20]=&LexicalAnalyzer::ASA;
        semanticActions[17][21]=&LexicalAnalyzer::ASA;
        semanticActions[17][22]=&LexicalAnalyzer::ASEC_EOF;

    /* Fila 18 */
        semanticActions[18][0]=&LexicalAnalyzer::ASECOM;
        semanticActions[18][1]=&LexicalAnalyzer::ASECOM;
        semanticActions[18][2]=&LexicalAnalyzer::ASECOM;
        semanticActions[18][3]=&LexicalAnalyzer::ASECOM;
        semanticActions[18][4]=&LexicalAnalyzer::ASECOM;
        semanticActions[18][5]=&LexicalAnalyzer::ASECOM;
        semanticActions[18][6]=&LexicalAnalyzer::ASECOM;
        semanticActions[18][7]=&LexicalAnalyzer::ASECOM;
        semanticActions[18][8]=&LexicalAnalyzer::ASECOM;
        semanticActions[18][9]=&LexicalAnalyzer::ASECOM;
        semanticActions[18][10]=&LexicalAnalyzer::ASECOM;
        semanticActions[18][11]=&LexicalAnalyzer::ASECOM;
        semanticActions[18][12]=&LexicalAnalyzer::ASECOM;
        semanticActions[18][13]=&LexicalAnalyzer::ASECOM;
        semanticActions[18][14]=&LexicalAnalyzer::ASECOM;
        semanticActions[18][15]=&LexicalAnalyzer::ASECOM;
        semanticActions[18][16]=&LexicalAnalyzer::ASECOM;
        semanticActions[18][17]=&LexicalAnalyzer::ASECOM;
        semanticActions[18][18]=&LexicalAnalyzer::ASECOM;
        semanticActions[18][19]=&LexicalAnalyzer::ASECOM;
        semanticActions[18][20]=&LexicalAnalyzer::ASECOM;
        semanticActions[18][21]=&LexicalAnalyzer::ASECOM;
        semanticActions[18][22]=&LexicalAnalyzer::ASECOM_EOF;

    /* Fila 19 */
        semanticActions[19][0]=&LexicalAnalyzer::ASV;
        semanticActions[19][1]=&LexicalAnalyzer::ASV;
        semanticActions[19][2]=&LexicalAnalyzer::ASV;
        semanticActions[19][3]=&LexicalAnalyzer::ASV;
        semanticActions[19][4]=&LexicalAnalyzer::ASV;
        semanticActions[19][5]=&LexicalAnalyzer::ASV;
        semanticActions[19][6]=&LexicalAnalyzer::ASV;
        semanticActions[19][7]=&LexicalAnalyzer::ASV;
        semanticActions[19][8]=&LexicalAnalyzer::ASV;
        semanticActions[19][9]=&LexicalAnalyzer::ASV;
        semanticActions[19][10]=&LexicalAnalyzer::ASL;
        semanticActions[19][11]=&LexicalAnalyzer::ASV;
        semanticActions[19][12]=&LexicalAnalyzer::ASV;
        semanticActions[19][13]=&LexicalAnalyzer::ASV;
        semanticActions[19][14]=&LexicalAnalyzer::ASA;
        semanticActions[19][15]=&LexicalAnalyzer::ASV;
        semanticActions[19][16]=&LexicalAnalyzer::ASV;
        semanticActions[19][17]=&LexicalAnalyzer::ASV;
        semanticActions[19][18]=&LexicalAnalyzer::ASV;
        semanticActions[19][19]=&LexicalAnalyzer::ASV;
        semanticActions[19][20]=&LexicalAnalyzer::ASV;
        semanticActions[19][21]=&LexicalAnalyzer::ASV;
        semanticActions[19][22]=&LexicalAnalyzer::ASV;

        /*Fila 20*/

        semanticActions[20][0]=&LexicalAnalyzer::ASV;
        semanticActions[20][1]=&LexicalAnalyzer::ASV;
        semanticActions[20][2]=&LexicalAnalyzer::ASV;
        semanticActions[20][3]=&LexicalAnalyzer::ASV;
        semanticActions[20][4]=&LexicalAnalyzer::ASV;
        semanticActions[20][5]=&LexicalAnalyzer::ASV;
        semanticActions[20][6]=&LexicalAnalyzer::ASV;
        semanticActions[20][7]=&LexicalAnalyzer::ASV;
        semanticActions[20][8]=&LexicalAnalyzer::ASV;
        semanticActions[20][9]=&LexicalAnalyzer::ASV;
        semanticActions[20][10]=&LexicalAnalyzer::ASL;
        semanticActions[20][11]=&LexicalAnalyzer::ASV;
        semanticActions[20][12]=&LexicalAnalyzer::ASV;
        semanticActions[20][13]=&LexicalAnalyzer::ASV;
        semanticActions[20][14]=&LexicalAnalyzer::ASV;
        semanticActions[20][15]=&LexicalAnalyzer::ASV;
        semanticActions[20][16]=&LexicalAnalyzer::ASV;
        semanticActions[20][17]=&LexicalAnalyzer::ASV;
        semanticActions[20][18]=&LexicalAnalyzer::ASV;
        semanticActions[20][19]=&LexicalAnalyzer::ASV;
        semanticActions[20][20]=&LexicalAnalyzer::ASV;
        semanticActions[20][21]=&LexicalAnalyzer::ASV;
        semanticActions[20][22]=&LexicalAnalyzer::ASV;
        /* fila 21*/

        semanticActions[21][0]=&LexicalAnalyzer::ASV;
        semanticActions[21][1]=&LexicalAnalyzer::ASV;
        semanticActions[21][2]=&LexicalAnalyzer::ASA;
        semanticActions[21][3]=&LexicalAnalyzer::ASV;
        semanticActions[21][4]=&LexicalAnalyzer::ASV;
        semanticActions[21][5]=&LexicalAnalyzer::ASV;
        semanticActions[21][6]=&LexicalAnalyzer::ASV;
        semanticActions[21][7]=&LexicalAnalyzer::ASV;
        semanticActions[21][8]=&LexicalAnalyzer::ASV;
        semanticActions[21][9]=&LexicalAnalyzer::ASV;
        semanticActions[21][10]=&LexicalAnalyzer::ASL;
        semanticActions[21][11]=&LexicalAnalyzer::ASV;
        semanticActions[21][12]=&LexicalAnalyzer::ASV;
        semanticActions[21][13]=&LexicalAnalyzer::ASV;
        semanticActions[21][14]=&LexicalAnalyzer::ASA;
        semanticActions[21][15]=&LexicalAnalyzer::ASV;
        semanticActions[21][16]=&LexicalAnalyzer::ASV;
        semanticActions[21][17]=&LexicalAnalyzer::ASV;
        semanticActions[21][18]=&LexicalAnalyzer::ASV;
        semanticActions[21][19]=&LexicalAnalyzer::ASV;
        semanticActions[21][20]=&LexicalAnalyzer::ASV;
        semanticActions[21][21]=&LexicalAnalyzer::ASV;
        semanticActions[21][22]=&LexicalAnalyzer::ASV;

        /* Fila 22 */

        semanticActions[22][0]=&LexicalAnalyzer::ASV;
        semanticActions[22][1]=&LexicalAnalyzer::ASV;
        semanticActions[22][2]=&LexicalAnalyzer::ASV;
        semanticActions[22][3]=&LexicalAnalyzer::ASV;
        semanticActions[22][4]=&LexicalAnalyzer::ASV;
        semanticActions[22][5]=&LexicalAnalyzer::ASV;
        semanticActions[22][6]=&LexicalAnalyzer::ASV;
        semanticActions[22][7]=&LexicalAnalyzer::ASV;
        semanticActions[22][8]=&LexicalAnalyzer::ASV;
        semanticActions[22][9]=&LexicalAnalyzer::ASV;
        semanticActions[22][10]=&LexicalAnalyzer::ASAN;
        semanticActions[22][11]=&LexicalAnalyzer::ASV;
        semanticActions[22][12]=&LexicalAnalyzer::ASV;
        semanticActions[22][13]=&LexicalAnalyzer::ASV;
        semanticActions[22][14]=&LexicalAnalyzer::ASA;
        semanticActions[22][15]=&LexicalAnalyzer::ASV;
        semanticActions[22][16]=&LexicalAnalyzer::ASV;
        semanticActions[22][17]=&LexicalAnalyzer::ASV;
        semanticActions[22][18]=&LexicalAnalyzer::ASV;
        semanticActions[22][19]=&LexicalAnalyzer::ASV;
        semanticActions[22][20]=&LexicalAnalyzer::ASV;
        semanticActions[22][21]=&LexicalAnalyzer::ASV;
        semanticActions[22][22]=&LexicalAnalyzer::ASAN_EOF;



}

/* Devuelve el siguiente token */
 int LexicalAnalyzer::yylex () {

    string * buffer = new string;
    int token = INVALID;
    char c=0;
    int actualState = 0;
    int column = 0;

    while (actualState!=F && column!=EOF) {

        if (file.empty()) {
            column=EOF;
        } else {
            c = file.front();
            file.pop_front();
            column = this->getColumn(c);

        }

        //Ejecuta la accion semantica
        token = (this->*semanticActions[actualState][column])(buffer,c);
        //Actualiza el estado actual
        actualState = state [actualState][column];

        if (actualState==FE || (actualState==F && token==INVALID)) {
            actualState=0;
            buffer->clear();
        }
    } /*End While. Aca hay dos posibilidades: se llego a estado final con token valido,
       o se llego a fin de archivo*/

    if (actualState==F) {
        addRecognized(buffer, token); //lo agrega a la lista de tokens reconocidos
        return token;
    } else {
        return 0;
    }
}

/*Dado un char, devuelve la columna en la matriz*/
 int LexicalAnalyzer::getColumn(char c) {
     int ascci=c;
     if((c!='C' && c!='D' && c!='F' && c>='A' && c<='Z')
        || (c!='d' && c!='i' && c>='a' && c<='z')) //letra
         return 0;
     else if(c-'0'>=0 && c-'9'<=9) //digito
         return 1;
     else if(c=='F' || c=='C') //F o C
         return 2;
     else if(c=='i') //i
         return 3;
     else if(c=='d') //d
         return 4;
     else if(c=='D') //D
         return 5;
     else if(c=='.') //punto
         return 6;
     else if(c=='-') //negativo
         return 7;
     else if(c=='_') //guion bajo
         return 8;
     else if(c==9 || ascci==32) //tab o blanco
         return 9;
     else if(ascci==10) //salto de linea
         return 10;
     else if(c=='+') //suma
         return 11;
     else if(c=='(' || c==')' || c=='[' || c==']' || c=='{' || c=='}'
         || c==',' || c==';' || c=='/') //paretensis, llaves, corchetes,punto y coma,coma
         return 12;
     else if(c=='&') //ampersant
         return 13;
     else if(c=='@') //arroba
         return 14;
     else if(c=='"') //comillas
         return 15;
     else if(c=='>') //mayor
         return 16;
     else if(c=='<') //menor
         return 17;
     else if(c==':') //dos puntos
         return 18;
     else if(c=='!') //esclamacion
         return 19;
     else if(c=='=') //igual
         return 20;
     else if(c=='$') //fin archivo
         return 22;
     else
         return 21; //otro

 }



/*Accion semántica que acumula el char en el buffer */
int LexicalAnalyzer::ASA (string * buffer, char c) {
    buffer->push_back(c);

    //caso especial: cuando el elemento a almacenar es un salto de linea (para cadenas)
    if (c=='\n')
        lines++;

    return INVALID;
}

/*Accion semántica de token invalido */
int LexicalAnalyzer::ASTI (string * buffer, char c) {
    string msg = "\nError lexico: Token invalido en linea: ";
    msg+=std::to_string(lines)+".";
    errors->push_back(msg);
    return INVALID;
}

/*Accion semántica vacia*/
int LexicalAnalyzer::ASV (string * buffer, char c) {
    return INVALID;
}

/*Accion semantica que suma las lineas*/
int LexicalAnalyzer::ASL (string * buffer, char c) {
    lines++;
    return INVALID;
}

/*Accion que reconoce operador simple, pero consume el char*/
int LexicalAnalyzer::AS_opSimple(string * buffer, char c) {
    buffer->push_back(c);
    return ASOP_EOF(buffer, c);

}

/*Reconoce operador simple pero devuelve el char*/
int LexicalAnalyzer::ASOP (string * buffer, char c) {
    file.push_front(c);
    return ASOP_EOF(buffer, c);
}

/*Reconoce operador simple sin almacenar ni descartar el char (para EOF)*/
int LexicalAnalyzer::ASOP_EOF (string * buffer, char c) {
    int token = INVALID;

    if(*buffer == "+")
        token = '+';
    else if(*buffer == "-")
        token = '-';
    else if(*buffer == "*")
        token = '*';
    else if(*buffer == "/")
        token = '/';
    else if(*buffer == "=")
        token = '=';
    else if(*buffer == "(")
        token = '(';
    else if(*buffer == ")")
        token = ')';
    else if(*buffer == ",")
        token = ',';
    else if(*buffer == ";")
        token = ';';
    else if(*buffer == "<")
        token = '<';
    else if(*buffer == ">")
        token = '>';
    else if (*buffer == "{")
        token = '{';
    else if (*buffer == "}")
        token = '}';
    else if (*buffer == "[")
        token = '[';
    else if (*buffer == "]")
        token = ']';
    else if (*buffer == "!")
        token = '!';
    else if (*buffer == ":")
        token = ':';

    return token;
}

/*Accion semantica que reconoce identificadores y palabras reservadas*/
int LexicalAnalyzer::AS_id_pr(string * buffer, char c) {
    file.push_front(c); //devuelve char a la entrada
    return AS_id_pr_EOF(buffer,c);
}

/*Accion semantica que reconoce id y pr al final del archivo*/
int LexicalAnalyzer::AS_id_pr_EOF(string * buffer, char c) {

    std::map<string,int>::iterator it=reservedWords.find(*buffer);
    if (it != reservedWords.end())
        return it->second;

    //Es un identificador

    if (buffer->size()>20) {
        string msg = "\n Warning: identificador demasiado largo. Truncado. Linea: ";
        msg=msg+std::to_string(lines);
        msg.append(".");
        warnings->push_back(msg);
        *buffer=buffer->substr(0,19);
    }

    if (!symbolsTable->contains(*buffer)) {
        //se da de alta en la tabla
        Entry * entry = new Entry (*buffer, "ID", ID);
        symbolsTable->put(*buffer, entry);
    }

    //yylval = symbolsTable->indexOf(*buffer);

    return ID;
}

/*Accion semantica de error de prefijo numerico*/
int LexicalAnalyzer::ASEPN(string * buffer, char c) {
    string msg = "\nError lexico: prefijo numerico erroneo en linea: ";
    msg+=std::to_string(lines);
    msg.append(".");
    errors->push_back(msg);
    return INVALID;

}

/*Accion semantica de entero mal escrito*/
int LexicalAnalyzer::ASEE(string * buffer, char c) {
    string msg = "\nError lexico: numero entero mal escrito en linea: ";
    msg+=std::to_string(lines);
    msg.append(".");
    errors->push_back(msg);
    return INVALID;
}

/*Accion semantica que reconoce entero*/
int LexicalAnalyzer::ASE(string * buffer, char c) {
    file.push_front(c);
    return ASE_EOF(buffer,c);
}

int LexicalAnalyzer::ASE_EOF (string * buffer, char c) {

    string aux(*buffer);
    aux=aux.substr(2,aux.size()-1);

    int value = atoi(aux.c_str());

    //VERIFICAR BIEN QUE LOS NUMEROS COINCIDAN CON EL PRACTICO
    if (value < -32768 || value > 32768) {
        string msg = "\nError lexico: constante entera fuera de rango en linea: ";
        msg+=std::to_string(lines)+".";
        errors->push_back(msg);
        return INVALID;
    }

    if (!symbolsTable->contains(*buffer)) {
        Entry * entry = new Entry (*buffer, "CTE", CTE);
        entry->type="INT";
        entry->intValue=value;
        symbolsTable->put(*buffer, entry);
    }

    //yylval = symbolsTable->indexOf(*buffer);

    return CTE;


}

/*Accion semantica de error de double*/
int LexicalAnalyzer::ASED (string * buffer, char c) {
    file.push_front(c);
    string msg = "\nError lexico: double mal escrito en linea: ";
    msg+=std::to_string(lines)+".";
    errors->push_back(msg);
    return INVALID;

}

/*Accion semantica que reconoce constante double*/
int LexicalAnalyzer::ASD (string * buffer, char c) {
    file.push_front(c);
    return ASD_EOF(buffer,c);
}

/*Accion semantica que reconoce constante double en EOF*/
int LexicalAnalyzer::ASD_EOF (string * buffer, char c) {
    //VERIFICAR RANGO

    //VERIFICAR TS

    //YYLVAL = Index en la tabla

    return CTE;
}

/*Accion semantica que reconoce operadores dobles*/
int LexicalAnalyzer::ASOPD (string * buffer, char c) {
    buffer->push_back(c);
     int token =-1;

    if(*buffer == ">=")
        token = MAYORIGUAL;
    else if(*buffer == "<=")
        token = MENORIGUAL;
    else if(*buffer == "!=")
        token = DISTINTO;
    else if(*buffer == ":=")
        token = DOSPUNTOSIGUAL;
    else if (*buffer == "-=")
        token = MENOSIGUAL;

    return token;
}

/*Accion semantica que reconoce cadena*/
int LexicalAnalyzer::ASCAD (string * buffer, char c) {
    buffer->push_back(c);

    //VERIFICAR TS

    //YYLVAL = Index

    return CADENA;
}

/*Accion semantica de error de cadena*/
int LexicalAnalyzer::ASEC (string * buffer, char c) {
    file.push_front(c);
    string msg = "\nError lexico: Cadena mal escrita en linea: ";
    msg+=std::to_string(lines);
    msg.append(". Falta el simbolo '+' antes del salto de linea");
    errors->push_back(msg);
    return INVALID;
}

/*Accion de error de cadena al final del archivo*/
int LexicalAnalyzer::ASEC_EOF (string * buffer, char c) {
    string msg = "\nError lexico: Cadena mal escrita en linea: ";
    msg+=std::to_string(lines);
    msg.append(". Debe cerrarse con comillas. ");
    errors->push_back(msg);
    return INVALID;
}

/*Accion que reconoce anotacion */
int LexicalAnalyzer::ASAN (string * buffer, char c) {
    file.push_front(c);
    return ASAN_EOF(buffer,c);
}

/*Accion que reconoce anotacion en EOF */
int LexicalAnalyzer::ASAN_EOF (string * buffer, char c) {
    int token = INVALID;
    if (*buffer ==  "@F")
        token = ARROBA_F;
    else if (*buffer == "@C")
        token = ARROBA_C;

    return token;
}

/**/
int LexicalAnalyzer::ASECOM(string *buffer, char c) {
    file.push_front(c);
    return ASECOM_EOF(buffer,c);
}

/**/
int LexicalAnalyzer::ASECOM_EOF(string *buffer, char c) {
    string msg = "\nError lexico: Comentario mal escrita en linea: ";
    msg+=std::to_string(lines);
    msg.append(". Falto otro caracter '&'. ");
    errors->push_back(msg);
    return INVALID;
}

list<string> LexicalAnalyzer::getTokens()
{
return recognizedTokens;
}

/**********IMPORTANTE ***********/

/* Modificar cuando se usen las constantes dadas por el parser */

void LexicalAnalyzer::addRecognized(string * buffer, int token) {
    string description = "";
    if (token >= 300) //ACA IRIA 257 CON YACC CREO
    {
        if (token >=310)
            description="Palabra reservada: ";
        else if (token == ID)
            description="Identificador: ";
            else if (token == CTE) {
                //REVISAR LA TS Y AGREGAR "Constante entera: " o "Constante double")
            } else if (token == CADENA)
                description="Cadena: ";
    }

    description+=*buffer;
    description+="\n";

    recognizedTokens.push_back(description);

}
