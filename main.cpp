#include <iostream>
#include "class_guerrier.hpp"
#include "class_mage.hpp"
#include "class_archer.hpp"
#include "class_ennemi.hpp"
using namespace std;
#include <random>

personnage* LancerJeu(){
    string choix;
    string nomPerso;
    int flag=1;
    cout<<"Bienvenue dans l'univers de Donjon et Dragon\n" ;
    cout<<"Tu vas pouvoir creer un personnage et t'aventurer dans des contrees magiques et fantastiques\n" ;
    cout<<"Tout d'abord choissisez un nom pour votre personnage :" ;
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
                P1=new mage (nomPerso, 100, 100, 1, 1, 1, 1, 1,false);
            } else {
                cout << "Veuillez choisir une des classes existantes.\n";
                flag = 1;
            }
        } ;
    return P1;
}

void lancerCombat(personnage &J1, ennemi &J2){
    int tour=1, choixAtt;
    
    do{
        std::cout << "---------Tour Actuel "<<tour <<"---------\n" <<std::endl;

        // Tour du joueur 1
        std::cout << "---------C'est au tour de "<< J1.p_nom  <<"---------\n" <<std::endl;
        std::cout << "Vous avez encore "<<J1.p_pv <<" point de vie"<<endl;
        std::cout << "Vous avez encore "<<J1.p_mana <<" point de mana\n"<<endl;
        std::cout <<"Choissisez ce que vous voulez faire \n1.Attaquez l'ennemie \n2.Vous protegez d'une attaque ennemie\n3.Utilisez la capacite speciale de votre classe\n4.Utilisez un objet" << std::endl;
        cin >> choixAtt;
        switch (choixAtt)
        {
        case 1:
            J1.attaque(J2);
            break;
        case 2:
            J1.defendre();
            break;
        case 3:
            J1.capacite_spec(J2);
            break;
        default:
            break;
        }
        // Tour du joueur 2
        std::cout << "---------C'est au tour de "<< J2.p_nom  <<"---------\n" <<std::endl;
        cout <<J2.p_nom <<" a encore "<<J2.p_pv <<" point de vie"<<endl;
        int actionaleatoire=std::rand()%3+1;
        
        switch (actionaleatoire)
        {
        case 1:
            cout << "Ennemi attaque.\n";
            J2.attaque(J1);
            break;
        case 2:
            cout << "Ennemi defend.\n";
            J2.defendre();
            break;
        case 3:
            cout << "Capacite spe ennemi.\n";
            J2.capacite_spec(J1);
            break;
        default:
            break;
        }
        tour++;  // Incrémenter le tour après chaque tour
    }while (J1.p_pv > 0 && J2.p_pv > 0);
    if (J1.p_pv <= 0) {
        std::cout << J1.p_nom << " a ete vaincu ! " << J2.p_nom << " gagne le combat.\n";
    } else if (J2.p_pv <= 0) {
        std::cout << "Vous avez ete vaincu !\n";
}
}
int main()
{
    personnage* perso = LancerJeu();
    ennemi mechant1("Grogator",50,100,1,1,1,10,1,false);
    personnage& ref = *perso;
    lancerCombat(ref,mechant1);
    mechant1.drop_exp(ref);
    ref.aff_info();
/*  std::cout<<"Test du main";
    guerrier objet1("jean",100,100,3,1,1,1,1);
    objet1.aff_info();
    std::cout << "------------------" <<std::endl;
    ennemi objet2("grogator",100,100,1,1,1,10,1);
    objet2.aff_info();
    objet1.attaque(objet2);
    objet2.defendre();
    objet1.capacite_spe(objet2);
    std::cout << "------------------" <<std::endl;
    objet2.aff_info();
    std::cout << "------------------" <<std::endl;
    objet1.aff_info();
    objet1.lvlup();
    objet1.aff_info();
    */
    return 0;
}
