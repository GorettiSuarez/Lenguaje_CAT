#ifndef FUNCTIONSLIST_H
#define FUNCTIONSLIST_H
#include <string>

using namespace std;

typedef struct NodoFunc {
	string name;
    int defined; 
	struct NodoFunc* next;
	struct NodoFunc* prev;
} NodoFunc;

class FunctionsList {
	public:
		FunctionsList();
		~FunctionsList();
        NodoFunc* root;
		NodoFunc* last;
		void addNode(string name); 
        void setDefined(string name);
        string checkAllDefined();
        int searchNode(string name);
};


#endif
