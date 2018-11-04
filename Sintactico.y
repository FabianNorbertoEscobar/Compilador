/* declaraciones */

%{
	/* includes */

	#include <stdio.h>
	#include <conio.h>
	#include <stdlib.h>
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
		ErrorIdRepetida,
		ErrorIdNoDeclarado,
		ErrorOperacionNoValida,
		ErrorIdDistintoTipo,
		ErrorConstanteDistintoTipo
	};

	enum tipoDeError{
		ErrorSintactico,
		ErrorLexico
	};

	enum tipoCondicion{
		condicionIf,
		condicionWhile
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

	/* structs */

	typedef struct{
		char nombre[100];
		char valor[100];
		enum tipoDato tipo;
		int longitud;
		int limite;
	} registro;

	typedef struct
	{
		char *cadena;
		int cantExpresiones;
		int salto1;
		int salto2;
		int nro;
		enum and_or andOr;
		enum tipoDato tipo;
	}t_info;

	typedef struct s_nodoPila{
    	t_info info;
    	struct s_nodoPila* psig;
	}t_nodoPila;

	typedef t_nodoPila *t_pila;

	typedef struct
	{
		char cadena[CADENA_MAXIMA];
		int nro;
	}t_infoPolaca;

	typedef struct s_nodoPolaca{
    	t_infoPolaca info;
    	struct s_nodoPolaca* psig;
	}t_nodoPolaca;

	typedef t_nodoPolaca *t_polaca;

	/* funciones */

	int yyerrormsj(const char *,enum tipoDeError,enum error, const char*);
	int yyerror();

	void guardarPolaca(t_polaca*);
	int ponerEnPolacaNro(t_polaca*,int, char *);
	int ponerEnPolaca(t_polaca*, char *);
	void crearPolaca(t_polaca*);
	char* obtenerSalto(enum tipoSalto);
	char* obtenerSalto2(char*,enum tipoSalto);

	void vaciarPila(t_pila*);
	t_info* sacarDePila(t_pila*);
	void crearPila(t_pila*);
	int ponerEnPila(t_pila*,t_info*);
	t_info* topeDePila(t_pila*);

	void generar_assembler(t_polaca*);
	char* sacarDePolaca(t_polaca*);
	int buscarEnTablaDeSimbolosASM(enum sectorTabla, char*);

	/* variables globales */

	extern registro tablaVariables[TAM];
	extern registro tablaConstantes[TAM];
	extern int yylineno;
	extern int indiceConstante;
	extern int indiceVariable;
	extern char *tiraDeTokens;
	int yystopparser=0;
	FILE  *yyin;
	char *yyltext;
	char *yytext;
	int indicesParaAsignarTipo[TAM];
	enum tipoDato tipoAsignacion=sinTipo;
	int esAsignacion=0;
	int contadorListaVar=0;
	int contadorIf=0;
	int contadorWhile=0;
	int contadorBetween=0;
	int contadorInList=0;
	int contadorPolaca=0;
	int auxiliaresNecesarios=0;
	t_polaca polaca;
	t_pila pilaIf;
	t_pila pilaWhile;
	t_pila pilaBetween;
	t_pila pilaInList;
	t_pila pilaASM;
	char ultimoComparador[3];
	int expresionesRestantes;
	enum tipoCondicion tipoCondicion;
	float paramBetween;
	float paramInList;

%}

%union {
	int entero;
	double real;
	char cadena[50];
}

/* tokens */

%token DIGITO
%token LETRA
%token LETRA_MINUS
%token LETRA_MAYUS
%token CARACTER
%token <cadena>CTE_INT
%token <cadena>CTE_FLOAT
%token <cadena>CTE_STRING		
%token <cadena>ID
%token INICIO_PROGRAMA
%token FIN_PROGRAMA
%token OP_SUM
%token OP_REST
%token OP_MULT
%token OP_DIV
%token OP_ASIG
%token OP_DEC
%token OP_AND
%token OP_OR
%token OP_NOT
%token COMPARADOR
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
%token ENDWHILE
%token DO
%token IF
%token ELSE
%token ELSIF
%token ENDIF
%token INTEGER
%token FLOAT
%token STRING
%token READ
%token WRITE
%token BETWEEN
%token INLIST
%token COMENTARIO

%left OP_ASIG
%left OP_SUM OP_REST
%left OP_MULT OP_DIV

%start start

/* definicion de reglas */

