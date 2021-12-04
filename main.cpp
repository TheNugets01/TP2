#include "ListeChainee.h"
#include "Trajet.h"
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include <iostream>
#include <cstring>

using namespace std;

#define TAILLEBUFFER 100



char * Saisi(  );
void Menu(Catalogue * catalogue);

int main()
{
    cout << "Bienvenue dans notre Agence de Voyage" << endl;
    Catalogue * notreCatalogue = new Catalogue();
    Menu(notreCatalogue);
    /*Trajet * t1 = new TrajetSimple( Saisi() , Saisi() , Saisi() );
    Trajet * t2 = new TrajetSimple( Saisi(), Saisi() , Saisi() );
    notreCatalogue->Inserer(t1); 
    notreCatalogue->Inserer(t2);

    ListeChainee * test2 = new ListeChainee();
    Trajet * t3 = new TrajetSimple(Saisi() , Saisi() , Saisi());
    Trajet * t4 = new TrajetSimple(Saisi() , Saisi() , Saisi());
    test2->AjouterFin(t3);
    test2->AjouterFin(t4);

    Trajet * t5 = new TrajetCompose(test2);
    notreCatalogue->Inserer(t5);
    
    notreCatalogue -> Afficher();
    notreCatalogue -> Rechercher("a" , "z");*/
    delete notreCatalogue;

    return 0;
}

char * Saisi( )
{
    //char * unMot = "LA";
    char unMot[TAILLEBUFFER];
    cin >> unMot;

    char * LeMot = new char[strlen(unMot)];

    for( int i = 0 ; i < int(strlen(unMot)) ; ++i)
    {
        LeMot[i] = unMot[i]; // ya strcpy aussi je crois
    }

    return LeMot;
}

void Menu(Catalogue * catalogue)
{
    cout << "Veuillez choisir une Action :" << endl;
    cout << "1 : Ajouter un trajet au catalogue" << endl;
    cout << "2 : Afficher le catalogue" << endl;
    cout << "3 : Rechercher dans le cataloge " << endl;
    cout << "4 : Quitter" << endl;
    int lecture;
    cin >> lecture;
    while (lecture!=4)
    {
        if (lecture==1) // Desfois quand on affiche les trajets il affiche des caractères chelou jsp pk surement un problème d'accès a la mémoire 
        {
            bool estTC = false;
            ListeChainee * tc;
            cout << "Veuillez indiquez votre Ville de depart" << endl;
            char * depart = Saisi();
            cout << "Quel est la prochaine destination ?" << endl;
            char * arrive = Saisi();
            cout << "Par quel moyen de transport ?" << endl;
            char * transport = Saisi();
            Trajet * t1 = new TrajetSimple(depart,arrive,transport);
            cout << "Quel est la prochaine destination ? (Si Fini tapez -1)" << endl;
            depart = new char[strlen(arrive)];
            strcpy(depart,arrive);
            arrive = Saisi();

            while(strcmp(arrive,"-1")!=0)
            {
                if(!estTC)
                {
                    tc = new ListeChainee();
                    tc->AjouterFin(t1);
                    estTC = true;
                }
                cout << "Par quel moyen de transport ?" << endl;
                transport = Saisi();
                tc->AjouterFin(new TrajetSimple(depart,arrive,transport));
                cout << "Quel est la prochaine destination ? (Si Fini tapez -1)" << endl;
                depart = new char[strlen(arrive)];
                strcpy(depart,arrive);
                arrive = Saisi();
            }
            if(!estTC)
                catalogue->Inserer(t1);
            else
                catalogue->Inserer(new TrajetCompose(tc));
            delete[] arrive;
            delete[] depart;
        }
        else if (lecture==2)
        {
            catalogue -> Afficher();
            cout << endl;
            cout << "Pour retourner au menu tapez un chiffre" << endl;
            int c;
            cin >> c;
        }
        else if (lecture==3)
        {
            cout << "D'ou voulez vous partir ?" << endl;
            char * depart = Saisi(); // Attention on ne delete jamais la Saisi !!! ////!!!\\\\\ Perte de mémoire
            cout << "Pour arriver ou ?" << endl;
            char * arrive = Saisi(); // Attention on ne delete jamais la Saisi !!! ////!!!\\\\\ Perte de mémoire
            catalogue -> Rechercher(depart,arrive);
            cout << endl;
            cout << "Pour retourner au menu tapez un chiffre" << endl;
            int c;
            cin >> c;
        }
        else
        {
            cout << "Je n'ai pas compris veuillez recommencer !" << endl;
        }
        cout << "Veuillez choisir une Action :" << endl;
        cout << "1 : Ajouter un trajet au catalogue" << endl;
        cout << "2 : Afficher le catalogue" << endl;
        cout << "3 : Rechercher dans le cataloge " << endl;
        cout << "4 : Quitter" << endl;
        cin >> lecture;
    }
}