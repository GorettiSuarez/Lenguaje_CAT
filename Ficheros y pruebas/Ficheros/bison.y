%{
#include <stdio.h>
#include "SymbolTable.h"
#include "breaklist.h"
#include "FunctionsList.h"
#include <string.h>
#include <sstream>
#include <iostream>
#include <typeinfo>

using namespace std;

FILE *file;

extern FILE *yyin; /* declarado en l´exico */
extern int numlin; /* l´exico le da valores */
int yylex(void);
extern char* yytext;
extern int yydebug; /* modo debug si -t */
extern void yyerror(string mens);

void createVar(int type, string name);
Symbol* createVar2(int type, string name);
void checkIsNotString(int tipo);
void createParameter(int type, string name);
void generaCabecera();
void varEnPilaSymbol(string name);
void varEnPilaValue(int tipo);
void posicionMemoria(Symbol * item);
void checkAritmetic(int tipo1, int tipo2);
void checkLogic(int tipo1, int tipo2);
void checkEqualType(int tipo1, int tipo2);

#define generateCode(formato, params...) { \
	fprintf(file, formato, ##params);\
}

SymbolTable tabla;
breaklist breaks;
FunctionsList listaFunciones;

unsigned int tamanoString = 0; //Se usa para conocer el tamaño de las ristras que se van a imprimir
unsigned int etiqueta = 2; 
unsigned int dirRetorno; 
%}

%union { float real; double doble; int entero; char *ristra; char caracter; unsigned int uentero;}

%token <ristra> CAT KITTY KITTEN IDENTIF CKITTYVALUE CKITTENVALUE KITTENVALUE CATVALUE KITTYVALUE MAIN
%token <entero>  ASIGNA PUNTOYCOMA  

%token SUMA RESTA DIVISION MULTIPLICACION IGUAL DISTINTO MAYORQUE MENORQUE MAYORIGUAL MENORIGUAL OR AND NOT LLAMADA SEPARADOR FUNCION ABRELLAVE CIERRALLAVE ABREPARENTESIS CIERRAPARENTESIS HALT DOSPUNTOS BREAK IF ELSE WHILE FOR LEETECLADO ESCRIBEPANTALLA CONCATENA SALTOLINEA IN

%type <entero> tipo imprimir
%type <ristra> declaracion parametros parametros_instruccion instruccion asignacion bloque_llaves 
%type <real> valor exp 

%left NOT AND OR
%left RESTA SUMA 
%left MULTIPLICACION DIVISION
%left IGUAL DISTINTO MAYORQUE MENORQUE MAYORIGUAL MENORIGUAL
%left CONCATENA

%start programa

%%

programa : {
		    generaCabecera();
		}
        FUNCION MAIN ABREPARENTESIS CIERRAPARENTESIS
        {
                Symbol *item = createVar2(FUNCTION,"main");
                if(item==NULL){yyerror("La función no se ha declarado");}
                if(item->etiquetaFuncion == -1){
                    tabla.addEtiquetaToFuncion($3, 1); //MAIN siempre tendrá la etq 1
                }
				
                tabla.addScope();
            
			    generateCode("L %u:\tR7 = R6 - 8;\t //Comienza la funcion\n", item->etiquetaFuncion);
			    tabla.relDir += 8;
                item->direction = tabla.relDir;

        } 
        bloque_llaves
        {
            generateCode("\t\tGT(-2);\n");        
        }
        conjunto_funciones 
		{
            string fallo = listaFunciones.checkAllDefined();
            if( fallo != " "){
                ostringstream o;
				o <<  "No se ha declarado la funcion: " << fallo << "\n";
				yyerror(o.str());
            }
    		generateCode("END\n");
		}
	;

conjunto_funciones: funcion conjunto_funciones
					|
					;

 
funcion : FUNCION IDENTIF ABREPARENTESIS CIERRAPARENTESIS {
                listaFunciones.setDefined($2);

                //tabla.imprimir();

                Symbol *item = createVar2(FUNCTION,$2);
                if(item==NULL){yyerror("La función no se ha declarado");}
                if(item->etiquetaFuncion == -1){
                    tabla.addEtiquetaToFuncion($2, etiqueta);
                    etiqueta++;
                }
				
                tabla.addScope();
            
                //PILA = R6Previo, L retorno | parametros... (ninguno en este caso)

                //ponemos el cabezal de la pila en la zona donde están las variables de entrada
			    generateCode("L %u:\t\tR7 = R6 - 8; //Cmienza la funcion\n", item->etiquetaFuncion);

			    tabla.relDir += 8;
                item->direction = tabla.relDir;

			} bloque_llaves 
			{

                //guardar R6 antiguo
		      	generateCode("\t\tR5 = P(R6); //Guardamos en R5 el R6 antiguo\n");

		      	//guardar direccion de retorno
			    generateCode("\t\tR2 = P(R6 - 8); //Guardamos en R2 la etiqueta de retorno\n");
			    //movemos la cima de la pila al estado deseado para retornar (vacía y con el resultado en la pila)
		      	generateCode("\t\tR7 = R6 + 8;\n");
                
                //recuperamos R6 del nivel superior
			    generateCode("\t\tR6 = R5; //Hacemos que R6 vuelva a su antiguo lugar\n");
			    generateCode("\t\tGT(R2); //Vamos a la etiqueta de retorno\n");

            }

			/* define pepe(cat a, cat b)*/
		| FUNCION IDENTIF ABREPARENTESIS  {
                listaFunciones.setDefined($2);

                tabla.imprimir();

                Symbol *item = createVar2(FUNCTION,$2);
                if(item==NULL){yyerror("La función no se ha declarado");}
                if(item->etiquetaFuncion == -1){
                    tabla.addEtiquetaToFuncion($2, etiqueta);
                    etiqueta++;
                }
				
                tabla.addScope();
            
                //PILA = R6Previo, L retorno | parametros... (ninguno en este caso) | var retorno en caso de haberla

                //ponemos el cabezal de la pila en la zona donde están las variables de entrada
			    generateCode("L %u:\t\tR7 = R6 - 8; //Cmienza la funcion\n", item->etiquetaFuncion);
			    tabla.relDir += 8;
                item->direction = tabla.relDir;
                generateCode("\t\t//La direccion es %u\n", item->direction);

            } parametros CIERRAPARENTESIS IN ABREPARENTESIS tipo IDENTIF CIERRAPARENTESIS {
                createParameter($9,$10); 
                varEnPilaSymbol($10);
			} bloque_llaves
             {
                //guardar R6 antiguo
		      	generateCode("\t\tR5 = P(R6);\n");

		      	//guardar direccion de retorno
			    generateCode("\t\tR2 = P(R6 - 8);\n");
			    //movemos la cima de la pila al estado deseado para retornar (vacía y con el resultado en la pila)
		      	generateCode("\t\tR7 = R6 + 8;\n");
                
                Symbol *item2 = tabla.search_symbol($10);
		  	    posicionMemoria(item2); //Deja la dir en R1
                generateCode("\t\tR7 = R7 - 8;\n");
		  		generateCode("\t\tRR1 = D(R1);\n");
				generateCode("\t\tD(R7) = RR1;\n");

                //recuperamos R6 del nivel superior
			    generateCode("\t\tR6 = R5;\n");
			    generateCode("\t\tGT(R2);\n");

            }
		;


