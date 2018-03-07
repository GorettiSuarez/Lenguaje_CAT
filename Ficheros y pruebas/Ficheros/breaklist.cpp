#include "breaklist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

//Constructor de la tabla de simbolos
breaklist::breaklist()
{
	root = NULL;
	last = NULL;
}

//Destructor de la tabla
breaklist::~breaklist()
{
	Nodo *item = root;
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

void breaklist::deleteLast()
{
    if(root == last){
        root = NULL;
        last = NULL;    
    }else{
        if(last != NULL){
            Nodo *item = last;
            item->prev->next = NULL;
            last = item->prev;
            delete item;
        }
    }
}

//Añade un nuevo simbolo a la tabla
void breaklist::addNode(int valor)
{
	if (root == NULL)
	{
		root = new Nodo();
		root->value = valor;
		root->next = NULL;
		root->prev = NULL;
		last = root;
	}else{
        	Nodo *result = new Nodo();
            result->value = valor;
            result->next = NULL;
            result->prev = last;
            last->next = result;
            last = result;  
    }
}
