#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

struct Arbre
{
	char* val ;

// feuilles
	Arbre* droit = nullptr;
	Arbre*	gauche = nullptr;	
};


// Genconc 																	 .	
// Prend deux Arbre, les connecte et signifie que c'est une concatenation  / \

Arbre* genconc(Arbre *gauche, Arbre *droit){ 
	Arbre* C = new Arbre ;
	C->gauche = gauche;
	C->droit = droit;
	C->val = (char*) "conc";

	return C;
}



// GenUnion
Arbre* genunion(Arbre *gauche, Arbre *droit){
	Arbre* C = new Arbre ;
	C->gauche = gauche;
	C->droit = droit;
	C->val = (char*)"Union";

	return C;
}


// genstar									
// Ne met qu'une branche                    
Arbre* genstar(Arbre *gauche){
	Arbre* C = new Arbre ;
	C->gauche = gauche;
	C->droit = nullptr;
	C->val = (char*)"*";
	return C;
}



// genstar									
// Ne met qu'une branche                    
Arbre* genUn(Arbre *gauche){
	Arbre* C = new Arbre ;
	C->gauche = gauche;
	C->droit = nullptr;
	C->val = (char*)"*";
	return C;
}



//genleaf
Arbre* genleaf(char* val){
	Arbre* C = new Arbre ;
	C->val = (char*) val;
	return C;
}


struct Atom
{
	char* atom;
	int code;
	bool ter_statut;
};


// Genatom
Atom* genatom(char* genre_atome, int code = 0, bool ter = true){
	Atom* atome = { genre_atome, code, ter};
	return *atome;
}

	// if(ter){
	// 	Arbre->val = "Terminal";
	// }else {Arbre->val = "Non-Terminal";}



void printTree(Arbre *a){ // Print Arbre en infixe
	if (a != nullptr){
		printTree(a->gauche);
		cout << a->val << ";"; 
		printTree(a->droit);
	}
};

int main(int argc, char const *argv[])
{
	/*
	int Tableau[10] = {1,112,32,24,15,76,97,28,9};	// Il n'y a que 9 valeurs. La valeur manquante est initialisée a 0 

	auto a1 = genleaf("lapin");
	auto a2 = genleaf("mangouste");
	
	auto col = genconc(a1, a2);

	assert(col->gauche == a1);
	assert(col->droit == a2);

	printTree(col);*/

   // Initialize array of pointer
    const char* colour[4] = { "Blue", "Red", "Orange", "Yellow" };
 
    // Printing Strings stored in 2D array
    for (int i = 0; i < 4; i++)
        std::cout << colour[i] << "\n";
 
	Atom noyau{(char*)"lapin", 8, true}; 
	cout << noyau.atom;

    return 0;
}


	/*Arbre* rac = new Arbre;
	genconc(rac->gauche, rac->droit);

	printTree(rac);
	*///return 0;


		//cout << "Hello\n";
/*
	Arbre *ent =nullptr ; // on initialise l'Arbre
	for(const auto &val:Tableau){
		cout << val << " ;";
	}*/
/*	for(const auto &val:Tableau){ //pour chaques valeurs dans tableau
		insertBranch(ent, val);
	}*/
//	printTree(ent);

/*void insertBranch(Arbre* &racine, const char* v){ // pourquoi un Arbre* &racine ?
	if (racine == nullptr){
		racine= new Arbre;
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