%%

	start: 				programa
						{
							printf("\nCOMPILACION EXITOSA\n");
						}

	programa:			INICIO_PROGRAMA
						{
							printf("\ninicio del programa\n\n");
						}
						bloque
						FIN_PROGRAMA
						{
							printf("\nfin del programa\n");
	             		}
	;

	bloque:            	lista_sentencias
						{
							printf("bloque\n");
						}
	;
	
	lista_sentencias: 	sentencia
						{
							
						}
	|					
						lista_sentencias sentencia
						{

						}
	;

	sentencia:			bloque_declaracion
						{
							printf("bloque de declaracion\n");
						}
	|
	                 	asignacion
	                 	{
	                 		printf("asignacion\n");
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
	                 		printf("iteracion\n");
	                 	}
	|
	                 	seleccion
	                 	{
	                 		printf("seleccion\n");
	                 	}
	|                 	
						COMENTARIO
						{
							printf("comentario\n");
						}
	;

	asignacion:			ID
						{
							if(tablaVariables[buscarEnTablaDeSimbolos(sectorVariables,$<cadena>1)].tipo==sinTipo)
							{
								yyerrormsj($<cadena>1,ErrorSintactico,ErrorIdNoDeclarado,"");
							}
							esAsignacion=1;
							printf("asignacion: %s\t", $<cadena>1);
							tipoAsignacion=tablaVariables[buscarEnTablaDeSimbolos(sectorVariables,$<cadena>1)].tipo;
							ponerEnPolaca(&polaca,tablaVariables[buscarEnTablaDeSimbolos(sectorVariables,$<cadena>1)].nombre);
							printf("(tipo: %s)\n",obtenerTipo(sectorVariables,tipoAsignacion));
						}
						OP_ASIG expresion
						{
							esAsignacion=0;
							tipoAsignacion=sinTipo;
							ponerEnPolaca(&polaca,"=");
							printf("fin asignacion\n");
						}
	;

	iteracion:  		WHILE PARENTESIS_I condicion
						{
							tipoCondicion=condicionWhile;
						}
						PARENTESIS_F
						{
							printf("while\n");
						}
						DO bloque
						{
							printf("inicio while\n");
							t_info info;
							info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
							info.nro=contadorWhile++;
							sprintf(info.cadena,"#repeat_%d",info.nro);
							ponerEnPolaca(&polaca,info.cadena);
							sprintf(info.cadena,"$repeat_%d",info.nro);
							ponerEnPila(&pilaWhile,&info);
						}
						ENDWHILE
						{
							printf("fin while\n");
							sacarDePila(&pilaWhile);
						}
	;

	seleccion:			IF
						{
							printf("if\n");
							t_info info;
							info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
							info.nro=contadorIf++;
							sprintf(info.cadena,"#if_%d",info.nro);
							ponerEnPolaca(&polaca,info.cadena);
							ponerEnPila(&pilaIf,&info);
							tipoCondicion=condicionIf;
						}
						PARENTESIS_I condicion PARENTESIS_F
						{
							char aux[10];
					 		sprintf(aux,"#then_if_%d",topeDePila(&pilaIf)->nro);
					 		ponerEnPolaca(&polaca,aux);
						}
	                  	DO resto
	                  	ENDIF
	                  	{
							printf("endif\n");
							char aux[20];
							sprintf(aux,"#endif_%d",sacarDePila(&pilaIf)->nro);
							ponerEnPolaca(&polaca,aux);
						}
	;

	condicion: 			comparacion
						{
							printf("comparacion\n");
							switch(tipoCondicion)
							{
								case condicionIf:
									topeDePila(&pilaIf)->andOr=condicionSimple;
									topeDePila(&pilaIf)->salto1=contadorPolaca+1;
									ponerEnPolaca(&polaca,"CMP");
									ponerEnPolaca(&polaca,"");
									ponerEnPolaca(&polaca,obtenerSalto(inverso));
									break;

								case condicionWhile:
									topeDePila(&pilaWhile)->andOr=condicionSimple;
									ponerEnPolaca(&polaca,"CMP");
							 		ponerEnPolaca(&polaca,topeDePila(&pilaWhile)->cadena);
									ponerEnPolaca(&polaca,obtenerSalto(normal));
									char aux[20];
									sprintf(aux,"#end_repeat_%d",topeDePila(&pilaWhile)->nro);
									ponerEnPolaca(&polaca,aux);
									break;
							}
						}
	|					
						comparacion
	                    and_or
						{
							printf("and_or\n");	
							switch(tipoCondicion)
							{
								case condicionIf:
									switch(topeDePila(&pilaIf)->andOr){
									case and:
										topeDePila(&pilaIf)->salto2=contadorPolaca+1;
										ponerEnPolaca(&polaca,"CMP");
										ponerEnPolaca(&polaca,"");
										ponerEnPolaca(&polaca,obtenerSalto(inverso));
										break;

									case or:
										topeDePila(&pilaIf)->salto2=contadorPolaca+1;
										ponerEnPolaca(&polaca,"CMP");
										ponerEnPolaca(&polaca,"");
										ponerEnPolaca(&polaca,obtenerSalto(normal));
										break;
									}
									break;

								case condicionWhile:
									switch(topeDePila(&pilaWhile)->andOr){
										case and:
											ponerEnPolaca(&polaca,"CMP");
									 		char aux[20];
											sprintf(aux,"$end_repeat_%d",topeDePila(&pilaWhile)->nro);
											ponerEnPolaca(&polaca,aux);
											ponerEnPolaca(&polaca,obtenerSalto(inverso));
											break;

										case or:
											ponerEnPolaca(&polaca,"CMP");
									 		ponerEnPolaca(&polaca,topeDePila(&pilaWhile)->cadena);
											ponerEnPolaca(&polaca,obtenerSalto(normal));
											break;
									}
									break;
							}
						}
	                    comparacion
	                  	{
	                  		switch(tipoCondicion)
	                  		{
								case condicionIf:
									topeDePila(&pilaIf)->salto1=contadorPolaca+1;
									ponerEnPolaca(&polaca,"CMP");
									ponerEnPolaca(&polaca,"");
									ponerEnPolaca(&polaca,obtenerSalto(inverso));
									break;

								case condicionWhile:
									ponerEnPolaca(&polaca,"CMP");
							 		ponerEnPolaca(&polaca,topeDePila(&pilaWhile)->cadena);
									ponerEnPolaca(&polaca,obtenerSalto(normal));
									char aux[20];
									sprintf(aux,"#end_repeat_%d",topeDePila(&pilaWhile)->nro);
									ponerEnPolaca(&polaca,aux);
									break;
							}
	                  	}
	|
						OP_NOT comparacion
						{
							printf("not\n");
							switch(tipoCondicion)
							{
								case condicionIf:
									topeDePila(&pilaIf)->andOr=condicionSimple;
									topeDePila(&pilaIf)->salto1=contadorPolaca+1;
									ponerEnPolaca(&polaca,"CMP");
									ponerEnPolaca(&polaca,"");
									ponerEnPolaca(&polaca,obtenerSalto(normal));
									break;

								case condicionWhile:
									topeDePila(&pilaWhile)->andOr=condicionSimple;
									ponerEnPolaca(&polaca,"CMP");
							 		ponerEnPolaca(&polaca,topeDePila(&pilaWhile)->cadena);
									ponerEnPolaca(&polaca,obtenerSalto(inverso));
									char aux[20];
									sprintf(aux,"#end_repeat_%d",topeDePila(&pilaWhile)->nro);
									ponerEnPolaca(&polaca,aux);
									break;
							}
	                  	}
	|
						between
						{
							printf("condición con between\n");
						}
	|
						inlist
						{
							printf("condición con in list\n");
						}
	;

	and_or:				OP_AND
						{
							if(tipoCondicion==condicionIf)
							{
								topeDePila(&pilaIf)->andOr=and;
							}
							else
							{
								topeDePila(&pilaWhile)->andOr=and;
							}
						}
	|					OP_OR
						{
							if(tipoCondicion==condicionIf)
							{
								topeDePila(&pilaIf)->andOr=or;
							}
							else
							{
								topeDePila(&pilaWhile)->andOr=or;
							}
						}
	;

	comparacion : expresion COMPARADOR expresion {strcpy(ultimoComparador,$<cadena>2);}
	;

	resto:				bloque
						{
							printf("if true\n");
							char aux[10];
					 		sprintf(aux,"$endif_%d",topeDePila(&pilaIf)->nro);
					 		if(topeDePila(&pilaIf)->andOr==and||topeDePila(&pilaIf)->andOr==or)
					 			ponerEnPolacaNro(&polaca,topeDePila(&pilaIf)->salto2,aux);
					 		ponerEnPolacaNro(&polaca,topeDePila(&pilaIf)->salto1,aux);
						}
	|
						bloque
	                  	{
	                  		printf("if true\n");
	                  		char aux[10];
					 		sprintf(aux,"$endif_%d",topeDePila(&pilaIf)->nro);
					 		ponerEnPolaca(&polaca,aux);
					 		ponerEnPolaca(&polaca,"BI");
	                  	}
	                    ELSE
	                    {
	                    	printf("else\n");
	                    	char aux[10];
					 		sprintf(aux,"#else_%d",topeDePila(&pilaIf)->nro);
					 		ponerEnPolaca(&polaca,aux);
	                    }
	                    bloque
	                    {
	                    	printf("if false\n");
					 		char aux[10];
					 		sprintf(aux,"$else_%d",topeDePila(&pilaIf)->nro);
					 		if(topeDePila(&pilaIf)->andOr==and)
					 		{
					 			ponerEnPolacaNro(&polaca,topeDePila(&pilaIf)->salto2,aux);
					 		}
					 		else
					 		{
					 			if(topeDePila(&pilaIf)->andOr==or)
					 			{
					 				sprintf(aux,"$then_if_%d",topeDePila(&pilaIf)->nro);
					 				ponerEnPolacaNro(&polaca,topeDePila(&pilaIf)->salto2,aux);
					 			}
					 		}
					 		sprintf(aux,"$else_%d",topeDePila(&pilaIf)->nro);
					 		ponerEnPolacaNro(&polaca,topeDePila(&pilaIf)->salto1,aux);
	                    }
	|
						bloque
						{
							printf("if true\n");
	                  		char aux[10];
					 		sprintf(aux,"$endif_%d",topeDePila(&pilaIf)->nro);
					 		ponerEnPolaca(&polaca,aux);
					 		ponerEnPolaca(&polaca,"BI");
						}
						ELSIF
						{
							printf("elsif");
							t_info info;
							info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
							info.nro=contadorIf++;
							sprintf(info.cadena,"#if_%d",info.nro);
							ponerEnPolaca(&polaca,info.cadena);
							ponerEnPila(&pilaIf,&info);
							tipoCondicion=condicionIf;
						}
						PARENTESIS_I condicion PARENTESIS_F
						{
							char aux[10];
					 		sprintf(aux,"#then_if_%d",topeDePila(&pilaIf)->nro);
					 		ponerEnPolaca(&polaca,aux);
						}
	                  	bloque
						ELSE
						{
							printf("else\n");
	                    	char aux[10];
					 		sprintf(aux,"#else_%d",topeDePila(&pilaIf)->nro);
					 		ponerEnPolaca(&polaca,aux);
						}
						bloque
						{
							printf("if false\n");
					 		char aux[10];
					 		sprintf(aux,"$else_%d",topeDePila(&pilaIf)->nro);
					 		if(topeDePila(&pilaIf)->andOr==and)
					 		{
					 			ponerEnPolacaNro(&polaca,topeDePila(&pilaIf)->salto2,aux);
					 		}
					 		else
					 		{
					 			if(topeDePila(&pilaIf)->andOr==or)
					 			{
					 				sprintf(aux,"$then_if_%d",topeDePila(&pilaIf)->nro);
					 				ponerEnPolacaNro(&polaca,topeDePila(&pilaIf)->salto2,aux);
					 			}
					 		}
					 		sprintf(aux,"$else_%d",topeDePila(&pilaIf)->nro);
					 		ponerEnPolacaNro(&polaca,topeDePila(&pilaIf)->salto1,aux);
						}
	;

	lectura:			READ ID
	                    {
							printf("read id\n");
							if(tablaVariables[buscarEnTablaDeSimbolos(sectorVariables,$<cadena>1)].tipo==sinTipo)
							{
								yyerrormsj($<cadena>1,ErrorSintactico,ErrorIdNoDeclarado,"");
							}
							ponerEnPolaca(&polaca,tablaVariables[buscarEnTablaDeSimbolos(sectorVariables,$<cadena>2)].nombre);
							ponerEnPolaca(&polaca,"READ");
						}
	;

	escritura:			WRITE ID
	                    {
	                    	printf("write id\n");
	                    	if(tablaVariables[buscarEnTablaDeSimbolos(sectorVariables,$<cadena>1)].tipo==sinTipo)
	                    	{
								yyerrormsj($<cadena>1,ErrorSintactico,ErrorIdNoDeclarado,"");
	                    	}
							ponerEnPolaca(&polaca,tablaVariables[buscarEnTablaDeSimbolos(sectorVariables,$<cadena>2)].nombre);
							ponerEnPolaca(&polaca,"WRITE");
	                    }
 	|
 						WRITE CTE_STRING
 						{
 							printf("write string\n");
							ponerEnPolaca(&polaca,tablaConstantes[buscarEnTablaDeSimbolos(sectorConstantes,$<cadena>2)].nombre);
							ponerEnPolaca(&polaca,"WRITE");
 						}
	;

	bloque_declaracion:	DECVAR
						{
							printf("bloque de declaracion\n");
						}
						declaraciones ENDDEC
						{
							printf("fin bloque de declaracion\n");
						}
	;

	declaraciones:		declaraciones lista_id_y_tipo
						{
							printf("multiple\n");
						}
	|
						lista_id_y_tipo
	;

	lista_id_y_tipo: 	var_dec COMA lista_id_y_tipo
	|
						var_dec OP_DEC tipodato
						{
							contadorListaVar=0;
						}
	;

	var_dec:			ID
						{
							int posicion=buscarEnTablaDeSimbolos(sectorVariables,yylval.cadena);
							indicesParaAsignarTipo[contadorListaVar++]=posicion;
						}
	|					
						ID
						{
							int posicion=buscarEnTablaDeSimbolos(sectorVariables,yylval.cadena);
							indicesParaAsignarTipo[contadorListaVar++]=posicion;
						}
						PARENTESIS_I CTE_INT
						{
							if(atoi($<cadena>4)<=0)
							{
								yyerrormsj($<cadena>3,ErrorSintactico,ErrorOperacionNoValida,$<cadena>4);
							}
							tablaVariables[buscarEnTablaDeSimbolos(sectorVariables,$<cadena>3)].limite=atoi($<cadena>4);
						}
						PARENTESIS_F
	;

	tipodato: 			INTEGER
						{
							int posicion=buscarEnTablaDeSimbolos(sectorVariables,yylval.cadena);
							printf("Tipo de a: ");
							if(strcmp("sin tipo",(const char*)obtenerTipo(sectorVariables, tablaVariables[posicion].tipo)) == 0)
							{
								tablaVariables[posicion].tipo=tipoInt;
							}
							else
							{
								yyerrormsj(tablaVariables[posicion].valor,ErrorSintactico,ErrorIdRepetida,"");
							}										
							
							printf("tipo entero\n");							
						}
	|					FLOAT
						{
							int posicion=buscarEnTablaDeSimbolos(sectorVariables,yylval.cadena);
							printf("Tipo de a: ");
							if(strcmp("sin tipo",(const char*)obtenerTipo(sectorVariables, tablaVariables[posicion].tipo)) == 0)
							{
								tablaVariables[posicion].tipo=tipoFloat;
							}
							else
							{
								yyerrormsj(tablaVariables[posicion].valor,ErrorSintactico,ErrorIdRepetida,"");
							}
							
							printf("tipo flotante\n");
						}
	|					STRING
						{	
							int posicion=buscarEnTablaDeSimbolos(sectorVariables,yylval.cadena);
							printf("Tipo de a: ");
							if(strcmp("sin tipo",(const char*)obtenerTipo(sectorVariables, tablaVariables[posicion].tipo)) == 0)
							{
								tablaVariables[posicion].tipo=tipoString;
							}
							else
							{
								yyerrormsj(tablaVariables[posicion].valor,ErrorSintactico,ErrorIdRepetida,"");
							}
							
							printf("tipo string\n");
						}
	;

	expresion:			expresion OP_SUM
						{
							printf("+\n");
							auxiliaresNecesarios++;
					    	if(esAsignacion==1&&tipoAsignacion==tipoString)
					    	{
								yyerrormsj("suma", ErrorSintactico,ErrorOperacionNoValida,"");
					    	}
						}
						termino
						{
							ponerEnPolaca(&polaca,"+");
						}
	|
						expresion OP_REST
						{
							printf("-\n");
							auxiliaresNecesarios++;
							if(esAsignacion==1&&tipoAsignacion==tipoString)
							{
								yyerrormsj("resta", ErrorSintactico,ErrorOperacionNoValida,"");
							}
						}
						termino
						{
							ponerEnPolaca(&polaca,"-");
						}
	|
						termino
						{
							printf("termino\n");
						}
	;

	termino: 			termino OP_MULT
						{
							printf("*\n");
							auxiliaresNecesarios++;
					    	if(esAsignacion==1&&tipoAsignacion==tipoString)
					    	{
								yyerrormsj("multiplicacion", ErrorSintactico,ErrorOperacionNoValida,"");
					    	}
						}
						factor
	                  	{
	                    	ponerEnPolaca(&polaca,"*");
	                    }
	|
						termino OP_DIV
	                  	{
							printf("/\n");
							auxiliaresNecesarios++;
					    	if(esAsignacion==1&&tipoAsignacion==tipoString)
								yyerrormsj("division", ErrorSintactico,ErrorOperacionNoValida,"");
	                  	}
	                  	factor
	                  	{
	                  		ponerEnPolaca(&polaca,"/");
	                  	}
	|
	                  	factor
						{
							printf("factor\n");
	                    }
	;

	factor: 			CTE_INT
    					{
					    	printf("CTE_INT: %s\n", $<cadena>1);
				    		if(esAsignacion==1&&tipoAsignacion!=tipoInt)
				    		{
				    			yyerrormsj($<cadena>1, ErrorSintactico,ErrorConstanteDistintoTipo,"");
				    		}
							ponerEnPolaca(&polaca,tablaConstantes[buscarEnTablaDeSimbolos(sectorConstantes,$<cadena>1)].nombre);
					    }
	| 					
						CTE_FLOAT
					    {
					    	printf("CTE_FLOAT: %s\n", $<cadena>1);
					    	if(esAsignacion==1&&tipoAsignacion!=tipoFloat)
					    	{
					    		yyerrormsj($<cadena>1, ErrorSintactico,ErrorConstanteDistintoTipo,"");
					    	}
							ponerEnPolaca(&polaca,tablaConstantes[buscarEnTablaDeSimbolos(sectorConstantes,$<cadena>1)].nombre);
					    }
	|					
						CTE_STRING
						{
							printf("CTE_STRING: %s\n", $<cadena>1);
							if(esAsignacion==1&&tipoAsignacion!=tipoString)
							{
					    		yyerrormsj($<cadena>1, ErrorSintactico,ErrorConstanteDistintoTipo,"");
							}
							ponerEnPolaca(&polaca,tablaConstantes[buscarEnTablaDeSimbolos(sectorConstantes,$<cadena>1)].nombre);
						}
	|
	                  	ID
	                  	{
	                  		printf("id\n");
	                  		printf("%s\n", yylval.cadena);
	                  		int posicion=buscarEnTablaDeSimbolos(sectorVariables,yylval.cadena);
							indicesParaAsignarTipo[contadorListaVar++]=posicion;
					    	if(tablaVariables[buscarEnTablaDeSimbolos(sectorVariables,$<cadena>1)].tipo==sinTipo)
					    	{
								yyerrormsj($<cadena>1,ErrorSintactico,ErrorIdNoDeclarado,"");
					    	}
				    		if(esAsignacion==1&& tablaVariables[buscarEnTablaDeSimbolos(sectorVariables,$<cadena>1)].tipo!=tipoAsignacion)
				    		{
								yyerrormsj($<cadena>1, ErrorSintactico,ErrorIdDistintoTipo,"");
				    		}
							ponerEnPolaca(&polaca,tablaVariables[buscarEnTablaDeSimbolos(sectorVariables,$<cadena>1)].nombre);
	                  	}
	|
						PARENTESIS_I expresion PARENTESIS_F
	;

	between:			BETWEEN //#between_# id exp1 CMP BLT _to_false_ id exp2 CMP BGT _to_false_ TRUE BI _to_final_ FALSE final
						{
							printf("between\n");
							contadorBetween++;
							t_info info;
							info.nro = contadorBetween;
							info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
							sprintf(info.cadena,"#between_%d",info.nro);
							ponerEnPolaca(&polaca,info.cadena);
							if(info.cadena==NULL){
								printf("Error al solicitar memoria\n");
								exit(1);
							}
							sprintf(info.cadena,"#between_%d",info.nro);
							ponerEnPolaca(&polaca,info.cadena);
							info.cantExpresiones=0;
							ponerEnPila(&pilaBetween,&info);
						}
						PARENTESIS_I ID
						{
							printf("id paramBetween\n");
						}
						COMA rango PARENTESIS_F
						{
							printf("rango de expresiones\n");
						}
	;

	rango:				CORCHETE_I expresion PUNTO_Y_COMA expresion CORCHETE_F
						{
							printf("rango\n");
						}
	;

	inlist:				INLIST //#inlist_# (id exp# CMP BEQ _to_true_ FALSE)+ TRUE
						{
							printf("in list\n");
							contadorInList++;
							t_info info;
							info.nro = contadorInList;
							info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
							sprintf(info.cadena,"#inlist_%d",info.nro);
							ponerEnPolaca(&polaca,info.cadena);
							if(info.cadena==NULL){
								printf("Error al solicitar memoria\n");
								exit(1);
							}
							sprintf(info.cadena,"#between_%d",info.nro);
							ponerEnPolaca(&polaca,info.cadena);
							info.cantExpresiones=0;
							ponerEnPila(&pilaInList,&info);
						}
						PARENTESIS_I ID
						{
							printf("id paramInList\n");
						}
						PUNTO_Y_COMA lista_expresiones PARENTESIS_F
						{
							printf("Expresiones en InList_%d: %d\n", topeDePila(&pilaInList)->nro,topeDePila(&pilaInList)->cantExpresiones);
							char aux[50];
							sprintf(aux,"%d.0",topeDePila(&pilaInList)->cantExpresiones);
							insertarEnTablaDeSimbolos(sectorConstantes,tipoFloat,aux);
							sprintf(aux,"%s",tablaConstantes[buscarEnTablaDeSimbolos(sectorConstantes,aux)].nombre);
							ponerEnPolaca(&polaca,aux);
							sacarDePila(&pilaInList);
						}
	;

	lista_expresiones:	CORCHETE_I expresiones CORCHETE_F
						{
							printf("lista de expresiones\n");
						}

	;

	expresiones: 		expresion
						{
							
						}
	|
						expresion
						{
							
						}
						PUNTO_Y_COMA expresiones
						{
							
						}
	;

