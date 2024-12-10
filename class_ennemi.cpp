#include <iostream>
#include "class_ennemi.hpp"
#include "class_personnage.hpp"

void ennemi::capacite_spec(personnage &ennemi){
    std::cout << p_nom <<" lance une attaque speciale \n"<<std::endl;
    ennemi.recevoir_attaque(20,1);
}

void ennemi::drop_exp(personnage& joueur){
    joueur.p_exp+=100;
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