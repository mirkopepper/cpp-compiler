%token CTE MAYORIGUAL MENORIGUAL DISTINTO DOSPUNTOSIGUAL MENOSIGUAL CADENA ARROBA_F ARROBA_C ID IF ELSE ENDIF PRINT INTEGER DOUBLE MATRIX WHILE ALLOW TO

%%
programa : ID bloque_declarativo '{' bloque_ejecutable '}'
                {
                addProgramComponent("Dectecto un programa!!");
                cout << "TERMINA" << endl;
                }
        | ID bloque_declarativo bloque_ejecutable '}'    {addErrorMessage("error: falta llave de inicio. Programa Compilado!");}
        | ID bloque_declarativo '{' bloque_ejecutable    {addErrorMessage("error: falta llave de cierre. Programa Compilado!");}
        ;

bloque_declarativo : bloque_declarativo sentencia_declarativa
        | sentencia_declarativa
        ;

sentencia_declarativa : variable
        | conversion
        | arreglo
        ;

variable : tipo lista_id ';'                  {addProgramComponent("Declaracion de una variable");}
		| tipo error ';'              {addErrorMessage("error de declaracion de variables: lista de identificadores mal esrita");}
		| tipo lista_id error ';'     {addErrorMessage("error de declaracion de variables: falta ';'");}
        ;

conversion : ALLOW tipo TO tipo ';'
                {
                addProgramComponent("Declaracion de conversion entre tipos");
                if ($2=="DOUBLE" && $4=="INTEGER")
                    conversionsAllowed = true;
                }
	| error tipo TO tipo ';' 	{addErrorMessage("Error de declaracion de conversion: palabra allow mal escrita");}
	| ALLOW error TO tipo ';' 	{addErrorMessage("Error de declaracion de conversion: falta tipo entre allow y to");}
	| ALLOW tipo error tipo ';' 	{addErrorMessage("Error de declaracion de conversion; palabra to mal escrita");}
	| ALLOW tipo TO error ';' 	{addErrorMessage("Error de declaracion de conversion: falta tipo despues del to");}
        ;

tipo : DOUBLE
                {
                type="DOUBLE";
                $$=type;
                }
        | INTEGER
                {
                type="INTEGER";
                $$=type;
                }
        ;

lista_id : lista_id ',' ID
                {
                declareVariable(getLexeme($3), "var@", type,"variable");
                }
        | lista_id ID error
                {
                addErrorMessage("antes del identificador tiene que ir una coma.");
                }
        | ID
                {
                declareVariable(getLexeme($1), "var@", type,"variable");
                }
        ;

arreglo : tipo MATRIX ID dimensiones_cte opcional_arreglo
                {
                /*declarar matriz,guardar limites y forma de alinearse.Si fuera necesario se inicializa*/
                declareMatriz(getLexeme($3),"mat@",$1,"matriz",$5);
                }
        ;


dimensiones_cte : '[' CTE ']' '[' CTE ']'
                {
                /*chequea que sean valores enteros e inicializa array por si la declaracion contiene inicializacion de matriz*/
                if(symbolsTable->getEntry(stoi($2))->type=="INTEGER" && symbolsTable->getEntry(stoi($5))->type=="INTEGER"){
                    ArrayInitializer aux(stoi(getLexeme($2)),stoi(getLexeme($5)));
                    array=aux;
                }
                else
                    addErrorMessage("los limites de la matriz deben ser valores enteros.");
                }
        ;

opcional_arreglo : ';'
                {
                addProgramComponent("Declaracion de matriz");
                /*No se inicializa nada pero se guarda inicializacion por filas (opcion por defecto)*/
                $$="@rows";
                }
        | inicializacion ';'
                {
                addProgramComponent("Declaracion e inicializacion de matriz");
                /*Se inicializa  y guarda por filas  (opcion por defecto)*/
                $$="initialize@rows";
                }
        | ';' anotacion
                {
                addProgramComponent("Declaracion y anotacion de matriz");
                /*Se guarda alineacion por filas/columnas*/
                $$="@"+$2;
                }
        | inicializacion ';' anotacion
                {
                addProgramComponent("Declaracion, inicializacion y anotacion de matriz");
                /*Se inicializa y guarda alineacion por filas/columnas*/
                $$="initialize@"+$3;
                }
        ;

anotacion : ARROBA_C
                {
                /*se inicializa por columnas*/
                $$="columns";
                }
        | ARROBA_F
                {
                /*se inicializa por filas*/
                $$="rows";
                }
        ;

inicializacion : '{' lista_de_listas '}'
        ;

lista_de_listas : lista_de_listas ';' lista_valores
                {
                /*pasa de la ultima posicion de la fila i a la 1ra de la fila i+1*/
                array.setJ(0);
                array.increaseI();
                }
        | lista_valores
                {
                /*pasa de la ultima posicion de la fila i a la 1ra de la fila i+1*/
                array.setJ(0);
                array.increaseI();
                }
        ;

lista_valores : lista_valores ',' CTE
                {
                /*pasa de la fila i en posicion j a misma fila en posicion j+1, ademas chequea que no se vaya de rango*/
                array.increaseJ();
                updateArray(symbolsTable->getEntry(stoi($3))->lexeme);
                }
        | CTE
                {
                /*guarda dato y chequea que no se vaya de rango*/
                updateArray(symbolsTable->getEntry(stoi($1))->lexeme);
                }
        ;

bloque_ejecutable : bloque_ejecutable sentencia
                {
                /*junta la sentencia con el arbol y actualiza la raiz*/
                string executableBlock=codeGen->crearNodo("@sentencia",$2);
                codeGen->addRightNode($1,executableBlock);
                $$=executableBlock;
                }
        | sentencia
                {
                /*se inicia un nuevo bloque ejecutable*/
                string executableBlock=codeGen->crearNodo("@sentencia",$1);
                /*si da verdadero, es porque no hubo inicializacion de matriz y estoy en el bloque main del programa(no es bloque if/while)*/
                if(codeGen->rootIsNull()){
                    codeGen->setAsRootNode($1);
                    mainBlockConected=true;
                }
                else{
                    /*si estoy en el bloque main, lo conecto con la inicializacion*/
                    if(!mainBlockConected){
                        codeGen->addRightNode(codeGen->getLastBlock(),executableBlock);
                        mainBlockConected=true;
                    }
                }
                codeGen->setAsBlockSentenceNode(executableBlock);
                $$=executableBlock;
                }
        ;

sentencia : seleccion
                {
                $$=$1;
                }
        | asignacion
                {
                addErrorMessage("error en sentencia = falta ';' en el final de la asignacion");
                }
        | asignacion ';'
                {
                addProgramComponent("sentencia de asignacion");
                $$=$1;
                }
        | iteracion
                {
                $$=$1;
                }
        | impresion ';'
                {
                addProgramComponent("sentecia de impresion");
                $$=$1;
                }
        | impresion
                {
                addErrorMessage("error en sentecia = falta ';' en el final de la impresion");
                }
        ;

seleccion : IF parentesis_condicion bloque_de_sentencias ELSE bloque_de_sentencias ENDIF
                {
                addProgramComponent("Sentencia IF con bloque ELSE");
                $$=codeGen->crearNodo("@if",$2,codeGen->crearNodo("@cuerpoIf",codeGen->crearNodo("@then",$3),codeGen->crearNodo("@else", $5)));
                }
        | IF parentesis_condicion bloque_de_sentencias bloque_de_sentencias ENDIF
                {
                addErrorMessage("error en sentencia IF: falta else");
                }
        | IF parentesis_condicion bloque_de_sentencias ENDIF
                {
                addProgramComponent("Sentencia IF sin bloque ELSE");
                $$=codeGen->crearNodo("@if",$2,codeGen->crearNodo("@cuerpoIf",codeGen->crearNodo("@then",$3)));
                }
                ;

bloque_de_sentencias : sentencia
                {
                $$=codeGen->crearNodo("@sentencia",$1);
                }
        | '{' bloque_ejecutable '}'
                {
                addProgramComponent("bloque ejecutable entre llaves");
                $$=codeGen->getLastBlock();
                }
        ;

parentesis_condicion : '(' condicion ')'
                {
                $$=codeGen->crearNodo("@condicion", $2);
                }
	| condicion ')' 			{addErrorMessage("error en parentesis_condicion: falta '('");}
	| '(' condicion  			{addErrorMessage("error en parentesis_condicion: falta ')' ");}
	| condicion  				{addErrorMessage("error en parentesis_condicion: faltan ambos parentesis ");}
	;

condicion : expresion comparador expresion
                {
                $$=createConditionNode($2,$1,$3);
                }
	| error comparador expresion		{addErrorMessage("error en condicion: problema con expresion del lado izquierdo");}
	| expresion error expresion		{addErrorMessage("error en condicion: problema con el comparador");}
	| expresion comparador error		{addErrorMessage("error en condicion: problema con expresion del lado derecho");}
        ;

comparador : '<'
                {
                $$="<";
                }
        | '>'
                {
                $$=">";
                }
        | MENORIGUAL
                {
                $$="<=";
                }
        | MAYORIGUAL
                {
                $$=">=";
                }
        | '='
                {
                $$="=";
                }
        | DISTINTO
                {
                $$="!=";
                }
        ;