%%

/* codigo */

int main(int argc,char *argv[])
{
	crearPila(&pilaIf);
	crearPila(&pilaWhile);
	crearPila(&pilaBetween);
	crearPila(&pilaInList);
	crearPila(&pilaASM);
	crearPolaca(&polaca);

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

	printf("\nANALIZADOR LEXICO GENERADO\n");
	printf("\nANALIZADOR SINTACTICO GENERADO\n");

	grabarTiraDeTokens();
	printf("\nTIRA DE TOKENS GENERADA\n");

	grabarTablaDeSimbolos(0);
	printf("\nTABLA DE SIMBOLOS GENERADA\n");

	vaciarPila(&pilaIf);
	vaciarPila(&pilaWhile);
	vaciarPila(&pilaBetween);
	vaciarPila(&pilaInList);

	guardarPolaca(&polaca);
	printf("\nPOLACA INVERSA GENERADA\n");

	generar_assembler(&polaca);
	printf("\nASSEMBLER GENERADO\n");

  	return 0;
}

/* funciones */

int yyerrormsj(const char * info,enum tipoDeError tipoDeError ,enum error error, const char *infoAdicional)
{
	grabarTablaDeSimbolos(1);
	printf("[Linea %d] ",yylineno);
  	switch(tipoDeError){
        case ErrorSintactico:
            printf("Error sintactico. ");
            break;
        case ErrorLexico:
            printf("Error lexico. ");
            break;
    }
  	switch(error){
		case ErrorIdRepetida:
			printf("Descripcion: el id '%s' ha sido declarado más de una vez\n",info);
			break;
		case ErrorIdNoDeclarado:
			printf("Descripcion: el id '%s' no ha sido declarado\n",info);
			break;
		case ErrorOperacionNoValida:
			printf("Descripcion: La operacion %s no es válida para variables de tipo %s\n",info, obtenerTipo(sectorVariables, tipoAsignacion));
			break;
		case ErrorIdDistintoTipo:
			printf("Descripcion: La variable '%s' no es de tipo %s\n",info,obtenerTipo(sectorVariables, tipoAsignacion));
			break;
		case ErrorConstanteDistintoTipo:
			printf("Descripcion: La constante %s no es de tipo %s\n", info, obtenerTipo(sectorVariables, tipoAsignacion));
			break;
    }

  	system ("Pause");
    exit (1);
}

