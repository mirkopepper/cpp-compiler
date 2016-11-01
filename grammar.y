%token CTE MAYORIGUAL MENORIGUAL DISTINTO DOSPUNTOSIGUAL MENOSIGUAL CADENA ARROBA_F ARROBA_C ID IF ELSE ENDIF PRINT INTEGER DOUBLE MATRIX WHILE ALLOW TO

%%
programa : ID bloque_declarativo '{' bloque_ejecutable '}'
                {addProgramComponent("Dectecto un programa!!");
                /*falta indicar que id se usa como nombre de programa*/
                }
        | ID bloque_declarativo bloque_ejecutable '}'    		{addErrorMessage("error: falta llave de inicio. Programa Compilado!");}
        | ID bloque_declarativo '{' bloque_ejecutable   		{addErrorMessage("error: falta llave de cierre. Programa Compilado!");}
        ;

bloque_declarativo : bloque_declarativo sentencia_declarativa
        | sentencia_declarativa
        ;

sentencia_declarativa : variable
        | conversion
        | arreglo
        ;

variable : tipo lista_id ';'          {addProgramComponent("Declaracion de una variable");}
        | tipo error ';'              {addErrorMessage("error de declaracion de variables: lista de identificadores mal esrita");}
        | tipo lista_id error ';'     {addErrorMessage("error de declaracion de variables: falta ';'");}
        ;

conversion : ALLOW tipo TO tipo ';' 	{if ($2=="DOUBLE" && $4=="INTEGER") conversionsAllowed = true;}
        | error tipo TO tipo ';' 	{addErrorMessage("Error de declaracion de conversion: palabra allow mal escrita");}
        | ALLOW error TO tipo ';' 	{addErrorMessage("Error de declaracion de conversion: falta tipo entre allow y to");}
        | ALLOW tipo error tipo ';' 	{addErrorMessage("Error de declaracion de conversion; palabra to mal escrita");}
        | ALLOW tipo TO error ';' 	{addErrorMessage("Error de declaracion de conversion: falta tipo despues del to");}
        ;

tipo : DOUBLE 		{type="DOUBLE";}
        | INTEGER 	{type="INTEGER";}
        ;

lista_id : lista_id ',' ID 	{declareVariable($3, "var@", type,"variable");}
        | lista_id ID error 	{addErrorMessage("antes del identificador tiene que ir una coma.");}
        | ID 			{declareVariable($1, "var@", type,"variable");}
        ;

arreglo : tipo MATRIX ID dimensiones_cte opcional_arreglo
                {
                /*declarar matriz,guardar limites y forma de alinearse.Si fuera necesario se inicializa*/
                }
        ;

dimensiones_cte : '[' CTE ']' '[' CTE ']'
                {
                /*falta chequear que sean valores enteros y guardar ambos valores*/
                }
        ;

opcional_arreglo : ';'
                {addProgramComponent("Declaracion de matriz");
                /*No se inicializa nada pero se guarda inicializacion por filas (opcion por defecto)*/
                }
        | inicializacion ';'            {addProgramComponent("Declaracion e inicializacion de matriz");}
                {addProgramComponent("Declaracion e inicializacion de matriz");
                /*Se inicializa  y guarda por filas  (opcion por defecto)*/
                }
        | ';' anotacion     		{addProgramComponent("Declaracion y anotacion de matriz");}
                {addProgramComponent("Declaracion y anotacion de matriz");
                /*Se guarda alineacion por filas/columnas*/
                }
        | inicializacion ';' anotacion 	{addProgramComponent("Declaracion, inicializacion y anotacion de matriz");}
                {addProgramComponent("Declaracion, inicializacion y anotacion de matriz");
                /*Se inicializa y guarda alineacion por filas/columnas*/
                }
        ;

anotacion : ARROBA_C    {/*guardar en algun lado que se inicaliza por columnas*/}
        | ARROBA_F      {/*guardar en algun lado que se inicaliza por filas*/}
        ;

