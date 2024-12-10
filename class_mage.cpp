#include <iostream>
#include "class_mage.hpp"
#include "class_personnage.hpp"

mage::mage(std::string nom, int pv, int mana, int force, int dex, int esprit, int exp, int lvl, bool en_defense)
{
    mage::p_nom = nom;
    mage::p_pv = pv;
    mage::p_mana = mana;
    mage::p_force = force;
    mage::p_dex = dex;    
    mage::p_int = esprit;
    mage::p_exp = exp;
    mage::p_lvl = lvl;
    mage::en_defense=false;
}

void mage::capacite_spec(personnage &ennemi){
    std::cout << p_nom <<" lance une attaque speciale \n"<<std::endl;
    ennemi.recevoir_attaque(50,1);
    p_mana-=70;
}