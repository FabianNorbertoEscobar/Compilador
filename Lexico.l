/* definiciones */

%{

	#include <stdio.h>
	#include <conio.h>
	#include <stdlib.h>

	#define TRUE 1
	#define FALSE 0

	FILE *yyin;
	int yylval;

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
	MAIN 					"int main"{PARENTESIS_I}{MAIN_PARAM}{PARENTESIS_F}
	MAIN_PARAM				" "|"int argc, char *argv[]"

/* definicion de reglas */

%%

	{DIGITO}+ {verificar_rango_int(); return CTE_INT;}
	{DIGITO}+"."{DIGITO}+ {verificar_rango_float(); return CTE_FLOAT;}
	\"({LETRA}|{DIGITO}|" ")*\" {return CTE_STRING;}
	{LETRA_MINUS}({LETRA}|{DIGITO}|_)* {guardar_en_tos(); return ID;}
	"+" {return OP_SUM;}
	"-" {return OP_REST;}
	"*" {return OP_MULT;}
	"/" {return OP_DIV}
	"=" {return OP_ASIG;}
	":" {return OP_DEC;}
	"&" {return OP_AND;}
	"|" {return OP_OR;}
	"!" {return OP_NOT;}
	"(" {return PARENTESIS_I;}
	")" {return PARENTESIS_F;}
	"{" {return LLAVE_I;}
	"}" {return LLAVE_F;}
	"[" {return CORCHETE_I;}
	"]" {return CORCHETE_F;}
	"-/" {return COMENTARIO_I;}
	"/-" {return COMENTARIO_F;}
	";" {return PUNTO_Y_COMA;}
	"," {return COMA;}
	">" {return COMP_MAYOR_ESTR;}
	"<" {return COMP_MENOR_ESTR;}
	">=" {return COMP_MAYOR_IGUAL;}
	"<=" {return COMP_MENOR_IGUAL;}
	"==" {return COMP_IGUAL;}
	"!=" {return COMP_DIST;}
	"DECVAR" { return DECVAR;}
	"ENDDEC" { return ENDDEC;}
	"WHILE" {return WHILE;}
	"IF" {return IF;}
	"ELSE" {return ELSE;}
	"ENDIF" {return ENDIF;}
	"INTEGER" {return INTEGER;}
	"FLOAT" {return FLOAT;}
	"READ" {return READ;}
	"WRITE" {return WRITE;}
	"BETWEEN" {return BETWEEN;}
	"INLIST" {return INLIST;}
	"int main"{PARENTESIS_I}{MAIN_PARAM}{PARENTESIS_F} {return "MAIN"}
	" "|"int argc, char *argv[]" {return "MAIN_PARAM"}

%%

/* codigo */

int main(int argc, char *argv[])
{

	if (!(yyin = fopen(argv[1], "rt")))
	{
		printf("\n No se puede abrir el archivo: %s \n", argv[1]);
		return FALSE;
	}
	else
	{
		yylex();
	}
	
	fclose(yyin);
	return TRUE;
}

int guardar_en_tos()
{

}

int verificar_rango_int()
{

}

int verificar_rango_float()
{

}
