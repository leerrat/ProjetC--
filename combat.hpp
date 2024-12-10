#include <iostream>
#include <string>
#include "class_ennemi.hpp"
#include "class_archer.hpp"
#include "class_guerrier.hpp"
#include "class_mage.hpp"
using namespace std;



//Méthode pour lancer le combat entre deux personnages
void lancerCombat(personnage &J1, personnage &J2){
    while (J1 && J2){
        afficherTour();

        // Tour du joueur 1
        std::cout << nom_J1 << " attaque !" << std::endl;
        J1.attaquer(J2);
        if (!J2.estVivant()) {
            break; // Sortir de la boucle si le joueur 2 est mort
        }

        // Tour du joueur 2
        std::cout << nom_J2 << " attaque !" << std::endl;
        J2.attaquer(J1);
        
        tour++;  // Incrémenter le tour après chaque tour
    }
}


//Méthode pour afficher le nombre de tours
void afficherTour(){
    cout<<"Tour actuel : " <<tour <<endl;
}

// Méthode pour afficher le gagant et le perdant
void  afficherResultat (personnage &J1, personnage &J2){
    if (J1.estVivant()){
        cout <<"\n"<< nom_J1<< "gagne le combat !"<<endl;
        cout <<"\n"<< nom_J2<< "perd le combat ! "<<endl;
    }
    else{
        cout << "\n"<< nom_J2<< "gagne le combat !" <<endl;
        cout <<"\n"<< nom_J1 <<"perd le combat !" <<endl;
    }
}
