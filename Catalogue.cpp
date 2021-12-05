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

void Catalogue::Inserer(Trajet * ainserer)
// Algorithme : Permet d'inserer un trajet au catalogue !!(pour l'instant en fin)!!
//
{
    listeParcours->AjouterFin(ainserer);
} //----- Fin de Inserer

void Catalogue::Afficher () const
// Algorithme : Permet d'Afficher le contenu du Catalogue
//
{
    cout << "Voici notre Catalogue de Trajets :" << endl;
    listeParcours->Afficher();
} //----- Fin de Afficher

void Catalogue::Rechercher (char * unDepart, char * uneArrivee)
// Algorithme : Permet de rechercher un trajet dans le catalogue 
//
{
    cout << "Vous voulez voyager entre " << unDepart << " et " << uneArrivee <<  ", Voila nos propositions :" << endl;
    Trajet * temp;
    Maillon * courant = listeParcours->GetDebut();
  while( courant->GetProchain() != nullptr )
  {
    temp = courant -> GetTrajet();
    if(strcmp(temp->GetVilleDepart(),unDepart)==0 && strcmp(temp->GetVilleArrivee(),uneArrivee)==0)
    {
        temp->Afficher();
    }
    courant = courant->GetProchain();
  }
  temp = courant -> GetTrajet();
    if(strcmp(temp->GetVilleDepart(),unDepart)==0 && strcmp(temp->GetVilleArrivee(),uneArrivee)==0)
    {
        temp->Afficher();
    }
} //----- Fin de Rechercher

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ()
// Algorithme : Initialise le Catalogue en creeant la liste chainee
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
listeParcours = new ListeChainee();
} 

//----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme : Détruit le Catalogue 
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
delete listeParcours; // Son contenu est detruit en cascade par les autres destructeurs
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées