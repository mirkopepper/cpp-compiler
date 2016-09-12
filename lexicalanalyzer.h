#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H

#include <list>
#include <String>
#include <Map>
#include "constants.h"
#include "symbolstable.h"
#include <iostream>
using namespace std;

#define F -2 //estado final
#define FE -3 //Final con error. Para cuando hay errores. También para los comentarios (se vuelve al estado 0)
#define EOF 21 //columna de fin de archivo
#define INVALID -4 //para devolver cuando el token no es valido, o en pasos intermedios


static const int state [23][23] ={

   /*
                                                                    (,)
                                                                    {,}
                                                                    [,]
                                                                    ','
                                                     tab            ';'
        letra	digito	F,C i	d	D	.   -	 _	blanco, \n  (+)  /      &	@	 "	 >	 <	 :	 !  (=)	  otro EOF      */
       { 1 ,       FE , 1,  1 , 1 , 1 , FE, 11 , 2 ,   0 ,  0 ,  F ,  F ,  18 , FE , 16 ,13, 12 ,14 ,15 ,F,    FE, FE}, //0
       { 1 ,       1 ,  1,  1 , 1 , 1 , F , F ,  1 ,   F ,  F ,  F ,  F ,  F ,  F ,  F , F,  F , F , F , F,    F,  F}, //1
       { FE ,      FE , FE, 3 , 5 , FE ,FE ,FE ,FE ,   FE , FE , FE , FE , FE , FE , FE, FE, FE ,FE ,FE, FE,   FE, FE}, //2
       { FE ,      4 ,  FE, FE, FE ,FE ,FE ,4 , FE ,   FE , FE , FE , FE , FE , FE,  FE ,FE, FE ,FE ,FE ,FE,   FE, FE}, //3
       { F ,       4 ,  F,  F , F , F , F , F , F ,    F ,  F ,  F ,  F ,  F ,  F ,  F , F,  F , F , F , F,    F,  F}, //4
       { FE ,      6 ,  FE, FE ,FE ,FE ,7 , 6 , FE,    FE , FE , FE , FE , FE , FE , FE, FE, FE, FE ,FE ,FE,   FE, FE}, //5
       { FE,       6 ,  FE, FE ,FE ,FE ,7 , FE ,FE ,   FE , FE , FE , FE , FE , FE , FE ,FE, FE ,FE ,FE ,FE,   FE, FE}, //6
       { F ,       7 ,  F,  F , 8 , 8 , F , F , F ,    F ,  F ,  F ,  F ,  F ,  F ,  F , F,  F , F , F , F,    F,  F}, //7
       { FE ,      9 ,  FE, FE ,FE ,FE ,FE ,10 ,FE ,   FE , FE , 10 , FE , FE , FE , FE ,FE, FE ,FE ,FE ,FE,   FE, FE}, //8
       { F ,       9 ,  F,  F , F , F , F , F , F ,    F ,  F ,  F ,  F ,  F ,  F ,  F , F,  F , F , F , F,    F,  F}, //9
       { FE ,      9 ,  FE, FE ,FE ,FE ,FE ,FE ,FE ,   FE , FE , FE , FE , FE , FE,  FE ,FE, FE, FE ,FE ,FE,   FE, FE}, //10
       { F ,       F ,  F,  F , F , F , F , F , F ,    F ,  F ,  F ,  F ,  F ,  F ,  F , F,  F , F , F , F,    F,  F}, //11
       { F ,       F ,  F,  F , F , F , F , F , F ,    F ,  F ,  F ,  F ,  F ,  F ,  F , F,  F , F , F , F,    F,  F}, //12
       { F ,       F ,  F,  F , F , F , F , F , F ,    F ,  F ,  F ,  F ,  F ,  F ,  F , F,  F , F , F , F,    F,  F}, //13
       { FE ,      FE,  FE, FE ,FE ,FE ,FE ,FE ,FE ,   FE , FE , FE , FE , FE , FE , FE ,FE, FE ,FE ,FE ,F,    FE, FE}, //14
       { FE ,      FE,  FE, FE ,FE ,FE ,FE ,FE ,FE ,   FE , FE , FE , FE , FE , FE , FE ,FE, FE ,FE ,FE ,F,    FE, FE}, //15
       { 16 ,      16 , 16, 16 ,16 ,16 ,16 ,16 ,16 ,   16 , FE , 17 , 16 , 16 , 16 , F , 16, 16 ,16 ,16 ,16,   16, FE}, //16
       { 16 ,      16 , 16, 16 ,16 ,16 ,16 ,16 ,16 ,   16 , 16 , 17 , 16 , 16 , 16 , F , 16, 16 ,16 ,16 ,16,   16, FE}, //17
       { FE ,      FE,  FE, FE ,FE ,FE ,FE ,FE ,FE ,   FE , FE , FE , FE , 19 , FE , FE ,FE, FE ,FE ,FE ,F,    FE, FE}, //18
       { 20 ,      20 , 20, 20 ,20 ,20 ,20 ,20 ,20 ,   20 , FE , 20 , 20 , 20  ,21 , 20 ,20, 20 ,20 ,20 ,20,   20, FE}, //19
       { 20 ,      20 , 20, 20 ,20 ,20 ,20 ,20 ,20 ,   20 , FE , 20 , 20 , 20  ,20 , 20 ,20, 20 ,20 ,20 ,20,   20, FE}, //20
       { 20 ,      20 , 22, 20 ,20 ,20 ,20 ,20 ,20 ,   20 , FE , 20 , 20 , 20  ,20 , 20 ,20, 20 ,20 ,20 ,20,   20, FE}, //21
       { 22 ,      22 , 22, 22 ,22 ,22 ,22 ,22 ,22 ,   22 , F ,  22 , 22 , 22 , 22 , 22, 22, 22 ,22 ,22 ,22,   22, F} //22

   };


