#ifndef DEF_MAGE
#define DEF_MAGE
using namespace std;
#include <iostream>
#include <string>
#include "class_personnage.hpp"
 
class mage : public personnage
{
    public:
        mage(std::string nom, int pv, int mana, int force, int dex, int esprit, int exp, int lvl, bool en_defense);
        void capacite_spec(personnage &ennemi);
};
#endif