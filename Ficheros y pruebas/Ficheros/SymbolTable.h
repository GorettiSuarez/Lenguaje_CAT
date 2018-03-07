#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include <string>

#define INTEGER 267
#define FLOAT 268
#define DOUBLE 269
#define STRING 270
#define FUNCTION 271
#define LOGICO 272

using namespace std;
//NEWCODE
typedef struct Symbol {
	string name;
	string value;
	//¿Como añadimos un array de valores al simbolo?¿Como se de que tipo lo creo?
	int type;
	int typeOfElements;
	int scope; //ambito 
	bool isParameter;
	char *arraySize;
	unsigned int direction; 
    int etiquetaFuncion;
	string funcName;
	struct Symbol* next;
	struct Symbol* prev;
} Symbol;

class SymbolTable {
	public:
		SymbolTable();
		~SymbolTable();
		int actualScope; //ambito actual, donde nos encontramos en el programa
		unsigned int relDir;
		Symbol* root;
		Symbol* last;
		Symbol* search_symbol(string varName); //Busca un simbolo en la tabla
		void addSymbol(string varName, int type); 
		void addParameter(string name, int type);
		void addScope(); //Entro en un nuevo ambito
		void quitScope(); //Salgo del ámbito actual
		void addValueToSymbol(string name, string value);
        void addEtiquetaToFuncion(string name, int value);
        void imprimir();
        void metodo(Symbol* previo, Symbol* item); //NEWCODE
};


#endif
