#ifndef DEF_ENNEMI
#define DEF_ENNEMI
 
#include <iostream>
#include <string>
#include "class_personnage.hpp"


class ennemi : public personnage
{
    public:
        ennemi(std::string nom, int pv, int mana, int force, int dex, int esprit, int exp, int lvl, bool en_defense);
        bool capacite_spec(personnage &ennemi);
        void drop_exp(personnage& joueur);
        void drop_item();
        void attaque(personnage &ennemi);
};

#endif