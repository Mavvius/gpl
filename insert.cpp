void insert_node(Noeud* noeud)
{
   Noeud* courant = arbre;
   Noeud* precedent = NULL;

   // Si l'arbre est vide, ça va très vite :
   if(arbre == NULL)
   {
      arbre = noeud;
      return;
   }
     // On se fraye un chemin jusqu'a une place vide
   while(courant)
   {
      precedent = courant;
      if(noeud->valeur < courant->valeur)
         courant = courant->fils_gauche;
      else
         courant = courant->fils_droite;
   }

   // Hop, on a trouvé une place libre, et
   // precedent pointe vers le parent de notre
   // noeud à replacer.
   if(noeud->valeur < precedent->valeur)
      precedent->fils_gauche = noeud;
   else
      precedent->fils_droite = noeud;
}


struct Noeud
{
    T donnees;
    Noeud <T>* suivant;
    // Pour définir une liste doublement chaînée
    // Noeud <T>* precedent;  
};



void Liste_ch <T> :: inserer (int pos, const T& valeur)
{
    if (pos < 0 || pos > compteur){
        cout << "Erreur! La position est invalide." << endl;
        return;
    }
    Noeud <T>* nouveau = CreerNoeud (valeur);
 
    //Insertion au début
    if (pos == 0){
        nouveau -> suivant = entete;
        entete = nouveau;
    }
    // Insertion au milieu 
    else{
        Noeud <T>* courant = entete;
        for (int i = 1; i < pos; i++){
            courant = courant -> suivant;
        }
        nouveau -> suivant = courant -> suivant;
        courant -> suivant = nouveau;
    }
    compteur++;
}
Supprimer un 

Liste_ch <>