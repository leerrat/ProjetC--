#include <iostream>
#include "class_guerrier.hpp"
#include "class_personnage.hpp"
#include "class_personnage.cpp"

guerrier::guerrier(std::string nom, int pv, int mana, int force, int dex, int esprit, int exp, int lvl, bool en_defense)
{
    guerrier::p_nom = nom;
    guerrier::p_pv = pv;
    guerrier::p_mana = mana;
    guerrier::p_force = force;
    guerrier::p_dex = dex;    
    guerrier::p_int = esprit;
    guerrier::p_exp = exp;
    guerrier::p_lvl = lvl;
    guerrier::en_defense=false;
}

void guerrier::capacite_spec(personnage &ennemi){
    std::cout << p_nom <<" lance une attaque speciale \n"<<std::endl;
    ennemi.recevoir_attaque(30,1);
    p_mana-=50;
}