%token CTE MAYORIGUAL MENORIGUAL DISTINTO DOSPUNTOSIGUAL MENOSIGUAL CADENA ARROBA_F ARROBA_C ID IF ELSE ENDIF PRINT INTEGER DOUBLE MATRIX WHILE ALLOW TO

%%
programa : bloque_declarativo '{' bloque_ejecutable '}' {addProgramComponent("Dectecto un programa!!");}
        ;

bloque_declarativo : bloque_declarativo sentencia_declarativa {addProgramComponent("bloque declarativo=bloque declarativo + setencia declarativa");}
        | sentencia_declarativa	{addProgramComponent("bloque declarativo = sentencia declarativa");}
        ;

sentencia_declarativa : variable	{addProgramComponent("setencia declarativa = variable");}
        | conversion	{addProgramComponent("sentencia declaratica = conversion");}
        | arreglo	{addProgramComponent("sentencia declarativo = arreglo");}
        ;

variable : tipo lista_id ';' {addProgramComponent("variable = tipo + lista ids");}
        ;

conversion : ALLOW tipo TO tipo ';' {addProgramComponent("Conversion entre variables");}
        ;

tipo : DOUBLE	{addProgramComponent("tipo double");}
        | INTEGER	{addProgramComponent("tipo integer");}
        ;

lista_id : lista_id ',' ID	{addProgramComponent("lista ids = lista ids + id");}
        | ID	{addProgramComponent("lista ids = id");}
        ;

arreglo : tipo MATRIX ID dimensiones opcional_arreglo	{addProgramComponent("arreglo = tipo matrix id dimensiones opcional arreglo");}
        | tipo MATRIX ID dimensiones ';'    {addProgramComponent("Declaracion de matriz");}
        ;

dimensiones : dimension dimension	{addProgramComponent("dimensiones = dimension + dimension");}
        ;

dimension : '[' CTE ']'	{addProgramComponent("dimension = cte entre corchetes");}
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
        | impresion	{addProgramComponent("sentecia = impresion");}
        ;

seleccion : IF '(' condicion ')' bloque_de_sentencias ELSE bloque_de_sentencias ENDIF {addProgramComponent("Sentencia IF con bloque ELSE");}
        | IF '(' condicion ')' bloque_de_sentencias ENDIF  {addProgramComponent("Sentencia IF sin bloque ELSE");}
        ;

bloque_de_sentencias : sentencia	{addProgramComponent("bloque sentencias = sentencia");}
        | '{' bloque_ejecutable '}'	{addProgramComponent("bloque sentencias = bloque ejecutable entre llaves");}
        ;

condicion : expresion comparador expresion	{addProgramComponent("condicion = comparacion de expresiones");}
        ;

comparador : '<'	{addProgramComponent("comparador = menor");}
        | '>'	{addProgramComponent("comparador = mayor");}
        | MENORIGUAL	{addProgramComponent("comparador = menor igual");}
        | MAYORIGUAL	{addProgramComponent("comparador = mayor igual");}
        | '='	{addProgramComponent("comparador = igual");}
        | DISTINTO	{addProgramComponent("comparador = distinto");}
        ;

asignacion : asignacion_izq DOSPUNTOSIGUAL expresion ';' {addProgramComponent("Asignacion");}
        | asignacion_izq MENOSIGUAL expresion ';' {addProgramComponent("Asignacion con resta");}
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

celda : ID '[' expresion ']' '[' expresion ']'	{addProgramComponent("celda = id + expresion x2, cada una entre corchetes");}
        ;

iteracion : WHILE '(' condicion ')' bloque_de_sentencias {addProgramComponent("Sentencia WHILE");}
        ;

impresion : PRINT '(' CADENA ')' ';' {addProgramComponent("Impresion por pantalla");}
        ;
