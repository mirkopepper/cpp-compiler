#include "codegenerator.h"
#include "codegenerator.h"
#include <iostream>

CodeGenerator::CodeGenerator(SymbolsTable * symbolsTable)
{

    this->symbolsTable=symbolsTable;

    root=NULL;

}

string CodeGenerator::crearNodo(string dato){
    Node * nodo = new Node;
    nodo->dato=QString::fromStdString(dato);
    nodo->hijoDerecho=NULL;
    nodo->hijoIzquierdo=NULL;
    return pointersTable.registerNode(nodo);
}

string CodeGenerator::crearNodo(string dato, string nodoIzquierda){
    Node * nodo = new Node;
    nodo->dato=QString::fromStdString(dato);
    nodo->hijoDerecho=NULL;
    nodo->hijoIzquierdo=pointersTable.getNode(nodoIzquierda);
    return pointersTable.registerNode(nodo);
}

string CodeGenerator::crearNodo(string dato, string nodoIzquierda, string nodoDerecha){
    Node * nodo = new Node;
    nodo->dato=QString::fromStdString(dato);
    nodo->hijoDerecho=pointersTable.getNode(nodoDerecha);
    if(nodoIzquierda=="root")
        nodo->hijoIzquierdo=root;
    else{
        nodo->hijoIzquierdo=pointersTable.getNode(nodoIzquierda);
    }
    return pointersTable.registerNode(nodo);
}

void CodeGenerator::addRightNode(string parentNode, string rightNode){
    if(parentNode!=""){
        Node * parent=pointersTable.getNode(parentNode);
        parent->hijoDerecho=pointersTable.getNode(rightNode);
    }
}

bool CodeGenerator::firstSentence() {
    return (root==NULL);
}

Node * CodeGenerator::getNode(string key){
    return this->pointersTable.getNode(key);
}

//mapea todas las constantes y cadenas a un nuevo nombre que será usado en assembler
//luego, cuando se mencione una constante o una cadena, se usarán los nombres nuevos
//para generar código. Esta conversion la hara el metodo convertirOperando, que dado
//un elemento de la tabla de simbolos, devuelve su nombre en assembler
void CodeGenerator::mapearConstantesYCadenas() {
    constantes.clear();
    cadenas.clear();
    QList<string> entries = symbolsTable->getKeys();
    for (int i=0; i<entries.size(); i++){
        Entry * entry = symbolsTable->getEntry(entries.at(i));
        if (entry->token == "CTE") {
            QString nombreCte = "@cte" + QString::number(constantes.size());
            constantes.insert(QString::fromStdString(entry->lexeme), nombreCte);
        } else if (entry->token == "CADENA") {
            QString nombreCad = "@cadena" + QString::number(cadenas.size());
            cadenas.insert(QString::fromStdString(entry->lexeme),nombreCad);
        }
    }
    /*Verificar que los nombres @cte y @cadena sean validos. Osea que no choquen
    con otra cosa y eso */
}

/*Devuelve la declaración de variable en assembler
 *de la variable dada
 */
QString CodeGenerator::declareAssemblerVariable(string lexeme) {
    Entry * e=symbolsTable->getEntry(lexeme);
    if(e->token=="ID"){
        string use=symbolsTable->getUse(lexeme);
        if(use=="variable"){
            if(e->type=="INTEGER")
                return QString::fromStdString(e->lexeme + " dw ?" );
            else
                return QString::fromStdString(e->lexeme + " dd ?");
        }
        if(use=="matriz"){
            int limit=(e->limit1)*(e->limit2);
            if(e->type=="INTEGER")
                return QString::fromStdString(e->lexeme + " dw " + to_string(limit) + " DUP(?)");
            else
                return QString::fromStdString(e->lexeme + " dd " + to_string(limit) + " DUP(?)");
        }
    }
    if(e->token=="CTE"){
        if(e->type=="INTEGER")
            return constantes.value(QString::fromStdString(lexeme)) + QString::fromStdString(" dw " + e->getValue());
        else
            return constantes.value(QString::fromStdString(lexeme)) + QString::fromStdString(" dd " + e->getValue());
    }
    if(e->token=="CADENA"){
        return cadenas.value(QString::fromStdString(lexeme)) + QString::fromStdString(" db " + lexeme + ", 0");
    }

    return "";
}

/* Devuelve TODAS las instrucciones assembler de declaracion
 * de variables. Seria la parte declarativa convertida en
 * assembler
 */
QList<QString> CodeGenerator::getAssemblerVariables() {
    QList<QString> result;
    result.clear();
    QList<string> entries = symbolsTable->getKeys();
    for (int i=0; i<entries.size(); i++){
        result.append(declareAssemblerVariable(entries.at(i)));
    }
    return result;
}


