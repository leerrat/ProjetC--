#ifndef FBEF1593_3BCE_4671_A1B4_058BEDCDEEC0
#define FBEF1593_3BCE_4671_A1B4_058BEDCDEEC0
#include <iostream>
#include <string>
using namespace std;

class Objet
{
protected:
 string m_nomobjet ;
 string m_typeobjet ;
 int m_effet ;
 int m_quantite ; 

    
public:
//constructeur par defaut 
Objet();
//constructeur avec parametres 
Objet(string m_nomobjet , string m_nomtype , int m_effet , int m_quantite) ;
//methode pour afficher les infos de l'objet 
void afficher_objet();
//methode pour augmenter la quantite d'un objet 
void augmenter_quantite(int nombreobjet) ;



};



#endif /* FBEF1593_3BCE_4671_A1B4_058BEDCDEEC0 */