inicializacion : '{' lista_de_listas '}'
        ;

lista_de_listas : lista_de_listas ';' lista_valores
        | lista_valores
        ;

lista_valores : lista_valores ',' CTE
        | CTE
        ;

bloque_ejecutable : bloque_ejecutable sentencia {$$=codeGen->crearNodo("@sentencia",$1,$2);}
        | sentencia 				{$$=codeGen->crearNodo("@sentencia",$1);}
        ;

sentencia : seleccion
        | asignacion		{addErrorMessage("error en sentencia = falta ';' en el final de la asignacion");}
        | asignacion ';' 	{addProgramComponent("sentencia de asignacion");}
        | iteracion
        | impresion ';' 	{addProgramComponent("sentecia de impresion");}
        | impresion		{addErrorMessage("error en sentecia = falta ';' en el final de la impresion");}
        ;

seleccion : IF parentesis_condicion bloque_de_sentencias ELSE bloque_de_sentencias ENDIF
                {addProgramComponent("Sentencia IF con bloque ELSE");
                $$=codeGen->crearNodo("@if",$2,codeGen->crearNodo("@cuerpo",codeGen->crearNodo("@then",$3),codeGen->crearNodo("@else", $5)));
                }
        | IF parentesis_condicion bloque_de_sentencias bloque_de_sentencias ENDIF 	{addErrorMessage("error en sentencia IF: falta else");}
        | IF parentesis_condicion bloque_de_sentencias ENDIF
                {addProgramComponent("Sentencia IF sin bloque ELSE");
                $$=codeGen->crearNodo("@if",$2,codeGen->crearNodo("@cuerpo",codeGen->crearNodo("@then",$3)));
                }
        ;

bloque_de_sentencias : sentencia
        | '{' bloque_ejecutable '}'
                {addProgramComponent("bloque ejecutable entre llaves");
                $$=$2;
                }
        ;

parentesis_condicion : '(' condicion ')' 	{$$=codeGen->crearNodo("@condicion", $2);}
        | condicion ')' 			{addErrorMessage("error en parentesis_condicion: falta '('");}
        | '(' condicion  			{addErrorMessage("error en parentesis_condicion: falta ')' ");}
        | condicion  				{addErrorMessage("error en parentesis_condicion: faltan ambos parentesis ");}
        ;

condicion : expresion comparador expresion
                {QString tipo1, tipo2;
                if (!lastTypes.empty())
                    tipo1 = lastTypes.pop();
                if (!lastTypes.empty())
                    tipo2 = lastTypes.pop();
                if (tipo1!=tipo2) {
                    if (tipo1=="INTEGER"){
                        string conversion = codeGen->crearNodo("@conv", $3);
                        $$=codeGen->crearNodo($2, $1, conversion);
                    }else{//tipo2=INTEGER
                        string conversion = codeGen->crearNodo("@conv", $1);
                        $$=codeGen->crearNodo($2, conversion, $3);
                    }
                }
                }
        | error comparador expresion		{addErrorMessage("error en condicion: problema con expresion del lado izquierdo");}
        | expresion error expresion		{addErrorMessage("error en condicion: problema con el comparador");}
        | expresion comparador error		{addErrorMessage("error en condicion: problema con expresion del lado derecho");}
        ;

comparador : '<' 		{$$="<";}
        | '>' 			{$$=">";}
        | MENORIGUAL
        | MAYORIGUAL
        | '=' 			{$$="=";}
        | DISTINTO
        ;

