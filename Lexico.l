/* definiciones */

%{
	/* includes */

	#include <stdio.h>
	#include <conio.h>
	#include <stdlib.h>
	#include <locale.h>
	#include <string.h>
	#include <float.h>
	#include <limits.h>
	#include "y.tab.h"

	/* defines */

	#define CARACTER_NOMBRE "_"
	#define NO_ENCONTRADO -1
	#define preMaxCadena 46
	#define preMaxEntero 6
	#define TRUE 1
	#define FALSE 0

	/* enums */

	enum valorMaximo{
		ENTERO_MAXIMO = 65535,
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
		errorEnteroFueraDeRango,
		errorRealFueraDeRango,
		errorCadenaDemasiadoLarga,
		errorIdDemasiadoLargo,
		errorCaracterInvalido
	};

	/* structs */

	typedef struct{
		char nombre[100];
		char valor[100];
		enum tipoDato tipo;
		int longitud;
		int limite;
	} registro;

	/* funciones */

	char* cortarCadena(char* ,int);
	char* reemplazarCaracter(char const * const,  char const * const,  char const * const);
	void grabarTablaDeSimbolos(int);
	void insertarEnTablaDeSimbolos(enum sectorTabla,enum tipoDato,char*);
	char* normalizar(char*);
	int buscarEnTablaDeSimbolos(enum sectorTabla, char*);
	void mensajeDeError(enum error,const char*);
	char * cortarCadena(char* ,int);
	void guardarToken(char *);
	char* obtenerTipo(enum sectorTabla, enum tipoDato);
	void mostrarTablaDeSimbolos();

	/* variables globales */

	unsigned long entero64bits;
	registro tablaVariables[TAM];
	registro tablaConstantes[TAM];
	int indiceVariable=0;
	int indiceConstante=0;
	char *tiraDeTokens;
	FILE *yyin;

%}

/* conjuntos y regex */

%option noyywrap
%option yylineno

DIGITO					[0-9]
LETRA_MINUS				[a-z]
LETRA_MAYUS				[A-Z]
LETRA					{LETRA_MINUS}|{LETRA_MAYUS}
CTE_INT					{DIGITO}+
CTE_FLOAT				{DIGITO}*"."{DIGITO}+
CTE_STRING				"\""({LETRA}|{DIGITO}|.)*"\""
ID 						{LETRA_MINUS}({LETRA}|{DIGITO}|_)*
INICIO_PROGRAMA			"PROGRAMA"
FIN_PROGRAMA			"END_PROGRAMA"
OP_SUM					"+"
OP_REST					"-"
OP_MULT					"*"
OP_DIV					"/"
OP_ASIG					"="
OP_DEC					":"
OP_AND					"&"|"AND"
OP_OR					"|"|"OR"
OP_NOT					"!"|"NOT"
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
ENDWHILE				"ENDWHILE"
DO 						"DO"
IF 						"IF"
ELSE 					"ELSE"
ELSIF					"ELSIF"
ENDIF					"ENDIF"
INTEGER					"INTEGER"
FLOAT 					"FLOAT"
STRING 					"STRING"
READ					"READ"
WRITE					"WRITE"
BETWEEN  				"BETWEEN"
INLIST					"INLIST"
COMENTARIO 				{COMENTARIO_I}({LETRA}|{DIGITO}|.)*{COMENTARIO_F}

/* definicion de reglas */

%%

{CTE_INT} 			{
						guardarToken("CTE_INT\n");
						strcpy(yylval.cadena, yytext);
						insertarEnTablaDeSimbolos(sectorConstantes, tipoInt, yytext);
						return CTE_INT;
					}

{CTE_FLOAT}			{
						guardarToken("CTE_FLOAT\n");
						strcpy(yylval.cadena, yytext);
						insertarEnTablaDeSimbolos(sectorConstantes, tipoFloat, yytext);
						return CTE_FLOAT;
					}

{CTE_STRING}		{
						guardarToken("CTE_STRING\n");
						strcpy(yylval.cadena, yytext);
						printf("valor cadena: %s\n", yylval.cadena);
						insertarEnTablaDeSimbolos(sectorConstantes, tipoString, yytext);
						return CTE_STRING;
					}

{ID} 				{
						guardarToken("ID\n");
						printf("ID: %s\n",yytext);
						strcpy(yylval.cadena,yytext);
						insertarEnTablaDeSimbolos(sectorVariables, sinTipo, yytext);
						return ID;
					}

