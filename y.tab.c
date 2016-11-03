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
    8,    6,    9,   10,   10,   13,   10,   14,   10,   12,
   12,   11,   15,   15,   16,   16,    2,    2,   17,   17,
   17,   17,   17,   17,   18,   18,   18,   23,   23,   22,
   22,   22,   22,   24,   24,   24,   24,   26,   26,   26,
   26,   26,   26,   19,   19,   19,   19,   19,   28,   28,
   27,   27,   25,   25,   25,   30,   30,   30,   31,   31,
   31,   29,   29,   29,   29,   29,   29,   20,   21,   21,
   21,   21,   21,
};
short yylen[] = {                                         2,
    5,    4,    4,    2,    1,    1,    1,    1,    3,    3,
    4,    5,    5,    5,    5,    5,    1,    1,    3,    3,
    1,    5,    6,    1,    2,    0,    3,    0,    4,    1,
    1,    3,    3,    1,    3,    1,    2,    1,    1,    1,
    2,    1,    2,    1,    6,    5,    4,    1,    3,    3,
    2,    2,    1,    3,    3,    3,    3,    1,    1,    1,
    1,    1,    1,    3,    4,    3,    3,    3,    1,    1,
    1,    1,    3,    3,    1,    3,    3,    1,    1,    1,
    1,    7,    7,    6,    7,    7,    7,    3,    4,    4,
    3,    3,    2,
};
short yydefred[] = {                                      0,
    0,    0,    0,   18,   17,    0,    0,    5,    6,    7,
    8,    0,    0,    0,    0,   69,   70,    0,    0,    0,
    0,    0,    0,    4,   38,   39,    0,   42,    0,    0,
    0,   72,    0,   21,    0,    0,    0,    0,    0,    0,
    0,    0,   80,    0,    0,    0,    0,    0,   81,    0,
   78,    0,    0,    0,    0,    2,   37,   41,   43,    0,
    0,    0,   10,    0,    0,    0,    9,    0,    0,    0,
    0,    0,    0,    0,    0,   61,   60,   63,   58,   59,
   62,    0,    0,    0,   48,    0,   51,    0,    0,    0,
    0,    0,    0,   91,    0,    0,   88,    1,   67,   66,
    0,   68,    0,    0,   11,   20,   19,   13,   14,   15,
   16,   12,    0,    0,    0,    0,   50,    0,    0,   47,
    0,    0,    0,    0,   57,    0,   76,   77,   90,   89,
   65,    0,    0,    0,   22,    0,    0,    0,    0,    0,
   49,    0,   46,    0,   36,    0,    0,   31,   30,   26,
    0,   84,    0,    0,    0,    0,   45,    0,   32,    0,
    0,   27,   28,   83,   85,   86,   87,   82,    0,    0,
   35,   29,   23,
};
short yydgoto[] = {                                       2,
    7,   23,    8,    9,   10,   11,   12,   36,  104,  135,
  136,  150,  162,  172,  146,  147,   85,   26,   27,   28,
   29,   46,   86,   47,   48,   82,   30,   31,   49,   50,
   51,
};
short yysindex[] = {                                   -245,
 -199,    0, -176,    0,    0, -197,  171,    0,    0,    0,
    0, -215, -178, -174, -237,    0,    0,   22,  -38,  -40,
  -38,  -19,  259,    0,    0,    0,   56,    0,   77, -117,
 -110,    0,   96,    0, -123,  -41, -176, -176, -176, -137,
 -148,  -49,    0,   22, -134,  -83,  116,  -29,    0,   95,
    0,  120, -227,  -83,  261,    0,    0,    0,    0,   82,
  -81,  -36,    0,   78,  118,  -75,    0,  -80,  134,  138,
  147,  148,  149,  -26,  -15,    0,    0,    0,    0,    0,
    0, -110,  191,  -19,    0, -103,    0, -110, -110, -110,
  -68, -110, -110,    0,  192,  194,    0,    0,    0,    0,
  -35,    0,  -67,  -42,    0,    0,    0,    0,    0,    0,
    0,    0, -110,  146,  -76,   34,    0,  275,  -83,    0,
  -31,   34,   95,   95,    0,   34,    0,    0,    0,    0,
    0,  152,  -18, -230,    0,  181,    4, -110, -110,  -44,
    0,  -28,    0,  158,    0,  -54,  206,    0,    0,    0,
 -230,    0,    7,   10,  159,  -39,    0,   -4,    0,  -18,
   -1,    0,    0,    0,    0,    0,    0,    0,  165,  206,
    0,    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -62,    0,    0,
    0,    0,    0,    0,    0,    0,  111,    0,  121,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    1,    0,    0,  228,    0,    0,   23,
    0,   80,    0,    0,  265,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  243,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   91,    0,    0,    0,    0,
  101,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  131,    0,    0,    0,    0,
    0,  141,   45,   69,    0,  155,    0,    0,    0,    0,
    0,    0,    0,  193,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -33,    0,    0,    0,
  210,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -32,
    0,    0,    0,
};
short yygindex[] = {                                      0,
    0,    3,  266,    0,    0,    0,  114,    0,    0,    0,
    0,  115,    0,    0,    0,  112,   15,    0,    0,    0,
    0,  253,  -30,  231,  513,  229,    0,  250,  484,   84,
  109,
};
#define YYTABLESIZE 653
short yytable[] = {                                      53,
   79,   45,   68,   89,  160,   90,   89,   89,   90,   90,
   79,   81,   80,   89,  140,   90,  134,   67,   39,   84,
    1,   25,   75,   97,   55,   34,   33,   89,   95,   90,
   79,   81,   80,  148,  149,   96,   25,   57,   40,   84,
   33,   79,   79,   79,   73,   79,   89,   79,   90,   89,
   34,   90,   89,  168,   90,  121,    3,   35,   14,   79,
   79,   79,   79,   75,  113,   75,  114,   75,   74,   57,
  159,    4,    5,    4,    5,    6,   89,  115,   90,   93,
  133,   75,   75,   75,   75,   73,  118,   73,  142,   73,
   92,   34,   33,   79,    4,    5,  152,   37,   25,  164,
   64,   38,  165,   73,   73,   73,   73,   74,   43,   74,
   40,   74,   41,   74,   58,   75,   13,   44,   72,   15,
   44,   42,   43,   79,   89,   79,   90,   74,   74,   74,
   74,   44,   57,    4,    5,   59,   92,   73,   93,   43,
   99,   93,   64,   16,   17,   75,   43,   75,   44,   92,
   69,   70,   71,   73,   63,   44,   87,   16,   17,   64,
   94,   74,   18,   19,  119,  120,   20,   73,  103,   73,
   21,   55,  123,  124,  100,   43,  105,   16,   17,  139,
  106,   56,   18,   19,   44,  107,   20,  125,   43,  132,
   21,   74,  108,   74,   71,   54,  109,   44,   71,   71,
  127,  128,   93,   71,   93,  110,  111,  112,   76,   77,
   78,  155,   43,   92,   65,   92,  167,   42,   43,  102,
  131,   44,   52,   64,   66,   64,   88,   44,   76,   77,
   78,  117,  129,   40,  130,   40,  138,  143,  145,  151,
  157,   16,   17,   44,  144,   44,   18,   19,  158,  161,
   20,  166,  169,   55,   21,  171,   79,  173,   79,   79,
   79,   79,   79,   56,    3,  163,   79,   79,   79,   79,
   79,  170,   24,   54,   79,   83,   91,   54,   75,   61,
   75,   75,   75,   75,   75,    0,    0,    0,   75,   75,
   75,   75,   75,   22,    0,    0,   75,    0,    0,    0,
   73,    0,   73,   73,   73,   73,   73,    0,    0,    0,
   73,   73,   73,   73,   73,   24,    0,    0,   73,    0,
    0,    0,    0,    0,   74,    0,   74,   74,   74,   74,
   74,    0,   25,    0,   74,   74,   74,   74,   74,    0,
   93,   93,   74,    0,    0,   93,   93,   93,   93,   93,
   53,   92,   92,   93,    0,    0,   92,   92,   92,   92,
   92,   64,   64,    0,   92,   52,   64,   64,   64,   64,
   64,   40,   40,    0,   64,    0,   40,   40,   40,   40,
   40,   44,   44,   56,   40,   98,   44,   44,   44,   44,
   44,   55,   55,    0,   44,    0,   55,   55,    0,  141,
   55,   56,   56,    0,   55,    0,   56,   56,    0,    0,
   56,    0,    0,    0,   56,   54,   54,    0,    0,    0,
   54,   54,    0,    0,   54,    0,    3,    0,   54,    0,
    0,   16,   17,    0,    0,    0,   18,   19,    0,    0,
   20,    4,    5,    0,   21,    6,    0,    0,   24,    0,
    0,    0,    0,   24,   24,    0,    0,    0,   24,   24,
    0,    0,   24,   24,   24,   25,   24,   24,    0,    0,
   25,   25,    0,    0,    0,   25,   25,    0,    0,   25,
   25,   25,    0,   25,   25,    0,    0,    0,   53,   53,
   32,    0,    0,   53,   53,    0,    0,   53,    0,    0,
    0,   53,    0,   52,   52,   32,   32,    0,   52,   52,
    0,    0,   52,    0,    0,    0,   52,    0,    0,   16,
   17,   16,   17,    0,   18,   19,   18,   19,   20,   32,
   20,    0,   21,    0,   21,   16,   17,   32,   32,    0,
   18,   19,   60,   62,   20,    0,    0,    0,   21,    0,
    0,    0,    0,   75,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   32,    0,   32,
    0,    0,    0,  101,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  116,    0,    0,    0,    0,    0,
  122,   32,   32,  126,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  137,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  153,  154,  156,
};
short yycheck[] = {                                      40,
    0,   40,   44,   43,   59,   45,   43,   43,   45,   45,
   60,   61,   62,   43,   91,   45,   59,   59,  256,  123,
  266,    7,    0,   54,   22,   59,   59,   43,  256,   45,
   60,   61,   62,  264,  265,  263,   22,   23,  276,  123,
  256,   41,   42,   43,    0,   45,   43,   47,   45,   43,
  266,   45,   43,   93,   45,   86,  256,  273,  256,   59,
   60,   61,   62,   41,   91,   43,   93,   45,    0,   55,
  125,  271,  272,  271,  272,  275,   43,   93,   45,    0,
  123,   59,   60,   61,   62,   41,   84,   43,  119,   45,
    0,  125,  125,   93,  271,  272,   93,  276,   84,   93,
    0,  276,   93,   59,   60,   61,   62,  256,  257,   41,
    0,   43,   91,   45,   59,   93,    3,  266,  256,    6,
    0,  256,  257,  123,   43,  125,   45,   59,   60,   61,
   62,  266,  118,  271,  272,   59,   42,   93,   59,  257,
   59,   47,  266,  261,  262,  123,  257,  125,  266,   59,
   37,   38,   39,   40,   59,  266,   41,  261,  262,   59,
   41,   93,  266,  267,  268,  269,  270,  123,   91,  125,
  274,   41,   89,   90,  256,  257,   59,  261,  262,  256,
  256,   41,  266,  267,  266,  266,  270,  256,  257,  257,
  274,  123,   59,  125,  257,   41,   59,  266,  261,  262,
   92,   93,  123,  266,  125,   59,   59,   59,  258,  259,
  260,  256,  257,  123,  256,  125,  256,  256,  257,  256,
  256,  266,  263,  123,  266,  125,  256,  266,  258,  259,
  260,   41,   41,  123,   41,  125,   91,  269,  257,   59,
  269,  261,  262,  123,   93,  125,  266,  267,   91,   44,
  270,   93,  257,  123,  274,  257,  256,   93,  258,  259,
  260,  261,  262,  123,    0,  151,  266,  267,  268,  269,
  270,  160,    7,   21,  274,   45,   48,  123,  256,   30,
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
    7,   -1,   -1,  266,  267,   -1,   -1,  270,   -1,   -1,
   -1,  274,   -1,  261,  262,   22,   23,   -1,  266,  267,
   -1,   -1,  270,   -1,   -1,   -1,  274,   -1,   -1,  261,
  262,  261,  262,   -1,  266,  267,  266,  267,  270,   46,
  270,   -1,  274,   -1,  274,  261,  262,   54,   55,   -1,
  266,  267,   30,   31,  270,   -1,   -1,   -1,  274,   -1,
   -1,   -1,   -1,   41,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   84,   -1,   86,
   -1,   -1,   -1,   61,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   82,   -1,   -1,   -1,   -1,   -1,
   88,  118,  119,   91,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  113,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  138,  139,  140,
};
#define YYFINAL 2
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
"programa : ID bloque_declarativo '{' bloque_ejecutable '}'",
"programa : ID bloque_declarativo bloque_ejecutable '}'",
"programa : ID bloque_declarativo '{' bloque_ejecutable",
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
"arreglo : tipo MATRIX ID dimensiones_cte opcional_arreglo",
"dimensiones_cte : '[' CTE ']' '[' CTE ']'",
"opcional_arreglo : ';'",
"opcional_arreglo : inicializacion ';'",
"$$1 :",
"opcional_arreglo : ';' anotacion $$1",
"$$2 :",
"opcional_arreglo : inicializacion ';' anotacion $$2",
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
typedef string YYSTYPE;
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
#line 5 "grammar.y"
{addProgramComponent("Dectecto un programa!!");
                /*falta indicar que id se usa como nombre de programa*/
                }