/*Devuelve el nombre de la variable assembler a la que se hace
*referencia
*/
QString CodeGenerator::convertOperand(string op) {

    Entry * entry = symbolsTable->getEntry(op);
    if (entry->token == "CTE"){/*es var aux, cte o matriz*/
        QString aux=constantes.value(QString::fromStdString(op));
        return aux;
    }

    if (entry->token == "CADENA")
        return cadenas.value(QString::fromStdString(op));

    if(entry-> token =="ID"){
        if(entry->matInstructions.size()>0){/*es matriz*/
            if(useDirReg){//necesita leer: elimino la ultima instruccion (MOV varAux, [ebx])y retorno la direccion
                code.append(entry->matInstructions);
                code.pop_back();
                code.pop_back();
                useDirReg=false;
                return "[ebx]";
            }
            else{
                code.append(entry->matInstructions);
                return QString::fromStdString(op);
            }
        }
    }


    /*entonces es una variable*/
    return QString::fromStdString(op);

}

QString CodeGenerator::convertOperand(QString op) {
    return this->convertOperand(op.toStdString());
}


/*Solo aquellos nodos que cumplan esta condicion seran procesados
 *para generar código.
 * Devuelve verdadero si sus hijos son hoja y si NO se trata de un
 * nodo de "@sentencia", ya que estos se deben IGNORAR
 * IMPORTANTE: los nodos relacionados con if y while se procesan en otro lado
 */
bool CodeGenerator::tieneHijosHoja(Node * node) {
    if ((node==NULL) || (node->dato == "@sentencia"))
        return false;

    //el nodo debe tener hijos al menos.
    if (node->hijoIzquierdo == NULL && node->hijoDerecho == NULL)
        return false;

    bool result = true;

    Node * izq = node->hijoIzquierdo;
    if (izq != NULL)
        if ((izq->hijoIzquierdo != NULL || izq->hijoDerecho != NULL))
            result = false;

    Node * der = node->hijoDerecho;
    if (der!= NULL)
        if (der->hijoIzquierdo != NULL || der->hijoDerecho != NULL)
            result = false;


    return result;

}

QString CodeGenerator::generateLabel(){
    labelsCounter++;
    QString label=QString::fromStdString("@label_"+to_string(labelsCounter));
    labels.push_back(label);
    return label;
}

QString CodeGenerator::getVarAux(string type){
    int numeroAuxiliar = this->variablesAuxiliares.size();
    QString varAux = "@aux_" + QString::number(numeroAuxiliar);
    variablesAuxiliares.push_back(varAux);
    Entry * entry = new Entry (varAux.toStdString(), "ID", ID);
    entry->type=type;
    symbolsTable->put(varAux.toStdString(), entry);
    symbolsTable->setUse(varAux.toStdString(),"variable");
    return varAux;
}