{INICIO_PROGRAMA} 	{
						guardarToken("INICIO_PROGRAMA\n");
						return INICIO_PROGRAMA;
					}

{FIN_PROGRAMA} 		{
						guardarToken("FIN_PROGRAMA\n");
						return FIN_PROGRAMA;
					}

{OP_SUM} 			{
						guardarToken("OP_SUM\n");
						return OP_SUM;
					}

{OP_REST} 			{
						guardarToken("OP_REST\n");
						return OP_REST;
					}

{OP_MULT} 			{	
						guardarToken("OP_MULT\n");
						return OP_MULT;
					}

{OP_DIV} 			{
						guardarToken("OP_DIV\n");
						return OP_DIV;
					}

{OP_ASIG} 			{
						guardarToken("OP_ASIG\n");
						return OP_ASIG;
					}

{OP_DEC} 			{
						guardarToken("OP_DEC\n");
						return OP_DEC;
					}

{OP_AND} 			{
						guardarToken("OP_AND\n");
						return OP_AND;
					}

{OP_OR} 			{
						guardarToken("OP_OR\n");
						return OP_OR;
					}

{OP_NOT} 			{
						guardarToken("OP_NOT\n");
						return OP_NOT;
					}

{PARENTESIS_I} 		{
						guardarToken("PARENTESIS_I\n");
						return PARENTESIS_I;
					}

{PARENTESIS_F} 		{
						guardarToken("PARENTESIS_F\n");
						return PARENTESIS_F;
					}

{LLAVE_I} 			{
						guardarToken("LLAVE_I\n");
						return LLAVE_I;
					}

{LLAVE_F} 			{
						guardarToken("LLAVE_F\n");
						return LLAVE_F;
					}

{CORCHETE_I} 		{
						guardarToken("CORCHETE_I\n");
						return CORCHETE_I;
					}

{CORCHETE_F} 		{
						guardarToken("CORCHETE_F\n");
						return CORCHETE_F;
					}

{COMENTARIO_I} 		{
						guardarToken("COMENTARIO_I\n");
						return COMENTARIO_I;
					}

{COMENTARIO_F} 		{
						guardarToken("COMENTARIO_F\n");
						return COMENTARIO_F;
					}

{PUNTO_Y_COMA} 		{
						guardarToken("PUNTO_Y_COMA\n");
						return PUNTO_Y_COMA;
					}

{COMA} 				{
						guardarToken("COMA\n");
						return COMA;
					}

{COMP_MAYOR_ESTR} 	{
						guardarToken("COMP_MAYOR_ESTR\n");
						strcpy(yylval.cadena, yytext);
						return COMP_MAYOR_ESTR;
					}

{COMP_MENOR_ESTR} 	{
						guardarToken("COMP_MENOR_ESTR\n");
						strcpy(yylval.cadena, yytext);
						return COMP_MENOR_ESTR;
					}

{COMP_MAYOR_IGUAL} 	{
						guardarToken("COMP_MAYOR_IGUAL\n");
						strcpy(yylval.cadena, yytext);
						return COMP_MAYOR_IGUAL;
					}

{COMP_MENOR_IGUAL} 	{
						guardarToken("COMP_MENOR_IGUAL\n");
						strcpy(yylval.cadena, yytext);
						return COMP_MENOR_IGUAL;
					}

{COMP_IGUAL} 		{
						guardarToken("COMP_IGUAL\n");
						strcpy(yylval.cadena, yytext);
						return COMP_IGUAL;
					}

{COMP_DIST} 		{
						guardarToken("COMP_DIST\n");
						strcpy(yylval.cadena, yytext);
						return COMP_DIST;
					}

{DECVAR} 			{
						guardarToken("DECVAR\n");
						return DECVAR;
					}

{ENDDEC} 			{
						guardarToken("ENDDEC\n");
						return ENDDEC;
					}

{WHILE} 			{
						guardarToken("WHILE\n");
						return WHILE;
					}

{ENDWHILE} 			{
						guardarToken("ENDWHILE\n");
						return ENDWHILE;
					}

{DO} 				{
						guardarToken("DO\n");
						return DO;
					}

{IF} 				{
						guardarToken("IF\n");
						return IF;
					}

