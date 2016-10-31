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
    8,    6,    9,   10,   12,   10,   14,   10,   15,   10,
   13,   13,   11,   16,   16,   17,   17,    2,    2,   18,
   18,   18,   18,   18,   18,   19,   19,   19,   24,   24,
   23,   23,   23,   23,   25,   25,   25,   25,   27,   27,
   27,   27,   27,   27,   20,   20,   20,   20,   20,   29,
   29,   28,   28,   26,   26,   26,   31,   31,   31,   32,
   32,   32,   30,   30,   30,   30,   30,   30,   21,   22,
   22,   22,   22,   22,
};
short yylen[] = {                                         2,
    5,    4,    4,    2,    1,    1,    1,    1,    3,    3,
    4,    5,    5,    5,    5,    5,    1,    1,    3,    3,
    1,    5,    6,    1,    0,    3,    0,    3,    0,    4,
    1,    1,    3,    3,    1,    3,    1,    2,    1,    1,
    1,    2,    1,    2,    1,    6,    5,    4,    1,    3,
    3,    2,    2,    1,    3,    3,    3,    3,    1,    1,
    1,    1,    1,    1,    3,    4,    3,    3,    3,    1,
    1,    1,    1,    3,    3,    1,    3,    3,    1,    1,
    1,    1,    7,    7,    6,    7,    7,    7,    3,    4,
    4,    3,    3,    2,
};
short yydefred[] = {                                      0,
    0,    0,    0,   18,   17,    0,    0,    5,    6,    7,
    8,    0,    0,    0,    0,   70,   71,    0,    0,    0,
    0,    0,    0,    4,   39,   40,    0,   43,    0,    0,
    0,   73,    0,   21,    0,    0,    0,    0,    0,    0,
    0,    0,   81,    0,    0,    0,    0,    0,   82,    0,
   79,    0,    0,    0,    0,    2,   38,   42,   44,    0,
    0,    0,   10,    0,    0,    0,    9,    0,    0,    0,
    0,    0,    0,    0,    0,   62,   61,   64,   59,   60,
   63,    0,    0,    0,   49,    0,   52,    0,    0,    0,
    0,    0,    0,   92,    0,    0,   89,    1,   68,   67,
    0,   69,    0,    0,   11,   20,   19,   13,   14,   15,
   16,   12,    0,    0,    0,    0,   51,    0,    0,   48,
    0,    0,    0,    0,   58,    0,   77,   78,   91,   90,
   66,    0,    0,    0,   22,    0,    0,    0,    0,    0,
   50,    0,   47,    0,   37,    0,    0,   32,   31,   27,
    0,   85,    0,    0,    0,    0,   46,    0,   33,    0,
    0,   28,   26,   29,   84,   86,   87,   88,   83,    0,
    0,   36,   30,   23,
};
short yydgoto[] = {                                       2,
    7,   23,    8,    9,   10,   11,   12,   36,  104,  135,
  136,  163,  150,  162,  173,  146,  147,   85,   26,   27,
   28,   29,   46,   86,   47,   48,   82,   30,   31,   49,
   50,   51,
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
   -1,    0,    0,    0,    0,    0,    0,    0,    0,  165,
  206,    0,    0,    0,
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
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -32,    0,    0,    0,
};
short yygindex[] = {                                      0,
    0,    3,  266,    0,    0,    0,  114,    0,    0,    0,
    0,    0,  115,    0,    0,    0,  112,   15,    0,    0,
    0,    0,  253,  -30,  231,  513,  229,    0,  250,  484,
   84,  109,
};
#define YYTABLESIZE 653
short yytable[] = {                                      53,
   80,   45,   68,   89,  160,   90,   89,   89,   90,   90,
   79,   81,   80,   89,  140,   90,  134,   67,   39,   84,
    1,   25,   76,   97,   55,   35,   34,   89,   95,   90,
   79,   81,   80,  148,  149,   96,   25,   57,   40,   84,
   33,   80,   80,   80,   74,   80,   89,   80,   90,   89,
   34,   90,   89,  169,   90,  121,    3,   35,   14,   80,
   80,   80,   80,   76,  113,   76,  114,   76,   75,   57,
  159,    4,    5,    4,    5,    6,   89,  115,   90,   94,
  133,   76,   76,   76,   76,   74,  118,   74,  142,   74,
   93,   35,   34,   80,    4,    5,  152,   37,   25,  165,
   65,   38,  166,   74,   74,   74,   74,   74,   43,   75,
   41,   75,   41,   75,   58,   76,   13,   44,   72,   15,
   45,   42,   43,   80,   89,   80,   90,   75,   75,   75,
   75,   44,   57,    4,    5,   59,   92,   74,   94,   43,
   99,   93,   64,   16,   17,   76,   43,   76,   44,   93,
   69,   70,   71,   73,   63,   44,   87,   16,   17,   65,
   94,   75,   18,   19,  119,  120,   20,   74,  103,   74,
   21,   56,  123,  124,  100,   43,  105,   16,   17,  139,
  106,   57,   18,   19,   44,  107,   20,  125,   43,  132,
   21,   75,  108,   75,   72,   55,  109,   44,   72,   72,
  127,  128,   94,   72,   94,  110,  111,  112,   76,   77,
   78,  155,   43,   93,   65,   93,  168,   42,   43,  102,
  131,   44,   52,   65,   66,   65,   88,   44,   76,   77,
   78,  117,  129,   41,  130,   41,  138,  143,  145,  151,
  157,   16,   17,   45,  144,   45,   18,   19,  158,  161,
   20,  167,  170,   56,   21,  172,   80,  174,   80,   80,
   80,   80,   80,   57,    3,  164,   80,   80,   80,   80,
   80,  171,   24,   54,   80,   83,   91,   55,   76,   61,
   76,   76,   76,   76,   76,    0,    0,    0,   76,   76,
   76,   76,   76,   22,    0,    0,   76,    0,    0,    0,
   74,    0,   74,   74,   74,   74,   74,    0,    0,    0,
   74,   74,   74,   74,   74,   24,    0,    0,   74,    0,
    0,    0,    0,    0,   75,    0,   75,   75,   75,   75,
   75,    0,   25,    0,   75,   75,   75,   75,   75,    0,
   94,   94,   75,    0,    0,   94,   94,   94,   94,   94,
   54,   93,   93,   94,    0,    0,   93,   93,   93,   93,
   93,   65,   65,    0,   93,   53,   65,   65,   65,   65,
   65,   41,   41,    0,   65,    0,   41,   41,   41,   41,
   41,   45,   45,   56,   41,   98,   45,   45,   45,   45,
   45,   56,   56,    0,   45,    0,   56,   56,    0,  141,
   56,   57,   57,    0,   56,    0,   57,   57,    0,    0,
   57,    0,    0,    0,   57,   55,   55,    0,    0,    0,
   55,   55,    0,    0,   55,    0,    3,    0,   55,    0,
    0,   16,   17,    0,    0,    0,   18,   19,    0,    0,
   20,    4,    5,    0,   21,    6,    0,    0,   24,    0,
    0,    0,    0,   24,   24,    0,    0,    0,   24,   24,
    0,    0,   24,   24,   24,   25,   24,   24,    0,    0,
   25,   25,    0,    0,    0,   25,   25,    0,    0,   25,
   25,   25,    0,   25,   25,    0,    0,    0,   54,   54,
   32,    0,    0,   54,   54,    0,    0,   54,    0,    0,
    0,   54,    0,   53,   53,   32,   32,    0,   53,   53,
    0,    0,   53,    0,    0,    0,   53,    0,    0,   16,
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
"$$1 :",
"opcional_arreglo : inicializacion ';' $$1",
"$$2 :",
"opcional_arreglo : ';' anotacion $$2",
"$$3 :",
"opcional_arreglo : inicializacion ';' anotacion $$3",
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
                }
break;
case 23:
#line 49 "grammar.y"
{
                /*falta chequear que sean valores enteros y guardar ambos valores*/
                }
break;
case 24:
#line 55 "grammar.y"
{addProgramComponent("Declaracion de matriz");
                /*No se inicializa nada pero se guarda inicializacion por filas (opcion por defecto)*/
                }
break;
case 25:
#line 58 "grammar.y"
{addProgramComponent("Declaracion e inicializacion de matriz");}
break;
case 26:
#line 59 "grammar.y"
{addProgramComponent("Declaracion e inicializacion de matriz");
                /*Se inicializa  y guarda por filas  (opcion por defecto)*/
                }
break;
case 27:
#line 62 "grammar.y"
{addProgramComponent("Declaracion y anotacion de matriz");}
break;
case 28:
#line 63 "grammar.y"
{addProgramComponent("Declaracion y anotacion de matriz");
                /*Se guarda alineacion por filas/columnas*/
                }
break;
case 29:
#line 66 "grammar.y"
{addProgramComponent("Declaracion, inicializacion y anotacion de matriz");}
break;
case 30:
#line 67 "grammar.y"
{addProgramComponent("Declaracion, inicializacion y anotacion de matriz");
                /*Se inicializa y guarda alineacion por filas/columnas*/
                }
break;
case 31:
#line 72 "grammar.y"
{/*guardar en algun lado que se inicaliza por columnas*/}
break;
case 32:
#line 73 "grammar.y"
{/*guardar en algun lado que se inicaliza por filas*/}
break;
case 38:
#line 87 "grammar.y"
{yyval=codeGen->crearNodo("@sentencia",yyvsp[-1],yyvsp[0]);}
break;
case 39:
#line 88 "grammar.y"
{yyval=codeGen->crearNodo("@sentencia",yyvsp[0]);}
break;
case 41:
#line 92 "grammar.y"
{addErrorMessage("error en sentencia = falta ';' en el final de la asignacion");}
break;
case 42:
#line 93 "grammar.y"
{addProgramComponent("sentencia de asignacion");}
break;
case 44:
#line 95 "grammar.y"
{addProgramComponent("sentecia de impresion");}
break;
case 45:
#line 96 "grammar.y"
{addErrorMessage("error en sentecia = falta ';' en el final de la impresion");}
break;
case 46:
#line 100 "grammar.y"
{addProgramComponent("Sentencia IF con bloque ELSE");
                yyval=codeGen->crearNodo("@if",yyvsp[-4],codeGen->crearNodo("@cuerpo",codeGen->crearNodo("@then",yyvsp[-3]),codeGen->crearNodo("@else", yyvsp[-1])));
                }
break;
case 47:
#line 103 "grammar.y"
{addErrorMessage("error en sentencia IF: falta else");}
break;
case 48:
#line 105 "grammar.y"
{addProgramComponent("Sentencia IF sin bloque ELSE");
                yyval=codeGen->crearNodo("@if",yyvsp[-2],codeGen->crearNodo("@cuerpo",codeGen->crearNodo("@then",yyvsp[-1])));
                }
break;
case 50:
#line 112 "grammar.y"
{addProgramComponent("bloque ejecutable entre llaves");
                yyval=yyvsp[-1];
                }
break;
case 51:
#line 117 "grammar.y"
{yyval=codeGen->crearNodo("@condicion", yyvsp[-1]);}
break;
case 52:
#line 118 "grammar.y"
{addErrorMessage("error en parentesis_condicion: falta '('");}
break;
case 53:
#line 119 "grammar.y"
{addErrorMessage("error en parentesis_condicion: falta ')' ");}
break;
case 54:
#line 120 "grammar.y"
{addErrorMessage("error en parentesis_condicion: faltan ambos parentesis ");}
break;
case 55:
#line 124 "grammar.y"
{QString tipo1, tipo2;
                if (!lastTypes.empty())
                    tipo1 = lastTypes.pop();
                if (!lastTypes.empty())
                    tipo2 = lastTypes.pop();
                if (tipo1!=tipo2) {
                    if (tipo1=="INTEGER"){
                        string conversion = codeGen->crearNodo("@conv", yyvsp[0]);
                        yyval=codeGen->crearNodo(yyvsp[-1], yyvsp[-2], conversion);
                    }else{/*tipo2=INTEGER*/
                        string conversion = codeGen->crearNodo("@conv", yyvsp[-2]);
                        yyval=codeGen->crearNodo(yyvsp[-1], conversion, yyvsp[0]);
                    }
                }
                }
break;
case 56:
#line 139 "grammar.y"
{addErrorMessage("error en condicion: problema con expresion del lado izquierdo");}
break;
case 57:
#line 140 "grammar.y"
{addErrorMessage("error en condicion: problema con el comparador");}
break;
case 58:
#line 141 "grammar.y"
{addErrorMessage("error en condicion: problema con expresion del lado derecho");}
break;
case 59:
#line 144 "grammar.y"
{yyval="<";}
break;
case 60:
#line 145 "grammar.y"
{yyval=">";}
break;
case 63:
#line 148 "grammar.y"
{yyval="=";}
break;
case 65:
#line 153 "grammar.y"
{
                QString tipo1,tipo2;
                if (!lastTypes.empty())
                    tipo1 = lastTypes.pop();
                if (!lastTypes.empty())
                    tipo2 = lastTypes.pop();
                /*tipo2=asig_izq tipo1=expresion*/
                if(tipo2=="INTEGER" && tipo1=="DOUBLE" && !conversionsAllowed)
                    addErrorMessage("Error en asignacion: conversion no permitida.");
                    yyval=codeGen->crearNodo(yyvsp[-1],yyvsp[-2],yyvsp[0]);
                }
break;
case 66:
#line 164 "grammar.y"
{addErrorMessage("Error en asignacion:problema con asignacion");}
break;
case 67:
#line 165 "grammar.y"
{addErrorMessage("Error en asignacioN:problema con la expresion del lado derecho");}
break;
case 68:
#line 166 "grammar.y"
{addErrorMessage("Error en asignacion:falta el operador de asignacion");}
break;
case 69:
#line 167 "grammar.y"
{addErrorMessage("Error en asignacion:falta variable en lado derecho");}
break;
case 74:
#line 179 "grammar.y"
{
                QString tipo1, tipo2;
                if (!lastTypes.empty())
                    tipo1 = lastTypes.pop();
                if (!lastTypes.empty())
                    tipo2 = lastTypes.pop();
                if (tipo1==tipo2) {
                    if (tipo1=="INTEGER")
                        lastTypes.push("INTEGER");
                    else
                        lastTypes.push("DOUBLE");
                    yyval=codeGen->crearNodo("+", yyvsp[-2], yyvsp[0]);
                } else {
                    /*como stack es una pila, tipo1=factor tipo2=termino*/
                    lastTypes.push("DOUBLE");
                    if (tipo1=="INTEGER") {
                        string conversion = codeGen->crearNodo("@conv", yyvsp[0]);
                        yyval=codeGen->crearNodo("+", yyvsp[-2], conversion);
                    } else {
                        string conversion = codeGen->crearNodo("@conv", yyvsp[-2]);
                        yyval=codeGen->crearNodo("+", conversion, yyvsp[0]);
                    }
                }
                }
break;
case 75:
#line 204 "grammar.y"
{
                QString tipo1, tipo2;
                if (!lastTypes.empty())
                    tipo1 = lastTypes.pop();
                if (!lastTypes.empty())
                    tipo2 = lastTypes.pop();
                if (tipo1==tipo2) {
                    if (tipo1=="INTEGER")
                        lastTypes.push("INTEGER");
                    else
                        lastTypes.push("DOUBLE");
                    yyval=codeGen->crearNodo("-", yyvsp[-2], yyvsp[0]);
                } else {
                    /*como stack es una pila, tipo1=factor tipo2=termino*/
                    lastTypes.push("DOUBLE");
                    if (tipo1=="INTEGER") {
                        string conversion = codeGen->crearNodo("@conv", yyvsp[0]);
                        yyval=codeGen->crearNodo("-", yyvsp[-2], conversion);
                    } else {
                        string conversion = codeGen->crearNodo("@conv", yyvsp[-2]);
                        yyval=codeGen->crearNodo("-", conversion, yyvsp[0]);
                    }
                }
                }
break;
case 77:
#line 232 "grammar.y"
{
                QString tipo1, tipo2;
                if (!lastTypes.empty())
                    tipo1 = lastTypes.pop();
                if (!lastTypes.empty())
                    tipo2 = lastTypes.pop();
                if (tipo1==tipo2) {
                    if (tipo1=="INTEGER")
                        lastTypes.push("INTEGER");
                    else
                        lastTypes.push("DOUBLE");
                    yyval=codeGen->crearNodo("*", yyvsp[-2], yyvsp[0]);
                } else {
                    /*como stack es una pila, tipo1=factor tipo2=termino*/
                    lastTypes.push("DOUBLE");
                    if (tipo1=="INTEGER") {
                        string conversion = codeGen->crearNodo("@conv", yyvsp[0]);
                        yyval=codeGen->crearNodo("*", yyvsp[-2], conversion);
                    } else {
                        string conversion = codeGen->crearNodo("@conv", yyvsp[-2]);
                        yyval=codeGen->crearNodo("*", conversion, yyvsp[0]);
                    }
                }
                }
break;
case 78:
#line 257 "grammar.y"
{
                QString tipo1, tipo2;
                if (!lastTypes.empty())
                    tipo1 = lastTypes.pop();
                if (!lastTypes.empty())
                    tipo2 = lastTypes.pop();
                if (tipo1==tipo2) {
                    if (tipo1=="INTEGER")
                        lastTypes.push("INTEGER");
                    else
                        lastTypes.push("DOUBLE");
                    yyval=codeGen->crearNodo("/", yyvsp[-2], yyvsp[0]);
                } else {
                    /*como stack es una pila, tipo1=factor tipo2=termino*/
                    lastTypes.push("DOUBLE");
                    if (tipo1=="INTEGER") {
                        string conversion = codeGen->crearNodo("@conv", yyvsp[0]);
                        yyval=codeGen->crearNodo("/", yyvsp[-2], conversion);
                    } else {
                        string conversion = codeGen->crearNodo("@conv", yyvsp[-2]);
                        yyval=codeGen->crearNodo("/", conversion, yyvsp[0]);
                    }
                }
                }
break;
case 80:
#line 285 "grammar.y"
{/*chequeo si ID fue declarado como VARIABLE*/
                string var=mangle(yyvsp[0],"variable");
                yyval=codeGen->crearNodo(var);
                if(var!="")
                    lastTypes.push(symbolsTable->getType(var));
                }
break;
case 81:
#line 292 "grammar.y"
{yyval=codeGen->crearNodo(yyvsp[0]);
                lastTypes.push(symbolsTable->getType(yyvsp[0]));
                }
break;
case 82:
#line 296 "grammar.y"
{yyval=yyvsp[0];
                Node * node = codeGen->pointersTable.getNode(yyvsp[0]);
                lastTypes.push(symbolsTable->getType(node->dato));
                }
break;
case 83:
#line 303 "grammar.y"
{/*chequeo tipo expresiones=INTEGER*/
                string mat=mangle(yyvsp[-6],"matriz");
                /*saca los ultimos 2 tipos*/
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
case 84:
#line 315 "grammar.y"
{addErrorMessage("error en celda: falta expresion en 1er dimension");}
break;
case 85:
#line 316 "grammar.y"
{addErrorMessage("error en celda: falta ']' en la 1er dimension");}
break;
case 86:
#line 317 "grammar.y"
{addErrorMessage("error en celda: falta '[' en la 2da dimension");}
break;
case 87:
#line 318 "grammar.y"
{addErrorMessage("error en celda: falta expresion en 2da dimension");}
break;
case 88:
#line 319 "grammar.y"
{addErrorMessage("error en celda: falta ']' en 2da dimension");}
break;
case 89:
#line 323 "grammar.y"
{addProgramComponent("Sentencia WHILE");
                yyval=codeGen->crearNodo("@while",yyvsp[-1],yyvsp[0]);
                }
break;
case 90:
#line 329 "grammar.y"
{addProgramComponent("Impresion por pantalla");
                yyval=codeGen->crearNodo("@print",yyvsp[-1]);
                }
break;
case 91:
#line 332 "grammar.y"
{addErrorMessage("error de impresion por pantalla: falta cadena");}
break;
case 92:
#line 333 "grammar.y"
{addErrorMessage("error de impresion por pantalla: falta parentesis '('");}
break;
case 93:
#line 334 "grammar.y"
{addErrorMessage("error de impresion por pantalla: falta parentesis ')'");}
break;
case 94:
#line 335 "grammar.y"
{addErrorMessage("error de impresion por pantalla: faltan ambos parentesis");}
break;
#line 996 "y.tab.c"
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
