// Rassembler toutes les fonction d'arbres


struct Noeud
{
   int valeur;
// feuilles 
   Noeud* droit;
   Noeud* gauche;
};
Noeud* arbre = NULL;

void insert_node(Noeud* noeud)
{
  // Noeud* courant = arbre;
  // Noeud* precedent = NULL;

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


void add_node(int valeur)
{
   // ajout nouveau noeud en mémoire
   Noeud* nouveau = new Noeud;
   nouveau->valeur = valeur;
   nouveau->droite = NULL;
   nouveau->gauche = NULL;

   // Puis on laisse Placer() le mettre à la bonne place
   insert_node(nouveau);
}

