
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
	#include <locale.h>
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
		tipoArray,
		sinTipo
	};

	enum sectorTabla{
		sectorVariables,
		sectorConstantes
	};

	enum error{
		ErrorIdRepetida,
		ErrorIdNoDeclarado,
		ErrorArraySinTipo,
		ErrorArrayFueraDeRango,
		ErrorLimiteArrayNoPermitido,
		ErrorOperacionNoValida,
		ErrorIdDistintoTipo,
		ErrorConstanteDistintoTipo,
		ErrorArrayAsignacionMultiple
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

	/* funciones */

	int buscarEnTablaDeSimbolos(enum sectorTabla, char*);
	void grabarTablaDeSimbolos(int);
	char* obtenerTipo(enum sectorTabla, enum tipoDato);
	int yyerrormsj(char *,enum tipoDeError,enum error, const char*);
	int yyerror();
	int yylex();

	/* primitivas de pila */

	void vaciarPila(t_pila*);
	t_info* sacarDePila(t_pila*);
	void crearPila(t_pila*);
	int ponerEnPila(t_pila*,t_info*);
	t_info* topeDePila(t_pila*);

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
	int esAsignacionVectorMultiple;
	int contadorListaVar=0;
	int contadorExpresionesVector=0;
	int cantidadDeExpresionesEsperadasEnVector=0;
	int contadorIf=0;
	int contadorWhile=0;
	int auxiliaresNecesarios=0;
	char ultimoComparador[3];
	char nombreVector[CADENA_MAXIMA];
	int inicioAsignacionMultiple;
	int expresionesRestantes;
	enum tipoCondicion tipoCondicion;



/* Line 189 of yacc.c  */
#line 224 "y.tab.c"

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
     CTE_INT = 262,
     CTE_FLOAT = 263,
     CTE_STRING = 264,
     ID = 265,
     CARACTER = 266,
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
     PARENTESIS_I = 278,
     PARENTESIS_F = 279,
     LLAVE_I = 280,
     LLAVE_F = 281,
     CORCHETE_I = 282,
     CORCHETE_F = 283,
     COMENTARIO_I = 284,
     COMENTARIO_F = 285,
     PUNTO_Y_COMA = 286,
     COMA = 287,
     COMP_MAYOR_ESTR = 288,
     COMP_MENOR_ESTR = 289,
     COMP_MAYOR_IGUAL = 290,
     COMP_MENOR_IGUAL = 291,
     COMP_IGUAL = 292,
     COMP_DIST = 293,
     DECVAR = 294,
     ENDDEC = 295,
     WHILE = 296,
     ENDWHILE = 297,
     DO = 298,
     IF = 299,
     ELSE = 300,
     ELSIF = 301,
     ENDIF = 302,
     INTEGER = 303,
     FLOAT = 304,
     READ = 305,
     WRITE = 306,
     BETWEEN = 307,
     INLIST = 308
   };
#endif
/* Tokens.  */
#define DIGITO 258
#define LETRA 259
#define LETRA_MINUS 260
#define LETRA_MAYUS 261
#define CTE_INT 262
#define CTE_FLOAT 263
#define CTE_STRING 264
#define ID 265
#define CARACTER 266
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
#define PARENTESIS_I 278
#define PARENTESIS_F 279
#define LLAVE_I 280
#define LLAVE_F 281
#define CORCHETE_I 282
#define CORCHETE_F 283
#define COMENTARIO_I 284
#define COMENTARIO_F 285
#define PUNTO_Y_COMA 286
#define COMA 287
#define COMP_MAYOR_ESTR 288
#define COMP_MENOR_ESTR 289
#define COMP_MAYOR_IGUAL 290
#define COMP_MENOR_IGUAL 291
#define COMP_IGUAL 292
#define COMP_DIST 293
#define DECVAR 294
#define ENDDEC 295
#define WHILE 296
#define ENDWHILE 297
#define DO 298
#define IF 299
#define ELSE 300
#define ELSIF 301
#define ENDIF 302
#define INTEGER 303
#define FLOAT 304
#define READ 305
#define WRITE 306
#define BETWEEN 307
#define INLIST 308




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 153 "Sintactico.y"

	int entero;
	double real;
	char cadena[50];



/* Line 214 of yacc.c  */
#line 374 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 386 "y.tab.c"

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   130

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNRULES -- Number of states.  */
#define YYNSTATES  149

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     9,    11,    13,    16,    18,    20,
      22,    24,    26,    28,    32,    33,    42,    43,    52,    54,
      55,    56,    62,    63,    64,    70,    71,    75,    77,    79,
      80,    81,    87,    88,    89,    95,    96,    97,   103,   104,
     105,   111,   112,   113,   119,   120,   121,   127,   129,   130,
     131,   137,   138,   139,   140,   152,   153,   157,   160,   163,
     164,   169,   171,   174,   178,   182,   184,   186,   188,   190,
     194,   198,   200,   204,   208,   210,   212,   214,   216,   220,
     227,   233,   240,   244,   246
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    -1,    12,    56,    57,    13,    -1,    58,
      -1,    59,    -1,    58,    59,    -1,    93,    -1,    60,    -1,
      90,    -1,    92,    -1,    61,    -1,    63,    -1,    10,    18,
      98,    -1,    -1,    41,    23,    65,    24,    62,    43,    57,
      42,    -1,    -1,    44,    23,    65,    24,    64,    43,    84,
      47,    -1,    71,    -1,    -1,    -1,    71,    66,    20,    67,
      71,    -1,    -1,    -1,    71,    68,    21,    69,    71,    -1,
      -1,    22,    70,    71,    -1,   101,    -1,   103,    -1,    -1,
      -1,    98,    72,    33,    73,    98,    -1,    -1,    -1,    98,
      74,    34,    75,    98,    -1,    -1,    -1,    98,    76,    35,
      77,    98,    -1,    -1,    -1,    98,    78,    36,    79,    98,
      -1,    -1,    -1,    98,    80,    37,    81,    98,    -1,    -1,
      -1,    98,    82,    38,    83,    98,    -1,    57,    -1,    -1,
      -1,    57,    85,    45,    86,    57,    -1,    -1,    -1,    -1,
      57,    87,    46,    23,    65,    24,    88,    57,    45,    89,
      57,    -1,    -1,    50,    91,    10,    -1,    51,    10,    -1,
      51,     9,    -1,    -1,    39,    94,    95,    40,    -1,    96,
      -1,    95,    96,    -1,    10,    19,    97,    -1,    10,    32,
      96,    -1,     7,    -1,     8,    -1,     9,    -1,    99,    -1,
      98,    14,    99,    -1,    98,    15,    99,    -1,   100,    -1,
      99,    16,   100,    -1,    99,    17,   100,    -1,     7,    -1,
       8,    -1,     9,    -1,    10,    -1,    23,    98,    24,    -1,
      52,    23,    10,    32,   102,    24,    -1,    27,    98,    31,
      98,    28,    -1,    53,    23,    10,    31,   104,    24,    -1,
      27,   105,    28,    -1,    98,    -1,    98,    31,   105,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   223,   229,   228,   239,   245,   250,   256,   261,   266,
     271,   276,   281,   287,   301,   300,   309,   308,   316,   322,
     326,   321,   335,   339,   334,   348,   347,   356,   361,   368,
     372,   367,   381,   385,   380,   394,   398,   393,   407,   411,
     406,   420,   424,   419,   433,   437,   432,   446,   452,   456,
     451,   465,   469,   474,   464,   484,   483,   490,   495,   502,
     501,   511,   513,   519,   521,   524,   541,   558,   578,   583,
     588,   594,   599,   604,   610,   619,   628,   637,   645,   648,
     651,   657,   660,   666,   668
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DIGITO", "LETRA", "LETRA_MINUS",
  "LETRA_MAYUS", "CTE_INT", "CTE_FLOAT", "CTE_STRING", "ID", "CARACTER",
  "INICIO_PROGRAMA", "FIN_PROGRAMA", "OP_SUM", "OP_REST", "OP_MULT",
  "OP_DIV", "OP_ASIG", "OP_DEC", "OP_AND", "OP_OR", "OP_NOT",
  "PARENTESIS_I", "PARENTESIS_F", "LLAVE_I", "LLAVE_F", "CORCHETE_I",
  "CORCHETE_F", "COMENTARIO_I", "COMENTARIO_F", "PUNTO_Y_COMA", "COMA",
  "COMP_MAYOR_ESTR", "COMP_MENOR_ESTR", "COMP_MAYOR_IGUAL",
  "COMP_MENOR_IGUAL", "COMP_IGUAL", "COMP_DIST", "DECVAR", "ENDDEC",
  "WHILE", "ENDWHILE", "DO", "IF", "ELSE", "ELSIF", "ENDIF", "INTEGER",
  "FLOAT", "READ", "WRITE", "BETWEEN", "INLIST", "$accept", "programa",
  "$@1", "bloque", "lista_sentencias", "sentencia", "asignacion",
  "iteracion", "$@2", "seleccion", "$@3", "condicion", "$@4", "$@5", "$@6",
  "$@7", "$@8", "comparacion", "$@9", "$@10", "$@11", "$@12", "$@13",
  "$@14", "$@15", "$@16", "$@17", "$@18", "$@19", "$@20", "resto", "$@21",
  "$@22", "$@23", "$@24", "$@25", "lectura", "$@26", "escritura",
  "bloque_declaracion", "$@27", "declaraciones", "lista_id_y_tipo",
  "tipodato", "expresion", "termino", "factor", "between", "rango",
  "inlist", "lista_expresiones", "expresiones", 0
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
     305,   306,   307,   308
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    56,    55,    57,    58,    58,    59,    59,    59,
      59,    59,    59,    60,    62,    61,    64,    63,    65,    66,
      67,    65,    68,    69,    65,    70,    65,    65,    65,    72,
      73,    71,    74,    75,    71,    76,    77,    71,    78,    79,
      71,    80,    81,    71,    82,    83,    71,    84,    85,    86,
      84,    87,    88,    89,    84,    91,    90,    92,    92,    94,
      93,    95,    95,    96,    96,    97,    97,    97,    98,    98,
      98,    99,    99,    99,   100,   100,   100,   100,   100,   101,
     102,   103,   104,   105,   105
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     4,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     3,     0,     8,     0,     8,     1,     0,
       0,     5,     0,     0,     5,     0,     3,     1,     1,     0,
       0,     5,     0,     0,     5,     0,     0,     5,     0,     0,
       5,     0,     0,     5,     0,     0,     5,     1,     0,     0,
       5,     0,     0,     0,    11,     0,     3,     2,     2,     0,
       4,     1,     2,     3,     3,     1,     1,     1,     1,     3,
       3,     1,     3,     3,     1,     1,     1,     1,     3,     6,
       5,     6,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,     0,    59,     0,     0,    55,
       0,     0,     4,     5,     8,    11,    12,     9,    10,     7,
       0,     0,     0,     0,     0,    58,    57,     3,     6,    74,
      75,    76,    77,     0,    13,    68,    71,     0,     0,    61,
      25,     0,     0,     0,    18,    29,    27,    28,     0,    56,
       0,     0,     0,     0,     0,     0,     0,    60,    62,     0,
       0,     0,    14,     0,     0,     0,     0,     0,     0,     0,
       0,    16,    78,    69,    70,    72,    73,    65,    66,    67,
      63,    64,    26,     0,     0,     0,    20,    23,    30,    33,
      36,    39,    42,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,    24,    31,    34,    37,    40,    43,    46,
      47,     0,     0,    79,    83,     0,    81,    15,     0,     0,
      17,     0,     0,    82,    49,     0,     0,    84,     0,     0,
      80,    50,     0,    52,     0,     0,    53,     0,    54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    11,    12,    13,    14,    15,    85,    16,
      94,    43,    63,    98,    64,    99,    59,    44,    65,   100,
      66,   101,    67,   102,    68,   103,    69,   104,    70,   105,
     121,   128,   138,   129,   144,   147,    17,    24,    18,    19,
      21,    38,    39,    80,    45,    35,    36,    46,   108,    47,
     110,   125
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -96
static const yytype_int8 yypact[] =
{
       7,   -96,    42,    -6,   -96,     4,   -96,    25,    30,   -96,
      20,    58,    -6,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
      54,    64,    -2,    -2,    65,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,    54,    32,    -4,   -96,   -16,    -1,   -96,
     -96,    53,    55,    56,    47,    22,   -96,   -96,    63,   -96,
      17,    54,    54,    54,    54,    18,    64,   -96,   -96,    54,
      79,    83,   -96,    74,    75,    62,    66,    67,    61,    68,
      60,   -96,   -96,    -4,    -4,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,    69,    72,    71,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,    76,    77,    80,    -6,    54,    54,
      54,    54,    54,    54,    54,    54,    -6,    54,    82,    54,
      84,    57,   -96,   -96,    32,    32,    32,    32,    32,    32,
      24,    70,     3,   -96,     9,    81,   -96,   -96,    73,    78,
     -96,    54,    54,   -96,   -96,    87,    51,   -96,    -6,    -2,
     -96,   -96,    91,   -96,    -6,    85,   -96,    -6,   -96
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -96,   -96,   -96,   -95,   -96,    99,   -96,   -96,   -96,   -96,
     -96,   -23,   -96,   -96,   -96,   -96,   -96,   -44,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -28,   -96,   -19,    21,    38,   -96,   -96,   -96,
     -96,   -12
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -52
static const yytype_int16 yytable[] =
{
      48,    34,   111,    55,     5,    29,    30,    31,    32,    37,
      58,   120,    53,    54,    50,    82,    56,    51,    52,     1,
      40,    33,    20,    51,    52,    77,    78,    79,    81,    25,
      26,    51,    52,     6,   131,     7,    51,    52,     8,    57,
     132,    72,     4,   141,     9,    10,    51,    52,    22,   145,
      41,    42,   148,    23,   112,   113,   -32,   -35,   -38,   -41,
     -44,    29,    30,    31,    32,    51,    52,   -19,   -22,   -48,
     -51,    27,    73,    74,    37,    49,    60,    33,    61,   140,
      62,   114,   115,   116,   117,   118,   119,    71,   122,    83,
     124,    75,    76,    84,    86,    88,    87,    91,    93,   127,
      89,    95,    90,    96,   107,    92,   123,   109,   126,   133,
     139,    28,   136,   124,    97,   143,   142,   130,   134,   106,
     137,     0,     0,     0,   135,     0,     0,     0,     0,     0,
     146
};

static const yytype_int16 yycheck[] =
{
      23,    20,    97,    19,    10,     7,     8,     9,    10,    10,
      38,   106,    16,    17,    33,    59,    32,    14,    15,    12,
      22,    23,    18,    14,    15,     7,     8,     9,    56,     9,
      10,    14,    15,    39,    31,    41,    14,    15,    44,    40,
      31,    24,     0,   138,    50,    51,    14,    15,    23,   144,
      52,    53,   147,    23,    98,    99,    34,    35,    36,    37,
      38,     7,     8,     9,    10,    14,    15,    20,    21,    45,
      46,    13,    51,    52,    10,    10,    23,    23,    23,    28,
      24,   100,   101,   102,   103,   104,   105,    24,   107,    10,
     109,    53,    54,    10,    20,    33,    21,    36,    38,    42,
      34,    32,    35,    31,    27,    37,    24,    27,    24,    28,
      23,    12,   131,   132,    43,    24,   139,    47,    45,    43,
     132,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,
      45
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    55,    56,     0,    10,    39,    41,    44,    50,
      51,    57,    58,    59,    60,    61,    63,    90,    92,    93,
      18,    94,    23,    23,    91,     9,    10,    13,    59,     7,
       8,     9,    10,    23,    98,    99,   100,    10,    95,    96,
      22,    52,    53,    65,    71,    98,   101,   103,    65,    10,
      98,    14,    15,    16,    17,    19,    32,    40,    96,    70,
      23,    23,    24,    66,    68,    72,    74,    76,    78,    80,
      82,    24,    24,    99,    99,   100,   100,     7,     8,     9,
      97,    96,    71,    10,    10,    62,    20,    21,    33,    34,
      35,    36,    37,    38,    64,    32,    31,    43,    67,    69,
      73,    75,    77,    79,    81,    83,    43,    27,   102,    27,
     104,    57,    71,    71,    98,    98,    98,    98,    98,    98,
      57,    84,    98,    24,    98,   105,    24,    42,    85,    87,
      47,    31,    31,    28,    45,    46,    98,   105,    86,    23,
      28,    57,    65,    24,    88,    57,    45,    89,    57
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
#line 229 "Sintactico.y"
    {
							printf("inicio del programa\n");
						}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 234 "Sintactico.y"
    {
							printf("fin del programa\n");
	             		}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 240 "Sintactico.y"
    {
							printf("bloque\n");
						}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 246 "Sintactico.y"
    {

						}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 251 "Sintactico.y"
    {

						}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 257 "Sintactico.y"
    {
							printf("bloque de declaración\n");
						}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 262 "Sintactico.y"
    {
	                 		printf("asignación\n");
	                 	}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 267 "Sintactico.y"
    {
	                 		printf("lectura\n");
	                 	}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 272 "Sintactico.y"
    {
							printf("escritura\n");
						}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 277 "Sintactico.y"
    {
	                 		printf("iteración\n");
	                 	}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 282 "Sintactico.y"
    {
	                 		printf("selección\n");
	                 	}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 288 "Sintactico.y"
    {
							if(tablaVariables[buscarEnTablaDeSimbolos(sectorVariables,(yyvsp[(1) - (3)].cadena))].tipo==sinTipo)
							{
								yyerrormsj((yyvsp[(1) - (3)].cadena),ErrorSintactico,ErrorIdNoDeclarado,"");
							}
							esAsignacion=1;
							printf("asignación: %s\t", (yyvsp[(1) - (3)].cadena));
							tipoAsignacion=tablaVariables[buscarEnTablaDeSimbolos(sectorVariables,(yyvsp[(1) - (3)].cadena))].tipo;
							printf("(tipo: %s)\n",obtenerTipo(sectorVariables,tipoAsignacion));
						}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 301 "Sintactico.y"
    {
							printf("while\n");
						}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 309 "Sintactico.y"
    {
							printf("if\n");
						}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 317 "Sintactico.y"
    {
							printf("comparación\n");
						}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 322 "Sintactico.y"
    {

						}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 326 "Sintactico.y"
    {
	                    	printf("and\n");
	                    }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 330 "Sintactico.y"
    {

	                  	}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 335 "Sintactico.y"
    {

						}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 339 "Sintactico.y"
    {
							printf("or\n");	
						}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 343 "Sintactico.y"
    {

	                  	}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 348 "Sintactico.y"
    {
							printf("not\n");
						}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 352 "Sintactico.y"
    {

	                  	}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 357 "Sintactico.y"
    {
							printf("between\n");
						}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 362 "Sintactico.y"
    {
							printf("in list\n");
						}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 368 "Sintactico.y"
    {

						}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 372 "Sintactico.y"
    {
							printf(">\n");
						}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 376 "Sintactico.y"
    {

						}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 381 "Sintactico.y"
    {

						}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 385 "Sintactico.y"
    {
							printf("<\n");
						}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 389 "Sintactico.y"
    {

						}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 394 "Sintactico.y"
    {

						}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 398 "Sintactico.y"
    {
							printf(">=\n");
						}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 402 "Sintactico.y"
    {

						}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 407 "Sintactico.y"
    {

						}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 411 "Sintactico.y"
    {
							printf("<=\n");
						}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 415 "Sintactico.y"
    {

						}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 420 "Sintactico.y"
    {

						}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 424 "Sintactico.y"
    {
							printf("==\n");
						}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 428 "Sintactico.y"
    {

						}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 433 "Sintactico.y"
    {

						}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 437 "Sintactico.y"
    {
							printf("!=\n");
						}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 441 "Sintactico.y"
    {

						}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 447 "Sintactico.y"
    {
							printf("if true\n");
						}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 452 "Sintactico.y"
    {
	                  		printf("if true\n");
	                  	}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 456 "Sintactico.y"
    {
	                    	printf("else\n");
	                    }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 460 "Sintactico.y"
    {
	                    	printf("if false\n");
	                    }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 465 "Sintactico.y"
    {
							printf("if true\n");
						}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 469 "Sintactico.y"
    {
							printf("elsif");
						}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 474 "Sintactico.y"
    {
							printf("else");
						}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 478 "Sintactico.y"
    {
							printf("if false");
						}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 484 "Sintactico.y"
    {
	                    	printf("read\n");
	                    }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 491 "Sintactico.y"
    {
	                    	printf("write id\n");
	                    }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 496 "Sintactico.y"
    {
 							printf("write string\n");
 						}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 502 "Sintactico.y"
    {
							printf("bloque de declaración\n");
						}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 506 "Sintactico.y"
    {
							printf("fin bloque de declaración\n");
						}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 514 "Sintactico.y"
    {
							printf("múltiple\n");
						}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 525 "Sintactico.y"
    {
							int i;
							printf("  Declaradas: ");
							for(i=0;i<contadorListaVar;i++)
							{
								if(tablaVariables[indicesParaAsignarTipo[i]].tipo==sinTipo){
									printf("'%s' ",tablaVariables[indicesParaAsignarTipo[i]].valor);
									tablaVariables[indicesParaAsignarTipo[i]].tipo=tipoInt;
								}
								else
								{
									yyerrormsj(tablaVariables[indicesParaAsignarTipo[i]].valor,ErrorSintactico,ErrorIdRepetida,"");
								}
							}
							printf("tipo entero\n");
						}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 542 "Sintactico.y"
    {
							int i;
							printf("  Declaradas: ");
							for(i=0;i<contadorListaVar;i++)
							{
								if(tablaVariables[indicesParaAsignarTipo[i]].tipo==sinTipo){
									printf("'%s' ",tablaVariables[indicesParaAsignarTipo[i]].valor);
									tablaVariables[indicesParaAsignarTipo[i]].tipo=tipoFloat;
								}
								else
								{
									yyerrormsj(tablaVariables[indicesParaAsignarTipo[i]].valor,ErrorSintactico,ErrorIdRepetida,"");
								}
							}
							printf("tipo flotante\n");
						}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 559 "Sintactico.y"
    {
							int i;
							printf("  Declaradas: ");
							for(i=0;i<contadorListaVar;i++)
							{
								if(tablaVariables[indicesParaAsignarTipo[i]].tipo==sinTipo)
								{
									printf("'%s' ",tablaVariables[indicesParaAsignarTipo[i]].valor);
									tablaVariables[indicesParaAsignarTipo[i]].tipo=tipoString;
								}
								else
								{
									yyerrormsj(tablaVariables[indicesParaAsignarTipo[i]].valor,ErrorSintactico,ErrorIdRepetida,"");
								}
							}
							printf("tipo string\n");
						}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 579 "Sintactico.y"
    {
							printf("término\n");
						}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 584 "Sintactico.y"
    {
							printf("+\n");
						}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 589 "Sintactico.y"
    {
							printf("-\n");
						}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 595 "Sintactico.y"
    {
							printf("factor\n");
	                    }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 600 "Sintactico.y"
    {
	                    	printf("*\n");
	                    }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 605 "Sintactico.y"
    {
							printf("/\n");
	                  	}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 611 "Sintactico.y"
    {
					    	printf("CTE_INT: %s\n", (yyvsp[(1) - (1)].cadena));
				    		if(esAsignacion==1&&tipoAsignacion!=tipoInt)
				    		{
				    			yyerrormsj((yyvsp[(1) - (1)].cadena), ErrorSintactico,ErrorConstanteDistintoTipo,"");
				    		}
					    }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 620 "Sintactico.y"
    {
					    	printf("CTE_FLOAT: %s\n", (yyvsp[(1) - (1)].cadena));
					    	if(esAsignacion==1&&tipoAsignacion!=tipoFloat)
					    	{
					    		yyerrormsj((yyvsp[(1) - (1)].cadena), ErrorSintactico,ErrorConstanteDistintoTipo,"");
					    	}
					    }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 629 "Sintactico.y"
    {
							printf("CTE_STRING: %s\n", (yyvsp[(1) - (1)].cadena));
							if(esAsignacion==1&&tipoAsignacion!=tipoString)
							{
					    		yyerrormsj((yyvsp[(1) - (1)].cadena), ErrorSintactico,ErrorConstanteDistintoTipo,"");
							}
						}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 638 "Sintactico.y"
    {
	                  		printf("id\n");
	                  		printf("%s\n", yylval);
	                  		int posicion=buscarEnTablaDeSimbolos(sectorVariables,yylval.cadena);
							indicesParaAsignarTipo[contadorListaVar++]=posicion;
	                  	}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 652 "Sintactico.y"
    {
							printf("rango\n");
						}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 661 "Sintactico.y"
    {
							printf("lista de expresiones\n");
						}
    break;



/* Line 1455 of yacc.c  */
#line 2433 "y.tab.c"
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
#line 671 "Sintactico.y"


/* codigo */

int main(int argc,char *argv[])
{

	setlocale(LC_CTYPE,"Spanish");

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

	printf("\n*** COMPILACIÓN EXITOSA ***\n");

  	return 0;
}

/* funciones */

int yyerrormsj(char * info,enum tipoDeError tipoDeError ,enum error error, const char *infoAdicional)
{
	grabarTablaDeSimbolos(1);
	printf("[Línea %d] ",yylineno);
  	switch(tipoDeError){
        case ErrorSintactico:
            printf("Error sintáctico. ");
            break;
        case ErrorLexico:
            printf("Error léxico. ");
            break;
    }
  	switch(error){
		case ErrorIdRepetida:
			printf("Descripción: el id '%s' ha sido declarado más de una vez\n",info);
			break;
		case ErrorIdNoDeclarado:
			printf("Descripción: el id '%s' no ha sido declarado\n",info);
			break;
		case ErrorArraySinTipo:
			printf("Descripción: el id '%s' NO tiene un tipo asignado\n",info);
			break;
		case ErrorArrayFueraDeRango:
			printf("Descripción: vector '%s(0..%d)' fuera de rango. Se intenta acceder a '%s[%s]'\n",info,(tablaVariables[buscarEnTablaDeSimbolos(sectorVariables,info)].limite),info,infoAdicional);
			break;
		case ErrorLimiteArrayNoPermitido:
			printf("Descripción: el vector %s (%s) no tiene un límite válido, debe ser mayor a 0\n",info, infoAdicional);
			break;
		case ErrorOperacionNoValida:
			printf("Descripción: La operación %s no es válida para variables de tipo %s\n",info, obtenerTipo(sectorVariables, tipoAsignacion));
			break;
		case ErrorIdDistintoTipo:
			printf("Descripción: La variable '%s' no es de tipo %s\n",info,obtenerTipo(sectorVariables, tipoAsignacion));
			break;
		case ErrorConstanteDistintoTipo:
			printf("Descripción: La constante %s no es de tipo %s\n", info, obtenerTipo(sectorVariables, tipoAsignacion));
			break;
		case ErrorArrayAsignacionMultiple:
			printf("Descripción: El vector %s esperaba %d expresiones, pero se recibieron %d.\n", info,cantidadDeExpresionesEsperadasEnVector,contadorExpresionesVector );
			break;
    }

  	system ("Pause");
    exit (1);
}

int yyerror()
{
	grabarTablaDeSimbolos(1);
	printf("Error sintáctico \n");
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
    {
        return 0;
    }
    pn->info=*info;
    pn->psig=*pp;
    *pp=pn;
    return 1;
}

t_info * sacarDePila(t_pila* pp)
{
	t_info* info = (t_info *) malloc(sizeof(t_info));
    if(!*pp)
    {
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

