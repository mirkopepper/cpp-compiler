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
    0,    1,    1,    3,    3,    3,    4,    5,    7,    7,
    8,    8,    6,    6,    6,    9,   11,   10,   10,   10,
   13,   13,   12,   14,   14,   15,   15,    2,    2,   16,
   16,   16,   16,   17,   17,   22,   22,   21,   24,   24,
   24,   24,   24,   24,   18,   18,   25,   25,   23,   23,
   23,   27,   27,   27,   28,   28,   28,   26,   19,   20,
};
short yylen[] = {                                         2,
    4,    2,    1,    1,    1,    1,    3,    5,    1,    1,
    3,    1,    6,    5,    2,    2,    3,    2,    1,    1,
    1,    1,    3,    3,    1,    3,    1,    2,    1,    1,
    1,    1,    1,    8,    6,    1,    3,    3,    1,    1,
    1,    1,    1,    1,    4,    4,    1,    1,    3,    3,
    1,    3,    3,    1,    1,    1,    1,    7,    5,    5,
};
short yydefred[] = {                                      0,
   10,    9,    0,    0,    0,    3,    4,    5,    6,    0,
    0,    0,    2,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   29,   30,   31,   32,   33,    0,   48,    0,
    7,    0,    0,    0,    0,    0,    0,    1,   28,    0,
    0,    0,    0,    0,   11,    8,   56,    0,    0,   57,
    0,   54,    0,    0,    0,    0,    0,    0,    0,   22,
   21,    0,   14,    0,    0,   20,   16,    0,    0,    0,
    0,    0,    0,   42,   41,   44,   39,   40,   43,    0,
    0,    0,   45,   46,   17,   27,    0,    0,   13,   18,
    0,    0,    0,   52,   53,    0,   36,    0,    0,   60,
   59,   23,    0,    0,    0,    0,    0,   35,    0,   26,
   58,   37,    0,   34,
};
short yydgoto[] = {                                       4,
    5,   22,    6,    7,    8,    9,   10,   16,   43,   64,
   44,   65,   66,   87,   88,   97,   24,   25,   26,   27,
   53,   98,   54,   80,   28,   50,   51,   52,
};
short yysindex[] = {                                   -169,
    0,    0, -258,    0, -114,    0,    0,    0,    0, -173,
 -234, -176,    0,    0, -221,   30, -258,  -28,   38,   44,
   56, -102,    0,    0,    0,    0,    0, -154,    0,  -24,
    0, -167,   45, -193, -193, -146, -193,    0,    0, -193,
 -193, -148,  -55,  -24,    0,    0,    0,  -28,   -6,    0,
   34,    0,   80,  -10,   83,   86,   26,   27,   36,    0,
    0, -125,    0,   74, -153,    0,    0,   43, -193, -193,
 -193, -193, -111,    0,    0,    0,    0,    0,    0, -193,
   76, -111,    0,    0,    0,    0,  -48,   92,    0,    0,
 -193,   34,   34,    0,    0, -176,    0, -155,   52,    0,
    0,    0, -125, -120,   17,  -96, -111,    0,   92,    0,
    0,    0, -131,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -44,    0,    0,    0, -142,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -40,    0,    0,
  -35,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   81,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -43,    0,    0,
    0,  -13,   -5,    0,    0,    0,    0,    0,   98,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -42,    0,
    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
    0,   46,  136,    0,    0,    0,   58,    0,    0,    0,
   99,    0,   79,    0,   42,   22,    0,    0,    0,    0,
  109,  -64,   25,    0,    0,   19,   53,   59,
};
#define YYTABLESIZE 255
short yytable[] = {                                      12,
   55,   55,   55,   63,   55,   51,   55,   51,   12,   51,
  103,   96,    1,    2,   12,   25,   24,  101,   55,   55,
   55,   55,   38,   51,   51,   51,   51,   49,  112,   49,
   29,   49,   69,   23,   70,   50,   69,   50,   70,   50,
   29,   17,  113,   39,   30,   49,   49,   49,   49,   77,
   79,   78,   55,   50,   50,   50,   50,   51,   49,   69,
   11,   70,   34,   47,   57,   58,   42,   62,   69,   69,
   70,   70,   48,   32,   33,   71,  102,   35,   15,   49,
   72,   25,   24,   36,   83,   84,   68,   50,   31,   18,
   19,   29,   14,   20,   69,   37,   70,   21,   45,   15,
   29,    1,    2,   46,   99,    3,   40,   41,   59,  111,
   60,   61,  107,  108,   29,  105,   55,   23,   47,   47,
   73,   92,   93,   81,   29,   29,   82,   39,   85,   94,
   95,   86,   89,   91,  100,  104,  110,  114,   38,   19,
   13,  106,   67,   90,  109,   56,    0,    0,    0,    0,
    0,    0,    0,    0,   18,   19,    1,    2,   20,    0,
    3,    0,   21,   18,   19,    0,    0,   20,    0,   18,
   19,   21,    0,   20,    0,    0,    0,   21,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   60,   61,
    0,    0,    0,    0,    0,    0,    0,   55,   55,   55,
    0,    0,   51,   51,   51,    0,   15,   15,    0,    0,
   15,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   49,   49,   49,   74,   75,   76,
    0,    0,   50,   50,   50,
};
short yycheck[] = {                                      44,
   41,   42,   43,   59,   45,   41,   47,   43,  123,   45,
   59,  123,  271,  272,   59,   59,   59,   82,   59,   60,
   61,   62,  125,   59,   60,   61,   62,   41,  125,   43,
   12,   45,   43,   12,   45,   41,   43,   43,   45,   45,
   22,  276,  107,   22,  266,   59,   60,   61,   62,   60,
   61,   62,   93,   59,   60,   61,   62,   93,   34,   43,
    3,   45,   91,  257,   40,   41,   91,  123,   43,   43,
   45,   45,  266,   44,   17,   42,  125,   40,  123,   93,
   47,  125,  125,   40,   59,   59,   93,   93,   59,  266,
  267,   73,  266,  270,   43,   40,   45,  274,  266,  273,
   82,  271,  272,   59,   80,  275,  261,  262,  257,   93,
  264,  265,  268,  269,   96,   91,  263,   96,  261,  262,
   41,   69,   70,   41,  106,  107,   41,  106,   93,   71,
   72,  257,   59,   91,   59,   44,  257,  269,   41,   59,
    5,   96,   44,   65,  103,   37,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  266,  267,  271,  272,  270,   -1,
  275,   -1,  274,  266,  267,   -1,   -1,  270,   -1,  266,
  267,  274,   -1,  270,   -1,   -1,   -1,  274,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  264,  265,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  258,  259,  260,
   -1,   -1,  258,  259,  260,   -1,  271,  272,   -1,   -1,
  275,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  258,  259,  260,  258,  259,  260,
   -1,   -1,  258,  259,  260,
};
#define YYFINAL 4
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
"bloque_declarativo : bloque_declarativo sentencia_declarativa",
"bloque_declarativo : sentencia_declarativa",
"sentencia_declarativa : variable",
"sentencia_declarativa : conversion",
"sentencia_declarativa : arreglo",
"variable : tipo lista_id ';'",
"conversion : ALLOW tipo TO tipo ';'",
"tipo : DOUBLE",
"tipo : INTEGER",
"lista_id : lista_id ',' ID",
"lista_id : ID",
"arreglo : tipo MATRIX ID dimensiones opcional_arreglo ';'",
"arreglo : tipo MATRIX ID dimensiones ';'",
"arreglo : tipo ID",
"dimensiones : dimension dimension",
"dimension : '[' CTE ']'",
"opcional_arreglo : inicializacion anotacion",
"opcional_arreglo : inicializacion",
"opcional_arreglo : anotacion",
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
"seleccion : IF '(' condicion ')' bloque_de_sentencias ELSE bloque_de_sentencias ENDIF",
"seleccion : IF '(' condicion ')' bloque_de_sentencias ENDIF",
"bloque_de_sentencias : sentencia",
"bloque_de_sentencias : '{' bloque_ejecutable '}'",
"condicion : expresion comparador expresion",
"comparador : '<'",
"comparador : '>'",
"comparador : MENORIGUAL",
"comparador : MAYORIGUAL",
"comparador : '='",
"comparador : DISTINTO",
"asignacion : asignacion_izq DOSPUNTOSIGUAL expresion ';'",
"asignacion : asignacion_izq MENOSIGUAL expresion ';'",
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
"iteracion : WHILE '(' condicion ')' bloque_de_sentencias",
"impresion : PRINT '(' CADENA ')' ';'",
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
case 7:
#line 16 "grammar.y"
{addRule("Declaracion de variable/s");}
break;
case 8:
#line 19 "grammar.y"
{addRule("Conversion entre variables");}
break;
case 14:
#line 31 "grammar.y"
{addRule("Declaracion de matriz");}
break;
case 18:
#line 41 "grammar.y"
{addRule("Declaracion, inicializacion y anotacion de matriz");}
break;
case 19:
#line 42 "grammar.y"
{addRule("Declaracion e inicializacion de matriz");}
break;
case 20:
#line 43 "grammar.y"
{addRule("Declaracion y anotacion de matriz");}
break;
case 34:
#line 71 "grammar.y"
{addRule("Sentencia IF con bloque ELSE");}
break;
case 35:
#line 72 "grammar.y"
{addRule("Sentencia IF sin bloque ELSE");}
break;
case 45:
#line 90 "grammar.y"
{addRule("Asignacion");}
break;
case 46:
#line 91 "grammar.y"
{addRule("Asignacion con resta");}
break;
case 59:
#line 116 "grammar.y"
{addRule("Sentencia WHILE");}
break;
case 60:
#line 119 "grammar.y"
{addRule("Impresion por pantalla");}
break;
#line 453 "y.tab.c"
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
