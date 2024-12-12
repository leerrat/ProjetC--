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

bool archer::capacite_spec(personnage &ennemi) {
    if (p_mana>=30)
    {
        std::cout << p_nom <<" lance une une fleche en pleine tete et inflige de nombreux degat !\n"<<std::endl;
        ennemi.recevoir_attaque(30,p_dex);
        p_mana-=30;
        return true;
    }else
    {
        cout<<"Vous n'avez pas assez de mana. Choissisez une autre option\n"<<endl;
        return false;
    }
}

void archer::attaque(personnage &ennemi) {
    std::cout << "--------------------------\n" << std::endl;
    std::cout << p_nom << " décoche une fleche precise !\n" << std::endl;
    ennemi.recevoir_attaque(10, p_dex); 
    p_mana += 15; 
}