#include <iostream>
#include "class_archer.hpp"
#include "class_personnage.hpp"

archer::archer(std::string nom, int pv, int mana, int force, int dex, int esprit, int exp, int lvl, bool en_defense)
{
    archer::p_nom = nom;
    archer::p_pv = pv;
    archer::p_mana = mana;
    archer::p_force = force;
    archer::p_dex = dex;    
    archer::p_int = esprit;
    archer::p_exp = exp;
    archer::p_lvl = lvl;
    archer::en_defense=false;
}

void archer::capacite_spec(personnage &ennemi) {
    std::cout << p_nom <<" lance une attaque speciale \n"<<std::endl;
    ennemi.recevoir_attaque(30,1);
    p_mana-=30;
}