#include "SymbolTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Symbol *lastFunc = NULL;

int v = 0; //NEWCODE

//Constructor de la tabla de simbolos
SymbolTable::SymbolTable()
{
	printf("SymbolTable(): Creo la tabla de símbolos\n");
	actualScope = 0;
	relDir = 0;
	root = NULL;
	last = NULL;

}

//Destructor de la tabla
SymbolTable::~SymbolTable()
{
	Symbol *item = root;
	if(item != NULL)
	{
		while (item->next != NULL)
		{
			item = item->next;
			delete root;
			root = item;
		}
		delete root;
	}
}


//Añade un nuevo simbolo a la tabla
void SymbolTable::addSymbol(string name, int type)
{
	if (root == NULL)
	{
		root = new Symbol();
		root->name = name;
		root->type = type;
		root->direction = 0;
		root->scope = actualScope;
		root->isParameter = false;
        root->etiquetaFuncion = -1;
		root->next = NULL;
		root->prev = NULL;
		last = root;

        if(type == FUNCTION){
            root->scope = 0;
        }


		cout << "addSymbol(): Elemento añadido --> " << root->name <<" \n";
		return;

	}
	
	Symbol* item = root;
	while (item->name != name)
	{
		if (item->next == NULL)
		{
			Symbol *result = new Symbol();
			result->name = name;
			result->type = type;
			result->direction = 0;
			result->scope = actualScope;
			result->next = NULL;
			result->isParameter = false;
            result->etiquetaFuncion = -1;
			result->prev = item;
			item->next = result;
			last = result;


            if(type == FUNCTION){
                result->scope = 0;
            }
			cout << "addSymbol(): Elemento añadido --> " << result->name << "\n\t Scope: " << result->scope << "\n\t Previo: " << result->prev->name <<"\n\t Siguiente del previo: " << item->next->name <<" \n";
			return;
			
		}
		item = item->next;
	}

	printf("addSymbol(): NO AÑADIDO\n");
	
}


//Añade un nuevo simbolo a la tabla
void SymbolTable::addParameter(string name, int type)
{
	
	Symbol* item = root;
	if(last->type == FUNCTION) {
		lastFunc = last;
	}
	while (item->name != name)
	{
		if (item->next == NULL)
		{
			Symbol *result = new Symbol();
			result->name = name;
			result->type = type;
			result->scope = actualScope;
			result->next = NULL;
			result->isParameter = true;
			result->funcName = lastFunc->name;
			result->prev = item;
			item->next = result;
			last = result;
			cout << "addParameter(): Parametro añadido --> " << result->name << "\n\t Scope: " << result->scope << "\n\t Función perteneciente: " << result->funcName <<"\n\t Previo: " << result->prev->name <<"\n\t Siguiente del previo: " << item->next->name <<" \n";
			return;
			
		}
		item = item->next;
	}

	printf("addParameter(): PARAMETRO NO AÑADIDO\n");
	
}


//Busca un símbolo en la tabla
Symbol* SymbolTable::search_symbol(string name)
{
	if (root == NULL)
	{
		return NULL;
	}
	
	Symbol* item = root;
	while (item->name != name)
	{
		if (item->next == NULL)
		{
			return NULL;
		}
		item = item->next;
	}
	cout << "Símbolo encontrado: " << name << "\n \t Scope = " << item->scope << "\n \t actualScope = "<< actualScope <<" \n";

	return item;
}

void SymbolTable::imprimir() {
	cout << " Comienzo de tabla... \n";
    if (root != NULL)
	{
		cout << "\troot: " << root->name << "\n";
	}
	
	Symbol* item = root;
	while (item->next != NULL)
	{
        item = item->next;
		cout << "\titem: " << item->name << "\n";		
	}

	cout << " Fin de tabla... \n";

}

//Entras en un nuevo ámbito del programa
void SymbolTable::addScope()
{
	actualScope++;
	relDir = 0; 
	cout << "addScope(): actualScope = " << actualScope << "\n";
}


void SymbolTable::quitScope()
{
    cout << "quitScope()\n";
	Symbol *item = last;
	if (actualScope != 0)
	{
		actualScope--;
        if(root != last){
            metodo(item->prev, item);
        }
        v = 0;
        imprimir();
    }
}

void SymbolTable::metodo(Symbol* x, Symbol* y){

    if (v == 0){
        y = x->next;
        v++;
    }

    if(x->scope > actualScope && x->isParameter == false) {
        Symbol* newx = x->prev;
         cout << "Estado: " << "\n\t Borro: " << x->name << "\n\t Llamo a metodo con: " << newx->name << " y " << y->name << "\n";
        delete x;
        
        metodo(newx, y);
        

    } else {
        if(y != NULL){

            if(y->scope > actualScope && y->isParameter == false) { //Necesito saber si el último elemento del metodo es una variable borrable o una funcion
                x->next = NULL;
                delete y;
                last = x;

            } else {
                x->next = y;
                y->prev = x;
                last = y;
            }
            

            //Para cuando tengo varias llamadas dentro de una funcion, borrar las variables entre ellas
            if(x->prev != NULL && x->prev->scope > actualScope) {
                metodo(x->prev, x);
            }

        }

    }
    
}

void SymbolTable::addValueToSymbol(string name, string value) {
	
	Symbol *result = search_symbol(name);
	if(result != NULL) {
		cout << "addValueToSymbol(): "<< name << " = \"" << value << "\" | Scope = " << result->scope <<" \n";
		result->value = value;
	} else {
		printf("Variable no declarada\n");
	}

}

void SymbolTable::addEtiquetaToFuncion(string name, int value) {
	Symbol *result = search_symbol(name);
	if(result != NULL) {
		result->etiquetaFuncion = value;
	} else {
		printf("Funcion no declarada\n");
	}

}


