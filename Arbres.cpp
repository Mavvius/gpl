#include <iostream>
#include <string> // to use strings if necessary
#include <cassert> // to test bits of codes with assertions
#include <typeinfo> // To check the type of the variables
#include <variant>
#include <vector>
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

struct tab_arbre
{
	std::variant<Arbre*, Atom*> tab;
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
void display(std::string symbols, Atom* l, bool gauche)
{
    if (l != nullptr) {
        std::cout << symbols;

        std::cout << (gauche ? "├──" : "└──" ); // ? est l'equivalent d'un if else. 

        //std::cout << l->atom << " " <<  l->terminal << " " << "\t" <<"\n";
    	std::cout << l->atom << "\n";
    }
}

// Pour afficher les Arbres
void display(std::string symbols, Arbre* t, bool gauche)
{
    if (t != nullptr) {
        std::cout << symbols; // chaine vide pour avoir la profondeur

        std::cout << (gauche ? "├──" : "└──" ); // "?" est l'equivalent d'un if else. (si gauche : sinon )

        std::cout << t->value << "\t\n";

// Le lancement change selon le type Atom ou Arbre mais la procedure est la même
        if (auto* ptree = std::get_if<Arbre*>(&t->left)) {
            //std::cout << t->value + ("│   ");
            display(symbols + (gauche ? "│   " : "\t"),*ptree, true);
        } else if (auto* pleaf = std::get_if<Atom*>(&t->left)) {
            //std::cout << t->value + ("│   ");
            display(symbols + (gauche ? "│   " : "\t"),*pleaf, true);
        }

        if (auto* ptree = std::get_if<Arbre*>(&t->right)) {
            //std::cout << t->value + ("\t");
            display(symbols + (gauche ? "│   " : "\t"),*ptree, false);
        
        } else if (auto* pleaf = std::get_if<Atom*>(&t->right)) {
            //std::cout << t->value + ("\t");
            display(symbols + (gauche ? "│   " : "\t") ,*pleaf, false);
        }
    }
}

// Pour lancer la fonction a la racine
// Template pour pouvoir lancer la Rule 2 qui n'est pas un arbre, juste un Atom
template <typename R>
void display(R* node)
{
    display("", node, false);    
}






// ##########################################################################
/**/


int main(int argc, char const *argv[])
{

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


	

	std::vector<std::vector<variant<Arbre*, Atom*>>> grammar {{rule1},{ rule2}, {rule3}, {rule4}, {rule5}};

	std::vector<std::vector<int>> v {{1,3,4},{2,5,6},{5,7,8}};

	int r = 1;
	for (auto i : grammar) {
		
		for(auto j : i){
		
			cout << "\n-- RULE " << r << "-- \n";
			if (auto* rtree = std::get_if<Arbre*>(&j)){
				display(*rtree) ;
			} else if (auto* ratom = std::get_if<Atom*>(&j)){
				display(*ratom) ;
			}
		
		r = r+1;					
		}


	}

/*	cout << "-- RULE 1 -- \n";
	display(rule1);
*//*	cout << "\n-- RULE 2 -- \n" << typeid(rule2).name() << "\n";
	display(rule2);
	cout << "\n-- RULE 3 -- \n";
	display(rule3);
	cout << "\n-- RULE 4 -- \n";
	display(rule4);
	cout << "\n-- RULE 5 -- \n";
	display(rule5);
*/
    return 0;
}