/*Asume que lo que recibe es un nodo con dos hijos hoja
 *Devuelve todas las instrucciones assembler asociadas a
 *dicha operacion
*/
void CodeGenerator::generateInstructions(Node * node) {
    QString instruccion;

    if (node->dato == "@print"){
        code.push_back(";INICIO PRINT");
        QString cadena=convertOperand(node->hijoIzquierdo->dato);
        instruccion = "invoke MessageBox, NULL, addr " + cadena + ", addr " + cadena + ", MB_OK";
        code.push_back(instruccion);
        code.push_back(";FINAL PRINT");
    }
    if (node->dato == "@conv"){
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            code.push_back(";INICIO CONV INTEGER A DOUBLE");
            instruccion = "FILD " + convertOperand(node->hijoIzquierdo->dato);
            code.push_back(instruccion);

            //se crea variable auxiliar para guardar el resultado
            QString varAux = getVarAux("DOUBLE");

            //guarda la variable
            instruccion = "FSTP "+ varAux;
            code.push_back(instruccion);
            code.push_back(";FINAL CONV INTEGER A DOUBLE");

        }else if(symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE"){
            code.push_back(";INICIO CONV DOUBLE A INTEGER");
            QString hijoIzq=convertOperand(node->hijoIzquierdo->dato);
            code.push_back(";INICIO CHEQUEO POR RANGO");
            instruccion = "FLD " + hijoIzq;
            code.push_back(instruccion);
            instruccion = "FABS";
            code.push_back(instruccion);
            instruccion = "FCOMP maxInt";
            code.push_back(instruccion);
            instruccion = "FSTSW ax";
            code.push_back(instruccion);
            instruccion = "SAHF";
            code.push_back(instruccion);
            instruccion = "JAE conversionFailed";
            code.push_back(instruccion);
            code.push_back(";FIN CHEQUEO POR RANGO");

            //se crea variable auxiliar para guardar el resultado
            QString varAux = getVarAux("INTEGER");

            //CONVIERTO
            instruccion = "FLD " + hijoIzq;
            code.push_back(instruccion);
            instruccion = "FIST " + varAux;
            code.push_back(instruccion);

            code.push_back(";INICIO CHEQUEO PARTE DECIMAL");
            instruccion = "FABS";
            code.push_back(instruccion);
            instruccion = "FICOMP " + varAux;
            code.push_back(instruccion);
            instruccion = "FSTSW ax";
            code.push_back(instruccion);
            instruccion = "SAHF";
            code.push_back(instruccion);
            instruccion = "JNE conversionFailed";
            code.push_back(instruccion);
            code.push_back(";FIN CHEQUEO PARTE DECIMAL");

            code.push_back(";FINAL CONV DOUBLE A INTEGER");

        }
    }
    if (node->dato == "!=") {
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            code.push_back(";INICIO COMP DISTINTO INTEGER");
            instruccion = "MOV ax, " + convertOperand(node->hijoIzquierdo->dato);
            code.push_back(instruccion);
            instruccion = "CMP ax, " + convertOperand(node->hijoDerecho->dato);
            code.push_back(instruccion);
            instruccion = "JE " + generateLabel();
            code.push_back(instruccion);
            code.push_back(";FINAL COMP DISTINTO INTEGER");

        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            code.push_back(";INICIO COMP DISTINTO DOUBLE");
            instruccion = "FLD " + convertOperand(node->hijoIzquierdo->dato);
            code.push_back(instruccion);
            instruccion = "FCOMP " + convertOperand(node->hijoDerecho->dato);
            code.push_back(instruccion);
            instruccion = "FSTSW ax";
            code.push_back(instruccion);
            instruccion = "SAHF";
            code.push_back(instruccion);
            instruccion = "JE " + generateLabel();
            code.push_back(instruccion);
            code.push_back(";FINAL COM DISTINTO DOUBLE");

        }
    }

    if(node->dato.contains("mat@")){
            /*chequeo de limites*/
            QList<QString> instructions;
            instructions.clear();
            instructions.push_back(";INICIO CHEQUEO LIMITES ARRAY");
            QString hijoIzq=convertOperand(node->hijoIzquierdo->dato);
            instruccion = "MOV ax, " + hijoIzq;
            instructions.push_back(instruccion);
            int limite = symbolsTable->getEntry(node->dato.toStdString())->limit1;
            instruccion = "CMP ax, " + QString::number(limite);
            instructions.push_back(instruccion);
            instruccion = "JGE matrixOutOfRange";
            instructions.push_back(instruccion);

            QString hijoDer=convertOperand(node->hijoDerecho->dato);
            instruccion = "MOV ax, " + hijoDer;
            instructions.push_back(instruccion);
            limite = symbolsTable->getEntry(node->dato.toStdString())->limit2;
            instruccion = "CMP ax, " + QString::number(limite);
            instructions.push_back(instruccion);
            instruccion = "JGE matrixOutOfRange";
            instructions.push_back(instruccion);
            instructions.push_back(";FIN CHEQUEO LIMITES ARRAY");

            /*calculo posicion*/
            instructions.push_back(";INICIO CALCULO POS ARRAY");
            if(symbolsTable->getEntry(node->dato.toStdString())->storage == "rows"){
                instructions.push_back(";FILAS!!!!!!!!!!!!!!!!");
                instruccion = "MOV ax, " + hijoIzq;
                instructions.push_back(instruccion);
                instruccion = "IMUL ax, " + QString::number(symbolsTable->getEntry(node->dato.toStdString())->limit2);
                instructions.push_back(instruccion);
                instruccion = "ADD ax, " + hijoDer;
                instructions.push_back(instruccion);
            }
            else if(symbolsTable->getEntry(node->dato.toStdString())->storage == "columns"){
                instructions.push_back(";COLUMNAS!!!!!!!!!!!!!!!!");
                instruccion = "MOV ax, " + hijoDer;
                instructions.push_back(instruccion);
                instruccion = "IMUL ax, " + QString::number(symbolsTable->getEntry(node->dato.toStdString())->limit1);
                instructions.push_back(instruccion);
                instruccion = "ADD ax, " + hijoIzq;
                instructions.push_back(instruccion);
            }

            /*multiplico por tamaño: 2 en int y 4 en double*/
            if(symbolsTable->getEntry(node->dato.toStdString())->type == "INTEGER"){
                instruccion = "IMUL ax, 2";
                instructions.push_back(instruccion);
            }
            else{
                instruccion = "IMUL ax, 4";
                instructions.push_back(instruccion);
            }
            instructions.push_back(";FIN CALCULO POS ARRAY");

            /*encuentro la direccion base de la mat*/
            instruccion = "MOV ebx, OFFSET " + node->dato;
            instructions.push_back(instruccion);

            /*paso ax a eax*/
            instruccion = "MOV ecx, 0";
            instructions.push_back(instruccion);
            instruccion = "MOV cx, ax";
            instructions.push_back(instruccion);
            instruccion = "MOV eax, ecx";
            instructions.push_back(instruccion);

            /*le agrego el desplazamiento recien calculado*/
            instruccion = "ADD ebx, eax";
            instructions.push_back(instruccion);

            /*genero variable auxiliar*/
            string type=symbolsTable->getEntry(node->dato.toStdString())->type;
            QString varAux = getVarAux(type);

            /*no se conoce el tamaño de [ebx], segun el tipo int o double aviso si es de 16 o 32 bits*/
            if(type == "INTEGER"){
                instruccion = "MOV ax, [ebx]";
                instructions.push_back(instruccion);
                instruccion = "MOV " + varAux + ", ax";
                instructions.push_back(instruccion);
            }
            else{
                instruccion = "MOV eax, [ebx]";
                instructions.push_back(instruccion);
                instruccion = "MOV " + varAux + ", eax";
                instructions.push_back(instruccion);
            }

            symbolsTable->getEntry(varAux.toStdString())->matInstructions=instructions;
    }

    if (node->dato == ">=") {
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            code.push_back(";INICIO COMP MAYOR IGUAL INTEGER");
            instruccion = "MOV ax, " + convertOperand(node->hijoIzquierdo->dato);
            code.push_back(instruccion);
            instruccion = "CMP ax, " + convertOperand(node->hijoDerecho->dato);
            code.push_back(instruccion);
            instruccion = "JL " + generateLabel();
            code.push_back(instruccion);
            code.push_back(";FINAL COMP MAYOR IGUAL INTEGER");

        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            code.push_back(";INICIO COMP MAYOR IGUAL DOUBLE");
            instruccion = "FLD " + convertOperand(node->hijoIzquierdo->dato);
            code.push_back(instruccion);
            instruccion = "FCOMP " + convertOperand(node->hijoDerecho->dato);
            code.push_back(instruccion);
            instruccion = "FSTSW ax";
            code.push_back(instruccion);
            instruccion = "SAHF";
            code.push_back(instruccion);
            instruccion = "JB " + generateLabel();
            code.push_back(instruccion);
            code.push_back(";FINAL COMP MAYOR IGUAL DOUBLE");

        }
    }

    if (node->dato == "<=") {
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            code.push_back(";INICIO COMP MENOR IGUAL INTEGER");
            instruccion = "MOV ax, " + convertOperand(node->hijoIzquierdo->dato);
            code.push_back(instruccion);
            instruccion = "CMP ax, " + convertOperand(node->hijoDerecho->dato);
            code.push_back(instruccion);
            instruccion = "JG " + generateLabel();
            code.push_back(instruccion);
            code.push_back(";FINAL COMP MENOR IGUAL INTEGER");

        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            code.push_back(";INICIO COMP MENOR IGUAL DOUBLE");
            instruccion = "FLD " + convertOperand(node->hijoIzquierdo->dato);
            code.push_back(instruccion);
            instruccion = "FCOMP " + convertOperand(node->hijoDerecho->dato);
            code.push_back(instruccion);
            instruccion = "FSTSW ax";
            code.push_back(instruccion);
            instruccion = "SAHF";
            code.push_back(instruccion);
            instruccion = "JA " +generateLabel();
            code.push_back(instruccion);
            code.push_back(";FINAL COMP MENOR IGUAL DOUBLE");

        }
    }

    if (node->dato == "=") {
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            code.push_back(";INICIO COMP IGUAL INTEGER");
            instruccion = "MOV ax, " + convertOperand(node->hijoIzquierdo->dato);
            code.push_back(instruccion);
            instruccion = "CMP ax, " + convertOperand(node->hijoDerecho->dato);
            code.push_back(instruccion);
            instruccion = "JNE "+ generateLabel();
            code.push_back(instruccion);
            code.push_back(";FIN COMP IGUAL INTEGER");

        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            code.push_back(";INICIO COMP IGUAL DOUBLE");
            instruccion = "FLD " + convertOperand(node->hijoIzquierdo->dato);
            code.push_back(instruccion);
            instruccion = "FCOMP " + convertOperand(node->hijoDerecho->dato);
            code.push_back(instruccion);
            instruccion = "FSTSW ax";
            code.push_back(instruccion);
            instruccion = "SAHF";
            code.push_back(instruccion);
            QString label=generateLabel();
            instruccion = "JB "+ label;
            code.push_back(instruccion);
            instruccion = "JA " + label;
            code.push_back(instruccion);
            code.push_back(";FINAL COMP IGUAL DOUBLE");

        }
    }

    if (node->dato == ">") {
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            code.push_back(";INICIO COMP MAYOR INTEGER");
            instruccion = "MOV ax, " + convertOperand(node->hijoIzquierdo->dato);
            code.push_back(instruccion);
            instruccion = "CMP ax, " + convertOperand(node->hijoDerecho->dato);
            code.push_back(instruccion);
            instruccion = "JLE " + generateLabel();
            code.push_back(instruccion);
            code.push_back(";FINAL COMP MAYOR INTEGER");

        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            code.push_back(";INICIO COMP MAYOR DOUBLE");
            instruccion = "FLD " + convertOperand(node->hijoIzquierdo->dato);
            code.push_back(instruccion);
            instruccion = "FCOMP " + convertOperand(node->hijoDerecho->dato);
            code.push_back(instruccion);
            instruccion = "FSTSW ax";
            code.push_back(instruccion);
            instruccion = "SAHF";
            code.push_back(instruccion);
            instruccion = "JBE " + generateLabel();
            code.push_back(instruccion);
            code.push_back(";FINAL COMP MAYOR DOUBLE");

        }
    }

    if (node->dato == "<") {
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            code.push_back(";INICIO COMP MENOR INTEGER");
            instruccion = "MOV ax, " + convertOperand(node->hijoIzquierdo->dato);
            code.push_back(instruccion);
            instruccion = "CMP ax, " + convertOperand(node->hijoDerecho->dato);
            code.push_back(instruccion);
            instruccion = "JGE " + generateLabel();
            code.push_back(instruccion);
            code.push_back(";FINAL COMP MENOR INTEGER");

        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            code.push_back(";INICIO COMP MENOR DOUBLE");
            instruccion = "FLD " + convertOperand(node->hijoIzquierdo->dato);
            code.push_back(instruccion);
            instruccion = "FCOMP " + convertOperand(node->hijoDerecho->dato);
            code.push_back(instruccion);
            instruccion = "FSTSW ax";
            code.push_back(instruccion);
            instruccion = "SAHF";
            code.push_back(instruccion);
            instruccion = "JAE " + generateLabel();
            code.push_back(instruccion);
            code.push_back(";FINAL COMP MENOR DOUBLE");

        }
    }

    if (node->dato == "+") {
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            code.push_back(";INICIO SUMA INTEGER");
            instruccion = "MOV ax, " + convertOperand(node->hijoIzquierdo->dato);
            code.push_back(instruccion);
            instruccion = "ADD ax, " + convertOperand(node->hijoDerecho->dato);
            code.push_back(instruccion);

            //se crea variable auxiliar para guardar el resultado
            QString varAux = getVarAux("INTEGER");

            //se copia el resultado en la nueva variable auxiliar
            instruccion = "MOV " + varAux + ", ax";
            code.push_back(instruccion);
            code.push_back(";FINAL SUMA INTEGER");

        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            code.push_back(";INICIO SUMA DOUBLE");
            instruccion = "FLD " + convertOperand(node->hijoIzquierdo->dato);
            code.push_back(instruccion);
            instruccion = "FADD " + convertOperand(node->hijoDerecho->dato);
            code.push_back(instruccion);

            //se crea variable auxiliar para guardar el resultado
            QString varAux = getVarAux("DOUBLE");

            //guarda la variable
            instruccion = "FSTP "+ varAux;
            code.push_back(instruccion);
            code.push_back(";FINAL SUMA DOUBLE");

        }
    }

    if (node->dato =="-"){
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            code.push_back(";INICIO RESTA INTEGER");
            instruccion = "MOV ax, " + convertOperand(node->hijoIzquierdo->dato);
            code.push_back(instruccion);
            instruccion = "SUB ax, " + convertOperand(node->hijoDerecho->dato);
            code.push_back(instruccion);

            //se crea variable auxiliar para guardar el resultado
            QString varAux = getVarAux("INTEGER");

            //se copia el resultado en la nueva variable auxiliar
            instruccion = "MOV " + varAux + ", ax";
            code.push_back(instruccion);
            code.push_back(";FINAL RESTA INTEGER");

        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            code.push_back(";INICIO RESTA DOUBLE");
            instruccion = "FLD " + convertOperand(node->hijoIzquierdo->dato);
            code.push_back(instruccion);
            instruccion = "FSUB " + convertOperand(node->hijoDerecho->dato);
            code.push_back(instruccion);

            //se crea variable auxiliar para guardar el resultado
            QString varAux = getVarAux("DOUBLE");

            //guarda la variable
            instruccion = "FSTP "+ varAux;
            code.push_back(instruccion);
            code.push_back(";FINAL RESTA DOUBLE");

        }
    }

    if (node->dato =="*"){
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            code.push_back(";INICIO MUL INTEGER");
            instruccion = "MOV ax, " + convertOperand(node->hijoIzquierdo->dato);
            code.push_back(instruccion);
            instruccion = "IMUL ax, " + convertOperand(node->hijoDerecho->dato);
            code.push_back(instruccion);

            //se crea variable auxiliar para guardar el resultado
            QString varAux = getVarAux("INTEGER");

            //se copia el resultado en la nueva variable auxiliar
            instruccion = "MOV " + varAux + ", ax";
            code.push_back(instruccion);
            code.push_back(";FINAL MUL INTEGER");

        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            code.push_back(";INICIO MUL DOUBLE");
            instruccion = "FLD " + convertOperand(node->hijoIzquierdo->dato);
            code.push_back(instruccion);
            instruccion = "FMUL " + convertOperand(node->hijoDerecho->dato);
            code.push_back(instruccion);

            //se crea variable auxiliar para guardar el resultado
            QString varAux = getVarAux("DOUBLE");

            //se copia el resultado en la nueva variable auxiliar
            instruccion = "FSTP " + varAux;
            code.push_back(instruccion);
            code.push_back(";FINAL MUL DOUBLE");

        }
    }

    if (node->dato =="/"){
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            code.push_back(";INICIO DIV INTEGER");
            code.push_back(";INICIO CHEQUEO CERO INTEGER");
            //chequeo de division por cero
            QString hijoDer=convertOperand(node->hijoDerecho->dato);
            instruccion = "CMP "+ hijoDer+ ", 0";
            code.push_back(instruccion);
            instruccion = "JE divZero";
            code.push_back(instruccion);
            code.push_back(";FINAL CHEQUEO CERO INTEGER");

            instruccion = "MOV dx, 0";
            code.push_back(instruccion);
            QString hijoIzq=convertOperand(node->hijoIzquierdo->dato);
            instruccion = "MOV ax, " + hijoIzq;
            code.push_back(instruccion);
            instruccion = "IDIV " + hijoDer;
            code.push_back(instruccion);

            //se crea variable auxiliar para guardar el resultado
            QString varAux = getVarAux("INTEGER");

            //se copia el resultado en la nueva variable auxiliar
            instruccion = "MOV " + varAux + ", ax";
            code.push_back(instruccion);
            code.push_back(";FINAL DIV INTEGER");

        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            code.push_back(";INICIO DIV DOUBLE");
            code.push_back(";INICIO CHQUEO CERO DOUBLE");
            //chequea division por cero
            instruccion = "FLD " + convertOperand(node->hijoDerecho->dato);
            code.push_back(instruccion);
            instruccion = "FTST";
            code.push_back(instruccion);
            instruccion = "FSTSW ax";
            code.push_back(instruccion);
            instruccion = "SAHF";
            code.push_back(instruccion);
            instruccion = "JE divZero";
            code.push_back(instruccion);
            code.push_back(";FINAL CHEQUEO CERO DOUBLE");

            instruccion = "FLD " + convertOperand(node->hijoIzquierdo->dato);
            code.push_back(instruccion);
            instruccion = "FDIV ST, ST(1)";
            code.push_back(instruccion);

            //se crea variable auxiliar para guardar el resultado
            QString varAux = getVarAux("DOUBLE");

            //se copia el resultado en la nueva variable auxiliar
            instruccion = "FSTP " + varAux;
            code.push_back(instruccion);
            code.push_back(";FINAL DIV DOUBLE");

        }
    }

    if (node->dato ==":="){
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            code.push_back(";INICIO ASIGNACION INTEGER");
            instruccion = "MOV dx, " + convertOperand(node->hijoDerecho->dato);
            code.push_back(instruccion);

            useDirReg=true;
            instruccion = "MOV " + convertOperand(node->hijoIzquierdo->dato) + ", dx";
            code.push_back(instruccion);
            code.push_back(";FINAL ASIGNACION INTEGER");

        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            code.push_back(";INICIO ASIGNACION DOUBLE");
            instruccion = "FLD " + convertOperand(node->hijoDerecho->dato);
            code.push_back(instruccion);

            useDirReg=true;
            instruccion = "FSTP DWORD PTR " + convertOperand(node->hijoIzquierdo->dato);
            code.push_back(instruccion);
            code.push_back(";FINAL ASIGNACION DOUBLE");

        }
    }
    if (node->dato =="-=") {
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            code.push_back(";INICIO ASIGNACION RESTA INTEGER");
            //ESTA ES LA RESTA
            QString hijoIzq=convertOperand(node->hijoIzquierdo->dato);
            instruccion = "MOV dx, " + hijoIzq;
            code.push_back(instruccion);
            QString hijoDer=convertOperand(node->hijoDerecho->dato);
            instruccion = "SUB dx, " + hijoDer;
            code.push_back(instruccion);

            //ESTA SERIA LA ASIGNACION
            useDirReg=true;
            instruccion = "MOV " + hijoIzq + ", dx";
            code.push_back(instruccion);
            code.push_back(";FINAL ASIGNACION RESTA INTEGER");

        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            code.push_back(";INICIO ASIGNACION RESTA DOUBLE");
            QString hijoIzq=convertOperand(node->hijoIzquierdo->dato);
            instruccion = "FLD " + hijoIzq;
            code.push_back(instruccion);
            QString hijoDer=convertOperand(node->hijoDerecho->dato);
            instruccion = "FSUB " + hijoDer;
            code.push_back(instruccion);

            useDirReg=true;
            instruccion = "FSTP DWORD PTR " + hijoIzq;
            code.push_back(instruccion);
            code.push_back(";FINAL ASIGNACION RESTA DOUBLE");

        }
    }
}

/*genera el conjunto de instrucciones contenidas por el if:condicion, bloque if y else si existe*/
void CodeGenerator::generateIfInstructions(Node *node){
    code.push_back(";INICIO DE IF");

    /*instructions vuelve con las instrucciones de condicion, mas el salto*/
    code.push_back(";INICIO DE COND IF");
    recorrerArbol(node->hijoIzquierdo->hijoIzquierdo);
    code.push_back(";FIN DE COND IF");

    /*ahora vuelve con las instrucciones del bloque then, sin el salto*/
    code.push_back(";INICIO BLOQUE THEN");
    recorrerArbol(node->hijoDerecho->hijoIzquierdo->hijoIzquierdo);
    code.push_back(";FIN BLOQUE THEN");

    /*ahora se generan las instrucciones del bloque else si existe*/
    QString falseConditionLabel = labels.at(labels.size()-1) + ":";
    labels.pop_back();
    if(node->hijoDerecho->hijoDerecho!=NULL){
        /*existe el else*/
        QString endIfLabel = "JMP " + generateLabel();
        code.push_back(endIfLabel);
        code.push_back(falseConditionLabel);
        code.push_back(";INICIO BLOQUE ELSE");
        recorrerArbol(node->hijoDerecho->hijoDerecho->hijoIzquierdo);
        code.push_back(";FIN BLOQUE ELSE");
        code.push_back(labels.at(labels.size()-1) + ":");
        labels.pop_back();
    }
    else
        /*no existe*/
        code.push_back(falseConditionLabel);
    code.push_back(";FIN IF");
}