{ELSE} 				{
						guardarToken("ELSE\n");
						return ELSE;
					}

{ELSIF}				{
						guardarToken("ELSIF\n");
						return ELSIF;
					}

{ENDIF} 			{
						guardarToken("ENDIF\n");
						return ENDIF;
					}

{INTEGER} 			{
						guardarToken("INTEGER\n");
						return INTEGER;
					}

{FLOAT} 			{
						guardarToken("FLOAT\n");
						return FLOAT;
					}

{STRING} 			{
						guardarToken("STRING\n");
						return STRING;
					}

{READ} 				{
						guardarToken("READ\n");
						return READ;
					}

{WRITE} 			{
						guardarToken("WRITE\n");
						return WRITE;
					}

{BETWEEN} 			{
						guardarToken("BETWEEN\n");
						return BETWEEN;
					}

{INLIST} 			{
						guardarToken("INLIST\n");
						return INLIST;
					}

{COMENTARIO}		{
						guardarToken("COMENTARIO\n");
						return COMENTARIO;
					}

"\n"				{
						mensajeDeError(errorCaracterInvalido,"\n");
						exit(1);
					}

"\r\n" 				{
						mensajeDeError(errorCaracterInvalido,"\r\n");
						exit(1);
					}

"\t"				{
						mensajeDeError(errorCaracterInvalido,"\t");
						exit(1);
					}

" "					{
						mensajeDeError(errorCaracterInvalido," ");
						exit(1);
					}

.    				{
						mensajeDeError(errorCaracterInvalido,".");
						exit(1);
					}

%%

/* codigo */

char * reemplazarCaracter(char const * const original,  char const * const pattern,  char const * const replacement)
{
	size_t const replen = strlen(replacement);
	size_t const patlen = strlen(pattern);
	size_t const orilen = strlen(original);
	size_t patcnt = 0;
	const char * oriptr;
	const char * patloc;
	
	for (oriptr = original; patloc = strstr(oriptr, pattern); oriptr = patloc + patlen)
	{
		patcnt++;
	}
	
	size_t const retlen = orilen + patcnt * (replen - patlen);
    char * const returned = (char *) malloc( sizeof(char) * (retlen + 1) );
    
    if (returned != NULL)
    {
		char * retptr = returned;
		
		for (oriptr = original; patloc = strstr(oriptr, pattern); oriptr = patloc + patlen)
		{
			size_t const skplen = patloc - oriptr;
			strncpy(retptr, oriptr, skplen);
			retptr += skplen;
			strncpy(retptr, replacement, replen);
			retptr += replen;
		}
	
		strcpy(retptr, oriptr);
	}
	
	return returned;
}

char * cortarCadena(char* cad,int tam){
	if(strlen(cad)>tam)
	{
		cad[tam]='\0';
	}
	return cad;
}

void grabarTablaDeSimbolos(int error){
	
	setlocale(LC_CTYPE,"Spanish");

	FILE*pt=fopen("tiraDeTokens.txt","w+");
	
	if(!pt)
	{
		printf("Error al crear la tabla de símbolos\n");
		return;
	}
	
	fprintf(pt,"%s",tiraDeTokens);
	fclose(pt);
	
	FILE*pf=fopen("ts.txt","w+");
	int i;
	
	if(!pf){
		printf("Error al crear la tabla de símbolos\n");
		return;
	}
	
	fprintf(pf,"%-32s|\t%-15s|\t%-32s|\t%-13s|\t%-13s\n\n","NOMBRE","TIPO","VALOR","LONGITUD","LIMITE");
	
	for(i = 0; i<indiceVariable; i++)
	{
		if(tablaVariables[i].limite!=0)
		{
			fprintf(pf,"%-32s|\t%-15s|\t%-32s|\t%-13s|\t%-13d\n",tablaVariables[i].nombre,obtenerTipo(sectorVariables, tablaVariables[i].tipo),"----------------------------","----------",tablaVariables[i].limite);
		}
		else
		{
			fprintf(pf,"%-32s|\t%-15s|\t%-32s|\t%-13s|\t%-13s\n",tablaVariables[i].nombre,obtenerTipo(sectorVariables, tablaVariables[i].tipo),"----------------------------","----------","----------");
		}
	}

	for(i = 0; i<indiceConstante; i++)
	{
		if(tablaConstantes[i].longitud==0)
		{
			fprintf(pf,"%-32s|\t%-15s|\t%-32s|\t%-13s|\t%-13s\n",tablaConstantes[i].nombre,obtenerTipo(sectorConstantes, tablaConstantes[i].tipo),tablaConstantes[i].valor,"----------","----------");
		}
		else
		{
			fprintf(pf,"%-32s|\t%-15s|\t%-32s|\t%-13d|\t%-13s\n",tablaConstantes[i].nombre,obtenerTipo(sectorConstantes, tablaConstantes[i].tipo),tablaConstantes[i].valor,tablaConstantes[i].longitud,"----------");
		}
	}

	if(error==1) 
	{
		fprintf(pf,"\n**** TABLA INCOMPLETA (ERROR DE COMPILACION) ****\n");
	}
	
	fclose(pf);
}

void mostrarTablaDeSimbolos(){

	setlocale(LC_CTYPE,"Spanish");
	
	printf("%-32s|\t%-15s|\t%-32s|\t%-13s|\t%-13s\n\n","NOMBRE","TIPO","VALOR","LONGITUD","LIMITE");
	int i;
	
	for(i = 0; i<indiceVariable; i++)
	{
		if(tablaVariables[i].limite!=0)
		{
			printf("%-32s|\t%-15s|\t%-32s|\t%-13s|\t%-13d\n",tablaVariables[i].nombre,obtenerTipo(sectorVariables, tablaVariables[i].tipo),"----------------------------","----------",tablaVariables[i].limite);
		}
		else
		{
			printf("%-32s|\t%-15s|\t%-32s|\t%-13s|\t%-13s\n",tablaVariables[i].nombre,obtenerTipo(sectorVariables, tablaVariables[i].tipo),"----------------------------","----------","----------");
		}
	}

	for(i = 0; i<indiceConstante; i++){
		if(tablaConstantes[i].longitud==0)
		{
			printf("%-32s|\t%-15s|\t%-32s|\t%-13s|\t%-13s\n",tablaConstantes[i].nombre,obtenerTipo(sectorConstantes, tablaConstantes[i].tipo),tablaConstantes[i].valor,"----------","----------");
		}
		else
		{
			printf("%-32s|\t%-15s|\t%-32s|\t%-13d|\t%-13s\n",tablaConstantes[i].nombre,obtenerTipo(sectorConstantes, tablaConstantes[i].tipo),tablaConstantes[i].valor,tablaConstantes[i].longitud,"----------");
		}
	}
}

char* normalizar(char* cadena){
	
	char *aux = (char *) malloc( sizeof(char) * (strlen(cadena)) + 2);
	strcpy(aux,CARACTER_NOMBRE);
	strcat(aux,cadena);
	
	aux=reemplazarCaracter(aux,",","c");
	aux=reemplazarCaracter(aux,".","p");
	aux=reemplazarCaracter(aux,":","d");
	aux=reemplazarCaracter(aux,";","P");
	aux=reemplazarCaracter(aux,"-","m");
	aux=reemplazarCaracter(aux," ","_");
	aux=reemplazarCaracter(aux,"\"","");
	aux=reemplazarCaracter(aux,"[","C");
	aux=reemplazarCaracter(aux,"]","C");
	
	return aux;
}

char* obtenerTipo(enum sectorTabla sector, enum tipoDato tipo){
	switch(sector){
		case sectorConstantes:
			switch(tipo){
				case tipoFloat:
					return("CTE_FLOAT");
					break;
				case tipoString:
					return("CTE_STRING");
					break;
				case tipoInt:
					return("CTE_INT");
					break;
			}
			break;
		case sectorVariables:
			switch(tipo){
				case tipoFloat:
					return("float");
					break;
				case tipoString:
					return("string");
					break;
				case tipoInt:
					return("int");
					break;
				case sinTipo:
					return("sin tipo");
					break;
			}
			break;
	}
}

