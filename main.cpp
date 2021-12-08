#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include <iostream>
#include <cstring>

using namespace std;

#define TAILLEBUFFER 100
#define VIDEBUFFERCLAVIER() char ch; while( (ch = getchar() != '\n') && ch != EOF );

char * Saisi(); //Extension de la portée sinon double definition
void Menu(Catalogue * catalogue);

int main()
{
    cout << "----- Bienvenue dans notre Agence de Voyage -----" << endl << endl;
    Catalogue * notreCatalogue = new Catalogue();
    Menu(notreCatalogue);
    
    delete notreCatalogue;

    return 0;
}

char * Saisi( )
// Algorithme : Permet de saisir une chaine de caractère au clavier et de la ranger dans une zone alloué dynamiquement
{
    char unMot[TAILLEBUFFER];
    cin >> unMot;

    char * leMot = new char[strlen(unMot)+1];
    strcpy( leMot , unMot );
    
    if(strcmp(leMot,"-1") != 0)
    {
        VIDEBUFFERCLAVIER();
    }
    
    return leMot;
} //----- Fin de Saisi

void Menu(Catalogue * catalogue)
// Algorithme : Permet d'afficher le menu et de gerer les interactions avec l'utilisateur
//
{   
    char lecture;
    cout << "Veuillez choisir une Action :" << endl;
    cout << "- 1 : Ajouter un trajet au catalogue" << endl;
    cout << "- 2 : Afficher le catalogue" << endl;
    cout << "- 3 : Rechercher dans le cataloge " << endl;
    cout << "- q : Quitter" << endl << ">> ";
    cin >> lecture;
    while (lecture != 'q')
    {
        if (lecture== '1')
        {
            VIDEBUFFERCLAVIER();
            bool estTC = false;
            ListeChainee * tc;
            cout << "Veuillez indiquez votre Ville de depart" << endl << ">> ";
            char * depart = Saisi();
            cout << "Quel est la prochaine destination ?" << endl << ">> ";
            char * arrive = Saisi();
            cout << "Par quel moyen de transport ?" << endl << ">> ";
            char * transport = Saisi();
            Trajet * t1 = new TrajetSimple(depart,arrive,transport);
            cout << "Quel est la prochaine destination ? (Si Fini tapez -1)" << endl << ">> ";
            depart = new char[ strlen(arrive) + 1 ];
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
                cout << "Par quel moyen de transport ?" << endl << ">> ";
                transport = Saisi();
                tc->AjouterFin( new TrajetSimple(depart,arrive,transport) );
                cout << "Quel est la prochaine destination ? (Si Fini tapez -1)" << endl << ">> ";
                depart = new char[ strlen(arrive) + 1 ];
                strcpy(depart,arrive);
                arrive = Saisi();
            }

            if(!estTC)
            {
                catalogue->Inserer(t1);
            }
            else
            {
                catalogue->Inserer(new TrajetCompose(tc));
            }

            delete[] arrive;
            delete[] depart;
        }
        else if (lecture== '2')
        {
            if( catalogue->GetListeParcours()->GetDebut() != nullptr)
            {
                VIDEBUFFERCLAVIER();
                catalogue -> Afficher();
                cout << endl;
                cout << "Pour retourner au menu entrez un charactere" << endl << ">> ";
                char c;
                cin >> c;
            }
            else
            {
                cout << "Votre Catalogue est vide" << endl;
            }
        }
        else if (lecture== '3')
        {
            if( catalogue->GetListeParcours()->GetDebut() != nullptr)
            {
                VIDEBUFFERCLAVIER();

                cout << "D'ou voulez vous partir ?" << endl << ">> ";
                const char * unDepart = Saisi();
                cout << "Pour arriver ou ?" << endl << ">> ";
                const char * uneArrivee = Saisi();

                catalogue -> Rechercher( unDepart , uneArrivee );
                cout << endl;
                cout << "Pour retourner au menu entrez un charactere" << endl << ">> ";
                char c;
                cin >> c;
            }
            else
            {
                cout << "Votre Catalogue est vide" << endl;
            }
        }
        else
        {
            cout << "Je n'ai pas compris veuillez recommencer !" << endl;
        }

        VIDEBUFFERCLAVIER();
        cout << endl << "Veuillez choisir une Action :" << endl;
        cout << "- 1 : Ajouter un trajet au catalogue" << endl;
        cout << "- 2 : Afficher le catalogue" << endl;
        cout << "- 3 : Rechercher dans le cataloge " << endl;
        cout << "- q : Quitter" << endl << ">> ";
        cin >> lecture;
    }
} //----- Fin de Menu