parametros : tipo IDENTIF { 
                createParameter($1,$2); //Crea el símbolo, dice que es parámetro, y lo relaciona con la última función creada. Falta que sea scope 0
                varEnPilaSymbol($2);

            } 
			|tipo IDENTIF SEPARADOR parametros { 
                createParameter($1,$2); //Crea el símbolo, dice que es parámetro, y lo relaciona con la última función creada. Falta que sea scope 0
                varEnPilaSymbol($2);
            }
			;

bloque_llaves : ABRELLAVE lista_instrucciones CIERRALLAVE{tabla.quitScope();}
			  ;

lista_instrucciones : instruccion lista_instrucciones
					|
					;		

imprimir	: IDENTIF {
				Symbol *item = tabla.search_symbol($1);
			    if(item != NULL){
				    checkIsNotString(item->type); //Solo se imprimen digitos
                    posicionMemoria(item); 
                    generateCode("\t\tR2=R1; //POSICION PILA A IMPRIMIR\n");
                    generateCode("\t\tR1=0x11ff8 ; //COMIENZA IMPRIMIR\n");
                    generateCode("\t\tR3=-1; //IMRIMIR DIGITO\n");
                    generateCode("\t\tR0=%d; //RETORNO\n", etiqueta);
                    generateCode("\t\tGT(putf_);\n");
                    generateCode("L %u:\n", etiqueta);
                    etiqueta++;				
			    } else {
				    yyerror("La variable no se ha declarado o no tiene tipo");
			    }
				
			}
			| CKITTENVALUE 
			{
                
                string a = $1;
                //Se quitan dos posiciones una el caracter final " y otra porque se empieza en 0
                string c = a.substr (1,a.size()-2);
                tamanoString = c.size();
                generateCode("\t\tR7 = R7 - %d;\n", tamanoString*4);
			    for(int i = 0; i<tamanoString;i++)
			    {
                    string d = c.substr (i,1);
				    generateCode("\t\tU(R7 + %d) = '%c';\n",i*4 , c[i]);
			    }
                generateCode("\t\tR1=0x11ffc; //COMIENZA IMPRIMIR\n");
                generateCode("\t\tR2=R7; //POSICION PILA A IMPRIMIR\n");
                generateCode("\t\tR3=%d; //NUMERO CARRACTERES\n", tamanoString);
                generateCode("\t\tR0=%d; //RETORNO\n", etiqueta);
                generateCode("\t\tGT(putf_);\n");
                generateCode("L %u:\n", etiqueta);
                etiqueta++;
                
            }
			| CKITTYVALUE
			{
                varEnPilaValue(STRING);
                string a = $1;
                string c = a.substr (1,1);
                tamanoString = c.size();
			    generateCode("\t\tU(R7) = '%c';\n", c[0]);
                generateCode("\t\tR1=0x11ffc; //COMIENZA IMPRIMIR\n");
                generateCode("\t\tR2=R7; //POSICION PILA A IMPRIMIR\n");
                generateCode("\t\tR3=%d; //NUMERO CARRACTERES\n", tamanoString);
                generateCode("\t\tR0=%d; //RETORNO\n", etiqueta);
                generateCode("\t\tGT(putf_);\n");
                generateCode("L %u:\n", etiqueta);
                etiqueta++;
            }
			| imprimir CONCATENA imprimir{}
            |CATVALUE { 
			    varEnPilaValue(INTEGER);
			    generateCode("\t\tI(R7) = %s; //Cojo el valor y lo pongo en la cima de la pila \n", $1);
                generateCode("\t\tR1=0x11ff4 ; //COMIENZA IMPRIMIR\n");
                generateCode("\t\tR2=R7; //POSICION PILA A IMPRIMIR\n");
                generateCode("\t\tR3=-2; //IMRIMIR DIGITO\n");
                generateCode("\t\tR0=%d; //RETORNO\n", etiqueta);
                generateCode("\t\tGT(putf_);\n");
                generateCode("L %u:\n", etiqueta);
                etiqueta++;
    
             }
            |SALTOLINEA{
                generateCode("\t\tR1=0x11ffc ; //COMIENZA IMPRIMIR\n");
                generateCode("\t\tR2 = 10; //POSICION PILA A IMPRIMIR\n"); //Valor ASCII de salto de linea
                generateCode("\t\tR3 = -3; //IMPRIMIR SALTO LINEA\n");
                generateCode("\t\tR0=%d; //RETORNO\n", etiqueta);
                generateCode("\t\tGT(putf_);\n");
                generateCode("L %u:\n", etiqueta);
                etiqueta++;
            }
            | KITTYVALUE {
                varEnPilaValue(FLOAT);
			    generateCode("\t\tD(R7) = %s;\n", $1);
                generateCode("\t\tR1=0x11ff8 ; //COMIENZA IMPRIMIR\n");
                generateCode("\t\tR2=R7; //POSICION PILA A IMPRIMIR\n");
                generateCode("\t\tR3=-1; //NUMERO CARRACTERES\n");
                generateCode("\t\tR0=%d; //RETORNO\n", etiqueta);
                generateCode("\t\tGT(putf_);\n");
                generateCode("L %u:\n", etiqueta);
                etiqueta++;
            }
		    | KITTENVALUE {
                varEnPilaValue(DOUBLE);
			    generateCode("\t\tD(R7) = %s;\n", $1);
                generateCode("\t\tR1=0x11ff8 ; //COMIENZA IMPRIMIR\n");
                generateCode("\t\tR2=R7; //POSICION PILA A IMPRIMIR\n");
                generateCode("\t\tR3=-1; //NUMERO CARRACTERES\n");
                generateCode("\t\tR0=%d; //RETORNO\n", etiqueta);
                generateCode("\t\tGT(putf_);\n");
                generateCode("L %u:\n", etiqueta);
                etiqueta++;
            }
			;
			 
