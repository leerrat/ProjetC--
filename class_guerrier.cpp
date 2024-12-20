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

bool guerrier::capacite_spec(personnage &ennemi){
    if (p_mana>=50)
    {
        std::cout << p_nom <<" effectue une attaque puissante avec son epee et inflige de nombreux degat ! \n"<<std::endl;
        ennemi.recevoir_attaque(30,1);
        p_mana-=50;
        return true;
    }else
    {
        cout<<"Vous n'avez pas assez de mana. Choissisez une autre option\n"<<endl;
        return false;
    }
}

void guerrier::attaque(personnage &ennemi) {
    std::cout << "--------------------------\n" << std::endl;
    std::cout << p_nom << " donne un cop d'epee\n" << std::endl;
    ennemi.recevoir_attaque(15, p_force); 
    p_mana += 20; 
}