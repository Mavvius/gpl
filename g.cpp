#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

struct Arbre
{
    char* val ;
// feuilles
    Arbre* droit = nullptr;
    Arbre* gauche = nullptr;    
};

/*
struct Arbre_v
{
    string val ;
// feuilles
    Arbre_v droit = nullptr;
    Arbre_v gauche = nullptr;    
};
*/


// Genconc 
Arbre* genconc(Arbre *gauche, Arbre *droit){
    assert(gauche != nullptr);
	assert(droit != nullptr);
	
	Arbre* C = new Arbre ;
    C->gauche = gauche;
    C->droit = droit;
    C->val = (char*) "conc";

    return C;
}
// Retirer les majuscule et les pluriels
//genleaf
Arbre* genleaf(char* val){
	Arbre* C = new Arbre ;
	C->val = (char*) val;
	return C;
}

// genstar
Arbre* genstar(Arbre *gauche){
    Arbre* C = new Arbre ;
    C->gauche = gauche;
    C->droit = nullptr;
    C->val = (char*)"*";
    return C ;
	}

// printtree
void printTree(Arbre *a){
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


/* Boulevard of Broken Dreams
// Genconc 																	 .	


/*Arbre* genconc(Arbre* gauche, Arbre* droit){ 
	Arbre* C = new Arbre ;
	C->gauche = gauche;
	C->droit = droit;
	C->val = (char*) "conc";

	return C;
}
*/
/*
template<typename T1, typename T2>
Arbre* genconc(T1* gauche, T2* droit){ 
	Arbre* C = new Arbre ;
	C->gauche = gauche;
	C->droit = droit;
	C->val = (char*) "conc";

	return C;
}*/

// template<typename T1, typename T2>
// Arbre* genconc(T1* gauche, T2* droit){ 
// 	Arbre* C = new Arbre ;
// 	C->gauche = gauche;
// 	C->droit = droit;
// 	C->val = (char*) "conc";

// 	return C;
// } */

// // GenUnion
// Arbre* genunion(Arbre* gauche, Arbre* droit){
// 	Arbre* C = new Arbre ;
// 	C->gauche = gauche;
// 	C->droit = droit;
// 	C->val = (char*)"Union";

// 	return C;
// }

// // genstar									
// // Ne met qu'une branche                    
// Arbre* genUn(Arbre *gauche){
// 	Arbre* C = new Arbre ;
// 	C->gauche = gauche;
// 	C->droit = nullptr;
// 	C->val = (char*)"*";
// 	return C;
// }