/*Definir todas las instrucciones*/
instruccion : asignacion 
			| declaracion
			| ESCRIBEPANTALLA imprimir PUNTOYCOMA  { }
			| LEETECLADO IDENTIF PUNTOYCOMA 
			{
				Symbol *item = tabla.search_symbol($2);
			    if(item != NULL){
				    checkIsNotString(item->type);
                    posicionMemoria(item);
                    //En R1 se encuentra la direccion de memoria de la variable
                    generateCode("\t\tR0=%d; //RETORNO\n", etiqueta);
                    generateCode("\t\tGT(scanf_);\n");
                    generateCode("L %u:\n", etiqueta);
                    etiqueta++;
						
			    } else {
				    yyerror("La variable no se ha declarado o no tiene tipo");
			    }
				
			}
			| FOR {
                tabla.addScope();
                generateCode("\t\tR7 = R7 - 8; //AQUI COMIENZA EL FOR\n");
				generateCode("\t\tP(R7) = R6;\n");
				generateCode("\t\tR6 = R7;\n");
            }
            ABREPARENTESIS asignacion {
            	$<uentero>$ = etiqueta; //dirección de repeticion
                generateCode("L %u:\t\n",etiqueta);	
			  	etiqueta++;
            }
            exp{
                $<uentero>$ = etiqueta;
                breaks.addNode(etiqueta);
                generateCode("\t\tRR1 = D(R7);\n");
		  	    generateCode("\t\tIF (RR1 == 0) GT(%u); //Comprobación FOR\n", etiqueta);
                etiqueta++;
            }
             PUNTOYCOMA IDENTIF{
                if (strcmp($4, $9)){
                    ostringstream o;
					o <<  "Los identificadores que controlan el for no coinciden: " << $4 << "----" << $9;
					yyerror(o.str());
                }
            } ASIGNA exp CIERRAPARENTESIS{
                  Symbol *item = tabla.search_symbol($9);
                        if( item == NULL) {
	                         string mensaje = "La variable no ha sido declarada";
	                        yyerror(mensaje);
                        } else {
                            switch(item->type){
                                case INTEGER:
                                    posicionMemoria(item); 
                                    generateCode("\t\tRR1 = D(R7);\n");
                                    generateCode("\t\tD(R1) = RR1;\n");
                                    generateCode("\t\tR7 = R6 - %u;\n",tabla.relDir); 
                                    break;

                                case FLOAT:
                                    posicionMemoria(item); 
                                    generateCode("\t\tRR1 = D(R7);\n");
                                    generateCode("\t\tD(R1) = RR1;\n");
                                    generateCode("\t\tR7 = R6 - %u;\n",tabla.relDir); 
                                    break;

                                case DOUBLE:
                                    posicionMemoria(item); 
                                    generateCode("\t\tRR1 = D(R7);\n");
                                    generateCode("\t\tD(R1) = RR1;\n");
                                    generateCode("\t\tR7 = R6 - %u;\n",tabla.relDir); 
                                    break;

                                case STRING:
                                    posicionMemoria(item); 
                                    for (int i = 0; i < tamanoString; i++){
                                        generateCode("\t\tR2 = U(R7 + %i);\n",i);
                                        generateCode("\t\tU(R1 + %i) = R2;\n", i);
                                    }
                                    generateCode("\t\tR7 = R6 - %u;\n",tabla.relDir); 
                                    break;

                                default:
                                    break;
                            }

                        }
            }
             bloque_llaves /*(cat i ~ 0; i < 3; i ~ i + 3)*/
			{
                generateCode("\t\tGT(%u);\n", $<uentero>5);
		  	    generateCode("L %u:", $<uentero>7);
                generateCode("\t\tR7 = R6;\n");
				generateCode("\t\tR6 = P(R7);\n");
				generateCode("\t\tR7 = R7 + 8; //AQUI TERMINA EL FOR\n");
                breaks.deleteLast();
            }
			| WHILE {
                tabla.addScope();
                generateCode("\t\tR7 = R7 - 8; //AQUI COMIENZA EL WHILE\n");
				generateCode("\t\tP(R7) = R6;\n");
				generateCode("\t\tR6 = R7;\n");

			  	$<uentero>$ = etiqueta; //dirección de repeticion
                generateCode("L %u:\t\n",etiqueta);	
			  	etiqueta++;
            } ABREPARENTESIS exp CIERRAPARENTESIS
            {
                $<uentero>$ = etiqueta;
                breaks.addNode(etiqueta);
                generateCode("\t\tRR1 = D(R7);\n");
		  	    generateCode("\t\tIF (RR1 == 0) GT(%u); //Comprobación WHILE\n", etiqueta);
                etiqueta++;
            }
             bloque_llaves
            {

                generateCode("\t\tGT(%u);\n", $<uentero>2);
		  	    generateCode("L %u:", $<uentero>6);
                generateCode("\t\tR7 = R6;\n");
				generateCode("\t\tR6 = P(R7);\n");
				generateCode("\t\tR7 = R7 + 8; //AQUI TERMINA EL WHILE\n");
                breaks.deleteLast();
            }
			| IF {
                tabla.addScope();
                generateCode("\t\tR7 = R7 - 8; //AQUI COMIENZA EL IF\n");
				generateCode("\t\tP(R7) = R6;\n");
				generateCode("\t\tR6 = R7;\n");

			  	$<uentero>$ = etiqueta; //dirección de salida
			  	etiqueta++;
			
			} ABREPARENTESIS exp CIERRAPARENTESIS 
			{ 
			
			  	$<uentero>$ = etiqueta; //dirección de else 
			  	
			  	generateCode("\t\tRR1 = D(R7);\n");
			  	generateCode("\t\tIF(RR1 < 1) GT(%u);\n",etiqueta);
		  		etiqueta++;
			}
			bloque_llaves {
				generateCode("\t\tGT(%u);\n",$<uentero>2);
		  		generateCode("L %u:\tR7 = R7 + 8;\n",$<uentero>6);			
			} ELSE {tabla.addScope();} bloque_llaves {
				generateCode("L %u:", $<uentero>2);
				generateCode("\t\tR7 = R6;\n");
				generateCode("\t\tR6 = P(R7);\n");
				generateCode("\t\tR7 = R7 + 8; //AQUI TERMINA EL IF\n");
				
			}
			| LLAMADA IDENTIF ABREPARENTESIS CIERRAPARENTESIS PUNTOYCOMA 
				{
                    listaFunciones.addNode($2);
                    //No vamos a tener parámetros en esta versión

                    //PILA = R6previo | L de retorno | parametros .. (ninguno en este caso)

                    //Reservamos espacio para meter el R6 luego
			        generateCode("\t\tR7 = R7 - 8; // LLAMADA: reservamos espacio para meter R6 actual. La etiqueta vale -> %d \n",etiqueta);  
			        generateCode("\t\tR5 = R7; //guardamos la direccion donde va a estar R6 \n"); 
                    

                    //Añadimos la L de retorno
                    generateCode("\t\tR7 = R7 - 8;\n");
			        dirRetorno = etiqueta;
                    etiqueta++;
			        generateCode("\t\tP(R7) = %u;\n", dirRetorno);
            
                    //Aquí se trabajaria con las var de param si hubiese...

                    Symbol *item = createVar2(FUNCTION,$2);
                    if(item==NULL){yyerror("La función no se ha declarado");}
                    if(item->etiquetaFuncion == -1){
                        tabla.addEtiquetaToFuncion($2, etiqueta);
                        cout << "se acaba de crear " << item->name << " con la etiqueta " << item->etiquetaFuncion << " \n";
                        etiqueta++;
                    }
				
                    //Actualizamos R6
                    generateCode("\t\tP(R5) = R6;\n");
			        generateCode("\t\tR6 = R5;\n");


                    //ponemos el salto L a donde tiene que retornar y llamamos a la funcion
			        generateCode("\t\tGT(%u);\n", item->etiquetaFuncion); //Busca la funcion a la que llamas y ve a ella
			        generateCode("L %u://Fin codigo LLAMADA \n ", dirRetorno); //L a la que hay que volver desde la funcion
                }
			| LLAMADA IDENTIF ABREPARENTESIS
                {
                    listaFunciones.addNode($2);
                    //No vamos a tener parámetros en esta versión

                    //PILA = R6previo | L de retorno | parametros .. (ninguno en este caso)

                    //Reservamos espacio para meter el R6 luego
			        generateCode("\t\tR7 = R7 - 8; // LLAMADA: reservamos espacio para meter R6 actual. La etiqueta vale -> %d \n",etiqueta);  
			        generateCode("\t\tR5 = R7; //Metemos en R5 la dir donde va a estar R6 \n"); 
                    

                    //Añadimos la L de retorno
                    generateCode("\t\tR7 = R7 - 8; //Dejamos un hueco\n");
			        dirRetorno = etiqueta;
                    etiqueta++;
			        generateCode("\t\tP(R7) = %u; //Metemos en ese hueco la etiqueta a la que ir cuando acabe la llamada\n", dirRetorno);
                }
             parametros_instruccion CIERRAPARENTESIS IN IDENTIF PUNTOYCOMA
				{
                    Symbol *item = createVar2(FUNCTION,$2);
                    if(item==NULL){yyerror("La función no se ha declarado");}
                    if(item->etiquetaFuncion == -1){
                        tabla.addEtiquetaToFuncion($2, etiqueta);
                        cout << "se acaba de crear " << item->name << " con la etiqueta " << item->etiquetaFuncion << " \n";
                        etiqueta++;
                    }
				
                    //Actualizamos R6
                    generateCode("\t\tP(R5) = R6; //Guardo el R6 como puntero en donde apunta R5\n");
			        generateCode("\t\tR6 = R5; //Pongo ahora R6 en donde apunta R5\n");


                    //ponemos el salto L a donde tiene que retornar y llamamos a la funcion
			        generateCode("\t\tGT(%u);\n", item->etiquetaFuncion); //Busca la funcion a la que llamas y ve a ella
			        generateCode("L %u://Fin codigo LLAMADA \n ", dirRetorno); //L a la que hay que volver desde la funcion


                    //Almacenamos lo que se queda en la cima de la pila en la variable
                    Symbol *item2 = tabla.search_symbol($8);
				    if( item2 != NULL) {
                        posicionMemoria(item2);
                        generateCode("\t\tRR1 = D(R7); //Cojo lo de la cima, que deberia ser el resultado de la funcion\n");
					    generateCode("\t\tD(R1) = RR1; //Voy a la variable y meto el resultado\n");
                        //generateCode("\t\tR7 = R6 - 8; //Esto es dudoso...\n");
                        generateCode("\t\tR7 = R6 - %u;\n",tabla.relDir);
                    } else {
					    ostringstream o;
					    o <<  "La variable " << $8 << " no ha sido declarada";
					    yyerror(o.str());

				    }

                }
			
			| HALT PUNTOYCOMA { generateCode("\t\tGT(-2);\n"); }
            |BREAK PUNTOYCOMA{
                if(breaks.last != NULL){
                    generateCode("\t\tGT(%u);\n",breaks.last->value);
                    breaks.deleteLast();
                }                    
            }
			;

