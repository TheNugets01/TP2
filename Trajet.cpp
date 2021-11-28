/*************************************************************************
                           Trajet  -  implémente un Trajet
                             -------------------
    début                : 19/11/2021
    copyright            : (C) 2021 par Hugo Blaess & Octave Duvivier
    e-mail               : hugo.blaess@insa-lyon.fr & octave.duvivier@insa-lyon.fr
*************************************************************************/

// -- Réalisation de la classe <Trajet> (fichier Trajet.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel

#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
char * Trajet::GetVilleDepart()
{
  return villeDepart;
}
char * Trajet::GetVilleArrivee()
{
  return villeArrivee;
}

//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet ( const char* depart, const char* arrivee)
// Algorithme : Initialise le Trajet
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif

  //Evite le Segmentation Fault car villeDepart et villeArrivee initialement aléatoire
  char Depart[sizeof(depart)];
  char Arrivee[sizeof(arrivee)];
  villeDepart = Depart;
  villeArrivee = Arrivee;

  
  for (int i; i < sizeof(depart) ;++i)
    villeDepart[i]=depart[i];

  for (int i; i< sizeof(arrivee) ;++i)
    villeArrivee[i]=arrivee[i];
} //----- Fin de maillon


Trajet::~Trajet ( )
// Algorithme : Détruit le Trajet
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
} //----- Fin de ~Maillon


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées