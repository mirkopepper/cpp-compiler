#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H
#include "node.h"
#include "pointerstable.h"
#include <QMap>
#include <QString>
#include "symbolstable.h"
#include <fstream>
#include "y.tab.h"
class CodeGenerator
{
public:
    CodeGenerator(SymbolsTable * symbolsTable);

    //Crea nodo hoja y devuelve su clave
    string crearNodo(string dato);

    //Crea nodo con un hijo a la izquierda y devuelve su clave
    string crearNodo (string dato, string nodoIzquierda);

    //Crea nodo con dos hijos y devuelve su clave
    string crearNodo(string dato, string nodoIzquierda, string nodoDerecha);

    //Le asigna como hijo izquierdo el 2do paramtro al 1ro
    void addRightNode(string parentNode, string rightNode);

    //Dado un string, devuelve el nodo correspondiente
    Node * getNode(string key);

    /*se le pasa la clave de un nodo ya creado, ahora el puntero raiz apunta a dicho nodo*/
    void setAsRootNode(string keyNode);

    /*se le pasa la clave de un nodo perteneciente a un bloque:de inicializacion de matrices o bloque de sentencias*/
    void setAsBlockSentenceNode(string keyNode);

    /*retorna el ultimo bloque de sentencias*/
    string getLastBlock();

    /*chequea si el arbol ya tiene sentencias (TRUE) o si esta vacio (FALSE)*/
    bool rootIsNull();

    /*imprime arbol*/
    void printSintacticTree();

    PointersTable pointersTable;

    void generateAssembler(const char * ruta);

private:
    //<lexema, nombre_assembler> para asociar un lexema de una cte a su nombre usado en assembler
    QMap <QString,QString> constantes;

    //idem anterior pero con cadenas
    QMap <QString, QString> cadenas;

    /*Almacena los nombres de variables auxiliares que se generaron y de paso sirve
     * de indice para generar nuevas ( ver processNode). La variable @aux_0 estara
     * en la posicion 0. La variable @aux_1 estara en la 1*/
    QList<QString> variablesAuxiliares;

    /*pila de etiquetas para saltos:guarda @label_i*/
    QList<QString> labels;

    /*permite que no haya 2 etiquetas iguales, aumenta cada ves que se debe generar una nueva*/
    int labelsCounter;

    SymbolsTable * symbolsTable;

    void mapearConstantesYCadenas();

    bool firstSentence();

    QList<QString> getAssemblerVariables();

    /*genera una etiqueta nueva y la pone en la pila de etiquetas*/
    QString generateLabel();

    /*genera una variable auxiliar y la agrega a la TS*/
    QString getVarAux(string type);

    /*genera las instrucciones assembler correspondientes para el nodo en cuestion*/
    void generateInstructions(Node * node);

    /*genera las instrucciones assembler de estructuras if*/
    void generateIfInstructions(Node * node);

    /*genera las instrucciones assembler de estructuras while*/
    void generateWhileInstructions(Node * node);

    /*poda el arbol desde el nodo pasado por parametro, si genera var auxiliares, cambia dicho nodo por uno nuevo*/
    void processNode(Node * &node);

    /*genera las sentencias declarativas en assembler*/
    QString declareAssemblerVariable(string lexeme);

    /*obtiene el nombre de la variable assembler asociado a op, que es el nombre de codigo intermedio*/
    QString convertOperand(string op);
    QString convertOperand(QString op);

    void generateCode();

    /*recorre el arbol buscando siempre primero el nodo mas a la izquierda cuyos hijos son hojas, genera assembler y lo procesa*/
    void  recorrerArbol (Node * &root);

    /*da true si los hijos son hoja*/
    bool tieneHijosHoja(Node * node);

    /*guarda las intrucciones assembler*/
    QList<QString> code;

    bool useDirReg=false;

    Node * root;

};

#endif // CODEGENERATOR_H
