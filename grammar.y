%token CTE MAYORIGUAL MENORIGUAL DISTINTO DOSPUNTOSIGUAL MENOSIGUAL CADENA ARROBA_F ARROBA_C ID IF ELSE ENDIF PRINT INTEGER DOUBLE MATRIX WHILE ALLOW TO

%%
programa : bloque_declarativo '{' bloque_ejecutable '}'
        ;

bloque_declarativo : bloque_declarativo sentencia_declarativa
        | sentencia_declarativa
        ;

sentencia_declarativa : variable
        | conversion
        | arreglo
        ;

variable : tipo lista_id ';' {addRule("Declaracion de variable/s");}
        ;

conversion : ALLOW tipo TO tipo ';' {addRule("Conversion entre variables");}
        ;

tipo : DOUBLE
        | INTEGER
        ;

lista_id : lista_id ',' ID
        | ID
        ;

arreglo : tipo MATRIX ID dimensiones opcional_arreglo ';'
        | tipo MATRIX ID dimensiones ';'    {addRule("Declaracion de matriz");}
        | tipo ID
        ;

dimensiones : dimension dimension
        ;

dimension : '[' CTE ']'
        ;

opcional_arreglo : inicializacion anotacion {addRule("Declaracion, inicializacion y anotacion de matriz");}
        | inicializacion    {addRule("Declaracion e inicializacion de matriz");}
        | anotacion     {addRule("Declaracion y anotacion de matriz");}
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
        | asignacion
        | iteracion
        | impresion
        ;

seleccion : IF '(' condicion ')' bloque_de_sentencias ELSE bloque_de_sentencias ENDIF {addRule("Sentencia IF con bloque ELSE");}
        | IF '(' condicion ')' bloque_de_sentencias ENDIF  {addRule("Sentencia IF sin bloque ELSE");}
        ;

bloque_de_sentencias : sentencia
        | '{' bloque_ejecutable '}'
        ;

condicion : expresion comparador expresion
        ;

comparador : '<'
        | '>'
        | MENORIGUAL
        | MAYORIGUAL
        | '='
        | DISTINTO
        ;

asignacion : asignacion_izq DOSPUNTOSIGUAL expresion ';' {addRule("Asignacion");}
        | asignacion_izq MENOSIGUAL expresion ';' {addRule("Asignacion con resta");}
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
        ;

iteracion : WHILE '(' condicion ')' bloque_de_sentencias {addRule("Sentencia WHILE");}
        ;

impresion : PRINT '(' CADENA ')' ';' {addRule("Impresion por pantalla");}
        ;
