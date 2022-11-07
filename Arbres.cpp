#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

struct Arbres
{
	char* val ;

// feuilles
	Arbres* droit = nullptr;
	Arbres*	gauche = nullptr;	
};


// Genconc 																	 .	
// Prend deux arbres, les connecte et signifie que c'est une concatenation  / \

Arbres* genconc(Arbres *gauche, Arbres *droit){ 
	Arbres* C = new Arbres ;
	C->gauche = gauche;
	C->droit = droit;
	C->val = (char*) "conc";

	return C;
}


// genstar									
// Ne met qu'une branche                    
Arbres* genstar(Arbres *gauche){
	Arbres* C = new Arbres ;
	C->gauche = gauche;
	C->droit = nullptr;
	C->val = (char*)"*";
	return C;
}


//genleaf
Arbres* genleaf(char* val){
	Arbres* C = new Arbres ;
	C->val = (char*) val;
	return C;
}



// Genatom
/*Arbres* genatom((char*) type_atome, int code = 0, bool ter){
	
	if(ter){
		arbres->val = "Terminal";
	}else {arbres->val = "Non-Terminal";}
}
// Genunion 
Arbres* genunion(Arbres *gauche, Arbres *droit){

}


// GenUn
Arbres* genUn(Arbres *gauche){

}*/

/*Arbres* genunion(Arbres *gauche, Arbres *droit){
	Arbres* C = new Arbres ;
	C->gauche = gauche;
	C->droit = droit;
	C->val = "conc";

	return C;
}*/

/*void insertBranch(Arbres* &racine, const char* v){ // pourquoi un arbres* &racine ?
	if (racine == nullptr){
		racine= new Arbres;
		racine->val = v;
		racine->gauche = nullptr;
		racine->droit = nullptr;

	} else {
		if (v < racine->val){ // Dans l'hypothèse ou on fait un arbre rangé par valeur
			insertBranch(racine->gauche, v);
		} else {
			insertBranch(racine->droit, v);
		}


	}
}*/
void printTree(Arbres *a){ // Print arbres en infixe
	if (a != nullptr){
		printTree(a->gauche);
		cout << a->val << ";"; 
		printTree(a->droit);
	}
};

int main(int argc, char const *argv[])
{
	
	int Tableau[10] = {1,112,32,24,15,76,97,28,9};	// Il n'y a que 9 valeurs. La valeur manquante est initialisée a 0 

	auto a1 = genleaf("lapin");
	auto a2 = genleaf("mangouste");
	
	auto col = genconc(a1, a2);

	assert(col->gauche == a1);
	assert(col->droit == a2);

	printTree(col);

	/*Arbres* rac = new Arbres;
	genconc(rac->gauche, rac->droit);

	printTree(rac);
	*///return 0;


		//cout << "Hello\n";
/*
	Arbres *ent =nullptr ; // on initialise l'arbres
	for(const auto &val:Tableau){
		cout << val << " ;";
	}*/
/*	for(const auto &val:Tableau){ //pour chaques valeurs dans tableau
		insertBranch(ent, val);
	}*/
//	printTree(ent);
}
