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
	%token MAIN
	%token MAIN_PARAM

	%right OP_ASIG
	%left OP_SUM OP_REST
	%left OP_MULT OP_DIV

	%start programa

/* definicion de reglas */

%%

	programa:			MAIN bloque
						{
							printf("programa\n");
	             		}
	;

	bloque:            	LLAVE_I lista_sentencias LLAVE_F
						{
							printf("bloque\n");
						}
	;
	
	lista_sentencias: 	sentencia PUNTO_Y_COMA
						{

						}
	|					
						lista_sentencias sentencia PUNTO_Y_COMA
						{

						}
	;

	sentencia:			declaracion
						{
							printf("declaración\n");
						}
	|
	                 	asignacion
	                 	{
	                 		printf("asignación\n");
	                 	}
	|
	                 	lectura
	                 	{
	                 		printf("lectura\n");
	                 	}
	|
						escritura
						{
							printf("escritura\n");
						}
	|
	                 	iteracion
	                 	{
	                 		printf("iteración\n");
	                 	}
	|
	                 	seleccion
	                 	{
	                 		printf("selección\n");
	                 	}
	;

	asignacion:			ID OP_ASIG expresion
						{
							printf("%s",buscarEnTOS($1));
							printf(":=");
							printf("%s",buscarEnTOS($3));
						}
	;

	iteracion:  		WHILE PARENTESIS_I condicion PARENTESIS_F
						{
							printf("while\n");
						}
						bloque
	;

	seleccion:			IF PARENTESIS_I condicion PARENTESIS_F
						{
							printf("if\n");
						}
	                  	resto
	;

	condicion: 			comparacion
						{
							printf("comparación\n");
						}
	|					
						comparacion
						{

						}
	                    OP_AND
	                    {
	                    	printf("and\n");
	                    }
	                    comparacion
	                  	{

	                  	}
	|
						comparacion
						{

						}
	                    OP_OR
						{
							printf("or\n");	
						}
	                    comparacion
	                  	{

	                  	}
	|
						OP_NOT
						{
							printf("not\n");
						}
						comparacion
	                  	{

	                  	}
	;

	comparacion:		expresion
						{

						}
						COMP_MAYOR_ESTR
						{
							printf(">\n");
						}
						expresion
						{

						}
	|					
						expresion
						{

						}
						COMP_MENOR_ESTR
						{
							printf("<\n");
						}
						expresion
						{

						}
	|					
						expresion
						{

						}
						COMP_MAYOR_IGUAL
						{
							printf(">=\n");
						}
						expresion
						{

						}
	|					
						expresion
						{

						}
						COMP_MENOR_IGUAL
						{
							printf("<=\n");
						}
						expresion
						{

						}
	|					
						expresion
						{

						}
						COMP_IGUAL
						{
							printf("==\n");
						}
						expresion
						{

						}
	|					
						expresion
						{

						}
						COMP_DIST
						{
							printf("!=\n");
						}
						expresion
						{

						}		
	;

	resto:				bloque
						{
							printf("if true\n");
						}
	|
						bloque
	                  	{
	                  		printf("if true\n");
	                  	}
	                    ELSE
	                    {
	                    	printf("else\n");
	                    }
	                    bloque
	                    {
	                    	printf("if false\n");
	                    }
	;

	lectura:			READ PARENTESIS_I CTE_STRING PARENTESIS_F
	                    {
	                    	printf("read\n");
	                    }
	;

	escritura:			WRITE PARENTESIS_I CTE_STRING PARENTESIS_F
	                    {
	                    	printf("write\n");
	                    }
	;

	declaracion:		DECVAR lista_id_y_tipo ENDDEC
						{
							printf("bloque de declaración\n");
						}
	;

	lista_id_y_tipo: 	ID OP_DEC tipodato
						{
							printf("declaración\n");
						}
	|
						ID COMA lista_id_y_tipo
	;

	tipodato: 			CTE_INT
						{
							printf("tipo entero\n");
						}
	|					CTE_FLOAT
						{
							printf("tipo flotante\n");
						}
	|					CTE_STRING
						{
							printf("tipo string\n");
						}
	;

	expresion:			termino
						{
							$$=$1;
						}
	|
						expresion OP_SUM termino
						{
							printf("%s\n",buscarEnTOS($1));
							printf("+\n");
							printf("%s\n",buscarEnTOS($3));
						}
	|
						expresion OP_REST termino
						{
							printf("%s\n",buscarEnTOS($1));
							printf("-\n");
							printf("%s\n",buscarEnTOS($3));
						}
	;

	termino: 			factor
						{
							$$=$1;
	                    }
	|
						termino OP_MULT factor
	                  	{
	                    	printf("%s\n",buscarEnTOS($1));
	                    	printf("*\n");
	                    	printf("%s\n",buscarEnTOS($3));
	                    }
	|
						termino OP_DIV factor
	                  	{
							printf("%s",buscarEnTOS($1));
							printf("|/|");
							printf("%s",buscarEnTOS($3));
	                  	}
	;

	factor: 			CTE
						{
							$$=yylval;
						}
	|
	                  	ID
	                  	{
	                  		$$=yylval;
	                  	}
	|
						PARENTESIS_I expresion PARENTESIS_F
	;

%%

/* codigo */

