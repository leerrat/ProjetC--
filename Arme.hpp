#ifndef D4326302_D0E0_4D4B_B2E5_E7A7DD3C9201
#define D4326302_D0E0_4D4B_B2E5_E7A7DD3C9201
#include "Objet.hpp" 

class Arme :public Objet {
protected:
      int a_degats ;
      int a_durabilite ;
    
public:
//constructeurs
    Arme(); // Constructeur par défaut
    Arme(string nom, int effet, int quantite, int degats, int durabilite)  ;// constructeur avec parametres 

// Accesseurs
    // int getDegats() ;
    //int getDurabilite() ;
    //void setDegats(int nouveauxDegats);
    //void setDurabilite(int nouvelleDurabilite);

//Methodes
    void afficher_arme() ;              // Affiche les informations spécifiques à l'arme
    void utiliser_arme();                         // Réduit la durabilité après une utilisation
    void reparer(int points);                // Répare l'arme pour restaurer la durabilite     


};



#endif /* D4326302_D0E0_4D4B_B2E5_E7A7DD3C9201 */
