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
    0,    1,    1,    3,    3,    3,    4,    4,    5,    7,
    7,    8,    8,    6,    6,    9,   11,   10,   10,   10,
   13,   13,   12,   14,   14,   15,   15,    2,    2,   16,
   16,   16,   16,   17,   17,   22,   22,   21,   24,   24,
   24,   24,   24,   24,   18,   18,   25,   25,   23,   23,
   23,   27,   27,   27,   28,   28,   28,   26,   19,   20,
};
short yylen[] = {                                         2,
    4,    2,    1,    1,    1,    1,    3,    3,    5,    1,
    1,    3,    1,    5,    5,    2,    3,    2,    2,    3,
    1,    1,    3,    3,    1,    3,    1,    2,    1,    1,
    1,    1,    1,    8,    6,    1,    3,    3,    1,    1,
    1,    1,    1,    1,    4,    4,    1,    1,    3,    3,
    1,    3,    3,    1,    1,    1,    1,    7,    5,    5,
};
short yydefred[] = {                                      0,
   11,   10,    0,    0,    0,    3,    4,    5,    6,    0,
    0,    0,    2,    0,   13,    0,    0,    0,    0,    0,
    0,    0,    0,   29,   30,   31,   32,   33,    0,   48,
    8,    0,    7,    0,    0,    0,    0,    0,    0,    1,
   28,    0,    0,    0,    0,    0,   12,    9,   56,    0,
    0,   57,    0,   54,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   14,    0,   16,    0,    0,    0,    0,
    0,    0,   42,   41,   44,   39,   40,   43,    0,    0,
    0,   45,   46,   17,   27,    0,    0,   22,   21,   19,
    0,    0,    0,    0,   52,   53,    0,   36,    0,    0,
   60,   59,   23,    0,    0,   20,    0,    0,    0,   35,
    0,   26,   58,   37,    0,   34,
};
short yydgoto[] = {                                       4,
    5,   23,    6,    7,    8,    9,   10,   17,   45,   64,
   46,   65,   90,   86,   87,   98,   25,   26,   27,   28,
   55,   99,   56,   79,   29,   52,   53,   54,
};
short yysindex[] = {                                   -172,
    0,    0, -213,    0, -120,    0,    0,    0,    0, -206,
 -231, -173,    0,   -8,    0, -201,   32, -213,  -19,   43,
   55,   62,  -87,    0,    0,    0,    0,    0, -149,    0,
    0,  -12,    0, -162,   47, -188, -188, -143, -188,    0,
    0, -188, -188, -142,  -18,  -12,    0,    0,    0,  -19,
   18,    0,   39,    0,   85,  -28,   88,   89,   25,   30,
   38, -124, -148,    0,   75,    0,   44, -188, -188, -188,
 -188,  -96,    0,    0,    0,    0,    0,    0, -188,   77,
  -96,    0,    0,    0,    0,  -43,   93,    0,    0,    0,
 -148, -188,   39,   39,    0,    0, -173,    0, -150,   45,
    0,    0,    0, -124, -119,    0,   21,  -85,  -96,    0,
   93,    0,    0,    0, -130,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -139,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -41,
    0,    0,  -36,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -115,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -16,    0,    0,    0,
 -110,    0,  -31,   -6,    0,    0,    0,    0,    0,   99,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -15,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
    0,   46,  136,    0,    0,    0,   74,    0,    0,    0,
   96,    0,   53,    0,   41,   24,    0,    0,    0,    0,
  107,  -35,    6,    0,    0,   -1,   56,   57,
};
#define YYTABLESIZE 254
short yytable[] = {                                      55,
   55,   55,   12,   55,   51,   55,   51,   15,   51,   49,
   30,   49,   18,   49,   68,  104,   69,   55,   55,   55,
   55,   30,   51,   51,   51,   51,   97,   49,   49,   49,
   49,   76,   78,   77,   50,   24,   50,   40,   50,  114,
   63,   51,   25,   24,   18,  102,   41,   59,   60,   14,
   31,   55,   50,   50,   50,   50,   51,    1,    2,   15,
   68,   49,   69,   68,   32,   69,   16,   68,   49,   69,
   30,   36,   68,  115,   69,   34,   11,   50,   44,   30,
   70,  103,   37,   82,  100,   71,   50,   68,   83,   69,
   33,   35,   19,   20,   38,   30,   21,  107,    1,    2,
   22,   39,    3,   47,   62,   48,   30,   30,   25,   24,
   67,   42,   43,  113,   61,   88,   89,  109,  110,   57,
   24,   47,   47,   93,   94,   72,   95,   96,   80,   81,
   84,   41,   85,   91,   92,  101,  105,  112,  116,   38,
   13,   66,  108,  106,  111,   58,    0,    0,    0,    0,
    1,    2,    0,    0,    3,   15,   15,    0,    0,   15,
   18,   18,    0,    0,   18,    0,    0,    0,    0,   19,
   20,    0,    0,   21,    0,    0,    0,   22,   19,   20,
   19,   20,   21,    0,   21,    0,   22,    0,   22,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   55,   55,   55,    0,
    0,   51,   51,   51,    0,    0,   49,   49,   49,   73,
   74,   75,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   50,   50,   50,
};
short yycheck[] = {                                      41,
   42,   43,  123,   45,   41,   47,   43,  123,   45,   41,
   12,   43,  123,   45,   43,   59,   45,   59,   60,   61,
   62,   23,   59,   60,   61,   62,  123,   59,   60,   61,
   62,   60,   61,   62,   41,   12,   43,  125,   45,  125,
   59,   36,   59,   59,  276,   81,   23,   42,   43,  256,
   59,   93,   59,   60,   61,   62,   93,  271,  272,  266,
   43,   93,   45,   43,  266,   45,  273,   43,  257,   45,
   72,   91,   43,  109,   45,   44,    3,  266,   91,   81,
   42,  125,   40,   59,   79,   47,   93,   43,   59,   45,
   59,   18,  266,  267,   40,   97,  270,   92,  271,  272,
  274,   40,  275,  266,  123,   59,  108,  109,  125,  125,
   93,  261,  262,   93,  257,  264,  265,  268,  269,  263,
   97,  261,  262,   68,   69,   41,   70,   71,   41,   41,
   93,  108,  257,   59,   91,   59,   44,  257,  269,   41,
    5,   46,   97,   91,  104,   39,   -1,   -1,   -1,   -1,
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
"variable : tipo error ';'",
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
#line 17 "grammar.y"
{addProgramComponent("error en lista_id");}
break;
case 9:
#line 20 "grammar.y"
{addProgramComponent("Conversion entre variables");}
break;
case 10:
#line 23 "grammar.y"
{addProgramComponent("tipo double");}
break;
case 11:
#line 24 "grammar.y"
{addProgramComponent("tipo integer");}
break;
case 12:
#line 27 "grammar.y"
{addProgramComponent("lista ids = lista ids + id");}
break;
case 13:
#line 28 "grammar.y"
{addProgramComponent("lista ids = id");}
break;
case 14:
#line 31 "grammar.y"
{addProgramComponent("arreglo = tipo matrix id dimensiones opcional arreglo");}
break;
case 15:
#line 32 "grammar.y"
{addProgramComponent("Declaracion de matriz");}
break;
case 16:
#line 35 "grammar.y"
{addProgramComponent("dimensiones = dimension + dimension");}
break;
case 17:
#line 38 "grammar.y"
{addProgramComponent("dimension = cte entre corchetes");}
break;
case 18:
#line 41 "grammar.y"
{addProgramComponent("Declaracion e inicializacion de matriz");}
break;
case 19:
#line 42 "grammar.y"
{addProgramComponent("Declaracion y anotacion de matriz");}
break;
case 20:
#line 43 "grammar.y"
{addProgramComponent("Declaracion, inicializacion y anotacion de matriz");}
break;
case 21:
#line 46 "grammar.y"
{addProgramComponent("anotacion c");}
break;
case 22:
#line 47 "grammar.y"
{addProgramComponent("anotacion f");}
break;
case 23:
#line 50 "grammar.y"
{addProgramComponent("inicializacion = lista de listas entre corchetes");}
break;
case 24:
#line 53 "grammar.y"
{addProgramComponent("lista de listas = lista de listas + puntocoma + lista valores");}
break;
case 25:
#line 54 "grammar.y"
{addProgramComponent("lista de listas = lista valores");}
break;
case 26:
#line 57 "grammar.y"
{addProgramComponent("lista valores = lista valores + coma + cte");}
break;
case 27:
#line 58 "grammar.y"
{addProgramComponent("lista valores = cte");}
break;
case 28:
#line 61 "grammar.y"
{addProgramComponent("bloque ejecutable = bloque ejecutable + sentencia");}
break;
case 29:
#line 62 "grammar.y"
{addProgramComponent("bloque ejecutable = sentencia");}
break;
case 30:
#line 65 "grammar.y"
{addProgramComponent("sentencia = seleccion");}
break;
case 31:
#line 66 "grammar.y"
{addProgramComponent("sentencia = asignacion");}
break;
case 32:
#line 67 "grammar.y"
{addProgramComponent("sentencia = iteracion");}
break;
case 33:
#line 68 "grammar.y"
{addProgramComponent("sentecia = impresion");}
break;
case 34:
#line 71 "grammar.y"
{addProgramComponent("Sentencia IF con bloque ELSE");}
break;
case 35:
#line 72 "grammar.y"
{addProgramComponent("Sentencia IF sin bloque ELSE");}
break;
case 36:
#line 75 "grammar.y"
{addProgramComponent("bloque sentencias = sentencia");}
break;
case 37:
#line 76 "grammar.y"
{addProgramComponent("bloque sentencias = bloque ejecutable entre llaves");}
break;
case 38:
#line 79 "grammar.y"
{addProgramComponent("condicion = comparacion de expresiones");}
break;
case 39:
#line 82 "grammar.y"
{addProgramComponent("comparador = menor");}
break;
case 40:
#line 83 "grammar.y"
{addProgramComponent("comparador = mayor");}
break;
case 41:
#line 84 "grammar.y"
{addProgramComponent("comparador = menor igual");}
break;
case 42:
#line 85 "grammar.y"
{addProgramComponent("comparador = mayor igual");}
break;
case 43:
#line 86 "grammar.y"
{addProgramComponent("comparador = igual");}
break;
case 44:
#line 87 "grammar.y"
{addProgramComponent("comparador = distinto");}
break;
case 45:
#line 90 "grammar.y"
{addProgramComponent("Asignacion");}
break;
case 46:
#line 91 "grammar.y"
{addProgramComponent("Asignacion con resta");}
break;
case 47:
#line 94 "grammar.y"
{addProgramComponent("asignacion izq = id");}
break;
case 48:
#line 95 "grammar.y"
{addProgramComponent("asignacion izq = celda");}
break;
case 49:
#line 98 "grammar.y"
{addProgramComponent("expresion = expresion mas termino");}
break;
case 50:
#line 99 "grammar.y"
{addProgramComponent("expresion = expresion menos termino");}
break;
case 51:
#line 100 "grammar.y"
{addProgramComponent("expresion = termino");}
break;
case 52:
#line 103 "grammar.y"
{addProgramComponent("termino = termino por factor");}
break;
case 53:
#line 104 "grammar.y"
{addProgramComponent("termino = termino dividido factor");}
break;
case 54:
#line 105 "grammar.y"
{addProgramComponent("termino = factor");}
break;
case 55:
#line 108 "grammar.y"
{addProgramComponent("factor = id");}
break;
case 56:
#line 109 "grammar.y"
{addProgramComponent("factor = cte");}
break;
case 57:
#line 110 "grammar.y"
{addProgramComponent("factor = celda");}
break;
case 58:
#line 113 "grammar.y"
{addProgramComponent("celda = id + expresion x2, cada una entre corchetes");}
break;
case 59:
#line 116 "grammar.y"
{addProgramComponent("Sentencia WHILE");}
break;
case 60:
#line 119 "grammar.y"
{addProgramComponent("Impresion por pantalla");}
break;
#line 645 "y.tab.c"
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
