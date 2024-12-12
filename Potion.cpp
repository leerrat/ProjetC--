#ifndef POTION_HPP
#define POTION_HPP

#include "Objet.hpp" 
#include "class_personnage.hpp" 
#include "Potion.hpp" 
#include <iostream>
#include <string>
using namespace std;

//constructeur 
Potion :: Potion () : Objet(){}
Potion::Potion(std::string nom, int effet, int quantite) : Objet(nom, "Potion", 20, quantite) {}



//methode pour afficher les infos de la potion
void Potion::afficher_potion(){
    cout << "------Informations de la potion------"<<"\n" ;
    Objet :: afficher_objet ();  // Appelle la méthode afficher_objet de la classe mère
    cout <<"---------------------------------"<<"\n";                                     
}
//methode pour utiliser une potion 
void Potion::utiliser_potion(personnage &cible) {
    if (m_quantite > 0) {
        m_quantite--;
        cible.p_pv += 20;
        cout << "Vous avez utilise une " << m_nomobjet <<"\n" ;
        cout << " Quantite restante : " << m_quantite << "\n";
    } else {
        std::cout << "Vous n'avez plus de " << m_nomobjet << " à utiliser" <<"\n";
    }
}

// Méthode pour ajouter des potions
void Potion::ajouter(int nombre) {
    m_quantite += nombre;
    cout << "Vous avez gagner " << nombre << " " << m_nomobjet << "\n" ;
    cout<<"Quantité totale : " << m_quantite << "\n";
    }

#endif