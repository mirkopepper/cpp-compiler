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
    8,    8,    6,    6,    9,   11,   10,   10,   10,   13,
   13,   12,   14,   14,   15,   15,    2,    2,   16,   16,
   16,   16,   17,   17,   22,   22,   21,   24,   24,   24,
   24,   24,   24,   18,   18,   25,   25,   23,   23,   23,
   27,   27,   27,   28,   28,   28,   26,   19,   20,
};
short yylen[] = {                                         2,
    4,    2,    1,    1,    1,    1,    3,    5,    1,    1,
    3,    1,    5,    5,    2,    3,    2,    2,    3,    1,
    1,    3,    3,    1,    3,    1,    2,    1,    1,    1,
    1,    1,    8,    6,    1,    3,    3,    1,    1,    1,
    1,    1,    1,    4,    4,    1,    1,    3,    3,    1,
    3,    3,    1,    1,    1,    1,    7,    5,    5,
};
short yydefred[] = {                                      0,
   10,    9,    0,    0,    0,    3,    4,    5,    6,    0,
    0,    0,    2,   12,    0,    0,    0,    0,    0,    0,
    0,    0,   28,   29,   30,   31,   32,    0,   47,    0,
    7,    0,    0,    0,    0,    0,    0,    1,   27,    0,
    0,    0,    0,    0,   11,    8,   55,    0,    0,   56,
    0,   53,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   13,    0,   15,    0,    0,    0,    0,    0,    0,
   41,   40,   43,   38,   39,   42,    0,    0,    0,   44,
   45,   16,   26,    0,    0,   21,   20,   18,    0,    0,
    0,    0,   51,   52,    0,   35,    0,    0,   59,   58,
   22,    0,    0,   19,    0,    0,    0,   34,    0,   25,
   57,   36,    0,   33,
};
short yydgoto[] = {                                       4,
    5,   22,    6,    7,    8,    9,   10,   16,   43,   62,
   44,   63,   88,   84,   85,   96,   24,   25,   26,   27,
   53,   97,   54,   77,   28,   50,   51,   52,
};
short yysindex[] = {                                   -171,
    0,    0, -188,    0, -120,    0,    0,    0,    0, -193,
 -228, -177,    0,    0, -195,   22, -188,    5,   45,   58,
   62,  -87,    0,    0,    0,    0,    0, -170,    0,   14,
    0, -159,   59, -190, -190, -146, -190,    0,    0, -190,
 -190, -135,  -17,   14,    0,    0,    0,    5,    2,    0,
   27,    0,   82,  -28,   84,   85,   16,   20,   34, -129,
 -155,    0,   70,    0,   41, -190, -190, -190, -190,  -96,
    0,    0,    0,    0,    0,    0, -190,   74,  -96,    0,
    0,    0,    0,  -48,   90,    0,    0,    0, -155, -190,
   27,   27,    0,    0, -177,    0, -157,   25,    0,    0,
    0, -129, -121,    0,   15,  -85,  -96,    0,   90,    0,
    0,    0, -132,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -148,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -41,    0,    0,
  -36,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -115,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -43,    0,    0,    0, -110,    0,
  -31,   -6,    0,    0,    0,    0,    0,   97,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -37,    0,
    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
    0,   44,  135,    0,    0,    0,   61,    0,    0,    0,
   98,    0,   54,    0,   39,   29,    0,    0,    0,    0,
  107,  -35,    9,    0,    0,   24,   49,   52,
};
#define YYTABLESIZE 254
short yytable[] = {                                      54,
   54,   54,   12,   54,   50,   54,   50,   14,   50,   48,
  102,   48,   17,   48,   66,   24,   67,   54,   54,   54,
   54,   23,   50,   50,   50,   50,   95,   48,   48,   48,
   48,   74,   76,   75,   49,   29,   49,   38,   49,  112,
   23,   61,   49,  100,   66,   29,   67,   17,   57,   58,
   39,   54,   49,   49,   49,   49,   50,   66,   66,   67,
   67,   48,   66,   11,   67,   32,   47,   66,   68,   67,
   30,  113,   14,   69,   80,   48,  101,   33,   81,   15,
   31,   24,    1,    2,   35,   98,   49,   23,   18,   19,
   40,   41,   20,   29,   65,   34,   21,   36,  105,    1,
    2,   37,   29,    3,   42,   60,   45,  111,   86,   87,
  107,  108,   46,   46,   91,   92,   55,   46,   29,   93,
   94,   59,   70,   23,   78,   79,   82,   83,   89,   29,
   29,   90,   99,  103,   39,  110,  114,   37,  106,   13,
  109,   64,  104,   56,    0,    0,    0,    0,    0,    0,
    1,    2,    0,    0,    3,   14,   14,    0,    0,   14,
   17,   17,    0,    0,   17,    0,    0,    0,    0,   18,
   19,    0,    0,   20,    0,    0,    0,   21,   18,   19,
   18,   19,   20,    0,   20,    0,   21,    0,   21,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   54,   54,   54,    0,
    0,   50,   50,   50,    0,    0,   48,   48,   48,   71,
   72,   73,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   49,   49,   49,
};
short yycheck[] = {                                      41,
   42,   43,  123,   45,   41,   47,   43,  123,   45,   41,
   59,   43,  123,   45,   43,   59,   45,   59,   60,   61,
   62,   59,   59,   60,   61,   62,  123,   59,   60,   61,
   62,   60,   61,   62,   41,   12,   43,  125,   45,  125,
   12,   59,   34,   79,   43,   22,   45,  276,   40,   41,
   22,   93,   59,   60,   61,   62,   93,   43,   43,   45,
   45,   93,   43,    3,   45,   44,  257,   43,   42,   45,
  266,  107,  266,   47,   59,  266,  125,   17,   59,  273,
   59,  125,  271,  272,   40,   77,   93,  125,  266,  267,
  261,  262,  270,   70,   93,   91,  274,   40,   90,  271,
  272,   40,   79,  275,   91,  123,  266,   93,  264,  265,
  268,  269,  261,  262,   66,   67,  263,   59,   95,   68,
   69,  257,   41,   95,   41,   41,   93,  257,   59,  106,
  107,   91,   59,   44,  106,  257,  269,   41,   95,    5,
  102,   44,   89,   37,   -1,   -1,   -1,   -1,   -1,   -1,
  271,  272,   -1,   -1,  275,  271,  272,   -1,   -1,  275,
  271,  272,   -1,   -1,  275,   -1,   -1,   -1,   -1,  266,
  267,   -1,   -1,  270,   -1,   -1,   -1,  274,  266,  267,
  266,  267,  270,   -1,  270,   -1,  274,   -1,  274,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  258,  259,  260,   -1,
   -1,  258,  259,  260,   -1,   -1,  258,  259,  260,  258,
  259,  260,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  258,  259,  260,
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
"arreglo : tipo MATRIX ID dimensiones opcional_arreglo",
"arreglo : tipo MATRIX ID dimensiones ';'",
"dimensiones : dimension dimension",
"dimension : '[' CTE ']'",
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
case 1:
#line 4 "grammar.y"
{addProgramComponent("Dectecto un programa!!");}
break;
case 2:
#line 7 "grammar.y"
{addProgramComponent("bloque declarativo=bloque declarativo + setencia declarativa");}
break;
case 3:
#line 8 "grammar.y"
{addProgramComponent("bloque declarativo = sentencia declarativa");}
break;
case 4:
#line 11 "grammar.y"
{addProgramComponent("setencia declarativa = variable");}
break;
case 5:
#line 12 "grammar.y"
{addProgramComponent("sentencia declaratica = conversion");}
break;
case 6:
#line 13 "grammar.y"
{addProgramComponent("sentencia declarativo = arreglo");}
break;
case 7:
#line 16 "grammar.y"
{addProgramComponent("variable = tipo + lista ids");}
break;
case 8:
#line 19 "grammar.y"
{addProgramComponent("Conversion entre variables");}
break;
case 9:
#line 22 "grammar.y"
{addProgramComponent("tipo double");}
break;
case 10:
#line 23 "grammar.y"
{addProgramComponent("tipo integer");}
break;
case 11:
#line 26 "grammar.y"
{addProgramComponent("lista ids = lista ids + id");}
break;
case 12:
#line 27 "grammar.y"
{addProgramComponent("lista ids = id");}
break;
case 13:
#line 30 "grammar.y"
{addProgramComponent("arreglo = tipo matrix id dimensiones opcional arreglo");}
break;
case 14:
#line 31 "grammar.y"
{addProgramComponent("Declaracion de matriz");}
break;
case 15:
#line 34 "grammar.y"
{addProgramComponent("dimensiones = dimension + dimension");}
break;
case 16:
#line 37 "grammar.y"
{addProgramComponent("dimension = cte entre corchetes");}
break;
case 17:
#line 40 "grammar.y"
{addProgramComponent("Declaracion e inicializacion de matriz");}
break;
case 18:
#line 41 "grammar.y"
{addProgramComponent("Declaracion y anotacion de matriz");}
break;
case 19:
#line 42 "grammar.y"
{addProgramComponent("Declaracion, inicializacion y anotacion de matriz");}
break;
case 20:
#line 45 "grammar.y"
{addProgramComponent("anotacion c");}
break;
case 21:
#line 46 "grammar.y"
{addProgramComponent("anotacion f");}
break;
case 22:
#line 49 "grammar.y"
{addProgramComponent("inicializacion = lista de listas entre corchetes");}
break;
case 23:
#line 52 "grammar.y"
{addProgramComponent("lista de listas = lista de listas + puntocoma + lista valores");}
break;
case 24:
#line 53 "grammar.y"
{addProgramComponent("lista de listas = lista valores");}
break;
case 25:
#line 56 "grammar.y"
{addProgramComponent("lista valores = lista valores + coma + cte");}
break;
case 26:
#line 57 "grammar.y"
{addProgramComponent("lista valores = cte");}
break;
case 27:
#line 60 "grammar.y"
{addProgramComponent("bloque ejecutable = bloque ejecutable + sentencia");}
break;
case 28:
#line 61 "grammar.y"
{addProgramComponent("bloque ejecutable = sentencia");}
break;
case 29:
#line 64 "grammar.y"
{addProgramComponent("sentencia = seleccion");}
break;
case 30:
#line 65 "grammar.y"
{addProgramComponent("sentencia = asignacion");}
break;
case 31:
#line 66 "grammar.y"
{addProgramComponent("sentencia = iteracion");}
break;
case 32:
#line 67 "grammar.y"
{addProgramComponent("sentecia = impresion");}
break;
case 33:
#line 70 "grammar.y"
{addProgramComponent("Sentencia IF con bloque ELSE");}
break;
case 34:
#line 71 "grammar.y"
{addProgramComponent("Sentencia IF sin bloque ELSE");}
break;
case 35:
#line 74 "grammar.y"
{addProgramComponent("bloque sentencias = sentencia");}
break;
case 36:
#line 75 "grammar.y"
{addProgramComponent("bloque sentencias = bloque ejecutable entre llaves");}
break;
case 37:
#line 78 "grammar.y"
{addProgramComponent("condicion = comparacion de expresiones");}
break;
case 38:
#line 81 "grammar.y"
{addProgramComponent("comparador = menor");}
break;
case 39:
#line 82 "grammar.y"
{addProgramComponent("comparador = mayor");}
break;
case 40:
#line 83 "grammar.y"
{addProgramComponent("comparador = menor igual");}
break;
case 41:
#line 84 "grammar.y"
{addProgramComponent("comparador = mayor igual");}
break;
case 42:
#line 85 "grammar.y"
{addProgramComponent("comparador = igual");}
break;
case 43:
#line 86 "grammar.y"
{addProgramComponent("comparador = distinto");}
break;
case 44:
#line 89 "grammar.y"
{addProgramComponent("Asignacion");}
break;
case 45:
#line 90 "grammar.y"
{addProgramComponent("Asignacion con resta");}
break;
case 46:
#line 93 "grammar.y"
{addProgramComponent("asignacion izq = id");}
break;
case 47:
#line 94 "grammar.y"
{addProgramComponent("asignacion izq = celda");}
break;
case 48:
#line 97 "grammar.y"
{addProgramComponent("expresion = expresion mas termino");}
break;
case 49:
#line 98 "grammar.y"
{addProgramComponent("expresion = expresion menos termino");}
break;
case 50:
#line 99 "grammar.y"
{addProgramComponent("expresion = termino");}
break;
case 51:
#line 102 "grammar.y"
{addProgramComponent("termino = termino por factor");}
break;
case 52:
#line 103 "grammar.y"
{addProgramComponent("termino = termino dividido factor");}
break;
case 53:
#line 104 "grammar.y"
{addProgramComponent("termino = factor");}
break;
case 54:
#line 107 "grammar.y"
{addProgramComponent("factor = id");}
break;
case 55:
#line 108 "grammar.y"
{addProgramComponent("factor = cte");}
break;
case 56:
#line 109 "grammar.y"
{addProgramComponent("factor = celda");}
break;
case 57:
#line 112 "grammar.y"
{addProgramComponent("celda = id + expresion x2, cada una entre corchetes");}
break;
case 58:
#line 115 "grammar.y"
{addProgramComponent("Sentencia WHILE");}
break;
case 59:
#line 118 "grammar.y"
{addProgramComponent("Impresion por pantalla");}
break;
#line 640 "y.tab.c"
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