asignacion : asignacion_izq operador_asignacion expresion
                {
                $$=createAssignmentNode($2,$1,$3);
                }
        | asignacion_izq operador_asignacion expresion error	{addErrorMessage("Error en asignacion:problema con asignacion");}
        | asignacion_izq operador_asignacion error 		{addErrorMessage("Error en asignacioN:problema con la expresion del lado derecho");}
        | asignacion_izq expresion ';' 				{addErrorMessage("Error en asignacion:falta el operador de asignacion");}
        | operador_asignacion expresion error 			{addErrorMessage("Error en asignacion:falta variable en lado derecho");}
        ;

operador_asignacion : DOSPUNTOSIGUAL
                {
                $$=":=";
                }
        | MENOSIGUAL
                {
                $$="-=";
                }
	;

asignacion_izq : ID
                {
                /*chequeo si ID fue declarado como VARIABLE*/
                string var=mangle(getLexeme($1),"variable");
                if(var!=""){
                    lastTypes.push(symbolsTable->getType(var));
                    $$=codeGen->crearNodo(var);
                }
                }
        | celda
                {
                $$=$1;
                }
        ;

expresion : expresion '+' termino
                {
                $$=createOperatorNode("+",$1,$3);
                }
        | expresion '-' termino
                {
                $$=createOperatorNode("-",$1,$3);
                }
        | termino
                {
                $$=$1;
                }
        ;

termino : termino '*' factor
                {
                $$=createOperatorNode("*",$1,$3);
                }
        | termino '/' factor
                {
                $$=createOperatorNode("/",$1,$3);
                }
        | factor
                {
                $$=$1;
                }
        ;

factor : ID
                {
                /*chequeo si ID fue declarado como VARIABLE*/
                string var=mangle(getLexeme($1),"variable");
                if(var!=""){
                    lastTypes.push(symbolsTable->getType(var));
                    $$=codeGen->crearNodo(var);
                }
                }
        | CTE
                {
                /*obtengo el tipo y lo pusheo, luego creo el nodo*/
                lastTypes.push(QString::fromStdString(symbolsTable->getEntry(stoi($1))->type));
                $$=codeGen->crearNodo(getLexeme($1));
                }
        | celda
                {
                $$=$1;
                Node * node = codeGen->getNode($1);
                lastTypes.push(symbolsTable->getType(node->dato));
                }
        ;

celda : ID '[' expresion ']' '[' expresion ']'
                {
                string longMatName=mangle(getLexeme($1),"matriz");
                QString subIndexType1,subIndexType2;
                if(!lastTypes.empty())
                    subIndexType2=lastTypes.pop();
                if(!lastTypes.empty())
                    subIndexType1=lastTypes.pop();
                /*chequea si existe en la tabla de simbolos y que el tipo en subindices sea correcto*/
                if((longMatName!="") && integerSubindex(subIndexType1,subIndexType2)){
                    lastTypes.push(QString::fromStdString(symbolsTable->getEntry(longMatName)->type));
                    $$=codeGen->crearNodo(longMatName,$3,$6);
                }
                }
        | ID '[' error ']' '[' expresion ']'     	{addErrorMessage("error en celda: falta expresion en 1er dimension");}
        | ID '[' error '[' expresion ']'       		{addErrorMessage("error en celda: falta ']' en la 1er dimension");}
        | ID '[' expresion ']' error expresion ']'      {addErrorMessage("error en celda: falta '[' en la 2da dimension");}
        | ID '[' expresion ']' '[' error ']'       	{addErrorMessage("error en celda: falta expresion en 2da dimension");}
        | ID '[' expresion ']' '[' expresion error      {addErrorMessage("error en celda: falta ']' en 2da dimension");}
        ;

iteracion : WHILE parentesis_condicion bloque_de_sentencias
                {
                addProgramComponent("Sentencia WHILE");
                $$=codeGen->crearNodo("@while",$2,codeGen->crearNodo("@cuerpoWhile",$3));
                }
        ;

impresion : PRINT '(' CADENA ')'
                {
                addProgramComponent("Impresion por pantalla");
                string cadena=codeGen->crearNodo(symbolsTable->getEntry(stoi($3))->getValue());
                $$=codeGen->crearNodo("@print",cadena);
                }
        | PRINT '(' error ')'  	{addErrorMessage("error de impresion por pantalla: falta cadena");}
	| PRINT CADENA ')'  	{addErrorMessage("error de impresion por pantalla: falta parentesis '('");}
	| PRINT '(' CADENA   	{addErrorMessage("error de impresion por pantalla: falta parentesis ')'");}
	| PRINT CADENA   	{addErrorMessage("error de impresion por pantalla: faltan ambos parentesis");}
        ;
