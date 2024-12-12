#include <iostream>
#include "class_guerrier.hpp"
#include "class_mage.hpp"
#include "class_archer.hpp"
#include "class_ennemi.hpp"
#include "Potion.hpp"
using namespace std;
#include <algorithm>
#include <random>
const int SOIN_POTION = 20;

personnage* LancerJeu(){
    string choix;
    string nomPerso;
    int flag=1;
    cout<<"Bienvenue dans l'univers de Donjon et Dragon\n" ;
    cout<<"Tu vas pouvoir creer un personnage et t'aventurer dans des contrees magiques et fantastiques\n" ;
    cout<<"Tout d'abord choissisez un nom pour votre personnage : " ;
    cin>>nomPerso;
    cout<<"\nVoici les classes disponibles:\nArcher (Redoutable avec son arc et son agilite),\nGuerrier (Professionelle de l'epee et des combats rapprocher),\nMage (Erudit des arts mystiques et envoyant de puissant sort\n";

    personnage* P1 = nullptr;
    
    while (flag == 1) {
            cout<<"Choissisez un personnage en ecrivant la classe que vous voulez:\n";
            cin>>choix;
            if (choix == "archer" || choix =="Archer") {
                cout << "Vous avez choisi l'Archer\n";
                flag = 0;
                P1=new archer (nomPerso, 100, 100, 1, 1, 1, 1, 1,false);
            } else if (choix == "guerrier"|| choix =="Guerrier") {
                cout << "Vous avez choisi le Guerrier\n";
                flag = 0;
                P1=new guerrier (nomPerso, 100, 100, 1, 1, 1, 1, 1,false);
            } else if (choix == "mage"|| choix =="Mage") {
                cout << "Vous avez choisi le Mage\n";
                flag = 0;
                P1=new mage (nomPerso, 100, 100, 1, 1, 5, 1, 1,false);
            } else {
                cout << "Veuillez choisir une des classes existantes.\n";
                flag = 1;
            }
        } ;
    return P1;
}

int lancerCombat(personnage &J1, ennemi &J2){
    int tour=1, choixAtt,win=0;
    Potion potionSoin("Potion de soin", 20, 3);
    do{
        std::cout << "---------Tour Actuel "<<tour <<"---------\n" <<std::endl;

        // Tour du joueur 1
        std::cout << "---------C'est au tour de "<< J1.p_nom  <<"---------\n" <<std::endl;
        std::cout << "Vous avez encore "<<J1.p_pv <<" point de vie"<<endl;
        std::cout << "Vous avez encore "<<J1.p_mana <<" point de mana\n"<<endl;
        bool actionValide = false;
        do {
            std::cout << "Choisissez ce que vous voulez faire :\n"
                      << "1. Attaquer l'ennemi\n"
                      << "2. Vous proteger d'une attaque ennemie\n"
                      << "3. Utiliser la capacite speciale de votre classe\n"
                      << "4. Utiliser une potion de soin" << std::endl;
            std::cin >> choixAtt;

            switch (choixAtt) {
            case 1:
                J1.attaque(J2);
                actionValide = true;
                break;
            case 2:
                J1.defendre();
                actionValide = true;
                break;
            case 3:
                J1.capacite_spec(J2);
                actionValide = true;
                break;
            case 4:
                std::cout << "Vous avez choisi d'utiliser une potion.\n";
                std::cout << "Vos PV avant soin : " << J1.p_pv << std::endl;
                potionSoin.utiliser_potion(J1);           
                actionValide = true;
                std::cout << "Vos PV après soin : " << J1.p_pv << std::endl;
                break;
            default:
                std::cout << "Choix invalide, veuillez reessayer.\n";
                break;
            }
        } while (!actionValide);
        if (J2.p_pv <= 0) {
            std::cout << J2.p_nom << " a ete vaincu ! Felicitations a toi " << J1.p_nom << " !\n";
            win=1;
            break;
        }
        // Tour du joueur 2
        std::cout << "---------C'est au tour de "<< J2.p_nom  <<"---------\n" <<std::endl;
        cout <<J2.p_nom <<" a encore "<<J2.p_pv <<" point de vie"<<endl;
        int actionaleatoire=std::rand()%3+1;
        
        switch (actionaleatoire)
        {
        case 1:
            J2.attaque(J1);
            break;
        case 2:
            J2.defendre();
            break;
        case 3:
            J2.capacite_spec(J1);
            break;
        default:
            break;
        }
        if (J1.p_pv <= 0) {
            std::cout << "Vous avez perdu !!" << " !\n";
            break;
        }
        tour++;  // Incrémenter le tour après chaque tour
    }while (J1.p_pv > 0 && J2.p_pv > 0);
    return win;
}
int main()
{
    char rejouer;
    do {
        // Création du personnage principal
        personnage* perso = LancerJeu();
        ennemi mechant1("Grogator", 50, 100, 1, 1, 1, 10, 1, false);

        // Référence vers le personnage pour lancer le combat
        personnage& ref = *perso;
        cout << "\nVous tombez nez a nez face un horrible monstre dans la foret !.\n";
        cout << "Preparez vous a combattre !!!.\n";
        // Lancer le combat
        int resultat = lancerCombat(ref, mechant1);
        // Gérer le résultat du combat
        if (resultat == 1) {
            std::cout << "Vous recevez de l'experience qui vous permet de montez de niveau et devenir plus fort !\n";
            mechant1.drop_exp(ref);
            ref.lvlup();
            ref.p_mana=100;
        } else {
            std::cout << "Vous avez perdu le combat...\n";
        }

        // Demander si le joueur souhaite rejouer
        std::cout << "Souhaitez-vous relancer une partie ? (o/n) : ";
        std::cin >> rejouer;

    } while (rejouer == 'o' || rejouer == 'O');

    std::cout << "Merci d'avoir joue ! A bientot.\n";
    return 0;
}