break;
case 2:
#line 8 "grammar.y"
{addErrorMessage("error: falta llave de inicio. Programa Compilado!");}
break;
case 3:
#line 9 "grammar.y"
{addErrorMessage("error: falta llave de cierre. Programa Compilado!");}
break;
case 9:
#line 21 "grammar.y"
{addProgramComponent("Declaracion de una variable");}
break;
case 10:
#line 22 "grammar.y"
{addErrorMessage("error de declaracion de variables: lista de identificadores mal esrita");}
break;
case 11:
#line 23 "grammar.y"
{addErrorMessage("error de declaracion de variables: falta ';'");}
break;
case 12:
#line 26 "grammar.y"
{if (yyvsp[-3]=="DOUBLE" && yyvsp[-1]=="INTEGER") conversionsAllowed = true;}
break;
case 13:
#line 27 "grammar.y"
{addErrorMessage("Error de declaracion de conversion: palabra allow mal escrita");}
break;
case 14:
#line 28 "grammar.y"
{addErrorMessage("Error de declaracion de conversion: falta tipo entre allow y to");}
break;
case 15:
#line 29 "grammar.y"
{addErrorMessage("Error de declaracion de conversion; palabra to mal escrita");}
break;
case 16:
#line 30 "grammar.y"
{addErrorMessage("Error de declaracion de conversion: falta tipo despues del to");}
break;
case 17:
#line 33 "grammar.y"
{type="DOUBLE";}
break;
case 18:
#line 34 "grammar.y"
{type="INTEGER";}
break;
case 19:
#line 37 "grammar.y"
{declareVariable(yyvsp[0], "var@", type,"variable");}
break;
case 20:
#line 38 "grammar.y"
{addErrorMessage("antes del identificador tiene que ir una coma.");}
break;
case 21:
#line 39 "grammar.y"
{declareVariable(yyvsp[0], "var@", type,"variable");}
break;
case 22:
#line 43 "grammar.y"
{
                /*declarar matriz,guardar limites y forma de alinearse.Si fuera necesario se inicializa*/
                declareMatriz(yyvsp[-2],"mat@",type,"matriz",yyvsp[0]);
                }
break;
case 23:
#line 50 "grammar.y"
{
                /*chequea que sean valores enteros*/
                if(symbolsTable->getType(yyvsp[-4])=="INTEGER" && symbolsTable->getType(yyvsp[-1])=="INTEGER"){
                    ArrayInitializer aux(stoi(yyvsp[-4]),stoi(yyvsp[-1]));
                    array=aux;
                }
                else
                    addErrorMessage("los limites de la matriz deben ser valores enteros.");
                }
break;
case 24:
#line 62 "grammar.y"
{addProgramComponent("Declaracion de matriz");
                /*No se inicializa nada pero se guarda inicializacion por filas (opcion por defecto)*/
                yyval="@@rows@";
                }
break;
case 25:
#line 67 "grammar.y"
{addProgramComponent("Declaracion e inicializacion de matriz");
                /*Se inicializa  y guarda por filas  (opcion por defecto)*/
                yyval="@initialization@rows@";
                }
break;
case 26:
#line 71 "grammar.y"
{addProgramComponent("Declaracion y anotacion de matriz");}
break;
case 27:
#line 72 "grammar.y"
{addProgramComponent("Declaracion y anotacion de matriz");
                /*Se guarda alineacion por filas/columnas*/
                yyval="@@"+yyvsp[-1]+"@";
                }
break;
case 28:
#line 76 "grammar.y"
{addProgramComponent("Declaracion, inicializacion y anotacion de matriz");}
break;
case 29:
#line 77 "grammar.y"
{addProgramComponent("Declaracion, inicializacion y anotacion de matriz");
                /*Se inicializa y guarda alineacion por filas/columnas*/
                yyval="@initialization@"+yyvsp[-1]+"@";
                }
break;
case 30:
#line 84 "grammar.y"
{/*se inicializa por columnas*/
                yyval="columns";
                }
break;
case 31:
#line 88 "grammar.y"
{/*se inicializa por filas*/
                yyval="rows";
                }
break;
case 34:
#line 98 "grammar.y"
{/*pasa de la ultima posicion de la fila i a la 1ra de la fila i+1*/
                array.setJ(0);
                array.increaseI();
                }
break;
case 35:
#line 105 "grammar.y"
{/*pasa de la fila i en posicion j a misma fila en posicion j+1, ademas chequea que no se vaya de rango*/
                array.increaseJ();
                updateArray(yyvsp[0]);
                }
break;
case 36:
#line 110 "grammar.y"
{/*guarda dato y chequea que no se vaya de rango*/
                updateArray(yyvsp[0]);
                }
break;
case 37:
#line 116 "grammar.y"
{/*junta la sentencia con el arbol y actualiza la raiz*/
                string executableBlock=codeGen->crearNodo("@sentencia",yyvsp[-1],yyvsp[0]);
                codeGen->setAsRootNode(executableBlock);
                yyval=executableBlock;
                }
break;
case 38:
#line 122 "grammar.y"
{/*mismo que arriba pero para cuando se inicia un bloque ejecutable*/
                string executableBlock=codeGen->crearNodo("@sentencia",yyvsp[0]);
                codeGen->setAsRootNode(executableBlock);
                yyval=executableBlock;
                }
break;
case 40:
#line 130 "grammar.y"
{addErrorMessage("error en sentencia = falta ';' en el final de la asignacion");}
break;
case 41:
#line 131 "grammar.y"
{addProgramComponent("sentencia de asignacion");}
break;
case 43:
#line 133 "grammar.y"
{addProgramComponent("sentecia de impresion");}
break;
case 44:
#line 134 "grammar.y"
{addErrorMessage("error en sentecia = falta ';' en el final de la impresion");}
break;
case 45:
#line 138 "grammar.y"
{addProgramComponent("Sentencia IF con bloque ELSE");
                yyval=codeGen->crearNodo("@if",yyvsp[-4],codeGen->crearNodo("@cuerpo",codeGen->crearNodo("@then",yyvsp[-3]),codeGen->crearNodo("@else", yyvsp[-1])));
                }
break;
case 46:
#line 141 "grammar.y"
{addErrorMessage("error en sentencia IF: falta else");}
break;
case 47:
#line 143 "grammar.y"
{addProgramComponent("Sentencia IF sin bloque ELSE");
                yyval=codeGen->crearNodo("@if",yyvsp[-2],codeGen->crearNodo("@cuerpo",codeGen->crearNodo("@then",yyvsp[-1])));
                }
break;
case 49:
#line 150 "grammar.y"
{addProgramComponent("bloque ejecutable entre llaves");
                yyval=yyvsp[-1];
                }
break;
case 50:
#line 155 "grammar.y"
{yyval=codeGen->crearNodo("@condicion", yyvsp[-1]);}
break;
case 51:
#line 156 "grammar.y"
{addErrorMessage("error en parentesis_condicion: falta '('");}
break;
case 52:
#line 157 "grammar.y"
{addErrorMessage("error en parentesis_condicion: falta ')' ");}
break;
case 53:
#line 158 "grammar.y"
{addErrorMessage("error en parentesis_condicion: faltan ambos parentesis ");}
break;
case 54:
#line 162 "grammar.y"
{
                yyval=createConditionNode(yyvsp[-1],yyvsp[-2],yyvsp[0]);
                }
break;
case 55:
#line 165 "grammar.y"
{addErrorMessage("error en condicion: problema con expresion del lado izquierdo");}
break;
case 56:
#line 166 "grammar.y"
{addErrorMessage("error en condicion: problema con el comparador");}
break;
case 57:
#line 167 "grammar.y"
{addErrorMessage("error en condicion: problema con expresion del lado derecho");}
break;
case 58:
#line 170 "grammar.y"
{yyval="<";}
break;
case 59:
#line 171 "grammar.y"
{yyval=">";}
break;
case 62:
#line 174 "grammar.y"
{yyval="=";}
break;
case 64:
#line 179 "grammar.y"
{
                yyval=createAssignmentNode(yyvsp[-1],yyvsp[-2],yyvsp[0]);
                }
