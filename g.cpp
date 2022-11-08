#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

struct Arbres
{
    char* val ;
// feuilles
    Arbres* droit = nullptr;
    Arbres* gauche = nullptr;    
};

/*
struct Arbres_v
{
    string val ;
// feuilles
    Arbres_v droit = nullptr;
    Arbres_v gauche = nullptr;    
};
*/


// Genconc 
Arbres* genconc(Arbres *gauche, Arbres *droit){
    assert(gauche != nullptr);
	assert(droit != nullptr);
	
	Arbres* C = new Arbres ;
    C->gauche = gauche;
    C->droit = droit;
    C->val = (char*) "conc";

    return C;
}
// Retirer les majuscule et les pluriels
//genleaf
Arbres* genleaf(char* val){
	Arbres* C = new Arbres ;
	C->val = (char*) val;
	return C;
}

// genstar
Arbres* genstar(Arbres *gauche){
    Arbres* C = new Arbres ;
    C->gauche = gauche;
    C->droit = nullptr;
    C->val = (char*)"*";
    return C ;
	}

// printtree
void printTree(Arbres *a){
	if (a!=nullptr){
		printTree(a->gauche);
		cout << a->val; 
		printTree(a->droit);
	}
}

int main()
{

    std::cout << "hello worlds" ;

	auto a1 = genleaf("lapin");
	auto a2 = genleaf("mangouste");
	
	auto col = genconc(a1, a2); 
// A verifier 1.Genconc connecte les deux feuilles	2.
	assert(col->gauche == a1);
	assert(col->droit == a2);


}



