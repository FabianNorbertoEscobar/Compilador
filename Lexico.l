/* definiciones */

%{

	#include <stdio.h>
	#include <conio.h>
	#include <stdlib.h>

	FILE *yyin;

}%

/* conjuntos y regex */

DIGITO					[0-9]
LETRA					[a-zA-Z]
LETRA_MINUS				[a-z]
LETRA_MAYUS				[A-Z]
CTE_INT					{DIGITO}+
CTE_FLOAT				{DIGITO}+"."{DIGITO}+
CTE_STRING				\"({LETRA}|{DIGITO}|" ")*\"			
ID 						{LETRA_MINUS}({LETRA}|{DIGITO}|_)*		
OP_SUM					"+"
OP_REST					"-"
OP_MULT					"*"
OP_DIV					"/"
OP_ASIG					"="
OP_DEC					":"
OP_AND					"&"
OP_OR					"|"
OP_NOT					"!"
PARENTESIS_I			"("
PARENTESIS_F			")"
LLAVE_I					"{"
LLAVE_F					"}"
CORCHETE_I				"["
CORCHETE_F				"]"
COMENTARIO_I			"-/"
COMENTARIO_F			"/-"
PUNTO_Y_COMA			";"
COMA 					","
COMP_MAYOR_ESTR			">"
COMP_MENOR_ESTR			"<"
COMP_MAYOR_IGUAL		">="
COMP_MENOR_IGUAL		"<="
COMP_IGUAL 				"=="
COMP_DIST				"!="
DECVAR					"DECVAR"
ENDDEC					"ENDDEC"
WHILE					"WHILE"
IF 						"IF"
ELSE 					"ELSE"
ENDIF					"ENDIF"
INTEGER					"INTEGER"
FLOAT 					"FLOAT"
READ					"READ"
WRITE					"WRITE"
BETWEEN  				"BETWEEN"
INLIST					"INLIST"

/* definicion de reglas */

%%

	

%%

/* codigo */

int main(int argc, char *argv[])
{

	if (!(yyin = fopen(argv[1], "rt")))
	{
		printf("\n No se puede abrir el archivo: %s \n", argv[1]);
	}
	else
	{
		yylex();
	}
	
	fclose(yyin);

}