/*genera el conjunto de instrucciones contenidas por el while:condicion y bloque*/
void CodeGenerator::generateWhileInstructions(Node *node){
    code.push_back(";INICIO DE WHILE");

    /*inicio de while: genera y apila la etiqueta de comienzo de while*/
    code.push_back(generateLabel()+":");

    /*instructions vuelve con las instrucciones de la condicion mas el salto*/
    code.push_back(";INICIO DE SENTENCIAS CONDICION WHILE");
    recorrerArbol(node->hijoIzquierdo->hijoIzquierdo);
    code.push_back(";FIN DE SENTENCIAS CONDICION WHILE");

    /*instructions vuelve con las instrucciones del cuerpo sin el salto hacia el comienzo*/
    code.push_back(";INICIO DE SENTENCIAS CUERPO WHILE");
    recorrerArbol(node->hijoDerecho->hijoIzquierdo);
    code.push_back(";FIN DE SENTENCIAS CUERPO WHILE");
    QString endWhileLabel = labels.at(labels.size()-1)+":";
    labels.pop_back();
    QString startWhileLabel = "JMP " + labels.at(labels.size()-1);
    labels.pop_back();
    code.push_back(startWhileLabel);
    code.push_back(endWhileLabel);
    code.push_back(";FIN DE WHILE");
}

