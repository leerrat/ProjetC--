#include "Objet.hpp" 

#include "Arme.hpp" 
#include <iostream>
#include <string>
using namespace std;

//constructeur par defaut
Arme ::Arme(){
    Objet() ;
    a_degats = 0;
    a_durabilite = 0;
}
//constructeur avec parametres 
Arme::Arme(std::string nom, int effet, int quantite, int degats, int durabilite) : Objet(nom, "Arme", effet, quantite)       
{
     a_degats=degats ;
     a_durabilite=durabilite; 
}
//methode pour afficher les infos de l'arme
void Arme::afficher_arme(){
    cout << "------Informations de l'arme------"<<"\n" ;
    Objet :: afficher_objet ();       // Appelle la méthode afficher_objet de la classe mère                              
    cout << "Degats :" << a_degats << "\n";
    cout << "Durabilite :" << a_durabilite << "\n";
    cout <<"---------------------------------"<<"\n";
}
//methode qui reduit la durabilie de l'arme 
void Arme::utiliser_arme() {
    if (a_durabilite > 0) {
        a_durabilite--;
        cout << "L'arme a ete utilisee.\n";
        cout << "La durabilite restante : " << a_durabilite << "\n";
    } else {
        cout << "L'arme est cassee et ne peut plus etre utilisee"<< "\n";
    }
}

// methode qui restaure la durabilite 
void Arme::reparer(int point){
    a_durabilite += point ;
    cout << "La durabilite de " <<m_nomobjet<< "est :"   <<  a_durabilite << "\n";
}

