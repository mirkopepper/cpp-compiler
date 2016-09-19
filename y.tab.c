#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
#define YYPREFIX "yy"
#define CTE 257
#define MAYORIGUAL 258
#define MENORIGUAL 259
#define DISTINTO 260
#define DOSPUNTOSIGUAL 261
#define MENOSIGUAL 262
#define CADENA 263
#define ARROBA_F 264
#define ARROBA_C 265
#define ID 266
#define IF 267
#define ELSE 268
#define ENDIF 269
#define PRINT 270
#define INTEGER 271
#define DOUBLE 272
#define MATRIX 273
#define WHILE 274
#define ALLOW 275
#define TO 276
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    0,    1,    1,    3,    3,    3,    4,    4,
    4,    5,    5,    5,    5,    5,    7,    7,    8,    8,
    8,    6,    6,    9,   10,   10,   10,   12,   12,   11,
   13,   13,   14,   14,    2,    2,   15,   15,   15,   15,
   15,   16,   16,   16,   21,   21,   20,   20,   20,   20,
   22,   22,   22,   22,   24,   24,   24,   24,   24,   24,
   17,   17,   17,   17,   17,   26,   26,   25,   25,   23,
   23,   23,   28,   28,   28,   29,   29,   29,   27,   30,
   18,   19,   19,   19,   19,   19,
};
short yylen[] = {                                         2,
    4,    3,    3,    2,    1,    1,    1,    1,    3,    3,
    4,    5,    5,    5,    5,    5,    1,    1,    3,    3,
    1,    6,    6,    3,    2,    2,    3,    1,    1,    3,
    3,    1,    3,    1,    2,    1,    1,    1,    1,    2,
    1,    6,    5,    4,    1,    3,    3,    2,    2,    1,
    3,    3,    3,    3,    1,    1,    1,    1,    1,    1,
    4,    3,    5,    4,    3,    1,    1,    1,    1,    3,
    3,    1,    3,    3,    1,    1,    1,    1,    3,    3,
    3,    4,    4,    3,    3,    2,
};
short yydefred[] = {                                      0,
    0,   18,   17,    0,    0,    0,    5,    6,    7,    8,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    4,   36,   37,   38,   39,    0,    0,   69,    0,   21,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   77,
    0,    0,    0,    0,    0,   78,    0,   75,    0,    0,
    0,    0,    2,   35,   40,    0,   66,   67,    0,   10,
    0,    0,    0,    9,    0,    0,    0,    0,    0,    0,
    0,   79,   58,   57,   60,   55,   56,   59,    0,    0,
    0,   45,    0,   48,    0,    0,    0,    0,    0,    0,
   84,    0,    0,   81,    1,   65,    0,    0,    0,    0,
   11,   20,   19,   13,   14,   15,   16,   12,   80,    0,
   47,    0,    0,   44,    0,    0,    0,    0,   54,    0,
   73,   74,   83,   82,   64,    0,   61,    0,    0,   46,
    0,   43,   63,   24,    0,    0,   22,    0,   42,   34,
    0,    0,   29,   28,   26,    0,   30,    0,    0,   27,
    0,   33,
};
short yydgoto[] = {                                       5,
    6,   20,    7,    8,    9,   10,   11,   32,  100,  137,
  138,  145,  141,  142,   82,   23,   24,   25,   26,   43,
   83,   44,   45,   79,   27,   59,   46,   47,   48,   38,
};
short yysindex[] = {                                   -222,
 -199,    0,    0, -197,    0, -111,    0,    0,    0,    0,
 -235, -254, -187, -240,  -14,  -38,  -37,  -38,  -59,   28,
    0,    0,    0,    0,    0,   20,  -90,    0,   59,    0,
 -212,  -35, -199, -199, -199, -136, -229,  -14,  -54,    0,
  -14, -231, -123,   80,   -4,    0,    5,    0,   82, -223,
 -123,  133,    0,    0,    0,   66,    0,    0, -158,    0,
   36,   73, -122,    0, -114,   99,  108,  110,  123,  134,
   22,    0,    0,    0,    0,    0,    0,    0, -229,  156,
  -59,    0,  127,    0, -229, -229, -229, -117, -229, -229,
    0,  157,  158,    0,    0,    0,  141,  -32,  -83,   36,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   58,
    0,  138, -123,    0,  -67,   58,    5,    5,    0,   58,
    0,    0,    0,    0,    0,  150,    0,  117,  -42,    0,
  -57,    0,    0,    0,  -44,  -87,    0,  161,    0,    0,
  -55,  173,    0,    0,    0,  -87,    0,  -44,  -28,    0,
  173,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -71,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  100,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    1,    0,    0,   10,    0,    0,   23,    0,   78,    0,
    0,  222,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   50,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   91,    0,    0,    0,    0,  109,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -31,
    0,    0,    0,    0,    0,  -26,   45,   69,    0,  -21,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -91,    0,    0,    0,    0,
    0,  -30,    0,    0,    0,  115,    0,    0,    0,    0,
  -29,    0,
};
short yygindex[] = {                                      0,
    0,   -5,  221,    0,    0,    0,  153,    0,  130,    0,
    0,   87,    0,   89,   -1,    0,    0,    0,    0,  224,
    4,  205,   34,  206,    0,    0,  396,   55,  106,  226,
};
#define YYTABLESIZE 509
short yytable[] = {                                      81,
   76,   42,   50,  148,   22,   76,   78,   77,   65,   52,
   86,   19,   87,   52,   53,   35,  136,   22,   54,   51,
   29,   33,   72,   64,   39,   40,  127,   40,   32,   31,
   30,   23,   92,    1,   41,   36,   41,   31,   86,   93,
   87,   76,   76,   76,   70,   76,   89,   76,    2,    3,
   54,   90,    4,   61,   94,   76,   78,   77,   13,   76,
   76,   76,   76,   72,   86,   72,   87,   72,   71,  147,
   71,    2,    3,    2,    3,  112,   37,   86,   55,   22,
  135,   72,   72,   72,   72,   70,  115,   70,   34,   70,
   85,   52,   98,   76,   32,   31,   53,   97,   40,   41,
   86,   51,   87,   70,   70,   70,   70,   41,   62,   71,
   54,   71,  110,   71,  109,   72,  131,   60,  116,   69,
   84,  120,   91,   76,   96,   76,   99,   71,   71,   71,
   71,  101,   50,  102,    2,    3,   86,   70,  119,   40,
  117,  118,   15,   16,    1,   72,   17,   72,   41,   85,
   18,  103,   53,   12,   15,   16,   14,  104,   17,    2,
    3,   71,   18,    4,   23,   56,  105,   70,  106,   70,
   57,   58,   49,  128,   23,   23,  143,  144,   23,   23,
   23,  107,   23,   23,   68,   66,   67,   68,   70,   68,
   68,   71,  108,   71,  121,  122,  111,  123,  124,  125,
   86,  132,   86,   73,   74,   75,   15,   16,  133,  134,
   17,  139,  140,   85,   18,   85,  149,   39,   40,  146,
   62,    3,   41,  126,   41,   49,   21,   41,  152,  129,
   63,   62,  150,   62,   52,   52,  151,   25,   52,   53,
   53,   51,   52,   53,   51,   51,   80,   53,   51,   81,
   88,   85,   51,   73,   74,   75,   76,   95,   76,   76,
   76,    0,  130,   72,    0,    0,   76,   76,   76,   76,
   76,    0,    0,    0,   76,   50,   50,    0,   72,   50,
   72,   72,   72,   50,    0,    0,    0,    0,   72,   72,
   72,   72,   72,   15,   16,    0,   72,   17,    0,    0,
   70,   18,   70,   70,   70,    0,    0,    0,    0,    0,
   70,   70,   70,   70,   70,   49,   49,    0,   70,   49,
    0,    0,    0,   49,   71,    0,   71,   71,   71,    0,
    0,    0,    0,    0,   71,   71,   71,   71,   71,    0,
    0,    0,   71,   86,   86,   86,   86,   86,    0,    0,
    0,   86,    0,    0,    0,    0,   85,   85,   85,   85,
   85,    0,    0,    0,   85,   41,   41,   41,   41,   41,
   25,    0,    0,   41,   62,   62,   62,   62,   62,    0,
   25,   25,   62,    0,   25,   25,   25,    0,   25,   25,
    0,    0,   15,   16,  113,  114,   17,    0,   15,   16,
   18,   28,   17,   15,   16,    0,   18,   17,    0,    0,
    0,   18,    0,    0,   28,   28,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   28,    0,
    0,    0,    0,    0,    0,    0,   28,   28,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   28,    0,   28,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   28,   28,
};
short yycheck[] = {                                     123,
    0,   40,   40,   59,    6,   60,   61,   62,   44,   41,
   43,  123,   45,   19,   41,  256,   59,   19,   20,   41,
  256,  276,    0,   59,  256,  257,   59,  257,   59,   59,
  266,  123,  256,  256,  266,  276,  266,  273,   43,  263,
   45,   41,   42,   43,    0,   45,   42,   47,  271,  272,
   52,   47,  275,  266,   51,   60,   61,   62,  256,   59,
   60,   61,   62,   41,   43,   43,   45,   45,    0,  125,
   37,  271,  272,  271,  272,   81,   91,    0,   59,   81,
  123,   59,   60,   61,   62,   41,   83,   43,  276,   45,
    0,  123,   59,   93,  125,  125,  123,  256,  257,    0,
   43,  123,   45,   59,   60,   61,   62,  266,    0,   41,
  112,   43,   79,   45,   93,   93,  113,   59,   85,  256,
   41,   88,   41,  123,   59,  125,   91,   59,   60,   61,
   62,   59,  123,  256,  271,  272,   59,   93,  256,  257,
   86,   87,  266,  267,  256,  123,  270,  125,  266,   59,
  274,  266,  125,    1,  266,  267,    4,   59,  270,  271,
  272,   93,  274,  275,  256,  256,   59,  123,   59,  125,
  261,  262,  123,  257,  266,  267,  264,  265,  270,  271,
  272,   59,  274,  275,  256,   33,   34,   35,   36,  261,
  262,  123,   59,  125,   89,   90,   41,   41,   41,   59,
  123,  269,  125,  258,  259,  260,  266,  267,   59,   93,
  270,  269,  257,  123,  274,  125,   44,  256,  257,   59,
  256,    0,  123,  256,  125,  263,    6,  266,  257,  100,
  266,  123,  146,  125,  266,  267,  148,  123,  270,  266,
  267,   18,  274,  270,  266,  267,   42,  274,  270,  123,
   45,  256,  274,  258,  259,  260,  256,  125,  258,  259,
  260,   -1,  125,   38,   -1,   -1,  266,  267,  268,  269,
  270,   -1,   -1,   -1,  274,  266,  267,   -1,  256,  270,
  258,  259,  260,  274,   -1,   -1,   -1,   -1,  266,  267,
  268,  269,  270,  266,  267,   -1,  274,  270,   -1,   -1,
  256,  274,  258,  259,  260,   -1,   -1,   -1,   -1,   -1,
  266,  267,  268,  269,  270,  266,  267,   -1,  274,  270,
   -1,   -1,   -1,  274,  256,   -1,  258,  259,  260,   -1,
   -1,   -1,   -1,   -1,  266,  267,  268,  269,  270,   -1,
   -1,   -1,  274,  266,  267,  268,  269,  270,   -1,   -1,
   -1,  274,   -1,   -1,   -1,   -1,  266,  267,  268,  269,
  270,   -1,   -1,   -1,  274,  266,  267,  268,  269,  270,
  256,   -1,   -1,  274,  266,  267,  268,  269,  270,   -1,
  266,  267,  274,   -1,  270,  271,  272,   -1,  274,  275,
   -1,   -1,  266,  267,  268,  269,  270,   -1,  266,  267,
  274,    6,  270,  266,  267,   -1,  274,  270,   -1,   -1,
   -1,  274,   -1,   -1,   19,   20,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   43,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   51,   52,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   81,   -1,   83,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  112,  113,
};
#define YYFINAL 5
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 276
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,
"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,"CTE","MAYORIGUAL","MENORIGUAL","DISTINTO",
"DOSPUNTOSIGUAL","MENOSIGUAL","CADENA","ARROBA_F","ARROBA_C","ID","IF","ELSE",
"ENDIF","PRINT","INTEGER","DOUBLE","MATRIX","WHILE","ALLOW","TO",
};
char *yyrule[] = {
"$accept : programa",
"programa : bloque_declarativo '{' bloque_ejecutable '}'",
"programa : bloque_declarativo bloque_ejecutable '}'",
"programa : bloque_declarativo '{' bloque_ejecutable",
"bloque_declarativo : bloque_declarativo sentencia_declarativa",
"bloque_declarativo : sentencia_declarativa",
"sentencia_declarativa : variable",
"sentencia_declarativa : conversion",
"sentencia_declarativa : arreglo",
"variable : tipo lista_id ';'",
"variable : tipo error ';'",
"variable : tipo lista_id error ';'",
"conversion : ALLOW tipo TO tipo ';'",
"conversion : error tipo TO tipo ';'",
"conversion : ALLOW error TO tipo ';'",
"conversion : ALLOW tipo error tipo ';'",
"conversion : ALLOW tipo TO error ';'",
"tipo : DOUBLE",
"tipo : INTEGER",
"lista_id : lista_id ',' ID",
"lista_id : lista_id ID error",
"lista_id : ID",
"arreglo : tipo MATRIX ID corchetes_cte corchetes_cte opcional_arreglo",
"arreglo : tipo MATRIX ID corchetes_cte corchetes_cte ';'",
"corchetes_cte : '[' CTE ']'",
"opcional_arreglo : inicializacion ';'",
"opcional_arreglo : ';' anotacion",
"opcional_arreglo : inicializacion ';' anotacion",
"anotacion : ARROBA_C",
"anotacion : ARROBA_F",
"inicializacion : '{' lista_de_listas '}'",
"lista_de_listas : lista_de_listas ';' lista_valores",
"lista_de_listas : lista_valores",
"lista_valores : lista_valores ',' CTE",
"lista_valores : CTE",
"bloque_ejecutable : bloque_ejecutable sentencia",
"bloque_ejecutable : sentencia",
"sentencia : seleccion",
"sentencia : asignacion",
"sentencia : iteracion",
"sentencia : impresion ';'",
"sentencia : impresion",
"seleccion : IF parentesis_condicion bloque_de_sentencias ELSE bloque_de_sentencias ENDIF",
"seleccion : IF parentesis_condicion bloque_de_sentencias bloque_de_sentencias ENDIF",
"seleccion : IF parentesis_condicion bloque_de_sentencias ENDIF",
"bloque_de_sentencias : sentencia",
"bloque_de_sentencias : '{' bloque_ejecutable '}'",
"parentesis_condicion : '(' condicion ')'",
"parentesis_condicion : condicion ')'",
"parentesis_condicion : '(' condicion",
"parentesis_condicion : condicion",
"condicion : expresion comparador expresion",
"condicion : error comparador expresion",
"condicion : expresion error expresion",
"condicion : expresion comparador error",
"comparador : '<'",
"comparador : '>'",
"comparador : MENORIGUAL",
"comparador : MAYORIGUAL",
"comparador : '='",
"comparador : DISTINTO",
"asignacion : asignacion_izq operador_asignacion expresion ';'",
"asignacion : asignacion_izq operador_asignacion expresion",
"asignacion : asignacion_izq operador_asignacion expresion error ';'",
"asignacion : asignacion_izq operador_asignacion error ';'",
"asignacion : asignacion_izq error ';'",
"operador_asignacion : DOSPUNTOSIGUAL",
"operador_asignacion : MENOSIGUAL",
"asignacion_izq : ID",
"asignacion_izq : celda",
"expresion : expresion '+' termino",
"expresion : expresion '-' termino",
"expresion : termino",
"termino : termino '*' factor",
"termino : termino '/' factor",
"termino : factor",
"factor : ID",
"factor : CTE",
"factor : celda",
"celda : ID corchetes_expresion corchetes_expresion",
"corchetes_expresion : '[' expresion ']'",
"iteracion : WHILE parentesis_condicion bloque_de_sentencias",
"impresion : PRINT '(' CADENA ')'",
"impresion : PRINT '(' error ')'",
"impresion : PRINT CADENA ')'",
"impresion : PRINT '(' CADENA",
"impresion : PRINT CADENA",
};
#endif
#ifndef YYSTYPE
typedef int YYSTYPE;
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 1:
#line 4 "grammar.y"
{addProgramComponent("Dectecto un programa!!");}
break;
case 2:
#line 5 "grammar.y"
{addProgramComponent("error: falta llave de inicio. Programa Compilado!");}
break;
case 3:
#line 6 "grammar.y"
{addProgramComponent("error: falta llave de cierre. Programa Compilado!");}
break;
case 4:
#line 9 "grammar.y"
{addProgramComponent("bloque declarativo=bloque declarativo + setencia declarativa");}
break;
case 5:
#line 10 "grammar.y"
{addProgramComponent("bloque declarativo = sentencia declarativa");}
break;
case 6:
#line 13 "grammar.y"
{addProgramComponent("setencia declarativa = variable");}
break;
case 7:
#line 14 "grammar.y"
{addProgramComponent("sentencia declaratica = conversion");}
break;
case 8:
#line 15 "grammar.y"
{addProgramComponent("sentencia declarativo = arreglo");}
break;
case 9:
#line 18 "grammar.y"
{addProgramComponent("variable = tipo + lista ids");}
break;
case 10:
#line 19 "grammar.y"
{addProgramComponent("error de declaracion de variables: lista de identificadores mal esrita");}
break;
case 11:
#line 20 "grammar.y"
{addProgramComponent("error de declaracion de variables: falta ';'");}
break;
case 12:
#line 23 "grammar.y"
{addProgramComponent("Conversion entre variables");}
break;
case 13:
#line 24 "grammar.y"
{addProgramComponent("Error de declaracion de conversion: palabra allow mal escrita");}
break;
case 14:
#line 25 "grammar.y"
{addProgramComponent("Error de declaracion de conversion: falta tipo entre allow y to");}
break;
case 15:
#line 26 "grammar.y"
{addProgramComponent("Error de declaracion de conversion; palabra to mal escrita");}
break;
case 16:
#line 27 "grammar.y"
{addProgramComponent("Error de declaracion de conversion: falta tipo despues del to");}
break;
case 17:
#line 30 "grammar.y"
{addProgramComponent("tipo double");}
break;
case 18:
#line 31 "grammar.y"
{addProgramComponent("tipo integer");}
break;
case 19:
#line 34 "grammar.y"
{addProgramComponent("lista ids = lista ids + id");}
break;
case 20:
#line 35 "grammar.y"
{addProgramComponent("antes del identificador tiene que ir una coma.");}
break;
case 21:
#line 36 "grammar.y"
{addProgramComponent("lista ids = id");}
break;
case 22:
#line 39 "grammar.y"
{addProgramComponent("arreglo = tipo matrix id dimensiones opcional arreglo");}
break;
case 23:
#line 40 "grammar.y"
{addProgramComponent("Declaracion de matriz");}
break;
case 24:
#line 44 "grammar.y"
{addProgramComponent("corchetes_cte = cte entre corchetes");}
break;
case 25:
#line 47 "grammar.y"
{addProgramComponent("Declaracion e inicializacion de matriz");}
break;
case 26:
#line 48 "grammar.y"
{addProgramComponent("Declaracion y anotacion de matriz");}
break;
case 27:
#line 49 "grammar.y"
{addProgramComponent("Declaracion, inicializacion y anotacion de matriz");}
break;
case 28:
#line 52 "grammar.y"
{addProgramComponent("anotacion c");}
break;
case 29:
#line 53 "grammar.y"
{addProgramComponent("anotacion f");}
break;
case 30:
#line 56 "grammar.y"
{addProgramComponent("inicializacion = lista de listas entre corchetes");}
break;
case 31:
#line 59 "grammar.y"
{addProgramComponent("lista de listas = lista de listas + puntocoma + lista valores");}
break;
case 32:
#line 60 "grammar.y"
{addProgramComponent("lista de listas = lista valores");}
break;
case 33:
#line 63 "grammar.y"
{addProgramComponent("lista valores = lista valores + coma + cte");}
break;
case 34:
#line 64 "grammar.y"
{addProgramComponent("lista valores = cte");}
break;
case 35:
#line 67 "grammar.y"
{addProgramComponent("bloque ejecutable = bloque ejecutable + sentencia");}
break;
case 36:
#line 68 "grammar.y"
{addProgramComponent("bloque ejecutable = sentencia");}
break;
case 37:
#line 71 "grammar.y"
{addProgramComponent("sentencia = seleccion");}
break;
case 38:
#line 72 "grammar.y"
{addProgramComponent("sentencia = asignacion");}
break;
case 39:
#line 73 "grammar.y"
{addProgramComponent("sentencia = iteracion");}
break;
case 40:
#line 74 "grammar.y"
{addProgramComponent("sentecia = impresion");}
break;
case 41:
#line 75 "grammar.y"
{addProgramComponent("ERRRORsentecia = impresion");}
break;
case 42:
#line 78 "grammar.y"
{addProgramComponent("Sentencia IF con bloque ELSE");}
break;
case 43:
#line 79 "grammar.y"
{addProgramComponent("error en sentencia IF: falta else");}
break;
case 44:
#line 80 "grammar.y"
{addProgramComponent("Sentencia IF sin bloque ELSE");}
break;
case 45:
#line 83 "grammar.y"
{addProgramComponent("bloque sentencias = sentencia");}
break;
case 46:
#line 84 "grammar.y"
{addProgramComponent("bloque sentencias = bloque ejecutable entre llaves");}
break;
case 47:
#line 87 "grammar.y"
{addProgramComponent("parentesis_condicion = condicion entre parentesis");}
break;
case 48:
#line 88 "grammar.y"
{addProgramComponent("error en parentesis_condicion: falta '('");}
break;
case 49:
#line 89 "grammar.y"
{addProgramComponent("error en parentesis_condicion: ')' ");}
break;
case 50:
#line 90 "grammar.y"
{addProgramComponent("error en parentesis_condicion: faltan ambos parentesis ");}
break;
case 51:
#line 93 "grammar.y"
{addProgramComponent("condicion = comparacion de expresiones");}
break;
case 52:
#line 94 "grammar.y"
{addProgramComponent("error en condicion: problema con expresion del lado izquierdo");}
break;
case 53:
#line 95 "grammar.y"
{addProgramComponent("error en condicion: problema con el comparador");}
break;
case 54:
#line 96 "grammar.y"
{addProgramComponent("error en condicion: problema con expresion del lado derecho");}
break;
case 55:
#line 99 "grammar.y"
{addProgramComponent("comparador = menor");}
break;
case 56:
#line 100 "grammar.y"
{addProgramComponent("comparador = mayor");}
break;
case 57:
#line 101 "grammar.y"
{addProgramComponent("comparador = menor igual");}
break;
case 58:
#line 102 "grammar.y"
{addProgramComponent("comparador = mayor igual");}
break;
case 59:
#line 103 "grammar.y"
{addProgramComponent("comparador = igual");}
break;
case 60:
#line 104 "grammar.y"
{addProgramComponent("comparador = distinto");}
break;
case 61:
#line 107 "grammar.y"
{addProgramComponent("Asignacion");}
break;
case 62:
#line 108 "grammar.y"
{addProgramComponent("Error en asignacion:falta el ';'");}
break;
case 63:
#line 109 "grammar.y"
{addProgramComponent("Error en asignacion:problema con asignacion");}
break;
case 64:
#line 110 "grammar.y"
{addProgramComponent("Error en asignacioN:problema con la expresion del lado derecho");}
break;
case 65:
#line 111 "grammar.y"
{addProgramComponent("Error en asignacion:falta el operador de asignacion");}
break;
case 68:
#line 118 "grammar.y"
{addProgramComponent("asignacion izq = id");}
break;
case 69:
#line 119 "grammar.y"
{addProgramComponent("asignacion izq = celda");}
break;
case 70:
#line 122 "grammar.y"
{addProgramComponent("expresion = expresion mas termino");}
break;
case 71:
#line 123 "grammar.y"
{addProgramComponent("expresion = expresion menos termino");}
break;
case 72:
#line 124 "grammar.y"
{addProgramComponent("expresion = termino");}
break;
case 73:
#line 127 "grammar.y"
{addProgramComponent("termino = termino por factor");}
break;
case 74:
#line 128 "grammar.y"
{addProgramComponent("termino = termino dividido factor");}
break;
case 75:
#line 129 "grammar.y"
{addProgramComponent("termino = factor");}
break;
case 76:
#line 132 "grammar.y"
{addProgramComponent("factor = id");}
break;
case 77:
#line 133 "grammar.y"
{addProgramComponent("factor = cte");}
break;
case 78:
#line 134 "grammar.y"
{addProgramComponent("factor = celda");}
break;
case 79:
#line 137 "grammar.y"
{addProgramComponent("celda = id + expresion x2, cada una entre corchetes");}
break;
case 80:
#line 146 "grammar.y"
{addProgramComponent("corchetes_expresion = expresion entre corchetes");}
break;
case 81:
#line 152 "grammar.y"
{addProgramComponent("Sentencia WHILE");}
break;
case 82:
#line 155 "grammar.y"
{addProgramComponent("Impresion por pantalla");}
break;
case 83:
#line 156 "grammar.y"
{addProgramComponent("error de impresion por pantalla: falta cadena");}
break;
case 84:
#line 157 "grammar.y"
{addProgramComponent("error de impresion por pantalla: falta parentesis '('");}
break;
case 85:
#line 158 "grammar.y"
{addProgramComponent("error de impresion por pantalla: falta parentesis ')'");}
break;
case 86:
#line 159 "grammar.y"
{addProgramComponent("error de impresion por pantalla: faltan ambos parentesis");}
break;
#line 835 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