/*Reemplaza el sub-arbol por otro con la ultima variable auxiliar creada
 *o lo cambia por NULL si la operacion no devolvia resultado
 */
void CodeGenerator::processNode(Node * &node) {
    Node * aBorrar = node;
    node = NULL;

    //Ya se descolgo. Ahora se reemplaza node con el subarbol o NULL
    string op = aBorrar->dato.toStdString();
    if (op == "+" || op =="-" || op == "*" || op == "/" || op == "@conv" || aBorrar->dato.startsWith("mat@")) {
        node = new Node;
        //le pone la referencia a la ultima var aux usada
        node->dato = variablesAuxiliares.at(variablesAuxiliares.size()-1);
        node->hijoIzquierdo=NULL;
        node->hijoDerecho=NULL;
    }
    //si no se cumple, node ya vuelve NULL.

    //Ahora se borra
    if (aBorrar->hijoIzquierdo!=NULL) {
        delete aBorrar->hijoIzquierdo;
        aBorrar->hijoIzquierdo = NULL;
    }

    if (aBorrar->hijoDerecho!=NULL) {
        delete aBorrar->hijoDerecho;
        aBorrar->hijoDerecho = NULL;
    }

    delete aBorrar;
    aBorrar = NULL;
 }

/* Recorre en pre-orden buscando el sub-arbol mas a la izquierda
 * con nodos hoja. Genera codigo con ellos e inserta instrucciones a la lista.
 * A la vuelta de la recursion vuelve a chequear si el nodo está listo para generar código
 */
