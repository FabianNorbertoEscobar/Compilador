
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 172 "Sintactico.y"

	int entero;
	double real;
	char cadena[50];



/* Line 1676 of yacc.c  */
#line 172 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


