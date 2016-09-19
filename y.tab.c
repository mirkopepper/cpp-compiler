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
   15,   15,   16,   16,   16,   21,   21,   20,   20,   20,
   20,   22,   22,   22,   22,   24,   24,   24,   24,   24,
   24,   17,   17,   17,   17,   17,   26,   26,   25,   25,
   23,   23,   23,   28,   28,   28,   29,   29,   29,   27,
   27,   27,   27,   27,   27,   18,   19,   19,   19,   19,
   19,
};
short yylen[] = {                                         2,
    4,    3,    3,    2,    1,    1,    1,    1,    3,    3,
    4,    5,    5,    5,    5,    5,    1,    1,    3,    3,
    1,    6,    6,    3,    2,    2,    3,    1,    1,    3,
    3,    1,    3,    1,    2,    1,    1,    1,    2,    1,
    2,    1,    6,    5,    4,    1,    3,    3,    2,    2,
    1,    3,    3,    3,    3,    1,    1,    1,    1,    1,
    1,    3,    4,    3,    3,    3,    1,    1,    1,    1,
    3,    3,    1,    3,    3,    1,    1,    1,    1,    7,
    7,    6,    7,    7,    7,    3,    4,    4,    3,    3,
    2,
};
short yydefred[] = {                                      0,
    0,   18,   17,    0,    0,    0,    5,    6,    7,    8,
    0,    0,    0,    0,   67,   68,    0,    0,    0,    0,
    0,    0,    4,   36,   37,    0,   40,    0,    0,    0,
   70,    0,   21,    0,    0,    0,    0,    0,    0,    0,
    0,   78,    0,    0,    0,    0,    0,   79,    0,   76,
    0,    0,    0,    0,    2,   35,   39,   41,    0,    0,
    0,   10,    0,    0,    0,    9,    0,    0,    0,    0,
    0,    0,    0,    0,   59,   58,   61,   56,   57,   60,
    0,    0,    0,   46,    0,   49,    0,    0,    0,    0,
    0,    0,   89,    0,    0,   86,    1,   65,   64,    0,
   66,    0,    0,   11,   20,   19,   13,   14,   15,   16,
   12,    0,    0,    0,    0,   48,    0,    0,   45,    0,
    0,    0,    0,   55,    0,   74,   75,   88,   87,   63,
    0,    0,    0,    0,    0,    0,   47,    0,   44,   24,
    0,    0,   22,    0,   82,    0,    0,    0,    0,   43,
   34,    0,    0,   29,   28,   26,    0,   81,   83,   84,
   85,   80,   30,    0,    0,   27,    0,   33,
};
short yydgoto[] = {                                       5,
    6,   22,    7,    8,    9,   10,   11,   35,  103,  143,
  144,  156,  152,  153,   84,   25,   26,   27,   28,   45,
   85,   46,   47,   81,   29,   30,   48,   49,   50,
};
short yysindex[] = {                                   -131,
 -116,    0,    0, -220,    0,  171,    0,    0,    0,    0,
 -158, -257, -242, -227,    0,    0,  -26,  -38,  -40,  -38,
  -19,  259,    0,    0,    0,  -12,    0,   -9,  -62, -134,
    0,   14,    0, -190,  -41, -116, -116, -116, -154, -114,
  -49,    0,  -26,  -81,  -83,   38,  -29,    0,  107,    0,
   55, -143,  -83,  261,    0,    0,    0,    0,   92,  -68,
  -36,    0,   18,   60, -129,    0, -132,   77,   86,   88,
   94,   98,  -16,  -15,    0,    0,    0,    0,    0,    0,
 -134,  120,  -19,    0, -103,    0, -134, -134, -134,  -44,
 -134, -134,    0,  128,  136,    0,    0,    0,    0,  -35,
    0,  -71,   18,    0,    0,    0,    0,    0,    0,    0,
    0, -134,   90,  -76,   52,    0,  275,  -83,    0,  -79,
   52,  107,  107,    0,   52,    0,    0,    0,    0,    0,
  100,  -42,   -4, -134, -134,  -17,    0,  -37,    0,    0,
  -24,  -91,    0,  176,    0,   10,   29,  148,  -39,    0,
    0,  -54,  201,    0,    0,    0,  -91,    0,    0,    0,
    0,    0,    0,  -24,   -7,    0,  201,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -60,    0,    0,    0,
    0,    0,    0,    0,    0,  111,    0,  121,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    1,    0,    0,  228,    0,    0,   23,    0,
   80,    0,    0,  252,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  243,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   91,    0,    0,    0,    0,  101,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  131,    0,    0,    0,    0,    0,
  141,   45,   69,    0,  155,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  193,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -33,    0,    0,    0,  210,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -32,    0,
};
short yygindex[] = {                                      0,
    0,    4,  247,    0,    0,    0,   20,    0,  153,    0,
    0,  108,    0,  102,   16,    0,    0,    0,    0,  238,
  -18,  229,  514,  225,    0,  245,  485,  119,  146,
};
#define YYTABLESIZE 650
short yytable[] = {                                      52,
   77,   44,   67,   88,  164,   89,   88,   88,   89,   89,
   78,   80,   79,   88,  136,   89,  142,   66,   36,   83,
   12,   24,   73,   14,   54,   32,   31,   88,   38,   89,
   78,   80,   79,   37,   96,   13,   24,   56,   88,   83,
   89,   77,   77,   77,   71,   77,   57,   77,   39,   58,
    2,    3,   88,  162,   89,   68,   69,   70,   72,   77,
   77,   77,   77,   73,   40,   73,  120,   73,   72,   56,
  163,   88,   62,   89,  112,   63,  113,  114,   86,   91,
  141,   73,   73,   73,   73,   71,  117,   71,  145,   71,
   90,   32,   31,   77,   88,   93,   89,   32,   24,  138,
   62,   71,  158,   71,   71,   71,   71,   33,  102,   72,
   38,   72,   94,   72,   34,   73,    2,    3,  104,   95,
   42,  159,   42,   77,    1,   77,  105,   72,   72,   72,
   72,   43,   56,  106,   88,  107,   89,   71,   91,    2,
    3,   73,   42,    4,  108,   73,  109,   73,   91,   90,
   98,   43,  110,   92,    2,    3,  111,   15,   16,   62,
  116,   72,   17,   18,  118,  119,   19,   71,  128,   71,
   20,   53,  154,  155,   41,   42,  129,   15,   16,  135,
  134,   54,   17,   18,   43,  131,   19,   99,   42,  139,
   20,   72,  140,   72,   42,   52,   69,   43,   15,   16,
   69,   69,   91,   43,   91,   69,  122,  123,   75,   76,
   77,  124,   42,   90,   64,   90,  161,   41,   42,  101,
  130,   43,   51,   62,   65,   62,   87,   43,   75,   76,
   77,  150,  151,   38,  157,   38,  126,  127,  148,   42,
  160,   15,   16,   42,  165,   42,   17,   18,   43,  168,
   19,    3,   23,   53,   20,  132,   77,   53,   77,   77,
   77,   77,   77,   54,  166,  167,   77,   77,   77,   77,
   77,   90,   82,   60,   77,    0,    0,   52,   73,    0,
   73,   73,   73,   73,   73,    0,    0,    0,   73,   73,
   73,   73,   73,   21,    0,    0,   73,    0,    0,    0,
   71,    0,   71,   71,   71,   71,   71,    0,    0,    0,
   71,   71,   71,   71,   71,   23,    0,    0,   71,    0,
    0,    0,    0,    0,   72,    0,   72,   72,   72,   72,
   72,    0,   25,    0,   72,   72,   72,   72,   72,    0,
   91,   91,   72,    0,    0,   91,   91,   91,   91,   91,
   51,   90,   90,   91,    0,    0,   90,   90,   90,   90,
   90,   62,   62,    0,   90,   50,   62,   62,   62,   62,
   62,   38,   38,    0,   62,    0,   38,   38,   38,   38,
   38,   42,   42,   55,   38,   97,   42,   42,   42,   42,
   42,   53,   53,    0,   42,    0,   53,   53,    0,  137,
   53,   54,   54,    0,   53,    0,   54,   54,    0,    0,
   54,    0,    0,    0,   54,   52,   52,    0,    0,    0,
   52,   52,    0,    0,   52,    0,    1,    0,   52,    0,
    0,   15,   16,    0,    0,    0,   17,   18,    0,    0,
   19,    2,    3,    0,   20,    4,    0,    0,   23,    0,
    0,    0,    0,   23,   23,    0,    0,    0,   23,   23,
    0,    0,   23,   23,   23,   25,   23,   23,    0,    0,
   25,   25,    0,    0,    0,   25,   25,    0,    0,   25,
   25,   25,    0,   25,   25,    0,    0,    0,   51,   51,
   31,    0,    0,   51,   51,    0,    0,   51,    0,    0,
    0,   51,    0,   50,   50,   31,   31,    0,   50,   50,
    0,    0,   50,    0,    0,    0,   50,    0,    0,   15,
   16,   15,   16,    0,   17,   18,   17,   18,   19,   31,
   19,    0,   20,    0,   20,   15,   16,   31,   31,    0,
   17,   18,   59,   61,   19,    0,    0,    0,   20,    0,
    0,    0,    0,   74,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   31,    0,   31,
    0,    0,    0,  100,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  115,    0,    0,    0,    0,    0,
  121,   31,   31,  125,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  133,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  146,  147,  149,
};
short yycheck[] = {                                      40,
    0,   40,   44,   43,   59,   45,   43,   43,   45,   45,
   60,   61,   62,   43,   91,   45,   59,   59,  276,  123,
    1,    6,    0,    4,   21,   59,   59,   43,  256,   45,
   60,   61,   62,  276,   53,  256,   21,   22,   43,  123,
   45,   41,   42,   43,    0,   45,   59,   47,  276,   59,
  271,  272,   43,   93,   45,   36,   37,   38,   39,   59,
   60,   61,   62,   41,   91,   43,   85,   45,    0,   54,
  125,   43,   59,   45,   91,  266,   93,   93,   41,    0,
  123,   59,   60,   61,   62,   41,   83,   43,   93,   45,
    0,  125,  125,   93,   43,   41,   45,  256,   83,  118,
    0,  256,   93,   59,   60,   61,   62,  266,   91,   41,
    0,   43,  256,   45,  273,   93,  271,  272,   59,  263,
    0,   93,  257,  123,  256,  125,  256,   59,   60,   61,
   62,  266,  117,  266,   43,   59,   45,   93,   59,  271,
  272,  256,  257,  275,   59,  123,   59,  125,   42,   59,
   59,  266,   59,   47,  271,  272,   59,  261,  262,   59,
   41,   93,  266,  267,  268,  269,  270,  123,   41,  125,
  274,   41,  264,  265,  256,  257,   41,  261,  262,  256,
   91,   41,  266,  267,  266,  257,  270,  256,  257,  269,
  274,  123,   93,  125,  257,   41,  257,  266,  261,  262,
  261,  262,  123,  266,  125,  266,   88,   89,  258,  259,
  260,  256,  257,  123,  256,  125,  256,  256,  257,  256,
  256,  266,  263,  123,  266,  125,  256,  266,  258,  259,
  260,  269,  257,  123,   59,  125,   91,   92,  256,  257,
   93,  261,  262,  123,   44,  125,  266,  267,  266,  257,
  270,    0,    6,  123,  274,  103,  256,   20,  258,  259,
  260,  261,  262,  123,  157,  164,  266,  267,  268,  269,
  270,   47,   44,   29,  274,   -1,   -1,  123,  256,   -1,
  258,  259,  260,  261,  262,   -1,   -1,   -1,  266,  267,
  268,  269,  270,  123,   -1,   -1,  274,   -1,   -1,   -1,
  256,   -1,  258,  259,  260,  261,  262,   -1,   -1,   -1,
  266,  267,  268,  269,  270,  123,   -1,   -1,  274,   -1,
   -1,   -1,   -1,   -1,  256,   -1,  258,  259,  260,  261,
  262,   -1,  123,   -1,  266,  267,  268,  269,  270,   -1,
  261,  262,  274,   -1,   -1,  266,  267,  268,  269,  270,
  123,  261,  262,  274,   -1,   -1,  266,  267,  268,  269,
  270,  261,  262,   -1,  274,  123,  266,  267,  268,  269,
  270,  261,  262,   -1,  274,   -1,  266,  267,  268,  269,
  270,  261,  262,  125,  274,  125,  266,  267,  268,  269,
  270,  261,  262,   -1,  274,   -1,  266,  267,   -1,  125,
  270,  261,  262,   -1,  274,   -1,  266,  267,   -1,   -1,
  270,   -1,   -1,   -1,  274,  261,  262,   -1,   -1,   -1,
  266,  267,   -1,   -1,  270,   -1,  256,   -1,  274,   -1,
   -1,  261,  262,   -1,   -1,   -1,  266,  267,   -1,   -1,
  270,  271,  272,   -1,  274,  275,   -1,   -1,  256,   -1,
   -1,   -1,   -1,  261,  262,   -1,   -1,   -1,  266,  267,
   -1,   -1,  270,  271,  272,  256,  274,  275,   -1,   -1,
  261,  262,   -1,   -1,   -1,  266,  267,   -1,   -1,  270,
  271,  272,   -1,  274,  275,   -1,   -1,   -1,  261,  262,
    6,   -1,   -1,  266,  267,   -1,   -1,  270,   -1,   -1,
   -1,  274,   -1,  261,  262,   21,   22,   -1,  266,  267,
   -1,   -1,  270,   -1,   -1,   -1,  274,   -1,   -1,  261,
  262,  261,  262,   -1,  266,  267,  266,  267,  270,   45,
  270,   -1,  274,   -1,  274,  261,  262,   53,   54,   -1,
  266,  267,   29,   30,  270,   -1,   -1,   -1,  274,   -1,
   -1,   -1,   -1,   40,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   83,   -1,   85,
   -1,   -1,   -1,   60,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   81,   -1,   -1,   -1,   -1,   -1,
   87,  117,  118,   90,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  112,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  134,  135,  136,
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
"sentencia : asignacion ';'",
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
"asignacion : asignacion_izq operador_asignacion expresion",
"asignacion : asignacion_izq operador_asignacion expresion error",
"asignacion : asignacion_izq operador_asignacion error",
"asignacion : asignacion_izq expresion ';'",
"asignacion : operador_asignacion expresion error",
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
"celda : ID '[' expresion ']' '[' expresion ']'",
"celda : ID '[' error ']' '[' expresion ']'",
"celda : ID '[' error '[' expresion ']'",
"celda : ID '[' expresion ']' error expresion ']'",
"celda : ID '[' expresion ']' '[' error ']'",
"celda : ID '[' expresion ']' '[' expresion error",
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
{addErrorMessage("error: falta llave de inicio. Programa Compilado!");}
break;
case 3:
#line 6 "grammar.y"
{addErrorMessage("error: falta llave de cierre. Programa Compilado!");}
break;
case 9:
#line 18 "grammar.y"
{addProgramComponent("Declaracion de una variable");}
break;
case 10:
#line 19 "grammar.y"
{addErrorMessage("error de declaracion de variables: lista de identificadores mal esrita");}
break;
case 11:
#line 20 "grammar.y"
{addErrorMessage("error de declaracion de variables: falta ';'");}
break;
case 12:
#line 23 "grammar.y"
{addProgramComponent("Declaracion de conversion entre tipos");}
break;
case 13:
#line 24 "grammar.y"
{addErrorMessage("Error de declaracion de conversion: palabra allow mal escrita");}
break;
case 14:
#line 25 "grammar.y"
{addErrorMessage("Error de declaracion de conversion: falta tipo entre allow y to");}
break;
case 15:
#line 26 "grammar.y"
{addErrorMessage("Error de declaracion de conversion; palabra to mal escrita");}
break;
case 16:
#line 27 "grammar.y"
{addErrorMessage("Error de declaracion de conversion: falta tipo despues del to");}
break;
case 20:
#line 35 "grammar.y"
{addErrorMessage("antes del identificador tiene que ir una coma.");}
break;
case 23:
#line 40 "grammar.y"
{addProgramComponent("Declaracion de matriz");}
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
case 38:
#line 72 "grammar.y"
{addErrorMessage("error en sentencia = falta ';' en el final de la asignacion");}
break;
case 39:
#line 73 "grammar.y"
{addProgramComponent("sentencia de asignacion");}
break;
case 41:
#line 75 "grammar.y"
{addProgramComponent("sentecia de impresion");}
break;
case 42:
#line 76 "grammar.y"
{addErrorMessage("error en sentecia = falta ';' en el final de la impresion");}
break;
case 43:
#line 79 "grammar.y"
{addProgramComponent("Sentencia IF con bloque ELSE");}
break;
case 44:
#line 80 "grammar.y"
{addErrorMessage("error en sentencia IF: falta else");}
break;
case 45:
#line 81 "grammar.y"
{addProgramComponent("Sentencia IF sin bloque ELSE");}
break;
case 47:
#line 85 "grammar.y"
{addProgramComponent("bloque ejecutable entre llaves");}
break;
case 49:
#line 89 "grammar.y"
{addErrorMessage("error en parentesis_condicion: falta '('");}
break;
case 50:
#line 90 "grammar.y"
{addErrorMessage("error en parentesis_condicion: falta ')' ");}
break;
case 51:
#line 91 "grammar.y"
{addErrorMessage("error en parentesis_condicion: faltan ambos parentesis ");}
break;
case 53:
#line 95 "grammar.y"
{addErrorMessage("error en condicion: problema con expresion del lado izquierdo");}
break;
case 54:
#line 96 "grammar.y"
{addErrorMessage("error en condicion: problema con el comparador");}
break;
case 55:
#line 97 "grammar.y"
{addErrorMessage("error en condicion: problema con expresion del lado derecho");}
break;
case 63:
#line 109 "grammar.y"
{addErrorMessage("Error en asignacion:problema con asignacion");}
break;
case 64:
#line 110 "grammar.y"
{addErrorMessage("Error en asignacioN:problema con la expresion del lado derecho");}
break;
case 65:
#line 111 "grammar.y"
{addErrorMessage("Error en asignacion:falta el operador de asignacion");}
break;
case 66:
#line 112 "grammar.y"
{addErrorMessage("Error en asignacion:falta variable en lado derecho");}
break;
case 81:
#line 139 "grammar.y"
{addErrorMessage("error en celda: falta expresion en 1er dimension");}
break;
case 82:
#line 140 "grammar.y"
{addErrorMessage("error en celda: falta ']' en la 1er dimension");}
break;
case 83:
#line 141 "grammar.y"
{addErrorMessage("error en celda: falta '[' en la 2da dimension");}
break;
case 84:
#line 142 "grammar.y"
{addErrorMessage("error en celda: falta expresion en 2da dimension");}
break;
case 85:
#line 143 "grammar.y"
{addErrorMessage("error en celda: falta ']' en 2da dimension");}
break;
case 86:
#line 146 "grammar.y"
{addProgramComponent("Sentencia WHILE");}
break;
case 87:
#line 149 "grammar.y"
{addProgramComponent("Impresion por pantalla");}
break;
case 88:
#line 150 "grammar.y"
{addErrorMessage("error de impresion por pantalla: falta cadena");}
break;
case 89:
#line 151 "grammar.y"
{addErrorMessage("error de impresion por pantalla: falta parentesis '('");}
break;
case 90:
#line 152 "grammar.y"
{addErrorMessage("error de impresion por pantalla: falta parentesis ')'");}
break;
case 91:
#line 153 "grammar.y"
{addErrorMessage("error de impresion por pantalla: faltan ambos parentesis");}
break;
#line 717 "y.tab.c"
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
