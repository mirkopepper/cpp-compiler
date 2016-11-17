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
    cout << endl << "NUEVOS VALORES EN CADENAS, CONTANTES Y LOS IDS:" << endl;
    for (int i=0; i<entries.size(); i++){
        Entry * entry = symbolsTable->getEntry(entries.at(i));
        if (entry->token == "CTE") {
            QString nombreCte = "@cte" + QString::number(constantes.size());
            cout << "constantes " << i << " " << entry->lexeme << ", " << nombreCte.toStdString() << endl;
            constantes.insert(QString::fromStdString(entry->lexeme), nombreCte);
        } else if (entry->token == "CADENA") {
            QString nombreCad = "@cadena" + QString::number(cadenas.size());
            cout << "cadenas " << i << " " << entry->lexeme << ", " << nombreCad.toStdString() << endl;
            cadenas.insert(QString::fromStdString(entry->lexeme),nombreCad);
        }
        else
            cout << "id " << i << " " << entry->lexeme << endl;
    }
    /*Verificar que los nombres @cte y @cadena sean validos. Osea que no choquen
    con otra cosa y eso */
}

/*Devuelve la declaración de variable en assembler
 *de la variable dada
 */
QString CodeGenerator::declareAssemblerVariable(string lexeme) {
    //ver GeneradorDeCodigo::declaracionVariable de alfonso para saber bien QUE devuelve
    /*
    */
    Entry * e=symbolsTable->getEntry(lexeme);
    if(e->token=="ID"){
        if(e->type=="INTEGER")
            return QString::fromStdString(e->lexeme + " dw " + e->getValue());
        else
            return QString::fromStdString(e->lexeme + " dd " + e->getValue());
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

    cout << "valor op: "<< op << endl;
    Entry * entry = symbolsTable->getEntry("_i0");
    cout << "entry lexema" << entry->lexeme << endl;

    if (entry->token == "CTE"){
        return constantes.value(QString::fromStdString("_i0"));
    }

    if (entry->token == "CADENA")
        return cadenas.value(QString::fromStdString(op));

    /*entonces es un id*/
    /*---MIRAR PARA EL CASO MATRICES*/
    return QString::fromStdString(op);

    //ver convertirOperando de alfonso
}

QString CodeGenerator::convertOperand(QString op) {
    this->convertOperand(op.toStdString());
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
    QString label="@label_"+labelsCounter;
    labels.push_back(label);
    return label;
}

/*Asume que lo que recibe es un nodo con dos hijos hoja
 *Devuelve todas las instrucciones assembler asociadas a
 *dicha operacion
*/
QList<QString> CodeGenerator::getInstructions(Node * node) {
    QString instruccion;
    QList<QString> instrucciones;
    instrucciones.clear();
    //VALORES DE NODE->DATO QUE FALTAN:,mat@id

    if (node->dato == "@print"){
        QString cadena=convertOperand(node->hijoIzquierdo->dato);
        instruccion = "invoke MessageBox, NULL, addr " + cadena + ", addr " + cadena + ", MB_OK";
        instrucciones.push_back(instruccion);
        return instrucciones;
    }
    if (node->dato == "@conv"){
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            instruccion = "FILD " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);

            //se crea variable auxiliar para guardar el resultado
            int numeroAuxiliar = this->variablesAuxiliares.size();
            QString varAux = "@aux_" + QString::number(numeroAuxiliar);
            variablesAuxiliares.push_back(varAux);
            Entry * entry = new Entry (varAux.toStdString(), "ID", ID);
            entry->type="DOUBLE";
            symbolsTable->put(varAux.toStdString(), entry);

            //guarda la variable
            instruccion = "FST "+ varAux;
            instrucciones.push_back(instruccion);
            return instrucciones;
        }else if(symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE"){
            instruccion = "FLD " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            //ACA TENGO QUE CHEQUEAR QUE EL DOUBLE ESTE ENTRE -2^15 y +2^15
            instruccion = "FCOM 32768";
            instrucciones.push_back(instruccion);
            instruccion = "FSTSW ax";
            instrucciones.push_back(instruccion);
            instruccion = "SAHF";
            instrucciones.push_back(instruccion);
            instruccion = "JGE conversionFailed";
            instrucciones.push_back(instruccion);

            instruccion = "FCOM -32768";
            instrucciones.push_back(instruccion);
            instruccion = "FSTSW ax";
            instrucciones.push_back(instruccion);
            instruccion = "SAHF";
            instrucciones.push_back(instruccion);
            instruccion = "JLE conversionFailed";
            instrucciones.push_back(instruccion);

            //se crea variable auxiliar para guardar el resultado
            int numeroAuxiliar = this->variablesAuxiliares.size();
            QString varAux = "@aux_" + QString::number(numeroAuxiliar);
            variablesAuxiliares.push_back(varAux);
            Entry * entry = new Entry (varAux.toStdString(), "ID", ID);
            entry->type="INTEGER";
            symbolsTable->put(varAux.toStdString(), entry);

            //CONVIERTO
            instruccion = "FIST " + varAux;
            instrucciones.push_back(instruccion);
            return instrucciones;
        }

    }
    if (node->dato == "!=") {
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            instruccion = "MOV ax, " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            instruccion = "CMP ax, " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);
            instruccion = "JE " + generateLabel();
            instrucciones.push_back(instruccion);
            return instrucciones;
        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            instruccion = "FLD " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            instruccion = "FCOM " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);
            instruccion = "FSTSW ax";
            instrucciones.push_back(instruccion);
            instruccion = "SAHF";
            instrucciones.push_back(instruccion);
            instruccion = "JE " + generateLabel();
            instrucciones.push_back(instruccion);
            return instrucciones;

        }
    }

    if (node->dato == ">=") {
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            instruccion = "MOV ax, " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            instruccion = "CMP ax, " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);
            instruccion = "JL " + generateLabel();
            instrucciones.push_back(instruccion);
            return instrucciones;
        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            instruccion = "FLD " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            instruccion = "FCOM " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);
            instruccion = "FSTSW ax";
            instrucciones.push_back(instruccion);
            instruccion = "SAHF";
            instrucciones.push_back(instruccion);
            instruccion = "JB " + generateLabel();
            instrucciones.push_back(instruccion);
            return instrucciones;

        }
    }

    if (node->dato == "<=") {
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            instruccion = "MOV ax, " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            instruccion = "CMP ax, " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);
            instruccion = "JG " + generateLabel();
            instrucciones.push_back(instruccion);
            return instrucciones;
        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            instruccion = "FLD " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            instruccion = "FCOM " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);
            instruccion = "FSTSW ax";
            instrucciones.push_back(instruccion);
            instruccion = "SAHF";
            instrucciones.push_back(instruccion);
            instruccion = "JA " +generateLabel();
            instrucciones.push_back(instruccion);
            return instrucciones;

        }
    }

    if (node->dato == "=") {
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            instruccion = "MOV ax, " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            instruccion = "CMP ax, " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);
            instruccion = "JNE "+ generateLabel();
            instrucciones.push_back(instruccion);
            return instrucciones;
        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            instruccion = "FLD " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            instruccion = "FCOM " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);
            instruccion = "FSTSW ax";
            instrucciones.push_back(instruccion);
            instruccion = "SAHF";
            instrucciones.push_back(instruccion);
            instruccion = "JB "+ generateLabel();
            instrucciones.push_back(instruccion);
            instruccion = "JA " + generateLabel();
            instrucciones.push_back(instruccion);
            return instrucciones;
        }
    }

    if (node->dato == ">") {
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            instruccion = "MOV ax, " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            instruccion = "CMP ax, " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);
            instruccion = "JLE " + generateLabel();
            instrucciones.push_back(instruccion);
            return instrucciones;
        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            instruccion = "FLD " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            instruccion = "FCOM " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);
            instruccion = "FSTSW ax";
            instrucciones.push_back(instruccion);
            instruccion = "SAHF";
            instrucciones.push_back(instruccion);
            instruccion = "JBE " + generateLabel();
            instrucciones.push_back(instruccion);
            return instrucciones;
        }
    }

    if (node->dato == "<") {
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            instruccion = "MOV ax, " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            instruccion = "CMP ax, " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);
            instruccion = "JGE " + generateLabel();
            instrucciones.push_back(instruccion);
            return instrucciones;
        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            instruccion = "FLD " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            instruccion = "FCOM " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);
            instruccion = "FSTSW ax";
            instrucciones.push_back(instruccion);
            instruccion = "SAHF";
            instrucciones.push_back(instruccion);
            instruccion = "JAE " + generateLabel();
            instrucciones.push_back(instruccion);
            return instrucciones;
        }
    }

    if (node->dato == "+") {
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            instruccion = "MOV ax, " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            instruccion = "ADD ax, " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);

            //se crea variable auxiliar para guardar el resultado
            int numeroAuxiliar = this->variablesAuxiliares.size();
            QString varAux = "@aux_" + QString::number(numeroAuxiliar);
            variablesAuxiliares.push_back(varAux);
            Entry * entry = new Entry (varAux.toStdString(), "ID", ID);
            entry->type="INTEGER";
            symbolsTable->put(varAux.toStdString(), entry);

            //se copia el resultado en la nueva variable auxiliar
            instruccion = "MOV " + varAux + ", ax";
            instrucciones.push_back(instruccion);
            return instrucciones;
        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            instruccion = "FLD " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            instruccion = "FADD " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);

            //se crea variable auxiliar para guardar el resultado
            int numeroAuxiliar = this->variablesAuxiliares.size();
            QString varAux = "@aux_" + QString::number(numeroAuxiliar);
            variablesAuxiliares.push_back(varAux);
            Entry * entry = new Entry (varAux.toStdString(), "ID", ID);
            entry->type="DOUBLE";
            symbolsTable->put(varAux.toStdString(), entry);

            //guarda la variable
            instruccion = "FST "+ varAux;
            instrucciones.push_back(instruccion);
            return instrucciones;
        }
    }

    if (node->dato =="-"){
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            instruccion = "MOV ax, " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            instruccion = "SUB ax, " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);

            //se crea variable auxiliar para guardar el resultado
            int numeroAuxiliar = this->variablesAuxiliares.size();
            QString varAux = "@aux_" + QString::number(numeroAuxiliar);
            variablesAuxiliares.push_back(varAux);
            Entry * entry = new Entry (varAux.toStdString(), "ID", ID);
            entry->type="INTEGER";
            symbolsTable->put(varAux.toStdString(), entry);

            //se copia el resultado en la nueva variable auxiliar
            instruccion = "MOV " + varAux + ", ax";
            instrucciones.push_back(instruccion);
            return instrucciones;
        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            instruccion = "FLD " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            instruccion = "FSUB " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);

            //se crea variable auxiliar para guardar el resultado
            int numeroAuxiliar = this->variablesAuxiliares.size();
            QString varAux = "@aux_" + QString::number(numeroAuxiliar);
            variablesAuxiliares.push_back(varAux);
            Entry * entry = new Entry (varAux.toStdString(), "ID", ID);
            entry->type="DOUBLE";
            symbolsTable->put(varAux.toStdString(), entry);

            //guarda la variable
            instruccion = "FST "+ varAux;
            instrucciones.push_back(instruccion);
            return instrucciones;
        }
    }

    if (node->dato =="*"){
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            instruccion = "MOV ax, " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            instruccion = "IMUL ax, " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);

            //se crea variable auxiliar para guardar el resultado
            int numeroAuxiliar = this->variablesAuxiliares.size();
            QString varAux = "@aux_" + QString::number(numeroAuxiliar);
            variablesAuxiliares.push_back(varAux);
            Entry * entry = new Entry (varAux.toStdString(), "ID", ID);
            entry->type="INTEGER";
            symbolsTable->put(varAux.toStdString(), entry);

            //se copia el resultado en la nueva variable auxiliar
            instruccion = "MOV " + varAux + ", ax";
            instrucciones.push_back(instruccion);
            return instrucciones;
        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            instruccion = "FLD " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            instruccion = "FMUL " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);

            //se crea variable auxiliar para guardar el resultado
            int numeroAuxiliar = this->variablesAuxiliares.size();
            QString varAux = "@aux_" + QString::number(numeroAuxiliar);
            variablesAuxiliares.push_back(varAux);
            Entry * entry = new Entry (varAux.toStdString(), "ID", ID);
            entry->type="DOUBLE";
            symbolsTable->put(varAux.toStdString(), entry);

            //se copia el resultado en la nueva variable auxiliar
            instruccion = "FST " + varAux;
            instrucciones.push_back(instruccion);
            return instrucciones;
        }
    }

    if (node->dato =="/"){
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            //chequeo de division por cero
            instruccion = "CMP "+ convertOperand(node->hijoDerecho->dato)+ ", 0";
            instrucciones.push_back(instruccion);
            instruccion = "JE divZero";
            instrucciones.push_back(instruccion);

            instruccion = "MOV dx, 0";
            instrucciones.push_back(instruccion);
            instruccion = "MOV ax, " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            instruccion = "IDIV " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);

            //se crea variable auxiliar para guardar el resultado
            int numeroAuxiliar = this->variablesAuxiliares.size();
            QString varAux = "@aux_" + QString::number(numeroAuxiliar);
            variablesAuxiliares.push_back(varAux);
            Entry * entry = new Entry (varAux.toStdString(), "ID", ID);
            entry->type="INTEGER";
            symbolsTable->put(varAux.toStdString(), entry);

            //se copia el resultado en la nueva variable auxiliar
            instruccion = "MOV " + varAux + ", ax";
            instrucciones.push_back(instruccion);
            return instrucciones;
        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            //chequea division por cero
            instruccion = "FLDZ ";
            instrucciones.push_back(instruccion);
            instruccion = "FLD " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);
            instruccion = "FCOM";
            instrucciones.push_back(instruccion);
            instruccion = "FSTSW ax";
            instrucciones.push_back(instruccion);
            instruccion = "SAHF";
            instrucciones.push_back(instruccion);
            instruccion = "JE divZero";
            instrucciones.push_back(instruccion);

            instruccion = "FLD " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            instruccion = "FDIV ST, ST(1)";
            instrucciones.push_back(instruccion);

            //se crea variable auxiliar para guardar el resultado
            int numeroAuxiliar = this->variablesAuxiliares.size();
            QString varAux = "@aux_" + QString::number(numeroAuxiliar);
            variablesAuxiliares.push_back(varAux);
            Entry * entry = new Entry (varAux.toStdString(), "ID", ID);
            entry->type="DOUBLE";
            symbolsTable->put(varAux.toStdString(), entry);

            //se copia el resultado en la nueva variable auxiliar
            instruccion = "FST " + varAux;
            instrucciones.push_back(instruccion);
            return instrucciones;
        }
    }

    if (node->dato ==":="){
        cout << "entro en :=" << endl;
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            cout << "es integer!!" << node->hijoDerecho->dato.toStdString() << endl;
            instruccion = "MOV ax, " + convertOperand(node->hijoDerecho->dato);
            cout << "ENTRO1" << endl;
            instrucciones.push_back(instruccion);
            instruccion = "MOV " + node->hijoIzquierdo->dato + ", ax";
            cout << "ENTRO2" << endl;
            instrucciones.push_back(instruccion);
            return instrucciones;

        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            instruccion = "FLD " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);
            instruccion = "FSTP " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            return instrucciones;
        }
    }
    if (node->dato =="-=") {
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            //ESTA ES LA RESTA
            instruccion = "MOV ax, " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            instruccion = "SUB ax, " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);
            //ESTA SERIA LA ASIGNACION
            instruccion = "MOV " + node->hijoIzquierdo->dato + ", ax";
            instrucciones.push_back(instruccion);
            return instrucciones;

        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            instruccion = "FLD " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);
            instruccion = "FSUB " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);
            instruccion = "FSTP " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            return instrucciones;
        }
    }
}

