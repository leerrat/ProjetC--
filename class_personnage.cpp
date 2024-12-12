#include <iostream>
#include "class_personnage.hpp"

personnage::personnage(std::string nom, int pv, int mana, int force, int dex, int esprit, int exp, int lvl, bool en_defense){
    personnage::p_nom = nom;
    personnage::p_pv = pv;
    personnage::p_mana = mana;
    personnage::p_force = force;
    personnage::p_dex = dex;    
    personnage::p_int = esprit;
    personnage::p_exp = exp;
    personnage::p_lvl = lvl;
    personnage::en_defense=false;
}

personnage::personnage(){

}

void personnage::recevoir_attaque(int degat,int stat){
    int degatot=(degat*stat);
    if (en_defense==true){
        personnage::p_pv -= degatot/2;
        en_defense=false;
        std::cout <<"l'ennemie s'est mis en defense donc prend la moitie des degats : "<<degatot/2 <<std::endl;
    }else
    {
        personnage::p_pv -= degat*stat;
        std::cout <<"l'ennemie prend des degats : "<<(degatot)<<std::endl;
    }
}

void personnage::attaque(personnage &ennemi){
    
}

void personnage::aff_info(){
    std::cout << "Voici le nom du personnage = " << personnage::p_nom <<std::endl;
    std::cout << "Voici les points de vie du personnage = " << personnage::p_pv <<std::endl;
    std::cout << "Voici la mana du personnage = " << personnage::p_mana <<std::endl;
    std::cout << "Voici les points d'experience du personnage = " << personnage::p_exp <<std::endl;
    std::cout << "Voici la dexterite du personnage = " << personnage::p_dex <<std::endl;
    std::cout << "Voici la force du personnage = " << personnage::p_force <<std::endl;
    std::cout << "Voici l'inteligence du personnage = " << personnage::p_int <<std::endl;
    std::cout << "Le personnage est niveau = " << personnage::p_lvl <<std::endl;
    std::cout << "le defend est " << personnage::en_defense <<std::endl;
}

void personnage::utiliser_objet(){

}

void personnage::defendre(){
    en_defense = true;
}

void personnage::lvlup(){
    p_exp = 0;
    p_lvl += 1;
    int choixlvl;
    std::cout << "\nFelicitation vous etes montez niveau \n"<< personnage::p_lvl<< std::endl;
    std::cout<< "Choissisez la statistique a montez\n1.Pour montez les points de vie\n2.Pour montez la force\n3.Pour montez la dexterite\n4.Pour montez l'esprit" <<std::endl;
    std::cin >> choixlvl;
    switch( choixlvl ) {
            case 1:
                p_pv+=50;
                std::cout <<"Vous avez augementez votre maximum de point de vie de 50 \n"<<std::endl;
                break;
            case 2:
                p_force+=1;
                std::cout <<"Vous avez augementez votre force de 1 \n"<<std::endl;
                break;
            case 3:
                p_dex+=1;
                std::cout <<"Vous avez augementez votre dexterite de 1 \n"<<std::endl;
                break;
            case 4:
                p_int+=1;
                std::cout <<"Vous avez augementez votre inteligence de 1 \n"<<std::endl;
            break;
    }
}

void personnage::capacite_spec(personnage &ennemi){}