/*Ahora todas las variables deben declararse previamente antes de llamar a una funcion*/
parametros_instruccion : IDENTIF SEPARADOR parametros_instruccion
						{
							Symbol *item = tabla.search_symbol($1);
							if( item == NULL) {
								ostringstream o;
								o <<  "La variable" << $1 << " no ha sido declarada";
								yyerror(o.str());
					
							} else {
	                            varEnPilaValue(item->type);
                                posicionMemoria(item); 
				                generateCode("\t\tRR3 = D(R1);\n");
				                generateCode("\t\tD(R7) = RR3;\n");
							}

						}
						| IDENTIF
						{
							Symbol *item = tabla.search_symbol($1);
							if( item == NULL) {
								ostringstream o;
								o <<  "La variable" << $1 << " no ha sido declarada";
								yyerror(o.str());
					
							} else {
			  					varEnPilaValue(item->type);
                                posicionMemoria(item); 
				                generateCode("\t\tRR3 = D(R1);\n");
				                generateCode("\t\tD(R7) = RR3;\n");
							}
						}
						;
			
			
declaracion: tipo IDENTIF PUNTOYCOMA {
                 createVar($1,$2); 
                 varEnPilaSymbol($2);
            } ;

tipo	: CAT {$$ = INTEGER;}
		| KITTY {$$ = FLOAT;}
		| KITTEN {$$ = DOUBLE;}
		;		
			