int yyerror()
{
	grabarTablaDeSimbolos(1);
	printf("Error sintactico \n");
	system ("Pause");
	exit (1);
}

/* primitivas de pila */

void crearPila(t_pila* pp)
{
    *pp=NULL;
}

int ponerEnPila(t_pila* pp,t_info* info)
{
    t_nodoPila* pn=(t_nodoPila*)malloc(sizeof(t_nodoPila));
    if(!pn)
        return 0;
    pn->info=*info;
    pn->psig=*pp;
    *pp=pn;
    return 1;
}

t_info * sacarDePila(t_pila* pp)
{
	t_info* info = (t_info *) malloc(sizeof(t_info));
    if(!*pp){
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

/* primitivas de polaca */

void crearPolaca(t_polaca* pp)
{
    *pp=NULL;
}

char * sacarDePolaca(t_polaca * pp)
{
	t_nodoPolaca* nodo;
	t_nodoPolaca* anterior;
	char * cadena = (char*)malloc(sizeof(char)*CADENA_MAXIMA);;
	nodo = *pp;

	while(nodo->psig)
	{
		anterior = nodo;
		nodo = nodo->psig;
	}

	anterior->psig=NULL;
	strcpy(cadena, nodo->info.cadena);
	free(nodo);
	return cadena;
}

int ponerEnPolaca(t_polaca* pp, char *cadena)
{
    t_nodoPolaca* pn = (t_nodoPolaca*)malloc(sizeof(t_nodoPolaca));
    if(!pn)
    {
    	printf("ponerEnPolaca: Error al solicitar memoria\n");
        return ERROR;
    }
    t_nodoPolaca* aux;
    strcpy(pn->info.cadena,cadena);
    pn->info.nro=contadorPolaca++;
    pn->psig=NULL;
    if(!*pp)
    {
    	*pp=pn;
    	return OK;
    }
    else
    {
    	aux=*pp;
    	while(aux->psig)
        	aux=aux->psig;
        aux->psig=pn;
    	return OK;
    }
}

int ponerEnPolacaNro(t_polaca* pp,int pos, char *cadena)
{
	t_nodoPolaca* aux;
	aux=*pp;
    while(aux!=NULL && aux->info.nro<pos)
    {
    	aux=aux->psig;
    }
    if(aux->info.nro==pos)
    {
    	strcpy(aux->info.cadena,cadena);
    	return OK;
    }
    else
    {
    	printf("NO ENCONTRADO\n");
    	return ERROR;
    }
    return ERROR;
}

void guardarPolaca(t_polaca *pp)
{
	FILE*pt=fopen("intermedia.txt","w+");
	t_nodoPolaca* pn;
	if(!pt)
	{
		printf("Error al crear la tabla de simbolos\n");
		return;
	}
	while(*pp)
    {
        pn=*pp;
        fprintf(pt, "%s\n",pn->info.cadena);
        *pp=(*pp)->psig;
        free(pn);
    }
	fclose(pt);
}

char* obtenerSalto(enum tipoSalto tipo)
{
	switch(tipo)
	{
		case normal:
			if(strcmp(ultimoComparador,"==")==0)
				return("BEQ");
			if(strcmp(ultimoComparador,">")==0)
				return("BGT");
			if(strcmp(ultimoComparador,"<")==0)
				return("BLT");
			if(strcmp(ultimoComparador,">=")==0)
				return("BGE");
			if(strcmp(ultimoComparador,"<=")==0)
				return("BLE");
			if(strcmp(ultimoComparador,"!=")==0)
				return("BNE");
			break;

		case inverso:
			if(strcmp(ultimoComparador,"==")==0)
				return("BNE");
			if(strcmp(ultimoComparador,">")==0)
				return("BLE");
			if(strcmp(ultimoComparador,"<")==0)
				return("BGE");
			if(strcmp(ultimoComparador,">=")==0)
				return("BLT");
			if(strcmp(ultimoComparador,"<=")==0)
				return("BGT");
			if(strcmp(ultimoComparador,"!=")==0)
				return("BEQ");
			break;
	}
}

char* obtenerSalto2(char* comparador,enum tipoSalto tipo)
{
	switch(tipo)
	{
		case normal:
			if(strcmp(comparador,"==")==0)
				return("BEQ");
			if(strcmp(comparador,">")==0)
				return("BGT");
			if(strcmp(comparador,"<")==0)
				return("BLT");
			if(strcmp(comparador,">=")==0)
				return("BGE");
			if(strcmp(comparador,"<=")==0)
				return("BLE");
			if(strcmp(comparador,"!=")==0)
				return("BNE");
			break;

		case inverso:
			if(strcmp(comparador,"==")==0)
				return("BNE");
			if(strcmp(comparador,">")==0)
				return("BLE");
			if(strcmp(comparador,"<")==0)
				return("BGE");
			if(strcmp(comparador,">=")==0)
				return("BLT");
			if(strcmp(comparador,"<=")==0)
				return("BGT");
			if(strcmp(comparador,"!=")==0)
				return("BEQ");
			break;
	}
}

/* assembler */

void generar_assembler(t_polaca *pp)
{
		t_nodoPolaca* aux;
		aux=*pp;
		int i;
		int nroAuxReal=0;
		int nroAuxEntero=0;
		char aux1[50]="aux\0";
		char aux2[10];
		enum tipoDato ultimoTipo=sinTipo;
		char ultimaCadena[CADENA_MAXIMA];
		int huboAsignacion=TRUE;
		FILE* pf=fopen("final.asm","w+");
		if(!pf)
		{
			printf("Error al guardar el archivo assembler.\n");
			exit(1);
		}
		
		// cabecera de assembler
		fprintf(pf,"include macros2.asm\n");
		fprintf(pf,"include number.asm\n\n");
		fprintf(pf,"include numbers.asm\n\n");
		fprintf(pf,".MODEL LARGE\n.STACK 200h\n.386\n.387\n.DATA\n\n\tMAXTEXTSIZE equ 50\n");
		
		// declaración de variables
		for(i = 0; i<indiceVariable; i++)
		{
			fprintf(pf,"\t@%s ",tablaVariables[i].nombre);
			switch(tablaVariables[i].tipo){
				case tipoInt:
					fprintf(pf,"\tDD 0.0\n");
					break;
				case tipoFloat:
					fprintf(pf,"\tDD 0.0\n");
					break;
				case tipoString:
					fprintf(pf,"\tDB MAXTEXTSIZE dup (?),'$'\n");
					break;
			}
		}

		// declaración de constantes
		for(i = 0; i<indiceConstante; i++)
		{
			switch(tablaConstantes[i].tipo)
			{
				case tipoInt:
					fprintf(pf,"\t@%s \tDW %d\n",tablaConstantes[i].nombre,atoi(tablaConstantes[i].valor));
					break;
				case tipoFloat:
					fprintf(pf,"\t@%s \tDD %s\n",tablaConstantes[i].nombre,tablaConstantes[i].valor);
					break;
				case tipoString:
					fprintf(pf,"\t@%s \tDB \"%s\",'$',%d dup(?)\n",tablaConstantes[i].nombre,tablaConstantes[i].valor,50-strlen(tablaConstantes[i].valor));
					break;

			}
		}

		// declaración de auxiliares
		for(i=0;i<auxiliaresNecesarios;i++)
		{
			fprintf(pf,"\t@_auxR%d \tDD 0.0\n",i);
		}
		for(i=0;i<auxiliaresNecesarios;i++)
		{
			fprintf(pf,"\t@_auxE%d \tDW 0\n",i);
		}

		// zona de código
		fprintf(pf,"\n.CODE\n.startup\n\tmov AX,@DATA\n\tmov DS,AX\n\n\tFINIT\n\n");

		// generación de assembler recorriendo la polaca
	    while(aux!=NULL)
	    {
	    	char linea[CADENA_MAXIMA];
	    	int pos;
	    	strcpy(linea,aux->info.cadena);

	    	// para variables
	    	if((pos=buscarEnTablaDeSimbolosASM(sectorVariables,linea))!=NO_ENCONTRADO)
	    	{
	    		t_info info;
	    		info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
	    		strcpy(info.cadena,linea);
	    		info.tipo=tablaVariables[pos].tipo;
	    		if(pilaASM!=NULL||huboAsignacion==FALSE)
	    		{
	    			huboAsignacion=TRUE;
	    		}
	    		else
	    		{
	    			huboAsignacion=FALSE;
	    		}
	    		ponerEnPila(&pilaASM,&info);
	    		ultimoTipo=info.tipo;
		    }

	    	// para constantes
	    	if((pos=buscarEnTablaDeSimbolosASM(sectorConstantes,linea))!=NO_ENCONTRADO)
	    	{
	    		t_info info2;
	    		info2.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
	    		strcpy(info2.cadena,linea);
	    		info2.tipo=tablaConstantes[pos].tipo;
	    		ponerEnPila(&pilaASM,&info2);
	    		if(info2.tipo!=tipoString)
	    		{
		    		if(pilaASM==NULL)
		    		{
		    			huboAsignacion=FALSE;
		    		}
		    		ultimoTipo=info2.tipo;	
		    	}
		    	else
		    	{
		    		ultimoTipo=info2.tipo;
		    	}
		    }

		    // operadores aritméticos
		    if(strcmp(linea,"*")==0)
		    {
				t_info *op1=sacarDePila(&pilaASM);
				t_info *op2;
				t_info info;
				switch(op1->tipo)
				{
					case tipoInt:
							fprintf(pf,";MULTIPLICACION DE ENTEROS\n");
							op2=sacarDePila(&pilaASM);
							fprintf(pf,"\tfild \t@%s\n", op1->cadena);
							fprintf(pf,"\tfimul \t@%s\n", op2->cadena); 
							strcpy(aux1,"_auxE");
							itoa(nroAuxEntero,aux2,10);
				   			strcat(aux1,aux2);
							fprintf(pf,"\tfistp \t@%s\n", aux1);
							info.tipo=tipoInt;
							info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
				    		strcpy(info.cadena,aux1);
				    		ponerEnPila(&pilaASM,&info);
							nroAuxEntero++;
						break;

					case tipoFloat:
						fprintf(pf,";MULTIPLICACION DE REALES\n");
						op2=sacarDePila(&pilaASM);
						fprintf(pf,"\tfld \t@%s\n", op1->cadena);
						fprintf(pf,"\tfld \t@%s\n", op2->cadena);
						fprintf(pf,"\tfmul\n");
						strcpy(aux1,"_auxR");
						itoa(nroAuxReal,aux2,10);
			   			strcat(aux1,aux2);
						fprintf(pf,"\tfstp \t@%s\n", aux1);
						info.tipo=tipoFloat;
						info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
				    	strcpy(info.cadena,aux1);
				    	ponerEnPila(&pilaASM,&info);
						nroAuxReal++;
						break;
				}
			}

			if(strcmp(linea,"+")==0)
			{
				t_info *op1=sacarDePila(&pilaASM);
				t_info *op2;
				t_info info;
				switch(op1->tipo)
				{
					case tipoInt:
							fprintf(pf,";SUMA DE ENTEROS\n");
							op2=sacarDePila(&pilaASM);
							fprintf(pf,"\tfild \t@%s\n", op1->cadena);
							fprintf(pf,"\tfiadd \t@%s\n", op2->cadena); 
							strcpy(aux1,"_auxE");
							itoa(nroAuxEntero,aux2,10);
				   			strcat(aux1,aux2);
							fprintf(pf,"\tfistp \t@%s\n", aux1);
							info.tipo=tipoInt;
							info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
				    		strcpy(info.cadena,aux1);
				    		ponerEnPila(&pilaASM,&info);
							nroAuxEntero++;
						break;

					case tipoFloat:
						fprintf(pf,";SUMA DE REALES\n");
						op2=sacarDePila(&pilaASM);
						fprintf(pf,"\tfld \t@%s\n", op1->cadena);
						fprintf(pf,"\tfld \t@%s\n", op2->cadena);
						fprintf(pf,"\tfadd\n");
						strcpy(aux1,"_auxR");
						itoa(nroAuxReal,aux2,10);
			   			strcat(aux1,aux2);
						fprintf(pf,"\tfstp \t@%s\n", aux1);
						info.tipo=tipoFloat;
						info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
				    	strcpy(info.cadena,aux1);
				    	ponerEnPila(&pilaASM,&info);
						nroAuxReal++;
						break;
				}
			}

			if(strcmp(linea,"/")==0)
			{
				t_info *op1=sacarDePila(&pilaASM);
				t_info *op2=sacarDePila(&pilaASM);;
				t_info info;
				switch(op2->tipo)
				{
					case tipoInt:
							fprintf(pf,";DIVISION DE ENTEROS\n");
							fprintf(pf,"\tfild \t@%s\n", op1->cadena);
							fprintf(pf,"\tfidivr \t@%s\n", op2->cadena); 
							strcpy(aux1,"_auxE");
							itoa(nroAuxEntero,aux2,10);
				   			strcat(aux1,aux2);
							fprintf(pf,"\tfistp \t@%s\n", aux1);
							info.tipo=tipoInt;
							info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
				    		strcpy(info.cadena,aux1);
				    		ponerEnPila(&pilaASM,&info);
							nroAuxEntero++;
						break;

					case tipoFloat:
						fprintf(pf,";DIVISION DE REALES\n");
						fprintf(pf,"\tfld \t@%s\n", op1->cadena);
						fprintf(pf,"\tfld \t@%s\n", op2->cadena);
						fprintf(pf,"\tfdivr\n");
						strcpy(aux1,"_auxR");
						itoa(nroAuxReal,aux2,10);
			   			strcat(aux1,aux2);
						fprintf(pf,"\tfstp \t@%s\n", aux1);
						info.tipo=tipoFloat;
						info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
				    	strcpy(info.cadena,aux1);
				    	ponerEnPila(&pilaASM,&info);
						nroAuxReal++;
						break;
				}
			}

			if(strcmp(linea,"-")==0)
			{
				t_info *op1=sacarDePila(&pilaASM);
				t_info *op2;
				t_info info;
				switch(op1->tipo)
				{
					case tipoInt:
							fprintf(pf,";RESTA DE ENTEROS\n");
							op2=sacarDePila(&pilaASM);
							fprintf(pf,"\tfild \t@%s\n", op1->cadena);
							fprintf(pf,"\tfisubr \t@%s\n", op2->cadena); 
							strcpy(aux1,"_auxE");
							itoa(nroAuxEntero,aux2,10);
				   			strcat(aux1,aux2);
							fprintf(pf,"\tfistp \t@%s\n", aux1);
							info.tipo=tipoInt;
							info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
				    		strcpy(info.cadena,aux1);
				    		ponerEnPila(&pilaASM,&info);
							nroAuxEntero++;
						break;

					case tipoFloat:
						fprintf(pf,";RESTA DE REALES\n");
						op2=sacarDePila(&pilaASM);
						fprintf(pf,"\tfld \t@%s\n", op1->cadena);
						fprintf(pf,"\tfld \t@%s\n", op2->cadena);
						fprintf(pf,"\tfsubr\n");
						strcpy(aux1,"_auxR");
						itoa(nroAuxReal,aux2,10);
			   			strcat(aux1,aux2);
						fprintf(pf,"\tfstp \t@%s\n", aux1);
						info.tipo=tipoFloat;
						info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
				    	strcpy(info.cadena,aux1);
				    	ponerEnPila(&pilaASM,&info);
						nroAuxReal++;
						break;
				}
			}

			// comparadores
			if(strcmp(linea,"CMP")==0)
			{
				t_info *op1= sacarDePila(&pilaASM);
				t_info *op2= sacarDePila(&pilaASM);
				if(op1->tipo==tipoFloat)
				{
					fprintf(pf,"\tfld \t@%s\n", op1->cadena);
					fprintf(pf,"\tfld \t@%s\n", op2->cadena);
				}
				else
				{
					fprintf(pf,"\tfild \t@%s\n", op1->cadena);
					fprintf(pf,"\tfild \t@%s\n", op2->cadena);
				}
			}

			//>
			if(strcmp(linea,"BLE")==0)
			{
				fprintf(pf,"\tfcomp\n\tfstsw\tax\n\tfwait\n\tsahf\n\tjbe\t\t%s\n",sacarDePila(&pilaASM)->cadena);
			}

			//<
			if(strcmp(linea,"BGE")==0)
			{
				fprintf(pf,"\tfcomp\n\tfstsw\tax\n\tfwait\n\tsahf\n\tjae\t\t%s\n",sacarDePila(&pilaASM)->cadena);
			}

			//!=
			if(strcmp(linea,"BEQ")==0)
			{
				fprintf(pf,"\tfcomp\n\tfstsw\tax\n\tfwait\n\tsahf\n\tje\t\t%s\n",sacarDePila(&pilaASM)->cadena);
			}

			//==
			if(strcmp(linea,"BNE")==0)
			{
				fprintf(pf,"\tfcomp\n\tfstsw\tax\n\tfwait\n\tsahf\n\tjne\t\t%s\n",sacarDePila(&pilaASM)->cadena);
			}

			//>=
			if(strcmp(linea,"BLT")==0)
			{
				fprintf(pf,"\tfcomp\n\tfstsw\tax\n\tfwait\n\tsahf\n\tjb\t\t%s\n",sacarDePila(&pilaASM)->cadena);
			}

			//<=
			if(strcmp(linea,"BGT")==0)
			{
				fprintf(pf,"\tfcomp\n\tfstsw\tax\n\tfwait\n\tsahf\n\tja\t\t%s\n",sacarDePila(&pilaASM)->cadena);
			}

			if(strcmp(linea,"BI")==0)
			{
				fprintf(pf,"\tjmp\t\t%s\n",sacarDePila(&pilaASM)->cadena);
			}

			// etiquetas
			if(strchr(linea, '#')!=NULL)
			{
				fprintf(pf,"%s:\n",reemplazarCaracter(linea,"#",""));
			}

			// saltos
			if(strchr(linea, '$')!=NULL)
			{
				t_info info;
				info.cadena=(char*)malloc(sizeof(char)*CADENA_MAXIMA);
		    	strcpy(info.cadena,(const char*)reemplazarCaracter(linea,"$",""));
		    	ponerEnPila(&pilaASM,&info);
			}

			if(strcmp(linea, "EXIT")==0)
			{
				fprintf(pf,"\tmov ah, 4ch\n\tint 21h\n");
			}

			// asignación
			if(strcmp(linea,"=")==0)
			{
				switch(ultimoTipo)
				{
					case tipoString:
						fprintf(pf,";ASIGNACION CADENA\n");
						fprintf(pf,"\tmov ax, @DATA\n\tmov ds, ax\n\tmov es, ax\n");
						fprintf(pf,"\tmov si, OFFSET\t@%s\n", sacarDePila(&pilaASM)->cadena);
						fprintf(pf,"\tmov di, OFFSET\t@%s\n", sacarDePila(&pilaASM)->cadena);
						fprintf(pf,"\tcall copiar\n");
						break;

					case tipoInt:
						fprintf(pf,";ASIGNACION ENTERO\n");
						t_info *op1=sacarDePila(&pilaASM);
						fprintf(pf,"\tfild \t@%s\n", op1->cadena);
						fprintf(pf,"\tfistp \t@%s\n",sacarDePila(&pilaASM)->cadena);
						huboAsignacion=TRUE;
						break;

					case tipoFloat:
						fprintf(pf,";ASIGNACION REAL\n");
						t_info *op=sacarDePila(&pilaASM);
						fprintf(pf,"\tfld \t@%s\n", op->cadena);
						fprintf(pf,"\tfstp \t@%s\n",sacarDePila(&pilaASM)->cadena);
						huboAsignacion=TRUE;
						break;
				}
			}

		    // write
			if(strcmp(linea,"WRITE")==0)
			{
				fprintf(pf,";SALIDA POR CONSOLA\n");
				switch(ultimoTipo)
				{
			    	case tipoInt:
				    	fprintf(pf,"\tdisplayInteger \t@%s,3\n\tnewLine 1\n",sacarDePila(&pilaASM)->cadena);
						break;
					case tipoFloat:
						fprintf(pf,"\tdisplayFloat \t@%s,3\n\tnewLine 1\n",sacarDePila(&pilaASM)->cadena);
						break;
					case tipoString:
						fprintf(pf,"\tdisplayString \t@%s\n\tnewLine 1\n",sacarDePila(&pilaASM)->cadena);
						break;
		    	}
			}

			// read
			if(strcmp(linea,"READ")==0)
			{
				fprintf(pf,";ENTRADA POR CONSOLA\n");
				switch(ultimoTipo)
				{
			   		case tipoInt:
						fprintf(pf,"\tgetFloat \t@%s\n",sacarDePila(&pilaASM)->cadena);
						break;
					case tipoFloat:
						fprintf(pf,"\tgetFloat \t@%s\n",sacarDePila(&pilaASM)->cadena);
						break;
					case tipoString:
						fprintf(pf,"\tgetString \t@%s\n",sacarDePila(&pilaASM)->cadena);
						break;
		    	}
		    }
	    	aux=aux->psig;
	    }

	    fprintf(pf,"\tmov ah, 4ch\n\tint 21h\n\n;FIN DEL PROGRAMA DE USUARIO\n");

	    // funciones para manejo de entrada/salida y cadenas
	    fprintf(pf,"\nstrlen proc\n\tmov bx, 0\n\tstrl01:\n\tcmp BYTE PTR [si+bx],'$'\n\tje strend\n\tinc bx\n\tjmp strl01\n\tstrend:\n\tret\nstrlen endp\n");
		fprintf(pf,"\ncopiar proc\n\tcall strlen\n\tcmp bx , MAXTEXTSIZE\n\tjle copiarSizeOk\n\tmov bx , MAXTEXTSIZE\n\tcopiarSizeOk:\n\tmov cx , bx\n\tcld\n\trep movsb\n\tmov al , '$'\n\tmov byte ptr[di],al\n\tret\ncopiar endp\n");
		fprintf(pf,"\nconcat proc\n\tpush ds\n\tpush si\n\tcall strlen\n\tmov dx , bx\n\tmov si , di\n\tpush es\n\tpop ds\n\tcall strlen\n\tadd di, bx\n\tadd bx, dx\n\tcmp bx , MAXTEXTSIZE\n\tjg concatSizeMal\n\tconcatSizeOk:\n\tmov cx , dx\n\tjmp concatSigo\n\tconcatSizeMal:\n\tsub bx , MAXTEXTSIZE\n\tsub dx , bx\n\tmov cx , dx\n\tconcatSigo:\n\tpush ds\n\tpop es\n\tpop si\n\tpop ds\n\tcld\n\trep movsb\n\tmov al , '$'\n\tmov byte ptr[di],al\n\tret\nconcat endp\n");
		
		// fin del archivo
		fprintf(pf,"\nend");
		fclose(pf);
	}

	int buscarEnTablaDeSimbolosASM(enum sectorTabla sector, char* objetivo)
	{
		int i;
		switch(sector)
		{
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