/*genera el conjunto de instrucciones contenidas por el if:condicion, bloque if y else si existe*/
QList<QString> CodeGenerator::getIfInstructions(Node *node){
    QList<QString> * instructions;
    instructions->clear();

    /*instructions vuelve con las instrucciones de condicion, mas el salto*/
    recorrerArbol(node->hijoIzquierdo->hijoIzquierdo,instructions);

    /*ahora vuelve con las instrucciones del bloque then, sin el salto*/
    recorrerArbol(node->hijoDerecho->hijoIzquierdo->hijoIzquierdo,instructions);

    /*ahora se generan las instrucciones del bloque else si existe*/
    QString falseConditionLabel = labels.at(labels.size()-1) + ":";
    labels.pop_back();
    if(node->hijoDerecho->hijoDerecho!=NULL){
        /*existe el else*/
        QString endIfLabel = "JMP " + generateLabel();
        instructions->push_back(falseConditionLabel);
        recorrerArbol(node->hijoDerecho->hijoDerecho->hijoIzquierdo,instructions);
        instructions->push_back(endIfLabel);
    }
    else
        /*no existe*/
        instructions->push_back(falseConditionLabel);
    return *instructions;
}

/*genera el conjunto de instrucciones contenidas por el while:condicion y bloque*/
QList<QString> CodeGenerator::getWhileInstructions(Node *node){
    QList<QString> * instructions;
    instructions->clear();

    /*inicio de while: genera y apila la etiqueta de comienzo de while*/
    instructions->push_back(generateLabel()+":");

    /*instructions vuelve con las instrucciones de la condicion mas el salto*/
    recorrerArbol(node->hijoIzquierdo->hijoIzquierdo,instructions);

    /*instructions vuelve con las instrucciones del cuerpo sin el salto hacia el comienzo*/
    recorrerArbol(node->hijoDerecho->hijoIzquierdo,instructions);
    QString endWhileLabel = labels.at(labels.size()-1)+":";
    labels.pop_back();
    QString startWhileLabel = "JMP " + labels.at(labels.size()-1);
    labels.pop_back();
    instructions->push_back(startWhileLabel);
    instructions->push_back(endWhileLabel);
    return *instructions;

}

