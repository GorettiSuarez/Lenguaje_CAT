#ifndef BREAKLIST_H
#define BREAKLIST_H
#include <string>

using namespace std;
//NEWCODE
typedef struct Nodo {
	int value;
	struct Nodo* next;
	struct Nodo* prev;
} Nodo;

class breaklist {
	public:
		breaklist();
		~breaklist();
        Nodo* root;
		Nodo* last;
		void addNode(int value); 
        void deleteLast(); 
};


#endif
