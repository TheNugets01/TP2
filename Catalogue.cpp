/*************************************************************************
                           Catalogue  -  implemente un Catalogue
                             -------------------
    début                : 19/11/2021
    copyright            : (C) 2021 par Hugo Blaess & Octave Duvivier
    e-mail               : hugo.blaess@insa-lyon.fr & octave.duvivier@insa-lyon.fr
*************************************************************************/

// -- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel

#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalogue::Inserer( Trajet * aInserer)
{
    listeParcours->AjouterTri(aInserer);
} //----- Fin de Inserer

void Catalogue::Afficher () const
{
    cout << "Voici notre Catalogue de Trajets :" << endl;
    listeParcours->Afficher();
} //----- Fin de Afficher

void Catalogue::Rechercher ( const char * unDepart, const char * uneArrivee)
// On parcourt la liste de trajet et on verifie si le depart et l'arrivee correspondent a ceux passe en parametre
//
{
    if( listeParcours->GetDebut() != nullptr )
    // verifie que la liste n'est pas vide
    {
        bool Affichage = false; // permet d'afficher la bonne phrase d'intro et qu'une seule fois
        const Trajet * temp;
        Maillon * courant = listeParcours->GetDebut();
    
        while( courant != nullptr )
        {
            temp = courant -> GetTrajet();
            if(strcmp(temp->GetVilleDepart() , unDepart) == 0 && strcmp( temp->GetVilleArrivee() , uneArrivee ) == 0 )
            {
                if(Affichage == false)
                {
                    cout << "Vous voulez voyager entre " << unDepart << " et " << uneArrivee <<  ", Voila nos propositions :" << endl;
                    Affichage = true;
                }

                temp->Afficher();
            }
            courant = courant->GetProchain();
        }

        if( Affichage == false )
        {
            cout << "Nous n'avons pas trouvé de trajet corespondant dans le catalogue" << endl;
        }

        delete[] unDepart; // Il faut detruite les pointeurs que l'on a creer lors de la saisie
        delete[] uneArrivee;
    }
    else
    {
        cout << "Votre Catalogue est vide" << endl;

        delete[] unDepart; // idem dessus
        delete[] uneArrivee;
    }
} //----- Fin de Rechercher

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ()
{
    #ifdef MAP
        cout << "Appel au constructeur de <Catalogue>" << endl;
    #endif

    listeParcours = new ListeChainee();
} 

//----- Fin de Catalogue


Catalogue::~Catalogue ( )
{
    #ifdef MAP
        cout << "Appel au destructeur de <Catalogue>" << endl;
    #endif

    delete listeParcours; // Son contenu est detruit en cascade par les autres destructeurs
} //----- Fin de ~Catalogue

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées