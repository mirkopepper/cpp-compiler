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
   16,   16,   16,   21,   21,   20,   20,   20,   20,   22,
   22,   22,   22,   24,   24,   24,   24,   24,   24,   17,
   17,   17,   17,   17,   26,   26,   25,   25,   23,   23,
   23,   28,   28,   28,   29,   29,   29,   27,   30,   18,
   19,   19,   19,   19,   19,
};
short yylen[] = {                                         2,
    4,    3,    3,    2,    1,    1,    1,    1,    3,    3,
    4,    5,    5,    5,    5,    5,    1,    1,    3,    3,
    1,    6,    6,    3,    2,    2,    3,    1,    1,    3,
    3,    1,    3,    1,    2,    1,    1,    1,    1,    1,
    6,    5,    4,    1,    3,    3,    2,    2,    1,    3,
    3,    3,    3,    1,    1,    1,    1,    1,    1,    4,
    3,    5,    4,    3,    1,    1,    1,    1,    3,    3,
    1,    3,    3,    1,    1,    1,    1,    3,    3,    3,
    5,    5,    5,    5,    5,
};
short yydefred[] = {                                      0,
    0,   18,   17,    0,    0,    0,    5,    6,    7,    8,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    4,   36,   37,   38,   39,   40,    0,   68,    0,   21,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   76,
    0,    0,    0,    0,    0,   77,    0,   74,    0,    0,
    0,    0,    2,   35,    0,   65,   66,    0,   10,    0,
    0,    0,    9,    0,    0,    0,    0,    0,    0,    0,
   78,   57,   56,   59,   54,   55,   58,    0,    0,    0,
   44,    0,   47,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   80,    1,   64,    0,    0,    0,    0,   11,
   20,   19,   13,   14,   15,   16,   12,   79,    0,   46,
    0,    0,   43,    0,    0,    0,    0,   53,    0,   72,
   73,    0,    0,    0,    0,    0,   63,    0,   60,    0,
    0,   45,    0,   42,   85,   83,   82,   84,   81,   62,
   24,    0,    0,   22,    0,   41,   34,    0,    0,   29,
   28,   26,    0,   30,    0,    0,   27,    0,   33,
};
short yydgoto[] = {                                       5,
    6,   20,    7,    8,    9,   10,   11,   32,   99,  144,
  145,  152,  148,  149,   81,   23,   24,   25,   26,   43,
   82,   44,   45,   78,   27,   58,   46,   47,   48,   38,
};
short yysindex[] = {                                   -200,
 -246,    0,    0, -236,    0,  -95,    0,    0,    0,    0,
 -199, -255, -239, -222,  -39,  -40,  -37,  -40, -101,  -23,
    0,    0,    0,    0,    0,    0,   38,    0,    6,    0,
 -207,  -42, -246, -246, -246, -180, -146,  -39,  -51,    0,
  -39, -148,  -84,   36,  -31,    0,  142,    0, -160, -205,
  -84,  -12,    0,    0,   56,    0,    0, -123,    0,   26,
   64, -131,    0, -139,   83,   96,  104,  108,  115,    4,
    0,    0,    0,    0,    0,    0,    0, -146,  137, -101,
    0, -110,    0, -146, -146, -146, -117, -146, -146,  -35,
  140,  -33,    0,    0,    0,  126,  -21,  -66,   26,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   50,    0,
   10,  -84,    0,  -76,   50,  142,  142,    0,   50,    0,
    0,  136,  146,  151,  152,  153,    0,  154,    0,  122,
  -27,    0,  -49,    0,    0,    0,    0,    0,    0,    0,
    0,  -20, -128,    0,  163,    0,    0,  -55,  202,    0,
    0,    0, -128,    0,  -20,   -9,    0,  202,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   46,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    1,    0,    0,  -70,    0,    0,   23,    0,    0,    0,
    0,  252,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -68,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   78,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -36,    0,
    0,    0,    0,    0,  -34,   45,   69,    0,  -25,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   95,    0,    0,    0,    0,    0,  -44,    0,
    0,    0,  116,    0,    0,    0,    0,  -26,    0,
};
short yygindex[] = {                                      0,
    0,   -1,  247,    0,    0,    0,  118,    0,  157,    0,
    0,  112,    0,  111,   21,    0,    0,    0,    0,  254,
  -32,  231,   63,  229,    0,    0,  244,   59,   99,  240,
};
#define YYTABLESIZE 391
short yytable[] = {                                      42,
   75,   64,   50,  155,   51,  123,   52,  126,   75,   77,
   76,   85,   80,   86,   32,   50,   63,   52,   93,   13,
   33,   85,   71,   86,    2,    3,   22,   19,   75,   77,
   76,  143,   31,   35,    2,    3,   34,  129,   80,   22,
   54,   75,   75,   75,   69,   75,   85,   75,   86,  114,
   91,   37,   49,   36,   48,    1,   29,   92,   60,   75,
   75,   75,   75,   71,   59,   71,   30,   71,   70,  154,
    2,    3,   54,   31,    4,   68,   83,   61,  111,  133,
   32,   71,   71,   71,   71,   69,   51,   69,   52,   69,
    2,    3,   85,   75,   86,  142,  108,   50,   31,   70,
   22,   53,   90,   69,   69,   69,   69,   39,   40,   70,
   40,   70,   94,   70,   95,   71,   98,   41,   12,   41,
   97,   14,  100,   75,  101,   75,  102,   70,   70,   70,
   70,   54,   96,   40,  132,  150,  151,   69,  118,   40,
  109,  103,   41,  116,  117,   71,  115,   71,   41,  119,
   65,   66,   67,   69,  104,   15,   16,  112,  113,   17,
    1,   70,  105,   18,   15,   16,  106,   69,   17,   69,
   15,   16,   18,  107,   17,    2,    3,  110,   18,    4,
  124,   15,   16,   88,  127,   17,  120,  121,   89,   18,
  130,   70,  134,   70,  135,   49,   49,   48,   48,   49,
   61,   48,   61,   49,  136,   48,   72,   73,   74,  137,
  138,  139,  140,   61,  141,   39,   40,   23,   49,  146,
  122,  153,  125,   62,   84,   41,   72,   73,   74,   51,
   51,   52,   52,   51,  128,   52,  147,   51,   25,   52,
   50,   50,   15,   16,   50,  156,   17,  159,   50,   28,
   18,    3,   21,   15,   16,  131,   75,   17,   75,   75,
   75,   18,   28,   28,  157,  158,   75,   75,   75,   75,
   75,   51,   79,   87,   75,   15,   16,   71,   71,   17,
   71,   71,   71,   18,    0,    0,   28,    0,   71,   71,
   71,   71,   71,   55,   28,   28,   71,    0,   56,   57,
   69,   67,   69,   69,   69,    0,   67,   67,    0,    0,
   69,   69,   69,   69,   69,    0,    0,    0,   69,    0,
    0,    0,    0,   28,   70,   28,   70,   70,   70,    0,
    0,    0,    0,    0,   70,   70,   70,   70,   70,    0,
    0,    0,   70,   61,   61,   61,   61,   61,    0,    0,
   23,   61,    0,    0,   28,   28,    0,    0,    0,    0,
   23,   23,    0,    0,   23,   23,   23,    0,   23,   23,
    0,   25,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   25,   25,    0,    0,   25,   25,   25,    0,   25,
   25,
};
short yycheck[] = {                                      40,
    0,   44,   40,   59,   41,   41,   41,   41,   60,   61,
   62,   43,  123,   45,   59,   41,   59,   19,   51,  256,
  276,   43,    0,   45,  271,  272,    6,  123,   60,   61,
   62,   59,   59,  256,  271,  272,  276,   59,  123,   19,
   20,   41,   42,   43,    0,   45,   43,   47,   45,   82,
  256,   91,  123,  276,  123,  256,  256,  263,  266,   59,
   60,   61,   62,   41,   59,   43,  266,   45,    0,  125,
  271,  272,   52,  273,  275,  256,   41,    0,   80,  112,
  125,   59,   60,   61,   62,   41,  123,   43,  123,   45,
  271,  272,   43,   93,   45,  123,   93,  123,  125,   37,
   80,  125,  263,   59,   60,   61,   62,  256,  257,   41,
  257,   43,  125,   45,   59,   93,   91,  266,    1,  266,
   58,    4,   59,  123,  256,  125,  266,   59,   60,   61,
   62,  111,  256,  257,  125,  264,  265,   93,  256,  257,
   78,   59,  266,   85,   86,  123,   84,  125,  266,   87,
   33,   34,   35,   36,   59,  266,  267,  268,  269,  270,
  256,   93,   59,  274,  266,  267,   59,  123,  270,  125,
  266,  267,  274,   59,  270,  271,  272,   41,  274,  275,
   41,  266,  267,   42,   59,  270,   88,   89,   47,  274,
  257,  123,  269,  125,   59,  266,  267,  266,  267,  270,
  123,  270,  125,  274,   59,  274,  258,  259,  260,   59,
   59,   59,   59,  256,   93,  256,  257,  123,  256,  269,
  256,   59,  256,  266,  256,  266,  258,  259,  260,  266,
  267,  266,  267,  270,  256,  270,  257,  274,  123,  274,
  266,  267,  266,  267,  270,   44,  270,  257,  274,    6,
  274,    0,    6,  266,  267,   99,  256,  270,  258,  259,
  260,  274,   19,   20,  153,  155,  266,  267,  268,  269,
  270,   18,   42,   45,  274,  266,  267,   38,  256,  270,
  258,  259,  260,  274,   -1,   -1,   43,   -1,  266,  267,
  268,  269,  270,  256,   51,   52,  274,   -1,  261,  262,
  256,  256,  258,  259,  260,   -1,  261,  262,   -1,   -1,
  266,  267,  268,  269,  270,   -1,   -1,   -1,  274,   -1,
   -1,   -1,   -1,   80,  256,   82,  258,  259,  260,   -1,
   -1,   -1,   -1,   -1,  266,  267,  268,  269,  270,   -1,
   -1,   -1,  274,  266,  267,  268,  269,  270,   -1,   -1,
  256,  274,   -1,   -1,  111,  112,   -1,   -1,   -1,   -1,
  266,  267,   -1,   -1,  270,  271,  272,   -1,  274,  275,
   -1,  256,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  266,  267,   -1,   -1,  270,  271,  272,   -1,  274,
  275,
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
"impresion : PRINT '(' CADENA ')' ';'",
"impresion : PRINT '(' error ')' ';'",
"impresion : PRINT error CADENA ')' ';'",
"impresion : PRINT '(' CADENA error ';'",
"impresion : PRINT error CADENA error ';'",
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
#line 77 "grammar.y"
{addProgramComponent("Sentencia IF con bloque ELSE");}
break;
case 42:
#line 78 "grammar.y"
{addProgramComponent("error en sentencia IF: falta else");}
break;
case 43:
#line 79 "grammar.y"
{addProgramComponent("Sentencia IF sin bloque ELSE");}
break;
case 44:
#line 82 "grammar.y"
{addProgramComponent("bloque sentencias = sentencia");}
break;
case 45:
#line 83 "grammar.y"
{addProgramComponent("bloque sentencias = bloque ejecutable entre llaves");}
break;
case 46:
#line 86 "grammar.y"
{addProgramComponent("parentesis_condicion = condicion entre parentesis");}
break;
case 47:
#line 87 "grammar.y"
{addProgramComponent("error en parentesis_condicion: falta '('");}
break;
case 48:
#line 88 "grammar.y"
{addProgramComponent("error en parentesis_condicion: ')' ");}
break;
case 49:
#line 89 "grammar.y"
{addProgramComponent("error en parentesis_condicion: faltan ambos parentesis ");}
break;
case 50:
#line 92 "grammar.y"
{addProgramComponent("condicion = comparacion de expresiones");}
break;
case 51:
#line 93 "grammar.y"
{addProgramComponent("error en condicion: problema con expresion del lado izquierdo");}
break;
case 52:
#line 94 "grammar.y"
{addProgramComponent("error en condicion: problema con el comparador");}
break;
case 53:
#line 95 "grammar.y"
{addProgramComponent("error en condicion: problema con expresion del lado derecho");}
break;
case 54:
#line 98 "grammar.y"
{addProgramComponent("comparador = menor");}
break;
case 55:
#line 99 "grammar.y"
{addProgramComponent("comparador = mayor");}
break;
case 56:
#line 100 "grammar.y"
{addProgramComponent("comparador = menor igual");}
break;
case 57:
#line 101 "grammar.y"
{addProgramComponent("comparador = mayor igual");}
break;
case 58:
#line 102 "grammar.y"
{addProgramComponent("comparador = igual");}
break;
case 59:
#line 103 "grammar.y"
{addProgramComponent("comparador = distinto");}
break;
case 60:
#line 106 "grammar.y"
{addProgramComponent("Asignacion");}
break;
case 61:
#line 107 "grammar.y"
{addProgramComponent("Error en asignacion:falta el ';'");}
break;
case 62:
#line 108 "grammar.y"
{addProgramComponent("Error en asignacion:problema con asignacion");}
break;
case 63:
#line 109 "grammar.y"
{addProgramComponent("Error en asignacioN:problema con la expresion del lado derecho");}
break;
case 64:
#line 110 "grammar.y"
{addProgramComponent("Error en asignacion:falta el operador de asignacion");}
break;
case 67:
#line 117 "grammar.y"
{addProgramComponent("asignacion izq = id");}
break;
case 68:
#line 118 "grammar.y"
{addProgramComponent("asignacion izq = celda");}
break;
case 69:
#line 121 "grammar.y"
{addProgramComponent("expresion = expresion mas termino");}
break;
case 70:
#line 122 "grammar.y"
{addProgramComponent("expresion = expresion menos termino");}
break;
case 71:
#line 123 "grammar.y"
{addProgramComponent("expresion = termino");}
break;
case 72:
#line 126 "grammar.y"
{addProgramComponent("termino = termino por factor");}
break;
case 73:
#line 127 "grammar.y"
{addProgramComponent("termino = termino dividido factor");}
break;
case 74:
#line 128 "grammar.y"
{addProgramComponent("termino = factor");}
break;
case 75:
#line 131 "grammar.y"
{addProgramComponent("factor = id");}
break;
case 76:
#line 132 "grammar.y"
{addProgramComponent("factor = cte");}
break;
case 77:
#line 133 "grammar.y"
{addProgramComponent("factor = celda");}
break;
case 78:
#line 136 "grammar.y"
{addProgramComponent("celda = id + expresion x2, cada una entre corchetes");}
break;
case 79:
#line 145 "grammar.y"
{addProgramComponent("corchetes_expresion = expresion entre corchetes");}
break;
case 80:
#line 151 "grammar.y"
{addProgramComponent("Sentencia WHILE");}
break;
case 81:
#line 154 "grammar.y"
{addProgramComponent("Impresion por pantalla");}
break;
case 82:
#line 155 "grammar.y"
{addProgramComponent("error de impresion por pantalla: falta cadena");}
break;
case 83:
#line 156 "grammar.y"
{addProgramComponent("error de impresion por pantalla: falta parentesis '('");}
break;
case 84:
#line 157 "grammar.y"
{addProgramComponent("error de impresion por pantalla: falta parentesis ')'");}
break;
case 85:
#line 158 "grammar.y"
{addProgramComponent("error de impresion por pantalla: faltan ambos parentesis");}
break;
#line 808 "y.tab.c"
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
