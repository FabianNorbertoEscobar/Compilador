
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
     CTE_INT = 262,
     CTE_FLOAT = 263,
     CTE_STRING = 264,
     ID = 265,
     INICIO_PROGRAMA = 266,
     FIN_PROGRAMA = 267,
     OP_SUM = 268,
     OP_REST = 269,
     OP_MULT = 270,
     OP_DIV = 271,
     OP_ASIG = 272,
     OP_DEC = 273,
     OP_AND = 274,
     OP_OR = 275,
     OP_NOT = 276,
     PARENTESIS_I = 277,
     PARENTESIS_F = 278,
     LLAVE_I = 279,
     LLAVE_F = 280,
     CORCHETE_I = 281,
     CORCHETE_F = 282,
     COMENTARIO_I = 283,
     COMENTARIO_F = 284,
     PUNTO_Y_COMA = 285,
     COMA = 286,
     COMP_MAYOR_ESTR = 287,
     COMP_MENOR_ESTR = 288,
     COMP_MAYOR_IGUAL = 289,
     COMP_MENOR_IGUAL = 290,
     COMP_IGUAL = 291,
     COMP_DIST = 292,
     DECVAR = 293,
     ENDDEC = 294,
     WHILE = 295,
     ENDWHILE = 296,
     DO = 297,
     IF = 298,
     ELSE = 299,
     ELSIF = 300,
     ENDIF = 301,
     INTEGER = 302,
     FLOAT = 303,
     STRING = 304,
     READ = 305,
     WRITE = 306,
     BETWEEN = 307,
     INLIST = 308,
     COMENTARIO = 309
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
#define INICIO_PROGRAMA 266
#define FIN_PROGRAMA 267
#define OP_SUM 268
#define OP_REST 269
#define OP_MULT 270
#define OP_DIV 271
#define OP_ASIG 272
#define OP_DEC 273
#define OP_AND 274
#define OP_OR 275
#define OP_NOT 276
#define PARENTESIS_I 277
#define PARENTESIS_F 278
#define LLAVE_I 279
#define LLAVE_F 280
#define CORCHETE_I 281
#define CORCHETE_F 282
#define COMENTARIO_I 283
#define COMENTARIO_F 284
#define PUNTO_Y_COMA 285
#define COMA 286
#define COMP_MAYOR_ESTR 287
#define COMP_MENOR_ESTR 288
#define COMP_MAYOR_IGUAL 289
#define COMP_MENOR_IGUAL 290
#define COMP_IGUAL 291
#define COMP_DIST 292
#define DECVAR 293
#define ENDDEC 294
#define WHILE 295
#define ENDWHILE 296
#define DO 297
#define IF 298
#define ELSE 299
#define ELSIF 300
#define ENDIF 301
#define INTEGER 302
#define FLOAT 303
#define STRING 304
#define READ 305
#define WRITE 306
#define BETWEEN 307
#define INLIST 308
#define COMENTARIO 309




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 137 "Sintactico.y"

	int entero;
	double real;
	char cadena[50];



/* Line 1676 of yacc.c  */
#line 168 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


