#ifndef B6229262_58F6_4DEC_9478_C3DD6DE87B11
#define B6229262_58F6_4DEC_9478_C3DD6DE87B11
#include "Objet.hpp" 


#include <iostream>
#include <string>
using namespace std;

class Potion :public Objet {
public:
//constructeurs
    Potion(); // Constructeur par défaut
    Potion(string nom, int effet, int quantite) ; //constructeur avec parametres 
//methodes
    void afficher_potion() ;           // Affiche les informations spécifiques à la potion 
    void utiliser_potion (personnage& cible);
    void ajouter(int nombre); // Méthode pour ajouter des potions
  
};




#endif /* B6229262_58F6_4DEC_9478_C3DD6DE87B11 */
