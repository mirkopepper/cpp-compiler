%token CTE MAYORIGUAL MENORIGUAL DISTINTO DOSPUNTOSIGUAL MENOSIGUAL CADENA ARROBA_F ARROBA_C ID IF ELSE ENDIF PRINT INTEGER DOUBLE MATRIX WHILE ALLOW TO

%%
programa : ID bloque_declarativo '{' bloque_ejecutable '}'       {addProgramComponent("Dectecto un programa!!");}
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

conversion : ALLOW tipo TO tipo ';' 	{addProgramComponent("Declaracion de conversion entre tipos");}
	| error tipo TO tipo ';' 	{addErrorMessage("Error de declaracion de conversion: palabra allow mal escrita");}
	| ALLOW error TO tipo ';' 	{addErrorMessage("Error de declaracion de conversion: falta tipo entre allow y to");}
	| ALLOW tipo error tipo ';' 	{addErrorMessage("Error de declaracion de conversion; palabra to mal escrita");}
	| ALLOW tipo TO error ';' 	{addErrorMessage("Error de declaracion de conversion: falta tipo despues del to");}
        ;

tipo : DOUBLE
        | INTEGER
        ;

lista_id : lista_id ',' ID
	| lista_id ID error {addErrorMessage("antes del identificador tiene que ir una coma.");}
        | ID
        ;

arreglo : tipo MATRIX ID corchetes_cte corchetes_cte opcional_arreglo
        | tipo MATRIX ID corchetes_cte corchetes_cte ';'    		{addProgramComponent("Declaracion de matriz");}
        ;


corchetes_cte : '[' CTE ']'
        ;

opcional_arreglo : inicializacion ';'   {addProgramComponent("Declaracion e inicializacion de matriz");}
        | ';' anotacion     		{addProgramComponent("Declaracion y anotacion de matriz");}
	| inicializacion ';' anotacion 	{addProgramComponent("Declaracion, inicializacion y anotacion de matriz");}
        ;

anotacion : ARROBA_C
        | ARROBA_F
        ;

inicializacion : '{' lista_de_listas '}'
        ;

lista_de_listas : lista_de_listas ';' lista_valores
        | lista_valores
        ;

lista_valores : lista_valores ',' CTE
        | CTE
        ;

bloque_ejecutable : bloque_ejecutable sentencia
        | sentencia
        ;

sentencia : seleccion
        | asignacion	{addErrorMessage("error en sentencia = falta ';' en el final de la asignacion");}
        | asignacion ';'{addProgramComponent("sentencia de asignacion");}
        | iteracion
        | impresion ';' {addProgramComponent("sentecia de impresion");}
        | impresion	{addErrorMessage("error en sentecia = falta ';' en el final de la impresion");}
        ;

seleccion : IF parentesis_condicion bloque_de_sentencias ELSE bloque_de_sentencias ENDIF{addProgramComponent("Sentencia IF con bloque ELSE");}
	| IF parentesis_condicion bloque_de_sentencias bloque_de_sentencias ENDIF 	{addErrorMessage("error en sentencia IF: falta else");}
        | IF parentesis_condicion bloque_de_sentencias ENDIF  				{addProgramComponent("Sentencia IF sin bloque ELSE");}
        ;

bloque_de_sentencias : sentencia
        | '{' bloque_ejecutable '}'	{addProgramComponent("bloque ejecutable entre llaves");}
        ;

parentesis_condicion : '(' condicion ')'
	| condicion ')' 			{addErrorMessage("error en parentesis_condicion: falta '('");}
	| '(' condicion  			{addErrorMessage("error en parentesis_condicion: falta ')' ");}
	| condicion  				{addErrorMessage("error en parentesis_condicion: faltan ambos parentesis ");}
	;

condicion : expresion comparador expresion
	| error comparador expresion		{addErrorMessage("error en condicion: problema con expresion del lado izquierdo");}
	| expresion error expresion		{addErrorMessage("error en condicion: problema con el comparador");}
	| expresion comparador error		{addErrorMessage("error en condicion: problema con expresion del lado derecho");}
        ;

comparador : '<'
        | '>'
        | MENORIGUAL
        | MAYORIGUAL
        | '='
        | DISTINTO
        ;

asignacion : asignacion_izq operador_asignacion expresion
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
        | expresion '-' termino	
        | termino
        ;

termino : termino '*' factor
        | termino '/' factor
        | factor
        ;

factor : ID
        | CTE
        | celda
        ;

celda : ID '[' expresion ']' '[' expresion ']'
	| ID '[' error ']' '[' expresion ']'     	{addErrorMessage("error en celda: falta expresion en 1er dimension");}
        | ID '[' error '[' expresion ']'       		{addErrorMessage("error en celda: falta ']' en la 1er dimension");}
        | ID '[' expresion ']' error expresion ']'      {addErrorMessage("error en celda: falta '[' en la 2da dimension");}
        | ID '[' expresion ']' '[' error ']'       	{addErrorMessage("error en celda: falta expresion en 2da dimension");}
        | ID '[' expresion ']' '[' expresion error      {addErrorMessage("error en celda: falta ']' en 2da dimension");}
        ;

iteracion : WHILE parentesis_condicion bloque_de_sentencias {addProgramComponent("Sentencia WHILE");}
        ;

impresion : PRINT '(' CADENA ')'{addProgramComponent("Impresion por pantalla");}
	| PRINT '(' error ')'  	{addErrorMessage("error de impresion por pantalla: falta cadena");}
	| PRINT CADENA ')'  	{addErrorMessage("error de impresion por pantalla: falta parentesis '('");}
	| PRINT '(' CADENA   	{addErrorMessage("error de impresion por pantalla: falta parentesis ')'");}
	| PRINT CADENA   	{addErrorMessage("error de impresion por pantalla: faltan ambos parentesis");}
        ;
