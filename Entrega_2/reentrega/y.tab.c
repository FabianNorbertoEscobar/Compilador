
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 3 "Sintactico.y"

	/* includes */

	#include <stdio.h>
	#include <conio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <float.h>
	#include "y.tab.h"

	/* defines */

	#define CARACTER_NOMBRE "_"
	#define NO_ENCONTRADO -1
	#define SIN_ASIGNAR "SinAsignar"
	#define TRUE 1
	#define FALSE 0
	#define ERROR -1
	#define OK 3

	/* enums */

	enum valorMaximo{
		ENTERO_MAXIMO = 32768,
		CADENA_MAXIMA = 31,
		TAM = 100
	};

	enum tipoDato{
		tipoInt,
		tipoFloat,
		tipoString,
		sinTipo
	};

	enum sectorTabla{
		sectorVariables,
		sectorConstantes
	};

	enum error{
		ErrorIdRepetida,
		ErrorIdNoDeclarado,
		ErrorOperacionNoValida,
		ErrorIdDistintoTipo,
		ErrorConstanteDistintoTipo
	};

	enum tipoDeError{
		ErrorSintactico,
		ErrorLexico
	};

	enum tipoCondicion{
		condicionIf,
		condicionWhile
	};

	enum and_or{
		and,
		or,
		condicionSimple
	};

	enum tipoSalto{
		normal,
		inverso
	};

	/* structs */

	typedef struct{
		char nombre[100];
		char valor[100];
		enum tipoDato tipo;
		int longitud;
		int limite;
	} registro;

	typedef struct
	{
		char *cadena;
		int cantExpresiones;
		int salto1;
		int salto2;
		int nro;
		enum and_or andOr;
		enum tipoDato tipo;
	}t_info;

	typedef struct s_nodoPila{
    	t_info info;
    	struct s_nodoPila* psig;
	}t_nodoPila;

	typedef t_nodoPila *t_pila;

	typedef struct
	{
		char cadena[CADENA_MAXIMA];
		int nro;
	}t_infoPolaca;

	typedef struct s_nodoPolaca{
    	t_infoPolaca info;
    	struct s_nodoPolaca* psig;
	}t_nodoPolaca;

	typedef t_nodoPolaca *t_polaca;

	/* funciones */

	int yyerrormsj(const char *,enum tipoDeError,enum error, const char*);
	int yyerror();

	void guardarPolaca(t_polaca*);
	int ponerEnPolacaNro(t_polaca*,int, char *);
	int ponerEnPolaca(t_polaca*, char *);
	void crearPolaca(t_polaca*);
	char* obtenerSalto(enum tipoSalto);
	char* obtenerSalto2(char*,enum tipoSalto);

	void vaciarPila(t_pila*);
	t_info* sacarDePila(t_pila*);
	void crearPila(t_pila*);
	int ponerEnPila(t_pila*,t_info*);
	t_info* topeDePila(t_pila*);

	void generar_assembler ();
	void generar_assembler2 (t_polaca*);
	char * sacarDePolaca(t_polaca*);
	int buscarEnTablaDeSimbolosASM(enum sectorTabla, char*);

	/* variables globales */

	extern registro tablaVariables[TAM];
	extern registro tablaConstantes[TAM];
	extern int yylineno;
	extern int indiceConstante;
	extern int indiceVariable;
	extern char *tiraDeTokens;
	int yystopparser=0;
	FILE  *yyin;
	char *yyltext;
	char *yytext;
	int indicesParaAsignarTipo[TAM];
	enum tipoDato tipoAsignacion=sinTipo;
	int esAsignacion=0;
	int contadorListaVar=0;
	int contadorIf=0;
	int contadorWhile=0;
	int contadorBetween=0;
	int contadorInList=0;
	int contadorPolaca=0;
	int auxiliaresNecesarios=0;
	t_polaca polaca;
	t_pila pilaIf;
	t_pila pilaWhile;
	t_pila pilaBetween;
	t_pila pilaInList;
	t_pila pilaASM;
	char ultimoComparador[3];
	int expresionesRestantes;
	enum tipoCondicion tipoCondicion;
	float paramBetween;
	float paramInList;



/* Line 189 of yacc.c  */
#line 243 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DIGITO = 258,
     LETRA = 259,
     LETRA_MINUS = 260,
     LETRA_MAYUS = 261,
     CARACTER = 262,
     CTE_INT = 263,
     CTE_FLOAT = 264,
     CTE_STRING = 265,
     ID = 266,
     INICIO_PROGRAMA = 267,
     FIN_PROGRAMA = 268,
     OP_SUM = 269,
     OP_REST = 270,
     OP_MULT = 271,
     OP_DIV = 272,
     OP_ASIG = 273,
     OP_DEC = 274,
     OP_AND = 275,
     OP_OR = 276,
     OP_NOT = 277,
     COMPARADOR = 278,
     PARENTESIS_I = 279,
     PARENTESIS_F = 280,
     LLAVE_I = 281,
     LLAVE_F = 282,
     CORCHETE_I = 283,
     CORCHETE_F = 284,
     COMENTARIO_I = 285,
     COMENTARIO_F = 286,
     PUNTO_Y_COMA = 287,
     COMA = 288,
     COMP_MAYOR_ESTR = 289,
     COMP_MENOR_ESTR = 290,
     COMP_MAYOR_IGUAL = 291,
     COMP_MENOR_IGUAL = 292,
     COMP_IGUAL = 293,
     COMP_DIST = 294,
     DECVAR = 295,
     ENDDEC = 296,
     WHILE = 297,
     ENDWHILE = 298,
     DO = 299,
     IF = 300,
     ELSE = 301,
     ELSIF = 302,
     ENDIF = 303,
     INTEGER = 304,
     FLOAT = 305,
     STRING = 306,
     READ = 307,
     WRITE = 308,
     BETWEEN = 309,
     INLIST = 310,
     COMENTARIO = 311
   };
#endif
/* Tokens.  */
#define DIGITO 258
#define LETRA 259
#define LETRA_MINUS 260
#define LETRA_MAYUS 261
#define CARACTER 262
#define CTE_INT 263
#define CTE_FLOAT 264
#define CTE_STRING 265
#define ID 266
#define INICIO_PROGRAMA 267
#define FIN_PROGRAMA 268
#define OP_SUM 269
#define OP_REST 270
#define OP_MULT 271
#define OP_DIV 272
#define OP_ASIG 273
#define OP_DEC 274
#define OP_AND 275
#define OP_OR 276
#define OP_NOT 277
#define COMPARADOR 278
#define PARENTESIS_I 279
#define PARENTESIS_F 280
#define LLAVE_I 281
#define LLAVE_F 282
#define CORCHETE_I 283
#define CORCHETE_F 284
#define COMENTARIO_I 285
#define COMENTARIO_F 286
#define PUNTO_Y_COMA 287
#define COMA 288
#define COMP_MAYOR_ESTR 289
#define COMP_MENOR_ESTR 290
#define COMP_MAYOR_IGUAL 291
#define COMP_MENOR_IGUAL 292
#define COMP_IGUAL 293
#define COMP_DIST 294
#define DECVAR 295
#define ENDDEC 296
#define WHILE 297
#define ENDWHILE 298
#define DO 299
#define IF 300
#define ELSE 301
#define ELSIF 302
#define ENDIF 303
#define INTEGER 304
#define FLOAT 305
#define STRING 306
#define READ 307
#define WRITE 308
#define BETWEEN 309
#define INLIST 310
#define COMENTARIO 311




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 172 "Sintactico.y"

	int entero;
	double real;
	char cadena[50];



/* Line 214 of yacc.c  */
#line 399 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 411 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   114

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNRULES -- Number of states.  */
#define YYNSTATES  143

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     6,    11,    13,    15,    18,    20,
      22,    24,    26,    28,    30,    32,    33,    38,    39,    40,
      41,    52,    53,    54,    64,    66,    67,    72,    75,    77,
      79,    81,    83,    87,    89,    90,    91,    97,    98,    99,
     100,   101,   114,   117,   120,   123,   124,   129,   132,   134,
     138,   142,   144,   145,   146,   153,   155,   157,   159,   160,
     165,   166,   171,   173,   174,   179,   180,   185,   187,   189,
     191,   193,   195,   199,   200,   201,   210,   216,   217,   218,
     227,   231,   233
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    59,    -1,    -1,    12,    60,    61,    13,
      -1,    62,    -1,    63,    -1,    62,    63,    -1,    86,    -1,
      64,    -1,    84,    -1,    85,    -1,    66,    -1,    70,    -1,
      56,    -1,    -1,    11,    65,    18,    94,    -1,    -1,    -1,
      -1,    42,    24,    73,    67,    25,    68,    44,    61,    69,
      43,    -1,    -1,    -1,    45,    71,    24,    73,    25,    72,
      44,    77,    48,    -1,    76,    -1,    -1,    76,    75,    74,
      76,    -1,    22,    76,    -1,   101,    -1,   105,    -1,    20,
      -1,    21,    -1,    94,    23,    94,    -1,    61,    -1,    -1,
      -1,    61,    78,    46,    79,    61,    -1,    -1,    -1,    -1,
      -1,    61,    80,    47,    81,    24,    73,    25,    82,    61,
      46,    83,    61,    -1,    52,    11,    -1,    53,    11,    -1,
      53,    10,    -1,    -1,    40,    87,    88,    41,    -1,    88,
      89,    -1,    89,    -1,    90,    33,    89,    -1,    90,    19,
      93,    -1,    11,    -1,    -1,    -1,    11,    91,    24,     8,
      92,    25,    -1,    49,    -1,    50,    -1,    51,    -1,    -1,
      94,    14,    95,    97,    -1,    -1,    94,    15,    96,    97,
      -1,    97,    -1,    -1,    97,    16,    98,   100,    -1,    -1,
      97,    17,    99,   100,    -1,   100,    -1,     8,    -1,     9,
      -1,    10,    -1,    11,    -1,    24,    94,    25,    -1,    -1,
      -1,    54,   102,    24,    11,   103,    33,   104,    25,    -1,
      28,    94,    32,    94,    29,    -1,    -1,    -1,    55,   106,
      24,    11,   107,    32,   108,    25,    -1,    28,   109,    29,
      -1,    94,    -1,    94,    32,   109,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   245,   245,   251,   250,   261,   267,   272,   278,   283,
     288,   293,   298,   303,   308,   315,   314,   336,   340,   344,
     335,   362,   373,   361,   388,   415,   413,   478,   503,   508,
     514,   525,   538,   541,   552,   560,   551,   588,   596,   607,
     614,   587,   642,   654,   665,   674,   673,   683,   688,   691,
     693,   699,   706,   711,   705,   721,   736,   751,   769,   768,
     783,   782,   796,   803,   802,   817,   816,   828,   834,   844,
     854,   864,   881,   885,   903,   884,   912,   919,   937,   918,
     953,   957,   959
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DIGITO", "LETRA", "LETRA_MINUS",
  "LETRA_MAYUS", "CARACTER", "CTE_INT", "CTE_FLOAT", "CTE_STRING", "ID",
  "INICIO_PROGRAMA", "FIN_PROGRAMA", "OP_SUM", "OP_REST", "OP_MULT",
  "OP_DIV", "OP_ASIG", "OP_DEC", "OP_AND", "OP_OR", "OP_NOT", "COMPARADOR",
  "PARENTESIS_I", "PARENTESIS_F", "LLAVE_I", "LLAVE_F", "CORCHETE_I",
  "CORCHETE_F", "COMENTARIO_I", "COMENTARIO_F", "PUNTO_Y_COMA", "COMA",
  "COMP_MAYOR_ESTR", "COMP_MENOR_ESTR", "COMP_MAYOR_IGUAL",
  "COMP_MENOR_IGUAL", "COMP_IGUAL", "COMP_DIST", "DECVAR", "ENDDEC",
  "WHILE", "ENDWHILE", "DO", "IF", "ELSE", "ELSIF", "ENDIF", "INTEGER",
  "FLOAT", "STRING", "READ", "WRITE", "BETWEEN", "INLIST", "COMENTARIO",
  "$accept", "start", "programa", "$@1", "bloque", "lista_sentencias",
  "sentencia", "asignacion", "$@2", "iteracion", "$@3", "$@4", "$@5",
  "seleccion", "$@6", "$@7", "condicion", "$@8", "and_or", "comparacion",
  "resto", "$@9", "$@10", "$@11", "$@12", "$@13", "$@14", "lectura",
  "escritura", "bloque_declaracion", "$@15", "declaraciones",
  "lista_id_y_tipo", "var_dec", "$@16", "$@17", "tipodato", "expresion",
  "$@18", "$@19", "termino", "$@20", "$@21", "factor", "between", "$@22",
  "$@23", "rango", "inlist", "$@24", "$@25", "lista_expresiones",
  "expresiones", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    60,    59,    61,    62,    62,    63,    63,
      63,    63,    63,    63,    63,    65,    64,    67,    68,    69,
      66,    71,    72,    70,    73,    74,    73,    73,    73,    73,
      75,    75,    76,    77,    78,    79,    77,    80,    81,    82,
      83,    77,    84,    85,    85,    87,    86,    88,    88,    89,
      89,    90,    91,    92,    90,    93,    93,    93,    95,    94,
      96,    94,    94,    98,    97,    99,    97,    97,   100,   100,
     100,   100,   100,   102,   103,   101,   104,   106,   107,   105,
     108,   109,   109
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     4,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     0,     4,     0,     0,     0,
      10,     0,     0,     9,     1,     0,     4,     2,     1,     1,
       1,     1,     3,     1,     0,     0,     5,     0,     0,     0,
       0,    12,     2,     2,     2,     0,     4,     2,     1,     3,
       3,     1,     0,     0,     6,     1,     1,     1,     0,     4,
       0,     4,     1,     0,     4,     0,     4,     1,     1,     1,
       1,     1,     3,     0,     0,     8,     5,     0,     0,     8,
       3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     2,     0,     1,    15,    45,     0,    21,
       0,     0,    14,     0,     5,     6,     9,    12,    13,    10,
      11,     8,     0,     0,     0,     0,    42,    44,    43,     4,
       7,     0,    51,     0,    48,     0,    68,    69,    70,    71,
       0,     0,    73,    77,    17,    24,     0,    62,    67,    28,
      29,     0,    16,     0,    46,    47,     0,     0,    27,     0,
       0,     0,     0,    30,    31,    25,    58,    60,     0,    63,
      65,     0,     0,    55,    56,    57,    50,    49,    72,     0,
       0,    18,     0,     0,     0,    32,     0,     0,    22,    53,
      74,    78,     0,    26,    59,    61,    64,    66,     0,     0,
       0,     0,     0,     0,    54,     0,     0,    19,    33,     0,
       0,     0,     0,     0,     0,     0,     0,    23,     0,    75,
      81,     0,    79,    20,    35,    38,     0,     0,    80,     0,
       0,     0,    82,    36,     0,    76,     0,    39,     0,     0,
      40,     0,    41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    13,    14,    15,    16,    22,    17,
      62,    92,   114,    18,    25,    98,    44,    82,    65,    45,
     109,   115,   129,   116,   130,   138,   141,    19,    20,    21,
      23,    33,    34,    35,    53,    99,    76,    46,    83,    84,
      47,    86,    87,    48,    49,    60,   100,   111,    50,    61,
     101,   113,   121
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -97
static const yytype_int8 yypact[] =
{
       1,   -97,    15,   -97,    -2,   -97,   -97,   -97,    28,   -97,
       6,    20,   -97,    12,    -2,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,    29,    65,    -6,    39,   -97,   -97,   -97,   -97,
     -97,    47,    53,     3,   -97,    -7,   -97,   -97,   -97,   -97,
      47,    47,   -97,   -97,   -97,    41,    45,    48,   -97,   -97,
     -97,    -6,    52,    54,   -97,   -97,   -22,    65,   -97,    21,
      56,    58,    60,   -97,   -97,   -97,   -97,   -97,    47,   -97,
     -97,    61,    75,   -97,   -97,   -97,   -97,   -97,   -97,    76,
      77,   -97,    47,    47,    47,    52,    47,    47,   -97,   -97,
     -97,   -97,    46,   -97,    48,    48,   -97,   -97,    49,    64,
      59,    62,    -2,    -2,   -97,    63,    69,   -97,    23,    50,
      47,    74,    47,    78,    57,    55,    66,   -97,     7,   -97,
       9,    73,   -97,   -97,   -97,   -97,    47,    47,   -97,    -2,
      80,     5,   -97,   -97,    -6,   -97,    81,   -97,    -2,    68,
     -97,    -2,   -97
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -97,   -97,   -97,   -97,   -96,   -97,    91,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -50,   -97,   -97,   -29,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   -25,   -97,   -97,   -97,   -97,   -31,   -97,   -97,
     -11,   -97,   -97,   -12,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   -20
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -53
static const yytype_int16 yytable[] =
{
      52,    71,    36,    37,    38,    39,   107,   108,    55,     6,
      59,    58,    56,     1,    32,     5,    40,    26,    41,    66,
      67,    66,    67,    66,    67,    29,    57,    73,    74,    75,
      27,    28,    77,   133,   135,    66,    67,    85,     7,   126,
       8,   127,   139,     9,    54,   142,    78,    31,    42,    43,
      10,    11,    24,    93,    12,    36,    37,    38,    39,    66,
      67,    63,    64,    51,    69,    70,    66,    67,    68,   -34,
     -37,    41,    94,    95,    96,    97,    32,   -52,    72,   118,
      79,   120,    80,    89,   136,    81,    88,    90,    91,   104,
     102,   110,   105,   103,   106,   131,   120,   112,   117,   119,
     123,   124,   128,   122,   134,    30,   137,   132,     0,     0,
       0,     0,     0,   125,   140
};

static const yytype_int16 yycheck[] =
{
      31,    51,     8,     9,    10,    11,   102,   103,    33,    11,
      41,    40,    19,    12,    11,     0,    22,    11,    24,    14,
      15,    14,    15,    14,    15,    13,    33,    49,    50,    51,
      10,    11,    57,   129,    29,    14,    15,    68,    40,    32,
      42,    32,   138,    45,    41,   141,    25,    18,    54,    55,
      52,    53,    24,    82,    56,     8,     9,    10,    11,    14,
      15,    20,    21,    24,    16,    17,    14,    15,    23,    46,
      47,    24,    83,    84,    86,    87,    11,    24,    24,   110,
      24,   112,    24,     8,   134,    25,    25,    11,    11,    25,
      44,    28,    33,    44,    32,   126,   127,    28,    48,    25,
      43,    46,    29,    25,    24,    14,    25,   127,    -1,    -1,
      -1,    -1,    -1,    47,    46
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    58,    59,    60,     0,    11,    40,    42,    45,
      52,    53,    56,    61,    62,    63,    64,    66,    70,    84,
      85,    86,    65,    87,    24,    71,    11,    10,    11,    13,
      63,    18,    11,    88,    89,    90,     8,     9,    10,    11,
      22,    24,    54,    55,    73,    76,    94,    97,   100,   101,
     105,    24,    94,    91,    41,    89,    19,    33,    76,    94,
     102,   106,    67,    20,    21,    75,    14,    15,    23,    16,
      17,    73,    24,    49,    50,    51,    93,    89,    25,    24,
      24,    25,    74,    95,    96,    94,    98,    99,    25,     8,
      11,    11,    68,    76,    97,    97,   100,   100,    72,    92,
     103,   107,    44,    44,    25,    33,    32,    61,    61,    77,
      28,   104,    28,   108,    69,    78,    80,    48,    94,    25,
      94,   109,    25,    43,    46,    47,    32,    32,    29,    79,
      81,    94,   109,    61,    24,    29,    73,    25,    82,    61,
      46,    83,    61
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 246 "Sintactico.y"
    {
							printf("COMPILACION EXITOSA\n");
						}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 251 "Sintactico.y"
    {
							printf("inicio del programa\n");
						}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 256 "Sintactico.y"
    {
							printf("fin del programa\n");
	             		}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 262 "Sintactico.y"
    {
							printf("bloque\n");
						}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 268 "Sintactico.y"
    {

						}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 273 "Sintactico.y"
    {

						}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 279 "Sintactico.y"
    {
							printf("bloque de declaracion\n");
						}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 284 "Sintactico.y"
    {
	                 		printf("asignacion\n");
	                 	}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 289 "Sintactico.y"
    {
	                 		printf("lectura\n");
	                 	}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 294 "Sintactico.y"
    {
							printf("escritura\n");
						}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 299 "Sintactico.y"
    {
	                 		printf("iteracion\n");
	                 	}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 304 "Sintactico.y"
    {
	                 		printf("seleccion\n");
	                 	}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 309 "Sintactico.y"
    {
							printf("comentario\n");
						}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 315 "Sintactico.y"
    {
							if(tablaVariables[buscarEnTablaDeSimbolos(sectorVariables,(yyvsp[(1) - (1)].cadena))].tipo==sinTipo)
							{
								yyerrormsj((yyvsp[(1) - (1)].cadena),ErrorSintactico,ErrorIdNoDeclarado,"");
							}
							esAsignacion=1;
							printf("asignacion: %s\t", (yyvsp[(1) - (1)].cadena));
							tipoAsignacion=tablaVariables[buscarEnTablaDeSimbolos(sectorVariables,(yyvsp[(1) - (1)].cadena))].tipo;
							ponerEnPolaca(&polaca,tablaVariables[buscarEnTablaDeSimbolos(sectorVariables,(yyvsp[(1) - (1)].cadena))].nombre);
							printf("(tipo: %s)\n",obtenerTipo(sectorVariables,tipoAsignacion));
						}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 327 "Sintactico.y"
    {
							esAsignacion=0;
							tipoAsignacion=sinTipo;
							ponerEnPolaca(&polaca,"=");
							printf("fin asignacion\n");
						}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 336 "Sintactico.y"
    {
							tipoCondicion=condicionWhile;
						}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 340 "Sintactico.y"
    {
							printf("while\n");
						}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 344 "Sintactico.y"
    {
							printf("inicio while\n");
							t_info info;
							info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
							info.nro=contadorWhile++;
							sprintf(info.cadena,"#repeat_%d",info.nro);
							ponerEnPolaca(&polaca,info.cadena);
							sprintf(info.cadena,"$repeat_%d",info.nro);
							ponerEnPila(&pilaWhile,&info);
						}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 355 "Sintactico.y"
    {
							printf("fin while\n");
							sacarDePila(&pilaWhile);
						}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 362 "Sintactico.y"
    {
							printf("if\n");
							t_info info;
							info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
							info.nro=contadorIf++;
							sprintf(info.cadena,"#if_%d",info.nro);
							ponerEnPolaca(&polaca,info.cadena);
							ponerEnPila(&pilaIf,&info);
							tipoCondicion=condicionIf;
						}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 373 "Sintactico.y"
    {
							char aux[10];
					 		sprintf(aux,"#then_if_%d",topeDePila(&pilaIf)->nro);
					 		ponerEnPolaca(&polaca,aux);
						}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 380 "Sintactico.y"
    {
							printf("endif\n");
							char aux[20];
							sprintf(aux,"#endif_%d",sacarDePila(&pilaIf)->nro);
							ponerEnPolaca(&polaca,aux);
						}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 389 "Sintactico.y"
    {
							printf("comparacion\n");
							switch(tipoCondicion)
							{
								case condicionIf:
									topeDePila(&pilaIf)->andOr=condicionSimple;
									topeDePila(&pilaIf)->salto1=contadorPolaca+1;
									ponerEnPolaca(&polaca,"CMP");
									ponerEnPolaca(&polaca,"");
									ponerEnPolaca(&polaca,obtenerSalto(inverso));
									break;

								case condicionWhile:
									topeDePila(&pilaWhile)->andOr=condicionSimple;
									ponerEnPolaca(&polaca,"CMP");
							 		ponerEnPolaca(&polaca,topeDePila(&pilaWhile)->cadena);
									ponerEnPolaca(&polaca,obtenerSalto(normal));
									char aux[20];
									sprintf(aux,"#end_repeat_%d",topeDePila(&pilaWhile)->nro);
									ponerEnPolaca(&polaca,aux);
									break;
							}
						}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 415 "Sintactico.y"
    {
							printf("and_or\n");	
							switch(tipoCondicion)
							{
								case condicionIf:
									switch(topeDePila(&pilaIf)->andOr){
										case and:
											topeDePila(&pilaIf)->salto2=contadorPolaca+1;
											ponerEnPolaca(&polaca,"CMP");
											ponerEnPolaca(&polaca,"");
											ponerEnPolaca(&polaca,obtenerSalto(inverso));
											break;

										case or:
											topeDePila(&pilaIf)->salto2=contadorPolaca+1;
											ponerEnPolaca(&polaca,"CMP");
											ponerEnPolaca(&polaca,"");
											ponerEnPolaca(&polaca,obtenerSalto(normal));
											break;
									}
									break;

								case condicionWhile:
									switch(topeDePila(&pilaWhile)->andOr){
										case and:
											ponerEnPolaca(&polaca,"CMP");
									 		char aux[20];
											sprintf(aux,"$end_repeat_%d",topeDePila(&pilaWhile)->nro);
											ponerEnPolaca(&polaca,aux);
											ponerEnPolaca(&polaca,obtenerSalto(inverso));
											break;

										case or:
											ponerEnPolaca(&polaca,"CMP");
									 		ponerEnPolaca(&polaca,topeDePila(&pilaWhile)->cadena);
											ponerEnPolaca(&polaca,obtenerSalto(normal));
											break;
									}
									break;
							}
						}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 457 "Sintactico.y"
    {
	                  		switch(tipoCondicion)
	                  		{
								case condicionIf:
									topeDePila(&pilaIf)->salto1=contadorPolaca+1;
									ponerEnPolaca(&polaca,"CMP");
									ponerEnPolaca(&polaca,"");
									ponerEnPolaca(&polaca,obtenerSalto(inverso));
									break;

								case condicionWhile:
									ponerEnPolaca(&polaca,"CMP");
							 		ponerEnPolaca(&polaca,topeDePila(&pilaWhile)->cadena);
									ponerEnPolaca(&polaca,obtenerSalto(normal));
									char aux[20];
									sprintf(aux,"#end_repeat_%d",topeDePila(&pilaWhile)->nro);
									ponerEnPolaca(&polaca,aux);
									break;
							}
	                  	}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 479 "Sintactico.y"
    {
							printf("not\n");
							switch(tipoCondicion)
							{
								case condicionIf:
									topeDePila(&pilaIf)->andOr=condicionSimple;
									topeDePila(&pilaIf)->salto1=contadorPolaca+1;
									ponerEnPolaca(&polaca,"CMP");
									ponerEnPolaca(&polaca,"");
									ponerEnPolaca(&polaca,obtenerSalto(normal));
									break;

								case condicionWhile:
									topeDePila(&pilaWhile)->andOr=condicionSimple;
									ponerEnPolaca(&polaca,"CMP");
							 		ponerEnPolaca(&polaca,topeDePila(&pilaWhile)->cadena);
									ponerEnPolaca(&polaca,obtenerSalto(inverso));
									char aux[20];
									sprintf(aux,"#end_repeat_%d",topeDePila(&pilaWhile)->nro);
									ponerEnPolaca(&polaca,aux);
									break;
							}
	                  	}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 504 "Sintactico.y"
    {
							printf("condición con between\n");
						}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 509 "Sintactico.y"
    {
							printf("condición con in list\n");
						}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 515 "Sintactico.y"
    {
							if(tipoCondicion==condicionIf)
							{
								topeDePila(&pilaIf)->andOr=and;
							}
							else
							{
								topeDePila(&pilaWhile)->andOr=and;
							}
						}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 526 "Sintactico.y"
    {
							if(tipoCondicion==condicionIf)
							{
								topeDePila(&pilaIf)->andOr=or;
							}
							else
							{
								topeDePila(&pilaWhile)->andOr=or;
							}
						}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 538 "Sintactico.y"
    {strcpy(ultimoComparador,(yyvsp[(2) - (3)].cadena));}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 542 "Sintactico.y"
    {
							printf("if true\n");
							char aux[10];
					 		sprintf(aux,"$endif_%d",topeDePila(&pilaIf)->nro);
					 		if(topeDePila(&pilaIf)->andOr==and||topeDePila(&pilaIf)->andOr==or)
					 			ponerEnPolacaNro(&polaca,topeDePila(&pilaIf)->salto2,aux);
					 		ponerEnPolacaNro(&polaca,topeDePila(&pilaIf)->salto1,aux);
						}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 552 "Sintactico.y"
    {
	                  		printf("if true\n");
	                  		char aux[10];
					 		sprintf(aux,"$endif_%d",topeDePila(&pilaIf)->nro);
					 		ponerEnPolaca(&polaca,aux);
					 		ponerEnPolaca(&polaca,"BI");
	                  	}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 560 "Sintactico.y"
    {
	                    	printf("else\n");
	                    	char aux[10];
					 		sprintf(aux,"#else_%d",topeDePila(&pilaIf)->nro);
					 		ponerEnPolaca(&polaca,aux);
	                    }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 567 "Sintactico.y"
    {
	                    	printf("if false\n");
					 		char aux[10];
					 		sprintf(aux,"$else_%d",topeDePila(&pilaIf)->nro);
					 		if(topeDePila(&pilaIf)->andOr==and)
					 		{
					 			ponerEnPolacaNro(&polaca,topeDePila(&pilaIf)->salto2,aux);
					 		}
					 		else
					 		{
					 			if(topeDePila(&pilaIf)->andOr==or)
					 			{
					 				sprintf(aux,"$then_if_%d",topeDePila(&pilaIf)->nro);
					 				ponerEnPolacaNro(&polaca,topeDePila(&pilaIf)->salto2,aux);
					 			}
					 		}
					 		sprintf(aux,"$else_%d",topeDePila(&pilaIf)->nro);
					 		ponerEnPolacaNro(&polaca,topeDePila(&pilaIf)->salto1,aux);
	                    }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 588 "Sintactico.y"
    {
							printf("if true\n");
	                  		char aux[10];
					 		sprintf(aux,"$endif_%d",topeDePila(&pilaIf)->nro);
					 		ponerEnPolaca(&polaca,aux);
					 		ponerEnPolaca(&polaca,"BI");
						}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 596 "Sintactico.y"
    {
							printf("elsif");
							t_info info;
							info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
							info.nro=contadorIf++;
							sprintf(info.cadena,"#if_%d",info.nro);
							ponerEnPolaca(&polaca,info.cadena);
							ponerEnPila(&pilaIf,&info);
							tipoCondicion=condicionIf;
						}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 607 "Sintactico.y"
    {
							char aux[10];
					 		sprintf(aux,"#then_if_%d",topeDePila(&pilaIf)->nro);
					 		ponerEnPolaca(&polaca,aux);
						}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 614 "Sintactico.y"
    {
							printf("else\n");
	                    	char aux[10];
					 		sprintf(aux,"#else_%d",topeDePila(&pilaIf)->nro);
					 		ponerEnPolaca(&polaca,aux);
						}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 621 "Sintactico.y"
    {
							printf("if false\n");
					 		char aux[10];
					 		sprintf(aux,"$else_%d",topeDePila(&pilaIf)->nro);
					 		if(topeDePila(&pilaIf)->andOr==and)
					 		{
					 			ponerEnPolacaNro(&polaca,topeDePila(&pilaIf)->salto2,aux);
					 		}
					 		else
					 		{
					 			if(topeDePila(&pilaIf)->andOr==or)
					 			{
					 				sprintf(aux,"$then_if_%d",topeDePila(&pilaIf)->nro);
					 				ponerEnPolacaNro(&polaca,topeDePila(&pilaIf)->salto2,aux);
					 			}
					 		}
					 		sprintf(aux,"$else_%d",topeDePila(&pilaIf)->nro);
					 		ponerEnPolacaNro(&polaca,topeDePila(&pilaIf)->salto1,aux);
						}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 643 "Sintactico.y"
    {
							printf("read id\n");
							if(tablaVariables[buscarEnTablaDeSimbolos(sectorVariables,(yyvsp[(1) - (2)].cadena))].tipo==sinTipo)
							{
								yyerrormsj((yyvsp[(1) - (2)].cadena),ErrorSintactico,ErrorIdNoDeclarado,"");
							}
							ponerEnPolaca(&polaca,tablaVariables[buscarEnTablaDeSimbolos(sectorVariables,(yyvsp[(2) - (2)].cadena))].nombre);
							ponerEnPolaca(&polaca,"READ");
						}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 655 "Sintactico.y"
    {
	                    	printf("write id\n");
	                    	if(tablaVariables[buscarEnTablaDeSimbolos(sectorVariables,(yyvsp[(1) - (2)].cadena))].tipo==sinTipo)
	                    	{
								yyerrormsj((yyvsp[(1) - (2)].cadena),ErrorSintactico,ErrorIdNoDeclarado,"");
	                    	}
							ponerEnPolaca(&polaca,tablaVariables[buscarEnTablaDeSimbolos(sectorVariables,(yyvsp[(2) - (2)].cadena))].nombre);
							ponerEnPolaca(&polaca,"WRITE");
	                    }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 666 "Sintactico.y"
    {
 							printf("write string\n");
							ponerEnPolaca(&polaca,tablaConstantes[buscarEnTablaDeSimbolos(sectorConstantes,(yyvsp[(2) - (2)].cadena))].nombre);
							ponerEnPolaca(&polaca,"WRITE");
 						}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 674 "Sintactico.y"
    {
							printf("bloque de declaracion\n");
						}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 678 "Sintactico.y"
    {
							printf("fin bloque de declaracion\n");
						}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 684 "Sintactico.y"
    {
							printf("múltiple\n");
						}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 694 "Sintactico.y"
    {
							contadorListaVar=0;
						}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 700 "Sintactico.y"
    {
							int posicion=buscarEnTablaDeSimbolos(sectorVariables,yylval.cadena);
							indicesParaAsignarTipo[contadorListaVar++]=posicion;
						}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 706 "Sintactico.y"
    {
							int posicion=buscarEnTablaDeSimbolos(sectorVariables,yylval.cadena);
							indicesParaAsignarTipo[contadorListaVar++]=posicion;
						}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 711 "Sintactico.y"
    {
							if(atoi((yyvsp[(4) - (4)].cadena))<=0)
							{
								yyerrormsj((yyvsp[(3) - (4)].cadena),ErrorSintactico,ErrorOperacionNoValida,(yyvsp[(4) - (4)].cadena));
							}
							tablaVariables[buscarEnTablaDeSimbolos(sectorVariables,(yyvsp[(3) - (4)].cadena))].limite=atoi((yyvsp[(4) - (4)].cadena));
						}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 722 "Sintactico.y"
    {
							int posicion=buscarEnTablaDeSimbolos(sectorVariables,yylval.cadena);
							printf("Tipo de a: %s", obtenerTipo(sectorVariables, tablaVariables[posicion].tipo));
							if(strcmp("sin tipo",(const char*)obtenerTipo(sectorVariables, tablaVariables[posicion].tipo)) == 0)
							{
								tablaVariables[posicion].tipo=tipoInt;
							}
							else
							{
								yyerrormsj(tablaVariables[posicion].valor,ErrorSintactico,ErrorIdRepetida,"");
							}										
							
							printf("tipo entero\n");							
						}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 737 "Sintactico.y"
    {
							int posicion=buscarEnTablaDeSimbolos(sectorVariables,yylval.cadena);
							printf("Tipo de a: %s", obtenerTipo(sectorVariables, tablaVariables[posicion].tipo));
							if(strcmp("sin tipo",(const char*)obtenerTipo(sectorVariables, tablaVariables[posicion].tipo)) == 0)
							{
								tablaVariables[posicion].tipo=tipoFloat;
							}
							else
							{
								yyerrormsj(tablaVariables[posicion].valor,ErrorSintactico,ErrorIdRepetida,"");
							}
							
							printf("tipo flotante\n");
						}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 752 "Sintactico.y"
    {	
							int posicion=buscarEnTablaDeSimbolos(sectorVariables,yylval.cadena);
							printf("Tipo de a: %s", obtenerTipo(sectorVariables, tablaVariables[posicion].tipo));
							if(strcmp("sin tipo",(const char*)obtenerTipo(sectorVariables, tablaVariables[posicion].tipo)) == 0)
							{
								tablaVariables[posicion].tipo=tipoString;
							}
							else
							{
								yyerrormsj(tablaVariables[posicion].valor,ErrorSintactico,ErrorIdRepetida,"");
							}
							
							printf("tipo string\n");
						}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 769 "Sintactico.y"
    {
							printf("+\n");
							auxiliaresNecesarios++;
					    	if(esAsignacion==1&&tipoAsignacion==tipoString)
					    	{
								yyerrormsj("suma", ErrorSintactico,ErrorOperacionNoValida,"");
					    	}
						}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 778 "Sintactico.y"
    {
							ponerEnPolaca(&polaca,"+");
						}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 783 "Sintactico.y"
    {
							printf("-\n");
							auxiliaresNecesarios++;
							if(esAsignacion==1&&tipoAsignacion==tipoString)
							{
								yyerrormsj("resta", ErrorSintactico,ErrorOperacionNoValida,"");
							}
						}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 792 "Sintactico.y"
    {
							ponerEnPolaca(&polaca,"-");
						}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 797 "Sintactico.y"
    {
							printf("termino\n");
						}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 803 "Sintactico.y"
    {
							printf("*\n");
							auxiliaresNecesarios++;
					    	if(esAsignacion==1&&tipoAsignacion==tipoString)
					    	{
								yyerrormsj("multiplicacion", ErrorSintactico,ErrorOperacionNoValida,"");
					    	}
						}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 812 "Sintactico.y"
    {
	                    	ponerEnPolaca(&polaca,"*");
	                    }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 817 "Sintactico.y"
    {
							printf("/\n");
							auxiliaresNecesarios++;
					    	if(esAsignacion==1&&tipoAsignacion==tipoString)
								yyerrormsj("division", ErrorSintactico,ErrorOperacionNoValida,"");
	                  	}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 824 "Sintactico.y"
    {
	                  		ponerEnPolaca(&polaca,"/");
	                  	}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 829 "Sintactico.y"
    {
							printf("factor\n");
	                    }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 835 "Sintactico.y"
    {
					    	printf("CTE_INT: %s\n", (yyvsp[(1) - (1)].cadena));
				    		if(esAsignacion==1&&tipoAsignacion!=tipoInt)
				    		{
				    			yyerrormsj((yyvsp[(1) - (1)].cadena), ErrorSintactico,ErrorConstanteDistintoTipo,"");
				    		}
							ponerEnPolaca(&polaca,tablaConstantes[buscarEnTablaDeSimbolos(sectorConstantes,(yyvsp[(1) - (1)].cadena))].nombre);
					    }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 845 "Sintactico.y"
    {
					    	printf("CTE_FLOAT: %s\n", (yyvsp[(1) - (1)].cadena));
					    	if(esAsignacion==1&&tipoAsignacion!=tipoFloat)
					    	{
					    		yyerrormsj((yyvsp[(1) - (1)].cadena), ErrorSintactico,ErrorConstanteDistintoTipo,"");
					    	}
							ponerEnPolaca(&polaca,tablaConstantes[buscarEnTablaDeSimbolos(sectorConstantes,(yyvsp[(1) - (1)].cadena))].nombre);
					    }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 855 "Sintactico.y"
    {
							printf("CTE_STRING: %s\n", (yyvsp[(1) - (1)].cadena));
							if(esAsignacion==1&&tipoAsignacion!=tipoString)
							{
					    		yyerrormsj((yyvsp[(1) - (1)].cadena), ErrorSintactico,ErrorConstanteDistintoTipo,"");
							}
							ponerEnPolaca(&polaca,tablaConstantes[buscarEnTablaDeSimbolos(sectorConstantes,(yyvsp[(1) - (1)].cadena))].nombre);
						}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 865 "Sintactico.y"
    {
	                  		printf("id\n");
	                  		printf("%s\n", yylval.cadena);
	                  		int posicion=buscarEnTablaDeSimbolos(sectorVariables,yylval.cadena);
							indicesParaAsignarTipo[contadorListaVar++]=posicion;
					    	if(tablaVariables[buscarEnTablaDeSimbolos(sectorVariables,(yyvsp[(1) - (1)].cadena))].tipo==sinTipo)
					    	{
								yyerrormsj((yyvsp[(1) - (1)].cadena),ErrorSintactico,ErrorIdNoDeclarado,"");
					    	}
				    		if(esAsignacion==1&& tablaVariables[buscarEnTablaDeSimbolos(sectorVariables,(yyvsp[(1) - (1)].cadena))].tipo!=tipoAsignacion)
				    		{
								yyerrormsj((yyvsp[(1) - (1)].cadena), ErrorSintactico,ErrorIdDistintoTipo,"");
				    		}
							ponerEnPolaca(&polaca,tablaVariables[buscarEnTablaDeSimbolos(sectorVariables,(yyvsp[(1) - (1)].cadena))].nombre);
	                  	}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 885 "Sintactico.y"
    {
							printf("between\n");
							contadorBetween++;
							t_info info;
							info.nro = contadorBetween;
							info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
							sprintf(info.cadena,"#between_%d",info.nro);
							ponerEnPolaca(&polaca,info.cadena);
							if(info.cadena==NULL){
								printf("Error al solicitar memoria\n");
								exit(1);
							}
							sprintf(info.cadena,"#between_%d",info.nro);
							ponerEnPolaca(&polaca,info.cadena);
							info.cantExpresiones=0;
							ponerEnPila(&pilaBetween,&info);
						}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 903 "Sintactico.y"
    {
							printf("id paramBetween\n");
						}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 907 "Sintactico.y"
    {
							printf("rango de expresiones\n");
						}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 913 "Sintactico.y"
    {
							printf("rango\n");
						}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 919 "Sintactico.y"
    {
							printf("in list\n");
							contadorInList++;
							t_info info;
							info.nro = contadorInList;
							info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
							sprintf(info.cadena,"#inlist_%d",info.nro);
							ponerEnPolaca(&polaca,info.cadena);
							if(info.cadena==NULL){
								printf("Error al solicitar memoria\n");
								exit(1);
							}
							sprintf(info.cadena,"#between_%d",info.nro);
							ponerEnPolaca(&polaca,info.cadena);
							info.cantExpresiones=0;
							ponerEnPila(&pilaInList,&info);
						}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 937 "Sintactico.y"
    {
							printf("id paramInList\n");
						}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 941 "Sintactico.y"
    {
							printf("lista de expresiones\n");
							printf("Expresiones en InList_%d: %d\n", topeDePila(&pilaInList)->nro,topeDePila(&pilaInList)->cantExpresiones);
							char aux[50];
							sprintf(aux,"%d.0",topeDePila(&pilaInList)->cantExpresiones);
							insertarEnTablaDeSimbolos(sectorConstantes,tipoFloat,aux);
							sprintf(aux,"%s",tablaConstantes[buscarEnTablaDeSimbolos(sectorConstantes,aux)].nombre);
							ponerEnPolaca(&polaca,aux);
							sacarDePila(&pilaInList);
						}
    break;



/* Line 1455 of yacc.c  */
#line 2742 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 962 "Sintactico.y"


/* codigo */

int main(int argc,char *argv[])
{
	crearPila(&pilaIf);
	crearPila(&pilaWhile);
	crearPolaca(&polaca);

  	if ((yyin = fopen(argv[1], "rt")) == NULL)
	{
		printf("\n No se puede abrir el archivo: %s\n", argv[1]);
	}
	else
	{
		tiraDeTokens=(char*)malloc(sizeof(char));
		if(tiraDeTokens==NULL)
		{
			printf("\n Error al solicitar memoria\n");
			exit(1);
		}
		strcpy(tiraDeTokens,"");
		yyparse();
	}
	fclose(yyin);

	grabarTablaDeSimbolos(0);

	vaciarPila(&pilaIf);
	vaciarPila(&pilaWhile);

	guardarPolaca(&polaca);

  	return 0;
}

/* funciones */

int yyerrormsj(const char * info,enum tipoDeError tipoDeError ,enum error error, const char *infoAdicional)
{
	grabarTablaDeSimbolos(1);
	printf("[Linea %d] ",yylineno);
  	switch(tipoDeError){
        case ErrorSintactico:
            printf("Error sintactico. ");
            break;
        case ErrorLexico:
            printf("Error lexico. ");
            break;
    }
  	switch(error){
		case ErrorIdRepetida:
			printf("Descripcion: el id '%s' ha sido declarado más de una vez\n",info);
			break;
		case ErrorIdNoDeclarado:
			printf("Descripcion: el id '%s' no ha sido declarado\n",info);
			break;
		case ErrorOperacionNoValida:
			printf("Descripcion: La operacion %s no es válida para variables de tipo %s\n",info, obtenerTipo(sectorVariables, tipoAsignacion));
			break;
		case ErrorIdDistintoTipo:
			printf("Descripcion: La variable '%s' no es de tipo %s\n",info,obtenerTipo(sectorVariables, tipoAsignacion));
			break;
		case ErrorConstanteDistintoTipo:
			printf("Descripcion: La constante %s no es de tipo %s\n", info, obtenerTipo(sectorVariables, tipoAsignacion));
			break;
    }

  	system ("Pause");
    exit (1);
}

int yyerror()
{
	grabarTablaDeSimbolos(1);
	printf("Error sintactico \n");
	system ("Pause");
	exit (1);
}

/* primitivas de pila */

void crearPila(t_pila* pp)
{
    *pp=NULL;
}

int ponerEnPila(t_pila* pp,t_info* info)
{
    t_nodoPila* pn=(t_nodoPila*)malloc(sizeof(t_nodoPila));
    if(!pn)
        return 0;
    pn->info=*info;
    pn->psig=*pp;
    *pp=pn;
    return 1;
}

t_info * sacarDePila(t_pila* pp)
{
	t_info* info = (t_info *) malloc(sizeof(t_info));
    if(!*pp){
    	return NULL;
    }
    *info=(*pp)->info;
    *pp=(*pp)->psig;
    return info;

}

void vaciarPila(t_pila* pp)
{
    t_nodoPila* pn;
    while(*pp)
    {
        pn=*pp;
        *pp=(*pp)->psig;
        free(pn);
    }
}

t_info* topeDePila(t_pila* pila)
{
	return &((*pila)->info);
}

/* primitivas de polaca */

void crearPolaca(t_polaca* pp)
{
    *pp=NULL;
}

char * sacarDePolaca(t_polaca * pp)
{
	t_nodoPolaca* nodo;
	t_nodoPolaca* anterior;
	char * cadena = (char*)malloc(sizeof(char)*CADENA_MAXIMA);;
	nodo = *pp;

	while(nodo->psig)
	{
		anterior = nodo;
		nodo = nodo->psig;
	}

	anterior->psig=NULL;
	strcpy(cadena, nodo->info.cadena);
	free(nodo);
	return cadena;
}

int ponerEnPolaca(t_polaca* pp, char *cadena)
{
    t_nodoPolaca* pn = (t_nodoPolaca*)malloc(sizeof(t_nodoPolaca));
    if(!pn)
    {
    	printf("ponerEnPolaca: Error al solicitar memoria\n");
        return ERROR;
    }
    t_nodoPolaca* aux;
    strcpy(pn->info.cadena,cadena);
    pn->info.nro=contadorPolaca++;
    pn->psig=NULL;
    if(!*pp)
    {
    	*pp=pn;
    	return OK;
    }
    else
    {
    	aux=*pp;
    	while(aux->psig)
        	aux=aux->psig;
        aux->psig=pn;
    	return OK;
    }
}

int ponerEnPolacaNro(t_polaca* pp,int pos, char *cadena)
{
	t_nodoPolaca* aux;
	aux=*pp;
    while(aux!=NULL && aux->info.nro<pos)
    {
    	aux=aux->psig;
    }
    if(aux->info.nro==pos)
    {
    	strcpy(aux->info.cadena,cadena);
    	return OK;
    }
    else
    {
    	printf("NO ENCONTRADO\n");
    	return ERROR;
    }
    return ERROR;
}

void guardarPolaca(t_polaca *pp)
{
	FILE*pt=fopen("intermedia.txt","w+");
	t_nodoPolaca* pn;
	if(!pt)
	{
		printf("Error al crear la tabla de simbolos\n");
		return;
	}
	while(*pp)
    {
        pn=*pp;
        fprintf(pt, "%s\n",pn->info.cadena);
        *pp=(*pp)->psig;
        free(pn);
    }
	fclose(pt);
}

char* obtenerSalto(enum tipoSalto tipo)
{
	switch(tipo)
	{
		case normal:
			if(strcmp(ultimoComparador,"==")==0)
				return("BEQ");
			if(strcmp(ultimoComparador,">")==0)
				return("BGT");
			if(strcmp(ultimoComparador,"<")==0)
				return("BLT");
			if(strcmp(ultimoComparador,">=")==0)
				return("BGE");
			if(strcmp(ultimoComparador,"<=")==0)
				return("BLE");
			if(strcmp(ultimoComparador,"!=")==0)
				return("BNE");
			break;

		case inverso:
			if(strcmp(ultimoComparador,"==")==0)
				return("BNE");
			if(strcmp(ultimoComparador,">")==0)
				return("BLE");
			if(strcmp(ultimoComparador,"<")==0)
				return("BGE");
			if(strcmp(ultimoComparador,">=")==0)
				return("BLT");
			if(strcmp(ultimoComparador,"<=")==0)
				return("BGT");
			if(strcmp(ultimoComparador,"!=")==0)
				return("BEQ");
			break;
	}
}

char* obtenerSalto2(char* comparador,enum tipoSalto tipo)
{
	switch(tipo)
	{
		case normal:
			if(strcmp(comparador,"==")==0)
				return("BEQ");
			if(strcmp(comparador,">")==0)
				return("BGT");
			if(strcmp(comparador,"<")==0)
				return("BLT");
			if(strcmp(comparador,">=")==0)
				return("BGE");
			if(strcmp(comparador,"<=")==0)
				return("BLE");
			if(strcmp(comparador,"!=")==0)
				return("BNE");
			break;

		case inverso:
			if(strcmp(comparador,"==")==0)
				return("BNE");
			if(strcmp(comparador,">")==0)
				return("BLE");
			if(strcmp(comparador,"<")==0)
				return("BGE");
			if(strcmp(comparador,">=")==0)
				return("BLT");
			if(strcmp(comparador,"<=")==0)
				return("BGT");
			if(strcmp(comparador,"!=")==0)
				return("BEQ");
			break;
	}
}

/* assembler */

void generar_assembler2(t_polaca *pp)
{
		t_nodoPolaca* aux;
		aux=*pp;
		int i;
		int nroAuxReal=0;
		int nroAuxEntero=0;
		char aux1[50]="aux\0";
		char aux2[10];
		enum tipoDato ultimoTipo=sinTipo;
		char ultimaCadena[CADENA_MAXIMA];
		int huboAsignacion=TRUE;
		FILE* pf=fopen("final.asm","w+");
		if(!pf)
		{
			printf("Error al guardar el archivo assembler.\n");
			exit(1);
		}
		
		// cabecera de assembler
		fprintf(pf,"include macros2.asm\n");
		fprintf(pf,"include number.asm\n\n");
		fprintf(pf,"include numbers.asm\n\n");
		fprintf(pf,".MODEL LARGE\n.STACK 200h\n.386\n.387\n.DATA\n\n\tMAXTEXTSIZE equ 50\n");
		
		// declaración de variables
		for(i = 0; i<indiceVariable; i++)
		{
			fprintf(pf,"\t@%s ",tablaVariables[i].nombre);
			switch(tablaVariables[i].tipo){
				case tipoInt:
					fprintf(pf,"\tDD 0.0\n");
					break;
				case tipoFloat:
					fprintf(pf,"\tDD 0.0\n");
					break;
				case tipoString:
					fprintf(pf,"\tDB MAXTEXTSIZE dup (?),'$'\n");
					break;
			}
		}

		// declaración de constantes
		for(i = 0; i<indiceConstante; i++)
		{
			switch(tablaConstantes[i].tipo)
			{
				case tipoInt:
					fprintf(pf,"\t@%s \tDW %d\n",tablaConstantes[i].nombre,atoi(tablaConstantes[i].valor));
					break;
				case tipoFloat:
					fprintf(pf,"\t@%s \tDD %s\n",tablaConstantes[i].nombre,tablaConstantes[i].valor);
					break;
				case tipoString:
					fprintf(pf,"\t@%s \tDB \"%s\",'$',%d dup(?)\n",tablaConstantes[i].nombre,tablaConstantes[i].valor,50-strlen(tablaConstantes[i].valor));
					break;

			}
		}

		// declaración de auxiliares
		for(i=0;i<auxiliaresNecesarios;i++)
		{
			fprintf(pf,"\t@_auxR%d \tDD 0.0\n",i);
		}
		for(i=0;i<auxiliaresNecesarios;i++)
		{
			fprintf(pf,"\t@_auxE%d \tDW 0\n",i);
		}

		// zona de código
		fprintf(pf,"\n.CODE\n.startup\n\tmov AX,@DATA\n\tmov DS,AX\n\n\tFINIT\n\n");

		// generación de assembler recorriendo la polaca
	    while(aux!=NULL)
	    {
	    	char linea[CADENA_MAXIMA];
	    	int pos;
	    	strcpy(linea,aux->info.cadena);

	    	// para variables
	    	if((pos=buscarEnTablaDeSimbolosASM(sectorVariables,linea))!=NO_ENCONTRADO)
	    	{
	    		t_info info;
	    		info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
	    		strcpy(info.cadena,linea);
	    		info.tipo=tablaVariables[pos].tipo;
	    		if(pilaASM!=NULL||huboAsignacion==FALSE)
	    		{
	    			huboAsignacion=TRUE;
	    		}
	    		else
	    		{
	    			huboAsignacion=FALSE;
	    		}
	    		ponerEnPila(&pilaASM,&info);
	    		ultimoTipo=info.tipo;
		    }

	    	// para constantes
	    	if((pos=buscarEnTablaDeSimbolosASM(sectorConstantes,linea))!=NO_ENCONTRADO)
	    	{
	    		t_info info2;
	    		info2.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
	    		strcpy(info2.cadena,linea);
	    		info2.tipo=tablaConstantes[pos].tipo;
	    		ponerEnPila(&pilaASM,&info2);
	    		if(info2.tipo!=tipoString)
	    		{
		    		if(pilaASM==NULL)
		    		{
		    			huboAsignacion=FALSE;
		    		}
		    		ultimoTipo=info2.tipo;	
		    	}
		    	else
		    	{
		    		ultimoTipo=info2.tipo;
		    	}
		    }

		    // operadores aritméticos
		    if(strcmp(linea,"*")==0)
		    {
				t_info *op1=sacarDePila(&pilaASM);
				t_info *op2;
				t_info info;
				switch(op1->tipo)
				{
					case tipoInt:
							fprintf(pf,";MULTIPLICACION DE ENTEROS\n");
							op2=sacarDePila(&pilaASM);
							fprintf(pf,"\tfild \t@%s\n", op1->cadena);
							fprintf(pf,"\tfimul \t@%s\n", op2->cadena); 
							strcpy(aux1,"_auxE");
							itoa(nroAuxEntero,aux2,10);
				   			strcat(aux1,aux2);
							fprintf(pf,"\tfistp \t@%s\n", aux1);
							info.tipo=tipoInt;
							info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
				    		strcpy(info.cadena,aux1);
				    		ponerEnPila(&pilaASM,&info);
							nroAuxEntero++;
						break;

					case tipoFloat:
						fprintf(pf,";MULTIPLICACION DE REALES\n");
						op2=sacarDePila(&pilaASM);
						fprintf(pf,"\tfld \t@%s\n", op1->cadena);
						fprintf(pf,"\tfld \t@%s\n", op2->cadena);
						fprintf(pf,"\tfmul\n");
						strcpy(aux1,"_auxR");
						itoa(nroAuxReal,aux2,10);
			   			strcat(aux1,aux2);
						fprintf(pf,"\tfstp \t@%s\n", aux1);
						info.tipo=tipoFloat;
						info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
				    	strcpy(info.cadena,aux1);
				    	ponerEnPila(&pilaASM,&info);
						nroAuxReal++;
						break;
				}
			}

			if(strcmp(linea,"+")==0)
			{
				t_info *op1=sacarDePila(&pilaASM);
				t_info *op2;
				t_info info;
				switch(op1->tipo)
				{
					case tipoInt:
							fprintf(pf,";SUMA DE ENTEROS\n");
							op2=sacarDePila(&pilaASM);
							fprintf(pf,"\tfild \t@%s\n", op1->cadena);
							fprintf(pf,"\tfiadd \t@%s\n", op2->cadena); 
							strcpy(aux1,"_auxE");
							itoa(nroAuxEntero,aux2,10);
				   			strcat(aux1,aux2);
							fprintf(pf,"\tfistp \t@%s\n", aux1);
							info.tipo=tipoInt;
							info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
				    		strcpy(info.cadena,aux1);
				    		ponerEnPila(&pilaASM,&info);
							nroAuxEntero++;
						break;

					case tipoFloat:
						fprintf(pf,";SUMA DE REALES\n");
						op2=sacarDePila(&pilaASM);
						fprintf(pf,"\tfld \t@%s\n", op1->cadena);
						fprintf(pf,"\tfld \t@%s\n", op2->cadena);
						fprintf(pf,"\tfadd\n");
						strcpy(aux1,"_auxR");
						itoa(nroAuxReal,aux2,10);
			   			strcat(aux1,aux2);
						fprintf(pf,"\tfstp \t@%s\n", aux1);
						info.tipo=tipoFloat;
						info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
				    	strcpy(info.cadena,aux1);
				    	ponerEnPila(&pilaASM,&info);
						nroAuxReal++;
						break;
				}
			}

			if(strcmp(linea,"/")==0)
			{
				t_info *op1=sacarDePila(&pilaASM);
				t_info *op2=sacarDePila(&pilaASM);;
				t_info info;
				switch(op2->tipo)
				{
					case tipoInt:
							fprintf(pf,";DIVISION DE ENTEROS\n");
							fprintf(pf,"\tfild \t@%s\n", op1->cadena);
							fprintf(pf,"\tfidivr \t@%s\n", op2->cadena); 
							strcpy(aux1,"_auxE");
							itoa(nroAuxEntero,aux2,10);
				   			strcat(aux1,aux2);
							fprintf(pf,"\tfistp \t@%s\n", aux1);
							info.tipo=tipoInt;
							info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
				    		strcpy(info.cadena,aux1);
				    		ponerEnPila(&pilaASM,&info);
							nroAuxEntero++;
						break;

					case tipoFloat:
						fprintf(pf,";DIVISION DE REALES\n");
						fprintf(pf,"\tfld \t@%s\n", op1->cadena);
						fprintf(pf,"\tfld \t@%s\n", op2->cadena);
						fprintf(pf,"\tfdivr\n");
						strcpy(aux1,"_auxR");
						itoa(nroAuxReal,aux2,10);
			   			strcat(aux1,aux2);
						fprintf(pf,"\tfstp \t@%s\n", aux1);
						info.tipo=tipoFloat;
						info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
				    	strcpy(info.cadena,aux1);
				    	ponerEnPila(&pilaASM,&info);
						nroAuxReal++;
						break;
				}
			}

			if(strcmp(linea,"-")==0)
			{
				t_info *op1=sacarDePila(&pilaASM);
				t_info *op2;
				t_info info;
				switch(op1->tipo)
				{
					case tipoInt:
							fprintf(pf,";RESTA DE ENTEROS\n");
							op2=sacarDePila(&pilaASM);
							fprintf(pf,"\tfild \t@%s\n", op1->cadena);
							fprintf(pf,"\tfisubr \t@%s\n", op2->cadena); 
							strcpy(aux1,"_auxE");
							itoa(nroAuxEntero,aux2,10);
				   			strcat(aux1,aux2);
							fprintf(pf,"\tfistp \t@%s\n", aux1);
							info.tipo=tipoInt;
							info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
				    		strcpy(info.cadena,aux1);
				    		ponerEnPila(&pilaASM,&info);
							nroAuxEntero++;
						break;

					case tipoFloat:
						fprintf(pf,";RESTA DE REALES\n");
						op2=sacarDePila(&pilaASM);
						fprintf(pf,"\tfld \t@%s\n", op1->cadena);
						fprintf(pf,"\tfld \t@%s\n", op2->cadena);
						fprintf(pf,"\tfsubr\n");
						strcpy(aux1,"_auxR");
						itoa(nroAuxReal,aux2,10);
			   			strcat(aux1,aux2);
						fprintf(pf,"\tfstp \t@%s\n", aux1);
						info.tipo=tipoFloat;
						info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
				    	strcpy(info.cadena,aux1);
				    	ponerEnPila(&pilaASM,&info);
						nroAuxReal++;
						break;
				}
			}

			// comparadores
			if(strcmp(linea,"CMP")==0)
			{
				t_info *op1= sacarDePila(&pilaASM);
				t_info *op2= sacarDePila(&pilaASM);
				if(op1->tipo==tipoFloat)
				{
					fprintf(pf,"\tfld \t@%s\n", op1->cadena);
					fprintf(pf,"\tfld \t@%s\n", op2->cadena);
				}
				else
				{
					fprintf(pf,"\tfild \t@%s\n", op1->cadena);
					fprintf(pf,"\tfild \t@%s\n", op2->cadena);
				}
			}

			//>
			if(strcmp(linea,"BLE")==0)
			{
				fprintf(pf,"\tfcomp\n\tfstsw\tax\n\tfwait\n\tsahf\n\tjbe\t\t%s\n",sacarDePila(&pilaASM)->cadena);
			}

			//<
			if(strcmp(linea,"BGE")==0)
			{
				fprintf(pf,"\tfcomp\n\tfstsw\tax\n\tfwait\n\tsahf\n\tjae\t\t%s\n",sacarDePila(&pilaASM)->cadena);
			}

			//!=
			if(strcmp(linea,"BEQ")==0)
			{
				fprintf(pf,"\tfcomp\n\tfstsw\tax\n\tfwait\n\tsahf\n\tje\t\t%s\n",sacarDePila(&pilaASM)->cadena);
			}

			//==
			if(strcmp(linea,"BNE")==0)
			{
				fprintf(pf,"\tfcomp\n\tfstsw\tax\n\tfwait\n\tsahf\n\tjne\t\t%s\n",sacarDePila(&pilaASM)->cadena);
			}

			//>=
			if(strcmp(linea,"BLT")==0)
			{
				fprintf(pf,"\tfcomp\n\tfstsw\tax\n\tfwait\n\tsahf\n\tjb\t\t%s\n",sacarDePila(&pilaASM)->cadena);
			}

			//<=
			if(strcmp(linea,"BGT")==0)
			{
				fprintf(pf,"\tfcomp\n\tfstsw\tax\n\tfwait\n\tsahf\n\tja\t\t%s\n",sacarDePila(&pilaASM)->cadena);
			}

			if(strcmp(linea,"BI")==0)
			{
				fprintf(pf,"\tjmp\t\t%s\n",sacarDePila(&pilaASM)->cadena);
			}

			// etiquetas
			if(strchr(linea, '#')!=NULL)
			{
				fprintf(pf,"%s:\n",reemplazarCaracter(linea,"#",""));
			}

			// saltos
			if(strchr(linea, '$')!=NULL)
			{
				t_info info;
				info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
		    	strcpy(info.cadena,(const char*)reemplazarCaracter(linea,"$",""));
		    	ponerEnPila(&pilaASM,&info);
			}

			if(strcmp(linea, "EXIT")==0)
			{
				fprintf(pf,"\tmov ah, 4ch\n\tint 21h\n");
			}

			// asignación
			if(strcmp(linea,"=")==0)
			{
				switch(ultimoTipo)
				{
					case tipoString:
						fprintf(pf,";ASIGNACION CADENA\n");
						fprintf(pf,"\tmov ax, @DATA\n\tmov ds, ax\n\tmov es, ax\n");
						fprintf(pf,"\tmov si, OFFSET\t@%s\n", sacarDePila(&pilaASM)->cadena);
						fprintf(pf,"\tmov di, OFFSET\t@%s\n", sacarDePila(&pilaASM)->cadena);
						fprintf(pf,"\tcall copiar\n");
						break;

					case tipoInt:
						fprintf(pf,";ASIGNACION ENTERO\n");
						t_info *op1=sacarDePila(&pilaASM);
						fprintf(pf,"\tfild \t@%s\n", op1->cadena);
						fprintf(pf,"\tfistp \t@%s\n",sacarDePila(&pilaASM)->cadena);
						huboAsignacion=TRUE;
						break;

					case tipoFloat:
						fprintf(pf,";ASIGNACION REAL\n");
						t_info *op=sacarDePila(&pilaASM);
						fprintf(pf,"\tfld \t@%s\n", op->cadena);
						fprintf(pf,"\tfstp \t@%s\n",sacarDePila(&pilaASM)->cadena);
						huboAsignacion=TRUE;
						break;
				}
			}

		    // write
			if(strcmp(linea,"WRITE")==0)
			{
				fprintf(pf,";SALIDA POR CONSOLA\n");
				switch(ultimoTipo)
				{
			    	case tipoInt:
				    	fprintf(pf,"\tdisplayInteger \t@%s,3\n\tnewLine 1\n",sacarDePila(&pilaASM)->cadena);
						break;
					case tipoFloat:
						fprintf(pf,"\tdisplayFloat \t@%s,3\n\tnewLine 1\n",sacarDePila(&pilaASM)->cadena);
						break;
					case tipoString:
						fprintf(pf,"\tdisplayString \t@%s\n\tnewLine 1\n",sacarDePila(&pilaASM)->cadena);
						break;
		    	}
			}

			// read
			if(strcmp(linea,"READ")==0)
			{
				fprintf(pf,";ENTRADA POR CONSOLA\n");
				switch(ultimoTipo)
				{
			   		case tipoInt:
						fprintf(pf,"\tgetFloat \t@%s\n",sacarDePila(&pilaASM)->cadena);
						break;
					case tipoFloat:
						fprintf(pf,"\tgetFloat \t@%s\n",sacarDePila(&pilaASM)->cadena);
						break;
					case tipoString:
						fprintf(pf,"\tgetString \t@%s\n",sacarDePila(&pilaASM)->cadena);
						break;
		    	}
		    }
	    	aux=aux->psig;
	    }

	    fprintf(pf,"\tmov ah, 4ch\n\tint 21h\n\n;FIN DEL PROGRAMA DE USUARIO\n");

	    // funciones para manejo de entrada/salida y cadenas
	    fprintf(pf,"\nstrlen proc\n\tmov bx, 0\n\tstrl01:\n\tcmp BYTE PTR [si+bx],'$'\n\tje strend\n\tinc bx\n\tjmp strl01\n\tstrend:\n\tret\nstrlen endp\n");
		fprintf(pf,"\ncopiar proc\n\tcall strlen\n\tcmp bx , MAXTEXTSIZE\n\tjle copiarSizeOk\n\tmov bx , MAXTEXTSIZE\n\tcopiarSizeOk:\n\tmov cx , bx\n\tcld\n\trep movsb\n\tmov al , '$'\n\tmov byte ptr[di],al\n\tret\ncopiar endp\n");
		fprintf(pf,"\nconcat proc\n\tpush ds\n\tpush si\n\tcall strlen\n\tmov dx , bx\n\tmov si , di\n\tpush es\n\tpop ds\n\tcall strlen\n\tadd di, bx\n\tadd bx, dx\n\tcmp bx , MAXTEXTSIZE\n\tjg concatSizeMal\n\tconcatSizeOk:\n\tmov cx , dx\n\tjmp concatSigo\n\tconcatSizeMal:\n\tsub bx , MAXTEXTSIZE\n\tsub dx , bx\n\tmov cx , dx\n\tconcatSigo:\n\tpush ds\n\tpop es\n\tpop si\n\tpop ds\n\tcld\n\trep movsb\n\tmov al , '$'\n\tmov byte ptr[di],al\n\tret\nconcat endp\n");
		
		// fin del archivo
		fprintf(pf,"\nend");
		fclose(pf);

		printf("\n--ASSEMBLER GENERADO--\n");
	}

	int buscarEnTablaDeSimbolosASM(enum sectorTabla sector, char* objetivo)
	{
		int i;
		switch(sector)
		{
			case sectorConstantes:
				for(i=0;i<indiceConstante;i++)
				{
					if(strcmp(tablaConstantes[i].nombre,objetivo)==0)
					{
						return i;
					}
				}
				return NO_ENCONTRADO;
				break;

			case sectorVariables:
				for(i=0;i<indiceVariable;i++)
				{
					if(strcmp(tablaVariables[i].nombre,objetivo)==0)
					{
						return i;
					}
				}
				return NO_ENCONTRADO;
				break;
		}
		return NO_ENCONTRADO;
}

