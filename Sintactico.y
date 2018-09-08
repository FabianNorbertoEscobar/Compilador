/* declaraciones */

%{

	#include <stdio.h>
	#include <conio.h>
	#include <stdlib.h>

	#define TRUE 1
	#define FALSE 0

}%

/* tokens */

	%token DIGITO
	%token LETRA
	%token LETRA_MINUS
	%token LETRA_MAYUS
	%token CTE_INT
	%token CTE_FLOAT
	%token CTE_STRING		
	%token ID	
	%token OP_SUM
	%token OP_REST
	%token OP_MULT
	%token OP_DIV
	%token OP_ASIG
	%token OP_DEC
	%token OP_AND
	%token OP_OR
	%token OP_NOT
	%token PARENTESIS_I
	%token PARENTESIS_F
	%token LLAVE_I
	%token LLAVE_F
	%token CORCHETE_I
	%token CORCHETE_F
	%token COMENTARIO_I
	%token COMENTARIO_F
	%token PUNTO_Y_COMA
	%token COMA
	%token COMP_MAYOR_ESTR
	%token COMP_MENOR_ESTR
	%token COMP_MAYOR_IGUAL
	%token COMP_MENOR_IGUAL
	%token COMP_IGUAL
	%token COMP_DIST
	%token DECVAR
	%token ENDDEC
	%token WHILE
	%token IF
	%token ELSE
	%token ENDIF
	%token INTEGER
	%token FLOAT
	%token READ
	%token WRITE
	%token BETWEEN
	%token INLIST

/* definicion de reglas */



/* codigo */