asignacion : asignacion_izq operador_asignacion expresion
                {
                QString tipo1,tipo2;
                if (!lastTypes.empty())
                    tipo1 = lastTypes.pop();
                if (!lastTypes.empty())
                    tipo2 = lastTypes.pop();
                /*tipo2=asig_izq tipo1=expresion*/
                if(tipo2=="INTEGER" && tipo1=="DOUBLE" && !conversionsAllowed)
                    addErrorMessage("Error en asignacion: conversion no permitida.");
                    $$=codeGen->crearNodo($2,$1,$3);
                }
        | asignacion_izq operador_asignacion expresion error	{addErrorMessage("Error en asignacion:problema con asignacion");}
        | asignacion_izq operador_asignacion error 		{addErrorMessage("Error en asignacioN:problema con la expresion del lado derecho");}
        | asignacion_izq expresion ';' 				{addErrorMessage("Error en asignacion:falta el operador de asignacion");}
        | operador_asignacion expresion error 			{addErrorMessage("Error en asignacion:falta variable en lado derecho");}
        ;

operador_asignacion : DOSPUNTOSIGUAL
        | MENOSIGUAL
        ;

asignacion_izq : ID
        | celda
        ;

expresion : expresion '+' termino
                {
                $$=createAritmethicalOperatorNode("+",$1,$3);
                }
        | expresion '-' termino
                {
                $$=createAritmethicalOperatorNode("-",$1,$3);
                }
        | termino
        ;

termino : termino '*' factor
                {
                $$=createAritmethicalOperatorNode("*",$1,$3);
                }
        | termino '/' factor
                {
                $$=createAritmethicalOperatorNode("/",$1,$3);
                }
        | factor
        ;

factor : ID
                {/*chequeo si ID fue declarado como VARIABLE*/
                string var=mangle($1,"variable");
                $$=codeGen->crearNodo(var);
                if(var!="")
                    lastTypes.push(symbolsTable->getType(var));
                }
        | CTE
                {$$=codeGen->crearNodo($1);
                lastTypes.push(symbolsTable->getType($1));
                }
        | celda
                {$$=$1;
                Node * node = codeGen->pointersTable.getNode($1);
                lastTypes.push(symbolsTable->getType(node->dato));
                }
        ;

celda : ID '[' expresion ']' '[' expresion ']'
                {/*chequeo tipo expresiones=INTEGER*/
                string mat=mangle($1,"matriz");
                /*saca los ultimos 2 tipos*/
                QString tipo1,tipo2;
                if(!lastTypes.empty())
                    tipo1=lastTypes.pop();
                if(!lastTypes.empty())
                    tipo2=lastTypes.pop();
                /*chequea si existe en la tabla de simbolos y que el tipo en subindices sea correcto*/
                if((mat!="") && integerSubindex(tipo1,tipo2))
                    $$=codeGen->crearNodo(mat,$3,$6);
                }
        | ID '[' error ']' '[' expresion ']'     	{addErrorMessage("error en celda: falta expresion en 1er dimension");}
        | ID '[' error '[' expresion ']'       		{addErrorMessage("error en celda: falta ']' en la 1er dimension");}
        | ID '[' expresion ']' error expresion ']'      {addErrorMessage("error en celda: falta '[' en la 2da dimension");}
        | ID '[' expresion ']' '[' error ']'       	{addErrorMessage("error en celda: falta expresion en 2da dimension");}
        | ID '[' expresion ']' '[' expresion error      {addErrorMessage("error en celda: falta ']' en 2da dimension");}
        ;

iteracion : WHILE parentesis_condicion bloque_de_sentencias
                {addProgramComponent("Sentencia WHILE");
                $$=codeGen->crearNodo("@while",$2,$3);
                }
        ;

impresion : PRINT '(' CADENA ')'
                {addProgramComponent("Impresion por pantalla");
                $$=codeGen->crearNodo("@print",$3);
                }
        | PRINT '(' error ')'  	{addErrorMessage("error de impresion por pantalla: falta cadena");}
        | PRINT CADENA ')'  	{addErrorMessage("error de impresion por pantalla: falta parentesis '('");}
        | PRINT '(' CADENA   	{addErrorMessage("error de impresion por pantalla: falta parentesis ')'");}
        | PRINT CADENA   	{addErrorMessage("error de impresion por pantalla: faltan ambos parentesis");}
        ;
