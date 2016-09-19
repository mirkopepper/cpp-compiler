%token CTE MAYORIGUAL MENORIGUAL DISTINTO DOSPUNTOSIGUAL MENOSIGUAL CADENA ARROBA_F ARROBA_C ID IF ELSE ENDIF PRINT INTEGER DOUBLE MATRIX WHILE ALLOW TO

%%
programa : bloque_declarativo '{' bloque_ejecutable '}' {addProgramComponent("Dectecto un programa!!");}
		| bloque_declarativo bloque_ejecutable '}' {addProgramComponent("error: falta llave de inicio. Programa Compilado!");}
		| bloque_declarativo '{' bloque_ejecutable {addProgramComponent("error: falta llave de cierre. Programa Compilado!");}
        ;

bloque_declarativo : bloque_declarativo sentencia_declarativa {addProgramComponent("bloque declarativo=bloque declarativo + setencia declarativa");}
        | sentencia_declarativa	{addProgramComponent("bloque declarativo = sentencia declarativa");}
        ;

sentencia_declarativa : variable	{addProgramComponent("setencia declarativa = variable");}
        | conversion	{addProgramComponent("sentencia declaratica = conversion");}
        | arreglo	{addProgramComponent("sentencia declarativo = arreglo");}
        ;

variable : tipo lista_id ';' {addProgramComponent("variable = tipo + lista ids");}
		| tipo error ';' {addProgramComponent("error de declaracion de variables: lista de identificadores mal esrita");}
		| tipo lista_id error ';' {addProgramComponent("error de declaracion de variables: falta ';'");}
        ;

conversion : ALLOW tipo TO tipo ';' {addProgramComponent("Conversion entre variables");}
	| error tipo TO tipo ';' {addProgramComponent("Error de declaracion de conversion: palabra allow mal escrita");}
	| ALLOW error TO tipo ';' {addProgramComponent("Error de declaracion de conversion: falta tipo entre allow y to");}
	| ALLOW tipo error tipo ';' {addProgramComponent("Error de declaracion de conversion; palabra to mal escrita");}
	| ALLOW tipo TO error ';' {addProgramComponent("Error de declaracion de conversion: falta tipo despues del to");}
        ;

tipo : DOUBLE	{addProgramComponent("tipo double");}
        | INTEGER	{addProgramComponent("tipo integer");}
        ;

lista_id : lista_id ',' ID	{addProgramComponent("lista ids = lista ids + id");}
	| lista_id ID error {addProgramComponent("antes del identificador tiene que ir una coma.");}
        | ID	{addProgramComponent("lista ids = id");}
        ;

arreglo : tipo MATRIX ID corchetes_cte corchetes_cte opcional_arreglo	{addProgramComponent("arreglo = tipo matrix id dimensiones opcional arreglo");}
        | tipo MATRIX ID corchetes_cte corchetes_cte ';'    {addProgramComponent("Declaracion de matriz");}
        ;


corchetes_cte : '[' CTE ']'	{addProgramComponent("corchetes_cte = cte entre corchetes");}
        ;

opcional_arreglo : inicializacion ';'   {addProgramComponent("Declaracion e inicializacion de matriz");}
        | ';' anotacion     {addProgramComponent("Declaracion y anotacion de matriz");}
	| inicializacion ';' anotacion {addProgramComponent("Declaracion, inicializacion y anotacion de matriz");}
        ;

anotacion : ARROBA_C	{addProgramComponent("anotacion c");}
        | ARROBA_F	{addProgramComponent("anotacion f");}
        ;

inicializacion : '{' lista_de_listas '}'	{addProgramComponent("inicializacion = lista de listas entre corchetes");}
        ;

lista_de_listas : lista_de_listas ';' lista_valores	{addProgramComponent("lista de listas = lista de listas + puntocoma + lista valores");}
        | lista_valores	{addProgramComponent("lista de listas = lista valores");}
        ;

lista_valores : lista_valores ',' CTE	{addProgramComponent("lista valores = lista valores + coma + cte");}
        | CTE	{addProgramComponent("lista valores = cte");}
        ;

bloque_ejecutable : bloque_ejecutable sentencia	{addProgramComponent("bloque ejecutable = bloque ejecutable + sentencia");}
        | sentencia	{addProgramComponent("bloque ejecutable = sentencia");}
        ;

sentencia : seleccion	{addProgramComponent("sentencia = seleccion");}
        | asignacion	{addProgramComponent("sentencia = asignacion");}
        | iteracion	{addProgramComponent("sentencia = iteracion");}
        | impresion	';'{addProgramComponent("sentecia = impresion");}
        | impresion	{addProgramComponent("ERRRORsentecia = impresion");}
        ;

seleccion : IF parentesis_condicion bloque_de_sentencias ELSE bloque_de_sentencias ENDIF {addProgramComponent("Sentencia IF con bloque ELSE");}
		| IF parentesis_condicion bloque_de_sentencias bloque_de_sentencias ENDIF {addProgramComponent("error en sentencia IF: falta else");}
        | IF parentesis_condicion bloque_de_sentencias ENDIF  {addProgramComponent("Sentencia IF sin bloque ELSE");}
        ;

