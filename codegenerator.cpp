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

void CodeGenerator::setAsRoot(string tree) {
    root = this->getNode(tree);
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
    //ver GeneradorDeCodigo::declaracionVariable de alfonso para saber bien QUE devuelve
    /*
    */
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

    if (entry->token == "CTE")
        return constantes.value(QString::fromStdString(op));

    if (entry->token == "CADENA")
        return cadenas.value(QString::fromStdString(op));


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
 */
bool CodeGenerator::tieneHijosHoja(Node * node) {
    if ((node==NULL) || (node->dato == "@sentencia"))
        return false;
    //despues de esto verificar si tiene sus hijos hoja o no

    //VERIFICAR SI LA LOGICA ESTA BIEN

    //AHORA EXISTEN MAS NODOS CONTROL: @condicion,@cuerpoif,@cuerpoWhile, NOSE SI TAMBIEN ENTRAN @then,@else EN ESTA CATEGORIA

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

/*Asume que lo que recibe es un nodo con dos hijos hoja
 *Devuelve todas las instrucciones assembler asociadas a
 *dicha operacion
*/
QList<QString> CodeGenerator::getInstructions(Node * node) {
    QString instruccion;
    QList<QString> instrucciones;
    instrucciones.clear();
    //VALORES DE NODE->DATO QUE FALTAN:@CONV,@SENTENCIA,@PRINT,@IF,@CONDICION,@CUERPO,@THEN,@ELSE,@WHILE
    if (node->dato == "!=") {
        //Se verifica si es una comparacion de enteros o double

        //----NUEVO COMENTARIO---
        //LE AGREGUE EL TIPO, QUE NO SE LO ASIGNABA EN NINGUN LADO HASTA DONDE VI YO
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            instruccion = "MOV ax, " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            instruccion = "CMP ax, " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);
            instruccion = "JNE FALTA_PONER_ETIQUETA";
            //ACA SE APILARIA LA ETIQUETA SUPONGO
            instrucciones.push_back(instruccion);
            return instrucciones;

        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            //ACA QUE TAMAÑO DE DATO TENEMOS QUE USAR?? 8,16,32,64,80,...??
        }
    }
    if (node->dato == ">=") {
        //Se verifica si es una comparacion de enteros o double

        //----NUEVO COMENTARIO---
        //LE AGREGUE EL TIPO, QUE NO SE LO ASIGNABA EN NINGUN LADO HASTA DONDE VI YO
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            instruccion = "MOV ax, " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            instruccion = "CMP ax, " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);
            instruccion = "JGE FALTA_PONER_ETIQUETA";
            //ACA SE APILARIA LA ETIQUETA SUPONGO
            instrucciones.push_back(instruccion);
            return instrucciones;

        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            //ACA QUE TAMAÑO DE DATO TENEMOS QUE USAR?? 8,16,32,64,80,...??
        }
    }
    if (node->dato == "<=") {
        //Se verifica si es una comparacion de enteros o double

        //----NUEVO COMENTARIO---
        //LE AGREGUE EL TIPO, QUE NO SE LO ASIGNABA EN NINGUN LADO HASTA DONDE VI YO
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            instruccion = "MOV ax, " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            instruccion = "CMP ax, " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);
            instruccion = "JLE FALTA_PONER_ETIQUETA";
            //ACA SE APILARIA LA ETIQUETA SUPONGO
            instrucciones.push_back(instruccion);
            return instrucciones;

        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            //ACA QUE TAMAÑO DE DATO TENEMOS QUE USAR?? 8,16,32,64,80,...??
        }
    }
    if (node->dato == "=") {
        //Se verifica si es una comparacion de enteros o double

        //----NUEVO COMENTARIO---
        //LE AGREGUE EL TIPO, QUE NO SE LO ASIGNABA EN NINGUN LADO HASTA DONDE VI YO
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            instruccion = "MOV ax, " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            instruccion = "CMP ax, " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);
            instruccion = "JE FALTA_PONER_ETIQUETA";
            //ACA SE APILARIA LA ETIQUETA SUPONGO
            instrucciones.push_back(instruccion);
            return instrucciones;

        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            //ACA QUE TAMAÑO DE DATO TENEMOS QUE USAR?? 8,16,32,64,80,...??
        }
    }
    if (node->dato == ">") {
        //Se verifica si es una comparacion de enteros o double

        //----NUEVO COMENTARIO---
        //LE AGREGUE EL TIPO, QUE NO SE LO ASIGNABA EN NINGUN LADO HASTA DONDE VI YO
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            instruccion = "MOV ax, " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            instruccion = "CMP ax, " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);
            instruccion = "JG FALTA_PONER_ETIQUETA";
            //ACA SE APILARIA LA ETIQUETA SUPONGO
            instrucciones.push_back(instruccion);
            return instrucciones;

        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            //ACA QUE TAMAÑO DE DATO TENEMOS QUE USAR?? 8,16,32,64,80,...??
        }
    }
    if (node->dato == "<") {
        //Se verifica si es una comparacion de enteros o double

        //----NUEVO COMENTARIO---
        //LE AGREGUE EL TIPO, QUE NO SE LO ASIGNABA EN NINGUN LADO HASTA DONDE VI YO
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            instruccion = "MOV ax, " + convertOperand(node->hijoIzquierdo->dato);
            instrucciones.push_back(instruccion);
            instruccion = "CMP ax, " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);
            instruccion = "JL FALTA_PONER_ETIQUETA";
            //ACA SE APILARIA LA ETIQUETA SUPONGO
            instrucciones.push_back(instruccion);
            return instrucciones;

        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            //ACA QUE TAMAÑO DE DATO TENEMOS QUE USAR?? 8,16,32,64,80,...??
        }
    }
    if (node->dato == "+") {
        //Se verifica si es una suma de enteros o double

        //----NUEVO COMENTARIO---
        //LE AGREGUE EL TIPO, QUE NO SE LO ASIGNABA EN NINGUN LADO HASTA DONDE VI YO
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
            //ACA QUE TAMAÑO DE DATO TENEMOS QUE USAR?? 8,16,32,64,80,...??
        }

    }
    if (node->dato =="-"){
        //Se verifica si es una resta de enteros o double

        //----NUEVO COMENTARIO---
        //LE AGREGUE EL TIPO, QUE NO SE LO ASIGNABA EN NINGUN LADO HASTA DONDE VI YO
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
            //ACA QUE TAMAÑO DE DATO TENEMOS QUE USAR?? 8,16,32,64,80,...??
        }
    }
    if (node->dato =="*"){
        //Se verifica si es una multiplicacion de enteros o double

        //----NUEVO COMENTARIO---
        //LE AGREGUE EL TIPO, QUE NO SE LO ASIGNABA EN NINGUN LADO HASTA DONDE VI YO
        //YO LE MANDE IMUL EN ESTE CASO, PORQUE TENEMOS NUMEROS CON SIGNO
        //CLARAMENTE LA MULTIPLICACION NOS DA 32 BITS, NOS QUEDAMOS CON LOS 16 BAJOS QUE ESTAN EN AX
        //HAY QUE AGREGAR ALGUNA OPERACION MAS PARA MANTENER EL SIGNO SI TENEMOS OVERFLOW???
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
            //ACA QUE TAMAÑO DE DATO TENEMOS QUE USAR?? 8,16,32,64,80,...??
        }
    }
    if (node->dato =="/"){
        //Se verifica si es una division de enteros o double

        //----NUEVO COMENTARIO---
        //LE AGREGUE EL TIPO, QUE NO SE LO ASIGNABA EN NINGUN LADO HASTA DONDE VI YO
        //LE AGREGUE CHEQUEO POR DIVISION POR ZERO AL PRINCIPIO
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            //CHEQUEO POR DIVISION POR ZERO QUE SALTA A UNA RUTINA??
            instruccion = "CMP "+ convertOperand(node->hijoDerecho->dato)+ ", 0";
            instrucciones.push_back(instruccion);
            instruccion = "JE divZero";
            instrucciones.push_back(instruccion);

            //NOSE SI ESTA SENTENCIA ESTA BIEN: PARA DIVIDIR, TENES QUE TENER EL DIVIDENDO EN DX:AX
            //EL COCIENTE QUEDA EN AX
            //EN LAS FILMINAS DICE: CWD EXTIENDE EL SIGNO DE AX EN DX:AX, TAL VES ESTE SEA EL QUE TENEMOS QUE USAR
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
            //ACA QUE TAMAÑO DE DATO TENEMOS QUE USAR?? 8,16,32,64,80,...??
        }
    }
    if (node->dato ==":="){
        //Se verifica si es una asignacion de enteros o double

        //----NUEVO COMENTARIO---
        //LE AGREGUE EL TIPO, QUE NO SE LO ASIGNABA EN NINGUN LADO HASTA DONDE VI YO
        if (symbolsTable->getType(node->hijoIzquierdo->dato) == "INTEGER") {
            instruccion = "MOV ax, " + convertOperand(node->hijoDerecho->dato);
            instrucciones.push_back(instruccion);

            //se copia el resultado en la nueva variable auxiliar
            //TAMPOCO ESTOY SEGURO SI ESTA BIEN REFERENCIAR ASI UNA VARIABLE
            instruccion = "MOV " + node->hijoDerecho->dato + ", ax";
            instrucciones.push_back(instruccion);
            return instrucciones;

        }
        else if (symbolsTable->getType(node->hijoIzquierdo->dato) == "DOUBLE") {
            //ACA QUE TAMAÑO DE DATO TENEMOS QUE USAR?? 8,16,32,64,80,...??
        }
    }
    if (node->dato =="-=") {
        //recordar que aca hay que hacer instrucciones de resta y de asignacion
        /* creo que no necesita una auxiliar, osea
         * a -= b
         * generaria codigo para a-b como en cualquier otra resta
         * despues del ultimo MOV ax,... se hace
         * MOV a, ax
         *
         * MIRANDO LOS FILMINAS CREO QUE SERIA:
         * MOV AX,_A
         * SUB AX,_B
         * MOV _A,AX
         * */
        //Se verifica si es una asignacion de enteros o double

        //----NUEVO COMENTARIO---
        //LE AGREGUE EL TIPO, QUE NO SE LO ASIGNABA EN NINGUN LADO HASTA DONDE VI YO
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
            //ACA QUE TAMAÑO DE DATO TENEMOS QUE USAR?? 8,16,32,64,80,...??
        }
    }
    //EJEMPLO
    /*  QString instruccion;
        if (node.operacion == "+") {

        if (symbolsTable->getType(node->hijoIzquierdo.dato) = "INT") {
            //SOLO HACE FALTA VER UNO DE LOS DOS PARA SABER EL TIPO
            instruccion = "MOV ax, " + convertirOperando(node->hijoIzquierdo.dato);
            instrucciones.push_back(instruccion);
            instruccion = "ADD ax, " + convertirOperando(node->hijoDerecho.dato);
            instrucciones.push_back(instruccion);
            instruccion = "JO overflow";
            instrucciones.push_back(instruccion);

            //Crea la nueva variable auxiliar
            int id = variablesAuxiliares.size();
            QString varAux = "@aux_" + QString::number(id);
            variablesAuxiliares.push_back(varAux)

            //TAMBIEN HAY QUE DARLA DE ALTA EN LA TABLA DE SIMBOLOS!
            //CON EL TIPO QUE CORRESPONDA

            instruccion = "MOV " + varAux + ", ax";
            instrucciones.push_back(instruccion);
            return instrucciones;
        }
            if (node.tipoOperacion=="FLOAT")
            ...
            VER ALFONSO
        }

        if (node.operacion == "*") {
            BLA BLA
        }

        Y ASI SUCESIVAMENTE


        OSEA, SE DEBE DEVOLVER LA LISTA DE INSTRUCCIONES PERO TAMBIEN SE VAN
        CREANDO LAS VARIABLES AUXILIARES EN EL CAMINO (SE AGREGAN A LA LISTA Y A LA TS)
    */
}

/*Reemplaza el sub-arbol por otro con la ultima variable auxiliar creada
 *o lo cambia por NULL si la operacion no devolvia resultado
 */

 void CodeGenerator::processNode(Node * &node) {
    Node * aBorrar = node;
    node = NULL;


    //Ya se descolgo. Ahora se reemplaza node con el subarbol o NULL
    string op = aBorrar->dato.toStdString();
    //SI ES @IF,@WHILE,@PRINT,ETC... QUE PASA????? ADEMAS CREO QUE FALTA := Y LOS COMPARADORES
    if (op == "+" || op =="-" || op == "-=" || op == "*" || op == "/" || op == "@conv") {
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

        if (tieneHijosHoja(root)) {
            instructions->append(getInstructions(root)); //se genera codigo y se agrega
            processNode(root); //se cambia el sub-arbol
        } else {
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
    QList<QString> instructions;
    instructions.clear();
    recorrerArbol(root, &instructions);
    return instructions;
}

/* Devuelve el codigo assembler en el archivo */

void CodeGenerator::generateAssembler(const char * ruta) {
    //Se mapean las constantes y cadena a nuevo nombres de assembler
    mapearConstantesYCadenas();

    //Se recorre el arbol y se genera codigo Assembler, dando lugar tambien a nuevas
    //variables auxiliares en la TS
    QList<QString> code = generateCode();

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

    /** DECLARACION DE VARIABLES **/

    out << ".data";
    out << "\n";
    for (int i=0; i<variables.size(); i++) {
        out << variables.at(i).toStdString();
        out << "\n";
    }

    //FALTA DECLARAR ACA LAS CONSTANTES MAXIMAS (DE INT, DOUBLE, ETC)

    //CON ESTO TE REFERIS A LOS LIMITES PERMITIDOS??? PONELE INT:-2^15 A 2^15???? DOUBLE: MANTISA E+308???

    /** CODIGO **/

    out << ".code";
    out << "\n";

    //FALTAN DEFINICIONES DE RUTINAS ACA

    out << "start:";
    out << "\n";

    for (int i=0; i<code.size(); i++) {
        out << code.at(i).toStdString();
        out << "\n";
    }

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
