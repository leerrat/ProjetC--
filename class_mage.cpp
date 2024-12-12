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

void mage::attaque(personnage &ennemi) {
    std::cout << "--------------------------\n" << std::endl;
    std::cout << p_nom << " lance un sort de feu !\n" << std::endl;
    ennemi.recevoir_attaque(20, p_int); // Basé sur l'intelligence du mage
    p_mana += 50;
}

void mage::capacite_spec(personnage &ennemi){
    std::cout << p_nom <<" fait tombez la foudre et inflige de nombreux degat !\n"<<std::endl;
    if (p_mana>=70)
    {
        p_mana-=70;
        ennemi.recevoir_attaque(50,p_int);
    }else
    {
        cout<<"vous n'avez pas assez de mana"<<endl;
    }
}