asignacion : tipo IDENTIF {
			
				createVar($1,$2);

                //crear variable en la pila
				varEnPilaSymbol($2);

                } ASIGNA exp PUNTOYCOMA{
                        
                        //Poner la direccion en R1
                        Symbol *item = tabla.search_symbol($2);
                        if( item == NULL) {
	                         string mensaje = "La variable no ha sido declarada";
	                        yyerror(mensaje);

                        } else {
                            checkEqualType($1, $5);
                		    switch($1){
                                case INTEGER:
                	                posicionMemoria(item); 
                                    generateCode("\t\tRR1 = D(R7);\n");
					                generateCode("\t\tD(R1) = RR1;\n");
                                    generateCode("\t\tR7 = R6 - %u;\n",tabla.relDir); 
	                                break;

                                case FLOAT:
                                    posicionMemoria(item); 
                                    generateCode("\t\tRR1 = D(R7);\n");
					                generateCode("\t\tD(R1) = RR1;\n");
                                    generateCode("\t\tR7 = R6 - %u;\n",tabla.relDir); 
	                                break;

                                case DOUBLE:
                                    posicionMemoria(item); 
                                    generateCode("\t\tRR1 = D(R7);\n");
					                generateCode("\t\tD(R1) = RR1;\n");
                                    generateCode("\t\tR7 = R6 - %u;\n",tabla.relDir); 
	                                break;
	
                                default:
	                                break;

                            }

						
						    $$ = $2;
                        }

				}
			| IDENTIF ASIGNA exp PUNTOYCOMA {

				Symbol *item = tabla.search_symbol($1);
				if( item != NULL) {
					checkEqualType(item->type, $3);
                		    switch(item->type){
                                case INTEGER:
                	                posicionMemoria(item); 
                                    generateCode("\t\tRR1 = D(R7);\n");
					                generateCode("\t\tD(R1) = RR1;\n");
                                    generateCode("\t\tR7 = R6 - %u;\n",tabla.relDir); 
	                                break;

                                case FLOAT:
                                    posicionMemoria(item); 
                                    generateCode("\t\tRR1 = D(R7);\n");
					                generateCode("\t\tD(R1) = RR1;\n");
                                    generateCode("\t\tR7 = R6 - %u;\n",tabla.relDir); 
	                                break;

                                case DOUBLE:
                                    posicionMemoria(item); 
                                    generateCode("\t\tRR1 = D(R7);\n");
					                generateCode("\t\tD(R1) = RR1;\n");
                                    generateCode("\t\tR7 = R6 - %u;\n",tabla.relDir); 
	                                break;

                                default:
	                                break;

                            }

						
						    $$ = $1;
					
				} else {
					ostringstream o;
					o <<  "La variable " << $1 << " no ha sido declarada";
					yyerror(o.str());
	
				}
			}
		   ;


