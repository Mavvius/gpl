#include <iostream>
#include <string> // to use strings if necessary
#include <cassert> // to test bits of codes with assertions
#include <typeinfo> // To check the type of the variables
#include <variant>
using namespace std;

//------------------ Les Différentes structures pour les arbres et les feuilles ------------------//
struct Atom // Les feuilles 
{
	char atom;
	int code = int(atom); // Le code ascii du symbole atom. // Pas sur que ca serve
	bool ter_statut;
	string terminal;
	Atom(char atom, bool ter_statut) : atom(atom), ter_statut(ter_statut) {};
};

struct Arbre
{
    std::variant<Arbre*, Atom*> left;
    std::variant<Arbre*, Atom*> right;

    char* value;
    Arbre(char* value) : value(value) {};
};

//------------------ Les Fonctions ------------------//

// Gen Conc
// Faire un template pour prévoir la possibilité de pointer vers des structures Arbre ou Atom. 
// Prend deux Arbre, les connecte et signifie que c'est une concatenation. 
template <typename Left, typename Right> 
Arbre* genconc(Left* left, Right* right)
{
    auto t = new Arbre(".");
    t->left = left;
    t->right = right;

    return t;
}

// Gen Union
// Equivalent du "+" signifie le ou inclusif. 
template <typename Left, typename Right>
Arbre* genUion(Left* left, Right* right)
{
    auto t = new Arbre("Union");
    t->left = left;
    t->right = right;

    return t;
}

// Gen Star									
// Ne met qu'une branche équivalent de l'étoile. Signifie 0 ou plusieurs                
Arbre* genStar(Arbre* left){
	Arbre* C = new Arbre((char*)"*") ;
	C->left = left;
//	Arbre* C->right = nullptr;
	return C;
}


// Gen Un									
// Ne met qu'une branche équivalent de l'étoile. Signifie 0 ou plusieurs                
Arbre* genUn(Arbre* left){
	Arbre* C = new Arbre((char*)"Un") ;
	C->left = left;
//	Arbre* C->right = nullptr;
	return C;
}

// Gen atom
// initialise l'atom au besoin 
Atom* genAtom(char symbol, bool ter_or_not){
	Atom* A = new Atom(symbol, ter_or_not);
	if(ter_or_not){
		A->terminal = "ELTER";
	} else { A->terminal = "IDNTER"; }

	return A;
}

// //genleaf
// Arbre* genleaf(char* val){
// 	Arbre* C = new Arbre ;
// 	C->val = (char*) val;
// 	return C;
// }

/*
void printTree(Tree* a){ // Print Arbre en infixe
	if (a != nullptr){
		printTree(a->gauche);
		cout << a->val << "\t"; 
		printTree(a->droit);
	}
};*/

int main(int argc, char const *argv[])
{
	
	int Tableau[10] = {1,112,32,24,15,76,97,28,9};	// Il n'y a que 9 valeurs. La valeur manquante est initialisée a 0 

	// auto a1 = genleaf((char*)"lapin");
	// auto a2 = genleaf((char*)"mangouste");
	char c = '*';
	Atom* noyau = new Atom('E',true); 
	cout << noyau->atom << "--" << noyau->code << "--" << noyau->ter_statut << endl ;
	cout << int(c);
	string chaine= "bliblou";
	cout << chaine <<"\n";

	auto a = genAtom('S', true);
	cout << a->code <<"-----" << a->terminal;
// 	// auto col = genconc(a1, a2);

// 	//assert(col->gauche == a1);
// 	//assert(col->droit == a2);

// 	//printTree(col);

//    // Initialize array of pointer
//     const char* colour[4] = { "Blue", "Red", "Orange", "Yellow" };
 
//     // Printing Strings stored in 2D array
//     for (int i = 0; i < 4; i++)
//         std::cout << colour[i] << "\n";
 
// 	cout << noyau->atom << "\n" << noyau->code << "\n" << noyau->ter_statut ;

// 	cout << "le type de col est :" << typeid(col).name() << "\n";
	
// 	int *t = new int;
// 	*t = 8;
// 	cout << typeid(Atom*).name();

	
// 	if(typeid(col).name() == typeid(Arbre*).name()){
// 		cout << "le check est ok ";
// 	};
// 	if(typeid(noyau).name() == typeid(Atom*).name()){
// 		cout << "le check est atom ";
// 	};

// 	//assert(typeid(noyau).name() == typeid(Arbre*).name());
// 	assert(typeid(col).name() == typeid(Arbre*).name());
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