bloque_de_sentencias : sentencia	{addProgramComponent("bloque sentencias = sentencia");}
        | '{' bloque_ejecutable '}'	{addProgramComponent("bloque sentencias = bloque ejecutable entre llaves");}
        ;

parentesis_condicion : '(' condicion ')' {addProgramComponent("parentesis_condicion = condicion entre parentesis");}
		| condicion ')' {addProgramComponent("error en parentesis_condicion: falta '('");}
		| '(' condicion  {addProgramComponent("error en parentesis_condicion: ')' ");}
		| condicion  {addProgramComponent("error en parentesis_condicion: faltan ambos parentesis ");}
		;

condicion : expresion comparador expresion	{addProgramComponent("condicion = comparacion de expresiones");}
		| error comparador expresion	{addProgramComponent("error en condicion: problema con expresion del lado izquierdo");}
		| expresion error expresion	{addProgramComponent("error en condicion: problema con el comparador");}
		| expresion comparador error	{addProgramComponent("error en condicion: problema con expresion del lado derecho");}
        ;

comparador : '<'	{addProgramComponent("comparador = menor");}
        | '>'	{addProgramComponent("comparador = mayor");}
        | MENORIGUAL	{addProgramComponent("comparador = menor igual");}
        | MAYORIGUAL	{addProgramComponent("comparador = mayor igual");}
        | '='	{addProgramComponent("comparador = igual");}
        | DISTINTO	{addProgramComponent("comparador = distinto");}
        ;

asignacion : asignacion_izq operador_asignacion expresion ';' {addProgramComponent("Asignacion");}
		| asignacion_izq operador_asignacion expresion {addProgramComponent("Error en asignacion:falta el ';'");}
		| asignacion_izq operador_asignacion expresion error ';' {addProgramComponent("Error en asignacion:problema con asignacion");}
        | asignacion_izq operador_asignacion error ';' {addProgramComponent("Error en asignacioN:problema con la expresion del lado derecho");}
		| asignacion_izq error ';' {addProgramComponent("Error en asignacion:falta el operador de asignacion");}
        ;

operador_asignacion : DOSPUNTOSIGUAL
	| MENOSIGUAL
	;

asignacion_izq : ID	{addProgramComponent("asignacion izq = id");}
        | celda		{addProgramComponent("asignacion izq = celda");}
        ;

expresion : expresion '+' termino	{addProgramComponent("expresion = expresion mas termino");}
        | expresion '-' termino		{addProgramComponent("expresion = expresion menos termino");}
        | termino		{addProgramComponent("expresion = termino");}
        ;

termino : termino '*' factor	{addProgramComponent("termino = termino por factor");}
        | termino '/' factor	{addProgramComponent("termino = termino dividido factor");}
        | factor		{addProgramComponent("termino = factor");}
        ;

factor : ID	{addProgramComponent("factor = id");}
        | CTE	{addProgramComponent("factor = cte");}
        | celda	{addProgramComponent("factor = celda");}
        ;

celda : ID corchetes_expresion corchetes_expresion	{addProgramComponent("celda = id + expresion x2, cada una entre corchetes");}
//		| ID error expresion ']' '[' expresion ']'	{addProgramComponent("error en celda = falta corchete '[' en 1er dimension");}
//		| ID '[' expresion error '[' expresion ']'	{addProgramComponent("error en celda = falta corchete ']' en 1er dimension");}
//		| ID '[' error ']' '[' expresion ']'	{addProgramComponent("error en celda = falta expresion en 1er dimension");}
//		| ID '[' expresion ']' error expresion ']'	{addProgramComponent("error en celda = falta corchete '[' en 2da dimension");}
//		| ID '[' expresion ']' '[' error ']'	{addProgramComponent("error en celda = falta corchete ']' en 2da dimension");}
//		| ID '[' expresion ']' '[' expresion error	{addProgramComponent("error en celda = falta expresion en 2da dimension");}
        ;

corchetes_expresion :  '[' expresion ']' {addProgramComponent("corchetes_expresion = expresion entre corchetes");}
//		| error expresion ']' {addProgramComponent("error en corchetes_expresion = falta '['");}
//		| '[' expresion error {addProgramComponent("error en corchetes_expresion = falta ']'");}
//		| '[' error ']' {addProgramComponent("error en corchetes_expresion = error con la expresion");}
		;

iteracion : WHILE parentesis_condicion bloque_de_sentencias {addProgramComponent("Sentencia WHILE");}
        ;

impresion : PRINT '(' CADENA ')' {addProgramComponent("Impresion por pantalla");}
	| PRINT '(' error ')'  {addProgramComponent("error de impresion por pantalla: falta cadena");}
	| PRINT CADENA ')'  {addProgramComponent("error de impresion por pantalla: falta parentesis '('");}
	| PRINT '(' CADENA   {addProgramComponent("error de impresion por pantalla: falta parentesis ')'");}
	| PRINT CADENA   {addProgramComponent("error de impresion por pantalla: faltan ambos parentesis");}
        ;
