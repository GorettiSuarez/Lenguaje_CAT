#include "FunctionsList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

//Constructor de la tabla de simbolos
FunctionsList::FunctionsList()
{
	root = NULL;
	last = NULL;
}

//Destructor de la tabla
FunctionsList::~FunctionsList()
{
	NodoFunc *item = root;
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
void FunctionsList::addNode(string name)
{
    if(searchNode(name) == 0){
	    if (root == NULL){
		    root = new NodoFunc();
		    root->name = name;
            root->defined = 0;
		    root->next = NULL;
		    root->prev = NULL;
		    last = root;
	    }else{
        	NodoFunc *result = new NodoFunc();
            result->name = name;
            result->defined = 0;
            result->next = NULL;
            result->prev = last;
            last->next = result;
            last = result;  
        }
    }
}


void FunctionsList::setDefined(string name) 
{
    if(root != NULL){
        NodoFunc *item = root;
        while(item->next != NULL){
            if(item->name == name){
                item->defined = 1;
                return;       
            }
            item = item->next;
        }
        if(item->name == name){
            item->defined = 1;
            return;       
        }
    }   
    addNode(name);
    if(last->name == name){
        last->defined = 1;
        return;       
    }
}

string FunctionsList::checkAllDefined() 
{   
    if(root != NULL){
        NodoFunc *item = root;
        while(item->next != NULL){
            if(item->defined == 0){
                return  item->name;       
            }
            item = item->next;
        }
        if(item->defined == 0){
            return  item->name;       
        }
    }
    return " ";
}

int FunctionsList::searchNode(string name)
{
    if(root != NULL){
        NodoFunc *item = root;
        while(item->next != NULL){
            if(item->name == name){
                return  1;       
            }
            item = item->next;
        }
        if(item->name == name){
            return  1;       
        }
    }
    return 0;
}