class LexicalAnalyzer
{
public:
    LexicalAnalyzer(const char * textfile, list<String> * warnings, list<String> * errors, SymbolsTable * symbolsTable);
    int yylex();

private:
    SymbolsTable * symbolsTable;
    list<String> * warnings;
    list <String> * errors;
    int lines = 1;
    QMap <String, int> reservedWords;

    //Para imprimir al final
    list <String> recognizedTokens;
    void addRecognized(String * buffer, int token);


    //Contendra el contenido del archivo. Se usa como entrada.
    list<char> file;

    //matriz de acciones semanticas
    int (LexicalAnalyzer::*semanticActions [23][23])(String*,char);

    //dado un char, devuelve su columna correspondiente
    int getColumn(char c);


    void initState();
    void initReservedWords();
    void error(string str);

    /** Acciones semanticas **/

    //Accion semantica de acumulación: agrega char a la entrada.
    int ASA(String * buffer, char c);

    //Accion semantica para token invalido
    int ASTI(String * buffer, char c);

    //Accion semantica para cuando no se tiene que almacenar ni descartar
    int ASV(String * buffer, char c);

    //Accion semantica para sumar lineas
    int ASL(String * buffer, char c);

    //Accion semantica operadores aritmeticos simples
    int AS_opSimple(String * buffer, char c);

    //Accion semantica  Verifica si es PR y devuelve, si no: identificador.
    int AS_id_pr(String * buffer, char c);

    // idem anterior pero no devuelve char
    int AS_id_pr_EOF(String * buffer, char c);

    //Acción semantica error de prefijo numerico
    int ASEPN(String * buffer, char c);

    //Acción semantica error entero mal escrito (error lexico)
    int ASEE(String * buffer, char c);

    //Accion semantica  reconoce entero
    int ASE(String * buffer, char c);

    //Accion semantica  error doble
    int ASED(String * buffer, char c);

    //Accion semantica  reconoce doble
    int ASD(String * buffer, char c);

    //Accion semantica  reconoce doble sobre final de archivo
    int ASD_EOF(String * buffer, char c);

    //Accion semantica reconoce operadores dobles. Consume char
    int ASOPD(String * buffer, char c);

    //Accion semantica accion que reconoce operadores simples. Devuelve char
    int ASOP(String * buffer, char c);

    //Accion semantica que reconoce operadores simples sobre final de archivo. Devuelve char
    int ASOP_EOF(String * buffer, char c);

    //Accion semantica que reconoce cadena
    int ASCAD(String * buffer, char c);

    //Accion semantica que reconoce  error cadena
    int ASEC(String * buffer, char c);

    //Accion semantica que reconoce anotacion
    int ASAN(String * buffer, char c);

    //Accion semantica que reconoce anotacion sobre fin de archivo
    int ASAN_EOF(String * buffer, char c);

    //Accion semantica que reconoce entero sobre fin de archivo
    int ASE_EOF(String * buffer, char c);

    //Accion semantica error cadena fin de archivo
    int ASEC_EOF (String * buffer, char c);

    //Accion semantica error comentario
    int ASECOM (String * buffer, char c);

    //Accion semantica error comentario en EOF
    int ASECOM_EOF (String * buffer, char c);

};

#endif // LEXICALANALIZER_H