exp : exp RESTA exp {
        checkAritmetic($1,$3);
        generateCode("\t\tRR2 = D(R7); //Comenzamos RESTA\n");
		generateCode("\t\tRR1 = D(R7 + 8);\n");
		generateCode("\t\tRR1 = RR1 - RR2;\n");
		generateCode("\t\tR7 = R7 + 8;\n");
		generateCode("\t\tD(R7) = RR1; //Final RESTA\n");
        $$ = $1;
    }
	| exp MULTIPLICACION exp {
        checkAritmetic($1,$3);
        generateCode("\t\tRR2 = D(R7); //Comenzamos MULTIPLICACION\n");
		generateCode("\t\tRR1 = D(R7 + 8);\n");
		generateCode("\t\tRR1 = RR1 * RR2;\n");
		generateCode("\t\tR7 = R7 + 8;\n");
		generateCode("\t\tD(R7) = RR1; //Final MULTIPLICACION\n");
        $$ = $1;
    }
	| exp SUMA exp {
        checkAritmetic($1,$3);
        generateCode("\t\tRR2 = D(R7); //Comenzamos SUMA\n");
		generateCode("\t\tRR1 = D(R7 + 8);\n");
		generateCode("\t\tRR1 = RR1 + RR2;\n");
		generateCode("\t\tR7 = R7 + 8;\n");
		generateCode("\t\tD(R7) = RR1; //Final SUMA\n");
        $$ = $1;
    }
	| exp DIVISION exp {
        checkAritmetic($1,$3);
        generateCode("\t\tRR2 = D(R7); //Comenzamos DIVISION\n");
		generateCode("\t\tRR1 = D(R7 + 8);\n");
		generateCode("\t\tRR1 = RR1 / RR2;\n");
		generateCode("\t\tR7 = R7 + 8;\n");
		generateCode("\t\tD(R7) = RR1; //Final DIVISION\n");
        $$ = $1;
    }
	| exp DISTINTO exp {
        checkAritmetic($1,$3);
        generateCode("\t\tRR2 = D(R7); //Comenzamos DISTINTO\n");
		generateCode("\t\tRR1 = D(R7 + 8);\n");
		generateCode("\t\tIF (RR1 != RR2) GT(%u);\n", etiqueta);
        etiqueta++;
		generateCode("\t\tRR1 = 0;\n");
		generateCode("\t\tGT(%u);\n", etiqueta);
		etiqueta++;
		generateCode("L %u:\tRR1 = 1;\n", (etiqueta - 2));
		generateCode("L %u:\tR7 = R7 + 8;\n", etiqueta - 1);
		generateCode ("\t\tD(R7) = RR1; //Final DISTINTO\n");
        $$ = LOGICO;
    }
	| exp IGUAL exp {
        checkAritmetic($1,$3);
        generateCode("\t\tRR2 = D(R7); //Comenzamos IGUALDAD\n");
		generateCode("\t\tRR1 = D(R7 + 8);\n");
		generateCode("\t\tIF (RR1 == RR2) GT(%u);\n", etiqueta);
        etiqueta++;
		generateCode("\t\tRR1 = 0;\n");
		generateCode("\t\tGT(%u);\n", etiqueta);
		etiqueta++;
		generateCode("L %u:\tRR1 = 1;\n", (etiqueta - 2));
		generateCode("L %u:\tR7 = R7 + 8;\n", etiqueta - 1);
		generateCode ("\t\tD(R7) = RR1; //Final IGUALDAD\n");
        $$ = LOGICO;
    }
	| exp MAYORQUE exp {
        checkAritmetic($1,$3);
        generateCode("\t\tRR2 = D(R7); //Comenzamos MAYOR\n");
		generateCode("\t\tRR1 = D(R7 + 8);\n");
		generateCode("\t\tIF (RR1 > RR2) GT(%u);\n", etiqueta);
        etiqueta++;
		generateCode("\t\tRR1 = 0;\n");
		generateCode("\t\tGT(%u);\n", etiqueta);
		etiqueta++;
		generateCode("L %u:\tRR1 = 1;\n", (etiqueta - 2));
		generateCode("L %u:\tR7 = R7 + 8;\n", etiqueta - 1);
		generateCode ("\t\tD(R7) = RR1; //Final MAYOR\n");
        $$ = LOGICO;
    }
	| exp MENORQUE exp  {
        checkAritmetic($1,$3);
        generateCode("\t\tRR2 = D(R7); //Comenzamos MENOR\n");
		generateCode("\t\tRR1 = D(R7 + 8);\n");
		generateCode("\t\tIF (RR1 < RR2) GT(%u);\n", etiqueta);
        etiqueta++;
		generateCode("\t\tRR1 = 0;\n");
		generateCode("\t\tGT(%u);\n", etiqueta);
		etiqueta++;
		generateCode("L %u:\tRR1 = 1;\n", (etiqueta - 2));
		generateCode("L %u:\tR7 = R7 + 8;\n", etiqueta - 1);
		generateCode ("\t\tD(R7) = RR1; //Final MENOR\n");
        $$ = $1;
    }
	| exp MENORIGUAL exp {
        checkAritmetic($1,$3);
        generateCode("\t\tRR2 = D(R7); //Comenzamos MENORIGUAL\n");
		generateCode("\t\tRR1 = D(R7 + 8);\n");
		generateCode("\t\tIF (RR1 <= RR2) GT(%u);\n", etiqueta);
        etiqueta++;
		generateCode("\t\tRR1 = 0;\n");
		generateCode("\t\tGT(%u);\n", etiqueta);
		etiqueta++;
		generateCode("L %u:\tRR1 = 1;\n", (etiqueta - 2));
		generateCode("L %u:\tR7 = R7 + 8;\n", etiqueta - 1);
		generateCode ("\t\tD(R7) = RR1; //Final MENORIGUAL\n");
        $$ = LOGICO;
    }
	| exp MAYORIGUAL exp {
        generateCode("\t\tRR2 = D(R7); //Comenzamos MAYORIGUAL\n");
		generateCode("\t\tRR1 = D(R7 + 8);\n");
		generateCode("\t\tIF (RR1 >= RR2) GT(%u);\n", etiqueta);
        etiqueta++;
		generateCode("\t\tRR1 = 0;\n");
		generateCode("\t\tGT(%u);\n", etiqueta);
		etiqueta++;
		generateCode("L %u:\tRR1 = 1;\n", (etiqueta - 2));
		generateCode("L %u:\tR7 = R7 + 8;\n", etiqueta - 1);
		generateCode ("\t\tD(R7) = RR1; //Final MAYORIGUAL\n");
        $$ = LOGICO;
    }
	| exp OR exp {
        checkLogic($1,$3);
        generateCode("\t\tRR2 = D(R7); //Comenzamos OR\n");
		generateCode("\t\tRR1 = D(R7 + 8);\n");
		generateCode("\t\tIF (RR1 >= 1) GT(%u);\n", etiqueta);
		generateCode("\t\tIF (RR2 >= 1) GT(%u);\n", etiqueta);
        etiqueta++;
		generateCode("\t\tRR1 = 0;\n");
		generateCode("\t\tGT(%u);\n", etiqueta);
        etiqueta++;
		generateCode("L %u:\tRR1 = 1;\n", (etiqueta - 2));
		generateCode("L %u:\tR7 = R7 + 8;\n", (etiqueta - 1));
		generateCode ("\t\tD(R7) = RR1; //Final OR\n");
        $$ = LOGICO;
    }
	| exp AND exp {
        checkLogic($1,$3);
        generateCode("\t\tRR2 = D(R7);\n");
		generateCode("\t\tRR1 = D(R7 + 8);\n");
		generateCode("\t\tIF (RR1 < 1) GT(%u);\n", etiqueta); //Si está false, voy a la etiq
		generateCode("\t\tIF (RR2 < 1) GT(%u);\n", etiqueta);
		generateCode("\t\tRR1 = 1;\n");
        etiqueta++;
		generateCode("\t\tGT(%u);\n", etiqueta);
		etiqueta++;
		generateCode("L %u:\tRR1 = 0;\n", (etiqueta - 2));
		generateCode("L %u:\tR7 = R7 + 8;\n", etiqueta - 1);
		generateCode ("\t\tD(R7) = RR1;\n");
        $$ = LOGICO;
    }
	| NOT exp {
        if ($2 != LOGICO){
            ostringstream o;
		    o <<  "El NOT solo se puede emplear con valores logicos" << "\n";
		    yyerror(o.str());
        }
        generateCode("\t\tRR1 = D(R7);\n");
		generateCode("\t\tIF (RR1 < 1) GT(%u);\n", etiqueta);
        etiqueta++;
		generateCode("\t\tRR1 = 0;\n");
		generateCode("\t\tGT(%u);\n", etiqueta);
		etiqueta++;
		generateCode("L %u:\tRR1 = 1;\n", (etiqueta - 2));
		generateCode("L %u:\tD(R7) = RR1;\n", (etiqueta - 1));
        $$ = LOGICO;
    }
	| ABREPARENTESIS exp CIERRAPARENTESIS { $$ = $2; }
	| valor { $$ = $1; }
	;
	
