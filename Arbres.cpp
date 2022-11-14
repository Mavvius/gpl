#include <iostream>
#include <string> // to use strings if necessary
#include <cassert> // to test bits of codes with assertions
#include <typeinfo> // To check the type of the variables
#include <variant>
using namespace std;

//------------------ Les Différentes structures pour les arbres et les feuilles ------------------//
struct Atom // Les feuilles 
{
	string atom;
	//int code = int(atom); // Le code ascii du symbole atom. // Pas sur que ca serve
	bool ter_statut;
	string terminal;
	Atom(string atom, bool ter_statut) : atom(atom), ter_statut(ter_statut) {};
};

struct Arbre
{
    std::variant<Arbre*, Atom*> left;
    std::variant<Arbre*, Atom*> right;

    string value;
    Arbre(string value) : value(value) {};
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
Arbre* genUnion(Left* left, Right* right)
{
    auto t = new Arbre("Union");
    t->left = left;
    t->right = right;

    return t;
}

// Gen Star									
// Ne met qu'une branche équivalent de l'étoile. Signifie 0 ou plusieurs                
Arbre* genStar(Arbre* left){
	Arbre* C = new Arbre((string)"*") ;
	C->left = left;
//	Arbre* C->right = nullptr;
	return C;
}


// Gen Un									
// Ne met qu'une branche équivalent de l'étoile. Signifie 0 ou plusieurs                
Arbre* genUn(Arbre* left){
	Arbre* C = new Arbre((string)"Un") ;
	C->left = left;
//	Arbre* C->right = nullptr;
	return C;
}

// Gen atom
// initialise l'atom au besoin 
Atom* genAtom(string symbol, bool ter_or_not){
	Atom* A = new Atom(symbol, ter_or_not);
	if(ter_or_not){
		A->terminal = "ELTER";
	} else { A->terminal = "IDNTER"; }

	return A;
}


//------------------ L'affichage ------------------//

// Spécifique pour afficher les feuilles
void display(std::string bidule, Atom* l, bool gauche)
{
    if (l != nullptr) {
        std::cout << bidule;

        std::cout << (gauche ? "├──" : "└──" ); // ? est l'equivalent d'un if else. 

        //std::cout << l->atom << " " <<  l->terminal << " " << "\t" <<"\n";
    	std::cout << l->atom << "\n";
    }
}

// Pour afficher les Arbres
void display(std::string truc, Arbre* t, bool gauche)
{
    if (t != nullptr) {
        std::cout << truc;

        std::cout << (gauche ? "├──" : "└──" ); // "?" est l'equivalent d'un if else. 

        std::cout << t->value << "\t\n";

// Le lancement change selon le type Atom ou Arbre mais la procedure est la même
        if (auto* ptree = std::get_if<Arbre*>(&t->left)) {
            //std::cout << t->value + ("│   ");
            display(truc + (gauche ? "│   " : "\t"),*ptree, true);
        } else if (auto* pleaf = std::get_if<Atom*>(&t->left)) {
            //std::cout << t->value + ("│   ");
            display(truc + (gauche ? "│   " : "\t"),*pleaf, true);
        }

        if (auto* ptree = std::get_if<Arbre*>(&t->right)) {
            //std::cout << t->value + ("\t");
            display(truc + (gauche ? "│   " : "\t"),*ptree, false);
        
        } else if (auto* pleaf = std::get_if<Atom*>(&t->right)) {
            //std::cout << t->value + ("\t");
            display(truc + (gauche ? "│   " : "\t") ,*pleaf, false);
        }
    }
}

// Pour lancer la fonction a la racine
void display(Arbre* node)
{
    display("", node, false);    
}






// ##########################################################################
/**/


int main(int argc, char const *argv[])
{
	
	int Tableau[10] = {1,112,32,24,15,76,97,28,9};	// Il n'y a que 9 valeurs. La valeur manquante est initialisée a 0 

	// auto a1 = genleaf((char*)"lapin");
	// auto a2 = genleaf((char*)"mangouste");
	char c = '*';
	Atom* noyau = new Atom("E",true); 
	cout << noyau->atom << "--"<< noyau->ter_statut << endl ;
	cout << int(c);
	string chaine= "bliblou";
	cout << chaine <<"\n";

	auto a = genAtom("S", true);
	cout << a->atom <<"-----" << a->terminal << "\n\n";

	auto* rule1 = genconc(genStar(genconc(genconc(genAtom("N", false), genAtom("->", true)), genAtom("E", false))), genAtom(";", true)); 
	auto* rule2 = genAtom("IDNTER", true);
	auto* rule3 = genconc(genAtom("T", false), genStar(genconc(genAtom("\"+\"", true), genAtom("T", false))));
	auto* rule4 = genconc(genAtom("T", false), genStar(genconc(genAtom("\".\"", true), genAtom("F", false))));
	auto* rule5 = genUnion(
					genUnion(
						genUnion(
							genUnion(genAtom("\"IDNTER\"", true), genAtom("\"ELTER\"", true)), 
								genconc(genconc(genAtom("(", true), genAtom("E", false)), genAtom(")", true))), 
									genconc(genconc(genAtom("[", true), genAtom("E", false)), genAtom("]", true))
										), genconc(genconc(genAtom("(/", true), genAtom("E", false)), genAtom("/)", true)));


	cout << "-- RULE 1 -- \n";
	display(rule1);
	cout << "\n-- RULE 2 -- \n";
	display("", rule2, false);
	cout << "\n-- RULE 3 -- \n";
	display(rule3);
	cout << "\n-- RULE 4 -- \n";
	display(rule4);
	cout << "\n-- RULE 5 -- \n";
	display(rule5);



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



/*

void display(Leaf* l, bool gauche)
{
    if (l != nullptr) {
        std::cout << l->value << (gauche ? "│   " : "\t");
    }
}

void display(std::string truc, Tree* t, bool gauche)
{
    truc = t->value;
    if (t != nullptr) {
     //   std::cout << t->value;

        std::cout << (gauche ? "├──" : "└──" ); // ? est l'equivalent d'un if else. 

        std::cout << t->value << std::endl;

        if (auto* ptree = std::get_if<Tree*>(&t->left)) {
            //std::cout << t->value + ("│   ");
            display(truc + (gauche ? "│   " : "\t"),*ptree, true);
        } else if (auto* pleaf = std::get_if<Leaf*>(&t->left)) {
            //std::cout << t->value + ("│   ");
            display(*pleaf, true);
        }

        if (auto* ptree = std::get_if<Tree*>(&t->right)) {
            //std::cout << t->value + ("\t");
            display(truc + (gauche ? "│   " : "\t"),*ptree, false);
        
        } else if (auto* pleaf = std::get_if<Leaf*>(&t->right)) {
            //std::cout << t->value + ("\t");
            display(*pleaf, false);
        }
    }
}
*/




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





/*void displayArbre(const std::string& prefix, const Arbre* node, bool isLeft)
{	
	if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" ); // ? est l'equivalent d'un if else. 

        // print the value of the node
        std::cout << node->value << std::endl;

        // enter the next tree level - left and right branch
       	displayArbre( prefix + (isLeft ? "│   " : "\t"), node->left, true);
       	displayArbre( prefix + (isLeft ? "│   " : "\t"), node->right, false);
 
	}
}

void displayArbre(const Arbre* node)
{
    displayArbre("", node, false);    
}

void displayArbre(Atom* l)
{
    if (l != nullptr) {
        std::cout << "Leaf: " << l->value;
    }
}

*/


/*void display(Leaf* l)
{
    if (l != nullptr) {
        std::cout << "Leaf: " << l->value << "\n";
    }
}

void display(Tree* t)
{
    if (t != nullptr) {
        if (auto* ptree = std::get_if<Tree*>(&t->left)) {
            display(*ptree);
        } else if (auto* pleaf = std::get_if<Leaf*>(&t->left)) {
            display(*pleaf);
        }
        std::cout << "Tree: " << t->value << "\n";
        if (auto* ptree = std::get_if<Tree*>(&t->right)) {
            display(*ptree);
        } else if (auto* pleaf = std::get_if<Leaf*>(&t->right)) {
            display(*pleaf);
        }
    }
}
*/