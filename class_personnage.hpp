#ifndef CLASS_PERSONNAGE
#define CLASS_PERSONNAGE
using namespace std;
#include <iostream>

class personnage
{
public:
    std::string p_nom;
    int p_pv;
    int p_force;
    int p_dex;
    int p_int;
    int p_mana;
    int p_exp;
    int p_lvl;
    bool en_defense;

    
public:
    personnage(std::string nom, int pv, int mana, int force, int dex, int esprit, int exp, int lvl, bool en_defense);
    personnage();
    //~class_personnage();
    virtual void capacite_spec(personnage &ennemi);
    void aff_info();
    void recevoir_attaque(int degat,int stat);
    virtual void attaque(personnage &ennemi) = 0;
    void utiliser_objet();
    void defendre();
    void lvlup();
};
/*
personnage::personnage()
{
}
*/

/*
class_personnage::~class_personnage()
{
}
*/
#endif