void insertarEnTablaDeSimbolos(enum sectorTabla sector, enum tipoDato tipo, char *valor){
	
	char *cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
	
	switch(sector){
		case sectorConstantes:
			if(buscarEnTablaDeSimbolos(sectorConstantes,valor)!=NO_ENCONTRADO) {
				return;
			}

			switch (tipo) {
				case tipoFloat:
					if (atof(valor)<0 || atof(valor)>FLT_MAX)
					{
						mensajeDeError(errorRealFueraDeRango,valor);
					}
					strcpy(tablaConstantes[indiceConstante].valor,valor);
					tablaConstantes[indiceConstante].tipo=tipoFloat;
					tablaConstantes[indiceConstante].longitud=0;
					tablaConstantes[indiceConstante].limite=0;
					strcpy(tablaConstantes[indiceConstante++].nombre,normalizar(valor));
					break;

				case tipoString:
					strcpy(cadena,valor);
					cortarCadena(cadena,preMaxCadena);
					cadena=reemplazarCaracter(cadena,"\"","");
					if(strlen(cadena)>=CADENA_MAXIMA)
					{
						mensajeDeError(errorCadenaDemasiadoLarga, cadena);
					}
					strcpy(tablaConstantes[indiceConstante].valor,cadena);
					tablaConstantes[indiceConstante].tipo=tipoString;
					tablaConstantes[indiceConstante].longitud=strlen(cadena);
					tablaConstantes[indiceConstante].limite=0;
					strcpy(tablaConstantes[indiceConstante++].nombre,normalizar(cadena));
					break;

				case tipoInt:
					strcpy(cadena,valor);
					cortarCadena(cadena,preMaxEntero);
					if (atoi(cadena)<0 || atoi(cadena)>ENTERO_MAXIMO)
					{
						mensajeDeError(errorEnteroFueraDeRango,valor);
					}
					strcpy(tablaConstantes[indiceConstante].valor,cadena);
					tablaConstantes[indiceConstante].tipo=tipoInt;
					tablaConstantes[indiceConstante].longitud=0;
					tablaConstantes[indiceConstante].limite=0;
					strcpy(tablaConstantes[indiceConstante++].nombre,normalizar(cadena));
					break;
			}
			break;

		case sectorVariables:
			cadena=cortarCadena(valor,preMaxCadena);
			cadena=reemplazarCaracter(cadena,"\"","");
			if(strlen(cadena)>=CADENA_MAXIMA)
			{
				mensajeDeError(errorCadenaDemasiadoLarga, cadena);
			}
			if(buscarEnTablaDeSimbolos(sectorVariables,cadena)!=NO_ENCONTRADO)
			{
				return;
			}
			strcpy(tablaVariables[indiceVariable].valor,cadena);
			tablaVariables[indiceVariable].tipo=sinTipo;
			tablaVariables[indiceVariable].longitud=0;
			tablaVariables[indiceVariable].limite=0;
			strcpy(tablaVariables[indiceVariable++].nombre,normalizar(cadena));
			break;
	}
}

int buscarEnTablaDeSimbolos(enum sectorTabla sector, char* objetivo){
	
	objetivo=normalizar(objetivo);
	int i;
	
	switch(sector){
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

void mensajeDeError(enum error error,const char* info){

	setlocale(LC_CTYPE,"Spanish");

	grabarTablaDeSimbolos(1);

	printf("[Línea %d] ",yylineno);
	switch(error){ 

        case errorEnteroFueraDeRango: 
            printf("ERROR LÉXICO. Descripción: Int %s fuera de rango [0 ; %d]\n",info,ENTERO_MAXIMO);
            break ;

		case errorRealFueraDeRango: 
            printf("ERROR LÉXICO. Descripción: Float %s fuera de rango. Debe ser un float de 32bits.\n",info);
            break ;

        case errorCadenaDemasiadoLarga:
            printf("ERROR LÉXICO. Descripción: String \"%s\" fuera de rango. La longitud máxima es de 30 caracteres.\n", info);
            break ; 

        case errorIdDemasiadoLargo:
            printf("ERROR LÉXICO. Descripción: Id \"%s\" demasiado largo. La longitud máxima es de 30 caracteres.\n", info);
            break ; 

        case errorCaracterInvalido:
        	printf("ERROR LÉXICO. Descripción: El caracter %s es inválido.\n",info);
        	break;
    }
       
    system ("Pause");
	exit (1);
}

void guardarToken(char* token){
	char* aux = (char*) malloc ( sizeof(char) * (strlen(tiraDeTokens)) +1);
	strcpy(aux, tiraDeTokens);
	tiraDeTokens=(char*) malloc ( sizeof(char) * (strlen(aux)) + strlen(token)+1);
	strcpy(tiraDeTokens,aux);
	strcat(tiraDeTokens,token);
}