/*Reemplaza el sub-arbol por otro con la ultima variable auxiliar creada
 *o lo cambia por NULL si la operacion no devolvia resultado
 */
void CodeGenerator::processNode(Node * &node) {
    Node * aBorrar = node;
    node = NULL;

    //Ya se descolgo. Ahora se reemplaza node con el subarbol o NULL
    string op = aBorrar->dato.toStdString();
    if (op == "+" || op =="-" || op == "*" || op == "/" || op == "@conv") {
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
void  CodeGenerator::recorrerArbol (Node * &root, QList<QString> * instructions) {
    if (root!=NULL) {
        cout << "valor raiz: " << root->dato.toStdString() << endl;
        if (root->dato == "@if"){
            instructions->append(getIfInstructions(root));
            processNode(root);
        }
        else
            if (root->dato == "@while"){
                instructions->append(getWhileInstructions(root));
                processNode(root);
            }
            else
                if (tieneHijosHoja(root)) {
                    cout << "tiene hijos hoja!" << endl;
                    instructions->append(getInstructions(root)); //se genera codigo y se agrega
                    cout << "instrucciones conseguidas!" << endl;
                    processNode(root); //se cambia el sub-arbol
                    cout << "nodo procesado!" << endl;
                } else {
                    cout << " no tiene hijos hoja!" << endl;
                    recorrerArbol(root->hijoIzquierdo, instructions);
                    recorrerArbol(root->hijoDerecho, instructions);
                    //vuelta de la recursion
                    if (tieneHijosHoja(root)) {
                        instructions->append(getInstructions(root)); //se genera codigo y se agrega
                        processNode(root); //se cambia el sub-arbol
                     }
                }
    }
}

/* Genera el codigo de a partir del arbol y devuelve
 * la lista de instrucciones assembler (parte ejecutable)
 */
QList<QString> CodeGenerator::generateCode() {
    labels.clear();
    QList<QString> instructions;
    instructions.clear();
    cout << "antes de recorrer arbol" << endl;
    recorrerArbol(root, &instructions);
    cout << "despues de recorrer arbol" << endl;
    return instructions;
}

/* Devuelve el codigo assembler en el archivo */

void CodeGenerator::generateAssembler(const char * ruta) {
    //Se mapean las constantes y cadena a nuevo nombres de assembler
    mapearConstantesYCadenas();

    //Se recorre el arbol y se genera codigo Assembler, dando lugar tambien a nuevas
    //variables auxiliares en la TS
    QList<QString> code = generateCode();
/*
    //Ya se tiene la TS completa y no habrá mas cambios. Se obtienen todas las
    //declaraciones de dichas variables en Assembler
    QList<QString> variables = getAssemblerVariables();


    ofstream out;
    out.open (ruta);

    /** ENCABEZADO **/
/*    out << ".386";
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

    /** DECLARACION DE VARIABLES **/
/*
    out << ".data";
    out << "\n";
    for (int i=0; i<variables.size(); i++) {
        out << variables.at(i).toStdString();
        out << "\n";
    }

    out << "divZero db \"error de ejecucion: no se puede dividir por cero\", 0";
    out << "\n";
    out << "conversionFailed db \"error de ejecucion: no se puede realizar la conversion\", 0";
    out << "\n";


    /** CODIGO **/
/*
    out << ".code";
    out << "\n";

    out << "divZero:";
    out << "\n";
    out << "invoke MessageBox, NULL, addr divZero, addr divZero, MB_OK";
    out << "\n";
    out << "invoke ExitProcess, 0";
    out << "\n";

    out << "conversionFailed:";
    out << "\n";
    out << "invoke MessageBox, NULL, addr conversionFailed, addr conversionFailed, MB_OK";
    out << "\n";
    out << "invoke ExitProcess, 0";
    out << "\n";

    out << "start:";
    out << "\n";

    for (int i=0; i<code.size(); i++) {
        out << code.at(i).toStdString();
        out << "\n";
    }

    out << "end start";

    out.close();
    */
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
