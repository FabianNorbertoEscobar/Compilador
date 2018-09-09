/* definiciones */

%{

	#include <stdio.h>
	#include <conio.h>
	#include <stdlib.h>
	#include <locale.h>
	#include <string.h>
	#include <float.h>
	#include "y.tab.h"

	#define TRUE 1
	#define FALSE 0

	FILE *yyin;
	int yylval;

}%

/* conjuntos y regex */

	%option noyywrap
	%option yylineno

	DIGITO					[0-9]
	LETRA					[a-zA-Z]
	LETRA_MINUS				[a-z]
	LETRA_MAYUS				[A-Z]
	CTE_INT					{DIGITO}+
	CTE_FLOAT				{DIGITO}*"."{DIGITO}+
	CTE_STRING				\"({LETRA}|{DIGITO}|{CARACTER}|" ")*\"			
	ID 						{LETRA_MINUS}({LETRA}|{DIGITO}|_)*	
	CARACTER				" "|!|¡|>|:|<|[ ]|+|@|"%"|#|&|°|´|^|`|?|¿|~|/|\\|-|_|.|;
	MAIN 					"int main"{PARENTESIS_I}{MAIN_PARAM}{PARENTESIS_F}
	MAIN_PARAM				" "|"int argc, char *argv[]"
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

	{CTE_INT} {guardar_token("CTE_INT"); yylval = atoi(yytext); verificar_rango_int(); strcpy(yylval.cadena, yytext); insertar_en_tabla_de_simbolos(sectorConstantes, tipoInt, yytext); return CTE_INT;}
	{CTE_FLOAT} {guardar_token("CTE_FLOAT"); yylval = atoi(yytext); verificar_rango_float(); strcpy(yylval.cadena, yytext); insertar_en_tabla_de_simbolos(sectorConstantes, tipoFloat, yytext); return CTE_FLOAT;}
	{CTE_STRING} {guardar_token("CTE_STRING"); strcpy(yylval.cadena, yytext); insertar_en_tabla_de_simbolos(sectorConstantes, tipoString, yytext); return CTE_STRING;}
	{ID} {guardar_token("ID"); printf("ID: %s\n",yytext); strcpy(yylval.cadena,yytext); insertar_en_tabla_de_simbolos(sectorVariables, sinTipo, yytext); return ID;}
	{CARACTER} {guardar_token("CARACTER"); RETURN CARACTER;}
	{MAIN} {guardar_token("MAIN"); return "MAIN"}
	{MAIN_PARAM} {guardar_token("MAIN_PARAM"); return "MAIN_PARAM"}
	{OP_SUM} {guardar_token("OP_SUM"); return OP_SUM;}
	{OP_REST} {guardar_token("OP_REST"); return OP_REST;}
	{OP_MULT} {guardar_token("OP_MULT"); return OP_MULT;}
	{OP_DIV} {guardar_token("OP_DIV"); return OP_DIV}
	{OP_ASIG} {guardar_token("OP_ASIG"); return OP_ASIG;}
	{OP_DEC} {guardar_token("OP_DEC"); return OP_DEC;}
	{OP_AND} {guardar_token("OP_AND"); return OP_AND;}
	{OP_OR} {guardar_token("OP_OR"); return OP_OR;}
	{OP_NOT} {guardar_token("OP_NOT"); return OP_NOT;}
	{PARENTESIS_I} {guardar_token("PARENTESIS_I"); return PARENTESIS_I;}
	{PARENTESIS_F} {guardar_token("PARENTESIS_F"); return PARENTESIS_F;}
	{LLAVE_I} {guardar_token("LLAVE_I"); return LLAVE_I;}
	{LLAVE_F} {guardar_token("LLAVE_F"); return LLAVE_F;}
	{CORCHETE_I} {guardar_token("CORCHETE_I"); return CORCHETE_I;}
	{CORCHETE_F} {guardar_token("CORCHETE_F"); return CORCHETE_F;}
	{COMENTARIO_I} {guardar_token("COMENTARIO_I"); return COMENTARIO_I;}
	{COMENTARIO_F} {guardar_token("COMENTARIO_F"); return COMENTARIO_F;}
	{PUNTO_Y_COMA} {guardar_token("PUNTO_Y_COMA"); return PUNTO_Y_COMA;}
	{COMA} {guardar_token("COMA"); return COMA;}
	{COMP_MAYOR_ESTR} {guardar_token("COMP_MAYOR_ESTR"); strcpy(yylval.cadena, yytext); return COMP_MAYOR_ESTR;}
	{COMP_MENOR_ESTR} {guardar_token("COMP_MENOR_ESTR"); strcpy(yylval.cadena, yytext); return COMP_MENOR_ESTR;}
	{COMP_MAYOR_IGUAL} {guardar_token("COMP_MAYOR_IGUAL"); strcpy(yylval.cadena, yytext); return COMP_MAYOR_IGUAL;}
	{COMP_MENOR_IGUAL} {guardar_token("COMP_MENOR_IGUAL"); strcpy(yylval.cadena, yytext); return COMP_MENOR_IGUAL;}
	{COMP_IGUAL} {guardar_token("COMP_IGUAL"); strcpy(yylval.cadena, yytext); return COMP_IGUAL;}
	{COMP_DIST} {guardar_token("COMP_DIST"); strcpy(yylval.cadena, yytext); return COMP_DIST;}
	{DECVAR} {guardar_token("DECVAR"); return DECVAR;}
	{ENDDEC} {guardar_token("ENDDEC"); return ENDDEC;}
	{WHILE} {guardar_token("WHILE"); return WHILE;}
	{IF} {guardar_token("IF"); return IF;}
	{ELSE} {guardar_token("ELSE"); return ELSE;}
	{ENDIF} {guardar_token("ENDIF"); return ENDIF;}
	{INTEGER} {guardar_token("INTEGER"); return INTEGER;}
	{FLOAT} {guardar_token("FLOAT"); return FLOAT;}
	{READ} {guardar_token("READ"); return READ;}
	{WRITE} {guardar_token("WRITE"); return WRITE;}
	{BETWEEN} {guardar_token("BETWEEN"); return BETWEEN;}
	{INLIST} {guardar_token("INLIST"); return INLIST;}
	
	"\n"
	"\r\n"
	"\t"
	" "
	. {mensajeDeError(errorCaracterInvalido,yytext);}

%%

/* codigo */

int main(int argc, char *argv[])
{

	setlocale(LC_CTYPE,"Spanish");

	if (!(yyin = fopen(argv[1], "rt")))
	{
		printf("\n No se puede abrir el archivo: %s \n", argv[1]);
		return TRUE;
	}
	else
	{
		yylex();
	}
	
	fclose(yyin);
	return FALSE;
}

int guardar_token()
{

}

int verificar_rango_int()
{

}

int verificar_rango_float()
{

}