void  CodeGenerator::recorrerArbol (Node * &root) {
    if (root!=NULL) {
        if (root->dato.toStdString() == "@if"){
            generateIfInstructions(root);
            processNode(root);
        }
        else
            if (root->dato.toStdString() == "@while"){
                generateWhileInstructions(root);
                processNode(root);
            }
            else
                if (tieneHijosHoja(root)) {
                    generateInstructions(root); //se genera codigo y se agrega
                    processNode(root); //se cambia el sub-arbol
                } else {
                    recorrerArbol(root->hijoIzquierdo);
                    recorrerArbol(root->hijoDerecho);
                    //vuelta de la recursion
                    if (tieneHijosHoja(root)) {
                        generateInstructions(root); //se genera codigo y se agrega
                        processNode(root); //se cambia el sub-arbol
                    }
                }
    }
}

/* Genera el codigo de a partir del arbol y devuelve
 * la lista de instrucciones assembler (parte ejecutable)
 */
void CodeGenerator::generateCode() {
    labels.clear();
    labelsCounter=0;
    code.clear();
    recorrerArbol(root);
}

/* Devuelve el codigo assembler en el archivo */

void CodeGenerator::generateAssembler(const char * ruta) {
    //Se mapean las constantes y cadena a nuevo nombres de assembler
    mapearConstantesYCadenas();
    //Se recorre el arbol y se genera codigo Assembler, dando lugar tambien a nuevas
    //variables auxiliares en la TS
    generateCode();

    //Ya se tiene la TS completa y no habrá mas cambios. Se obtienen todas las
    //declaraciones de dichas variables en Assembler
    QList<QString> variables = getAssemblerVariables();

    ofstream out;
    out.open (ruta);

    /** ENCABEZADO **/
    out << ".386";
    out << "\n";
    out << ".model flat, stdcall";
    out << "\n";
    out << "option casemap :none";
    out << "\n";
    out << "include \\masm32\\include\\windows.inc";
    out << "\n";
    out << "include \\masm32\\include\\kernel32.inc";
    out << "\n";
    out << "include \\masm32\\include\\user32.inc";
    out << "\n";
    out << "includelib \\masm32\\lib\\kernel32.lib";
    out << "\n";
    out << "includelib \\masm32\\lib\\user32.lib";
    out << "\n";
    out << "\n";

    /** DECLARACION DE VARIABLES **/

    out << ".data";
    out << "\n";
    for (int i=0; i<variables.size(); i++) {
        out << variables.at(i).toStdString();
        out << "\n";
    }

    out << "maxInt dd 32768.0";
    out << "\n";
    out << "minInt dd -32768.0";
    out << "\n";
    out << "DivZero db \"error de ejecucion: no se puede dividir por cero\", 0";
    out << "\n";
    out << "ConversionFailed db \"error de ejecucion: no se puede realizar la conversion\", 0";
    out << "\n";
    out << "MatOutOfRange db \"error de ejecucion: matriz fuera de rango\", 0";
    out << "\n";
    out << "\n";


    /** CODIGO **/

    out << ".code";
    out << "\n";

    out << "divZero:";
    out << "\n";
    out << "invoke MessageBox, NULL, addr DivZero, addr DivZero, MB_OK";
    out << "\n";
    out << "invoke ExitProcess, 0";
    out << "\n";

    out << "\n";
    out << "conversionFailed:";
    out << "\n";
    out << "invoke MessageBox, NULL, addr ConversionFailed, addr ConversionFailed, MB_OK";
    out << "\n";
    out << "invoke ExitProcess, 0";
    out << "\n";

    out << "\n";
    out << "matrixOutOfRange:";
    out << "\n";
    out << "invoke MessageBox, NULL, addr MatOutOfRange, addr MatOutOfRange, MB_OK";
    out << "\n";
    out << "invoke ExitProcess, 0";
    out << "\n";

    out << "\n";

    out << "start:";
    out << "\n";

    for (int i=0; i<code.size(); i++) {
        out << code.at(i).toStdString();
        out << "\n";
    }

    out << "invoke ExitProcess, 0";
    out << "\n";
    out << "end start";

    out.close();
}

void CodeGenerator::setAsRootNode(string keyNode){
    root=pointersTable.getNode(keyNode);

}

void CodeGenerator::setAsBlockSentenceNode(string keyNode){
    pointersTable.registerBlock(keyNode);
}

string CodeGenerator::getLastBlock(){
    return pointersTable.getLastBlock();
}

bool CodeGenerator::rootIsNull(){
    return root==NULL;
}

void CodeGenerator::printSintacticTree(){
    cout << "Codigo intermedio: Arbol Sintactico" << endl << endl << root->preOrderPrint("");
}