valor	: CATVALUE { 
			varEnPilaValue(INTEGER);
			generateCode("\t\tD(R7) = %s; //Cojo el valor y lo pongo en la cima de la pila \n", $1);
            $$ = INTEGER;
         }
		| KITTYVALUE {
            varEnPilaValue(FLOAT);
			generateCode("\t\tD(R7) = %s;\n", $1);
            $$ = FLOAT;
        }
		| KITTENVALUE {
            varEnPilaValue(DOUBLE);
            cout << $1 << "\n";
			generateCode("\t\tD(R7) = %s;\n", $1);
            $$ = DOUBLE;
        }
		| IDENTIF {
			//Buscar simbolo y devolver tipo
			Symbol *item = tabla.search_symbol($1);
			if(item != NULL){
				//checkIsNotString(item->type);
                varEnPilaValue(item->type);
                cout << "SCOPE tabla: " << tabla.actualScope << "SCOPE item: " << item->scope << "\n"; 
                posicionMemoria(item); 
				generateCode("\t\tRR3 = D(R1);\n");
				generateCode("\t\tD(R7) = RR3;\n");
						
			} else {
				yyerror("La variable no se ha declarado o no tiene tipo");
			}
            $$ = item->type;
		}
	;				

%%

void checkEqualType(int tipo1, int tipo2){
    if (tipo1 != tipo2){
        ostringstream o;
		o <<  "Asignacion con tipos diferentes: " <<"\n";
		yyerror(o.str());
    }
}

void checkAritmetic(int tipo1, int tipo2){
    //Primero miro si los tipos son distintos
    if (tipo1 != tipo2){
        ostringstream o;
		o <<  "No se pueden realizar operaciones con tipos diferentes" << "\n";
		yyerror(o.str());
    }

    //Compruebas que los tipos que te llegan no son strings para sumar (En verdad bastaria con comprobar uno porque al llegar aqui sabes que son iguales)
    if (tipo1 == STRING || tipo2 == STRING){
        ostringstream o;
		o <<  "No se pueden realizar operaciones con STRINGS" << "\n";
		yyerror(o.str());
    }

    //Que no sean logicos que tu los logicos no los sumas ni na
    if (tipo1 == LOGICO || tipo2 == LOGICO){
        ostringstream o;
		o <<  "No se pueden realizar operaciones con tipos logicos" << "\n";
		yyerror(o.str());
    }
}

void checkLogic(int tipo1, int tipo2){
    if (tipo1 != tipo2){
        ostringstream o;
		o <<  "No se pueden realizar operaciones con tipos diferentes" << "\n";
		yyerror(o.str());
    }
    if (tipo1 == STRING || tipo2 == STRING){
        ostringstream o;
		o <<  "No se pueden realizar operaciones con STRINGS" << "\n";
		yyerror(o.str());
    }

    //Este chequeo se usa solo un AND o OR (a ambos lados tiene que tener un logico, no puede haber una op aritm en plan 2+2 AND 3 > 1)
    if (tipo1 != LOGICO || tipo2 != LOGICO){
        ostringstream o;
		o <<  "Comparacion logica erronea" << "\n";
		yyerror(o.str());
    }
}