break;
case 65:
#line 182 "grammar.y"
{addErrorMessage("Error en asignacion:problema con asignacion");}
break;
case 66:
#line 183 "grammar.y"
{addErrorMessage("Error en asignacioN:problema con la expresion del lado derecho");}
break;
case 67:
#line 184 "grammar.y"
{addErrorMessage("Error en asignacion:falta el operador de asignacion");}
break;
case 68:
#line 185 "grammar.y"
{addErrorMessage("Error en asignacion:falta variable en lado derecho");}
break;
case 73:
#line 197 "grammar.y"
{
                yyval=createOperatorNode("+",yyvsp[-2],yyvsp[0]);
                }
break;
case 74:
#line 201 "grammar.y"
{
                yyval=createOperatorNode("-",yyvsp[-2],yyvsp[0]);
                }
break;
case 76:
#line 208 "grammar.y"
{
                yyval=createOperatorNode("*",yyvsp[-2],yyvsp[0]);
                }
break;
case 77:
#line 212 "grammar.y"
{
                yyval=createOperatorNode("/",yyvsp[-2],yyvsp[0]);
                }
break;
case 79:
#line 219 "grammar.y"
{/*chequeo si ID fue declarado como VARIABLE*/
                string var=mangle(yyvsp[0],"variable");
                yyval=codeGen->crearNodo(var);
                if(var!="")
                    lastTypes.push(symbolsTable->getType(var));
                }
break;
case 80:
#line 226 "grammar.y"
{yyval=codeGen->crearNodo(yyvsp[0]);
                lastTypes.push(symbolsTable->getType(yyvsp[0]));
                }
break;
case 81:
#line 230 "grammar.y"
{yyval=yyvsp[0];
                Node * node = codeGen->pointersTable.getNode(yyvsp[0]);
                lastTypes.push(symbolsTable->getType(node->dato));
                }
break;
case 82:
#line 237 "grammar.y"
{
                string mat=mangle(yyvsp[-6],"matriz");
                QString tipo1,tipo2;
                if(!lastTypes.empty())
                    tipo1=lastTypes.pop();
                if(!lastTypes.empty())
                    tipo2=lastTypes.pop();
                /*chequea si existe en la tabla de simbolos y que el tipo en subindices sea correcto*/
                if((mat!="") && integerSubindex(tipo1,tipo2))
                    yyval=codeGen->crearNodo(mat,yyvsp[-4],yyvsp[-1]);
                }
break;
case 83:
#line 248 "grammar.y"
{addErrorMessage("error en celda: falta expresion en 1er dimension");}
break;
case 84:
#line 249 "grammar.y"
{addErrorMessage("error en celda: falta ']' en la 1er dimension");}
break;
case 85:
#line 250 "grammar.y"
{addErrorMessage("error en celda: falta '[' en la 2da dimension");}
break;
case 86:
#line 251 "grammar.y"
{addErrorMessage("error en celda: falta expresion en 2da dimension");}
break;
case 87:
#line 252 "grammar.y"
{addErrorMessage("error en celda: falta ']' en 2da dimension");}
break;
case 88:
#line 256 "grammar.y"
{addProgramComponent("Sentencia WHILE");
                yyval=codeGen->crearNodo("@while",yyvsp[-1],yyvsp[0]);
                }
break;
case 89:
#line 262 "grammar.y"
{addProgramComponent("Impresion por pantalla");
                yyval=codeGen->crearNodo("@print",yyvsp[-1]);
                }
break;
case 90:
#line 265 "grammar.y"
{addErrorMessage("error de impresion por pantalla: falta cadena");}
break;
case 91:
#line 266 "grammar.y"
{addErrorMessage("error de impresion por pantalla: falta parentesis '('");}
break;
case 92:
#line 267 "grammar.y"
{addErrorMessage("error de impresion por pantalla: falta parentesis ')'");}
break;
case 93:
#line 268 "grammar.y"
{addErrorMessage("error de impresion por pantalla: faltan ambos parentesis");}
break;
#line 929 "y.tab.c"
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
