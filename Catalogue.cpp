/*************************************************************************
                           Catalogue  -  implémente un Catalogue
                             -------------------
    début                : 19/11/2021
    copyright            : (C) 2021 par Hugo Blaess & Octave Duvivier
    e-mail               : hugo.blaess@insa-lyon.fr & octave.duvivier@insa-lyon.fr
*************************************************************************/

// -- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel

#include "Catalogue.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalogue::Inserer(Trajet ainserer)
{
  
}

void Catalogue::Afficher ()
{
  
}

Trajet* Catalogue::Rechercher (char * depart, char * arrivee , char * transport)
{
  
}

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue (int* parcours) : listeParcours(parcours)
// Algorithme : Initialise le Catalogue
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de maillon


Catalogue::~Catalogue ( )
// Algorithme : Détruit le Catalogue
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Maillon


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées