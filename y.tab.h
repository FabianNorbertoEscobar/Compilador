
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

# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


