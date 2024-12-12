#ifndef DEF_ARCHER
#define DEF_ARCHER
using namespace std;
#include <iostream>
#include <string>
#include "class_personnage.hpp"

 
class archer : public personnage
{
    public:
        archer(std::string nom, int pv, int mana, int force, int dex, int esprit, int exp, int lvl, bool en_defense);
        bool capacite_spec(personnage &ennemi);
        void attaque(personnage &ennemi);
};
 
#endif