void checkIsNotString(int tipo) {
	if (tipo == STRING) {
		yyerror("El tipo es string, no puede asignar un numero.");
	}
}

void createVar(int type, string name) {
	Symbol *item = tabla.search_symbol(name);
	if( item == NULL) {
		//Creo el simbolo
		tabla.addSymbol(name,type);

	} else {
		string mensaje = "La variable " + name + " ya ha sido declarada";
		yyerror(mensaje);

	}
}

Symbol* createVar2(int type, string name) {
	Symbol *item = tabla.search_symbol(name);
	if( item == NULL) {
		//Creo el simbolo
		tabla.addSymbol(name,type);
        Symbol *item2 = tabla.search_symbol(name);
        return item2;
	} else {
		return item;

	}
}

void createParameter(int type, string name) {
	Symbol *item = tabla.search_symbol(name);
	if( item == NULL) {
		tabla.addParameter(name,type);

	} else {
		string mensaje = "El parámetro " + name + " ya ha sido declarado";
		yyerror(mensaje);

	}
}

void varEnPilaSymbol(string name){
        int alinearPila;
        Symbol *item = tabla.search_symbol(name);
	
	    if( item == NULL) {
		    yyerror("Variable no declarada");
	    } else {
		    switch(item->type){
			    case INTEGER:
				    //Aumento la dir relativa a la cima de la pila en 4 bytes
				    tabla.relDir += 8; 
				
				    //Modifico el puntero a la cima de la pila
				    generateCode("\t\tR7 = R7 - 8; //Asigno espacio para la variable\n"); 
				
				    //Asigno esta nueva direccion al simbolo, pues es donde está
				    item->direction = tabla.relDir; 
                    generateCode("\t\t//La direccion es %u\n", item->direction);
				    break;

                 case FLOAT:
				    //Aumento la dir relativa a la cima de la pila en 4 bytes
				    tabla.relDir += 8; 
				
				    //Modifico el puntero a la cima de la pila
				    generateCode("\t\tR7 = R7 - 8;\n"); 
				
				    //Asigno esta nueva direccion al simbolo, pues es donde está
				    item->direction = tabla.relDir; 
				    break;

                case DOUBLE:
				    //Aumento la dir relativa a la cima de la pila en 4 bytes
				    tabla.relDir += 8; 
				
				    //Modifico el puntero a la cima de la pila
				    generateCode("\t\tR7 = R7 - 8;\n"); 
				
				    //Asigno esta nueva direccion al simbolo, pues es donde está
				    item->direction = tabla.relDir; 
				    break;

                case STRING:
                    
                    //Aumento la dir relativa a la cima de la pila en 4 bytes
				    tabla.relDir += alinearPila; 
		
		            //Modifico el puntero a la cima de la pila
		            if( tamanoString % 4 != 0){
                        alinearPila = tamanoString + (4 - ( tamanoString % 4 ));
                        generateCode("\t\tR7 = R7 - %d;\n", alinearPila); 
                    }else{
                        generateCode("\t\tR7 = R7 - %d;\n", tamanoString);
                    }

                    //Asigno esta nueva direccion al simbolo, pues es donde está
				    item->direction = tabla.relDir; 
		            break;
				
			    default:
				    break;
		
		    }
		
	    }	
}

void varEnPilaValue(int tipo){
    int alinearPila;
    switch(tipo){
	        case INTEGER:
		
		        //Modifico el puntero a la cima de la pila
		        generateCode("\t\tR7 = R7 - 8; //Creo espacio para meter valor\n"); 
		        break;

            case FLOAT:
		
		        //Modifico el puntero a la cima de la pila
		        generateCode("\t\tR7 = R7 - 8;\n"); 
		        break;

            case DOUBLE:
		
		        //Modifico el puntero a la cima de la pila
		        generateCode("\t\tR7 = R7 - 8;\n"); 
		        break;

            case STRING:
		        generateCode("\t\tR7 = R7 - 4;\n");
		        
		        break;
		
	        default:
		        break;
	
	}
}

void generaCabecera() {
	//Generar el comienzo del fichero Q
	generateCode("#include \"Q.h\" \n");
    generateCode("BEGIN\n");
	generateCode("STAT(0)\n");
    generateCode("\t\tSTR(0x11ffc, \"%%c\"); //formato caracteres\n");
    generateCode("\t\tSTR(0x11ff8, \"%%f\" ); //formato decimales\n");
    generateCode("\t\tSTR(0x11ff4,\"%%d\"); //formato entero\n");
    generateCode("CODE(0)\n");
	generateCode("L %d:\n", 0);
    generateCode("\t\tR6= R7;\n");
}

int main(int argc, char** argv) {

	file = fopen("./ejecutableQ.q.c","w");
	if(file == NULL) 
		yyerror("Fichero ejecutableQ no abierto");
	
	if (argc>1) 
		yyin=fopen(argv[1],"r");
	yyparse();

	fclose(file);
}

void yyerror(string mens) {
	//printf("Error en linea %i: %s ",numlin,mens);
	cout << "Error en linea " << numlin << ": " << mens << "\n";
	exit(0);
}

void posicionMemoria(Symbol * item)
{
	//Numero de saltos de R6 que hay que dar
	int numSaltos = tabla.actualScope - item->scope;

	generateCode("\t\tR1 = R6;\n");
	for (int i = 0; i < numSaltos; i++)
	{
		generateCode("\t\tR1 = P(R1);\n");
	}
	//aumentamos la dirección con la referencia a la dirección relativa
	generateCode("\t\tR1 = R1 - %u;\n", item->direction); 
}
