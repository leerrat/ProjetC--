#include <string>
using namespace std;
#include "Objet.hpp"

//constructeur par defaut
Objet::Objet(){
    m_nomobjet ="Inconnu";
    m_typeobjet="Inconnu";
    m_effet = 0 ;
    m_quantite = 0 ;
}
//constructeur avec parametres 
Objet::Objet(string nomobjet , string typeobjet , int effet , int quantite){
    m_nomobjet=nomobjet;
    m_typeobjet=typeobjet;
    m_effet=effet ;
    m_quantite=quantite ;
}
//methode pour afficher les infos de l'objet 
void Objet::afficher_objet(){
    cout << "Nom : " << m_nomobjet << "\n";
    cout << "Type :" << m_typeobjet << "\n";
    cout << "Effet :" << m_effet << "\n";
    cout << "Quantite :" << m_quantite << "\n";
}
//methode pour augmenter la quantite de l'objet 
void Objet::augmenter_quantite(int nombreobjet){
    m_quantite+=nombreobjet;
}
