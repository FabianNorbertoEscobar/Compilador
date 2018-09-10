/* declaraciones */

%{
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
		tipoEntero,
		tipoReal,
		tipoCadena,
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
		ErrorArrayAsignacionMultiple,
		ErrorTipoAverage
	};

	enum tipoDeError{
		ErrorSintactico,
		ErrorLexico
	};

	enum tipoCondicion{
		condicionIf,
		condicionRepeat
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
	%token CARACTER
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
	|
						between
						{
							printf("between\n");
						}
	|
						inlist
						{
							printf("in list\n");
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
							printf("/\n");
							printf("%s",buscarEnTOS($3));
	                  	}
	;

	factor: 			CTE
						{
							$$=yylval;
							printf("%s\n", yylval);
						}
	|
	                  	ID
	                  	{
	                  		$$=yylval;
	                  		printf("%s\n", yylval);
	                  	}
	|
						PARENTESIS_I expresion PARENTESIS_F
	;

	between:			BETWEEN PARENTESIS_I ID COMA rango PARENTESIS_F
	;

	rango:				CORCHETE_I expresion PUNTO_Y_COMA expresion CORCHETE_F
						{
							printf("rango\n");
						}
	;

	inlist:				INLIST PARENTESIS_I ID PUNTO_Y_COMA lista_expresiones PARENTESIS_F
	;

	lista_expresiones:	CORCHETE_I expresiones CORCHETE_F
						{
							printf("lista de expresiones\n");
						}
	;

	expresiones: 		expresion
	|
						expresion PUNTO_Y_COMA expresiones
	;

%%

/* codigo */

int main(int argc,char *argv[])
{
	setlocale(LC_CTYPE,"Spanish");

	crearPila(&pilaWhile);
	crearPila(&pilaIf);

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
	vaciarPila(&pilaWhile);
	vaciarPila(&pilaIf);
	
	printf("\n*** COMPILACIÓN EXITOSA ***\n");

	return 0;
}

/* funciones */

int yyerrormsj(const char * info,enum tipoDeError tipoDeError ,enum error error, const char *infoAdicional)
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

/* pila */

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
