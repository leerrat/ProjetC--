#include <iostream>
#include "class_ennemi.hpp"
#include "class_personnage.hpp"

bool ennemi::capacite_spec(personnage &ennemi){
    std::cout << p_nom <<" vous mord de toute ses forces \n"<<std::endl;
    ennemi.recevoir_attaque(20,p_force);
    return true;
}

void ennemi::drop_exp(personnage& joueur){
    joueur.p_exp+=ennemi::p_exp;
}

ennemi::ennemi(std::string nom, int pv, int mana, int force, int dex, int esprit, int exp, int lvl, bool en_defense)
{
    ennemi::p_nom = nom;
    ennemi::p_pv = pv;
    ennemi::p_mana = mana;
    ennemi::p_force = force;
    ennemi::p_dex = dex;    
    ennemi::p_int = esprit;
    ennemi::p_exp = exp;
    ennemi::p_lvl = lvl;
    ennemi::en_defense=false;
}
void ennemi::attaque(personnage &ennemi) {
    //std::cout << "--------------------------\n" << std::endl;
    std::cout << p_nom << " montre ses crocs et vous attaque !\n" << std::endl;
    ennemi.recevoir_attaque(10, p_force); 
    p_mana += 20; 
}