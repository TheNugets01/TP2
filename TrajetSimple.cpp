/*************************************************************************
                           TrajetSimple  -  implémente un TrajetSimple
                             -------------------
    début                : 19/11/2021
    copyright            : (C) 2021 par Hugo Blaess & Octave Duvivier
    e-mail               : hugo.blaess@insa-lyon.fr & octave.duvivier@insa-lyon.fr
*************************************************************************/

// -- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel

#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

// #define MAP

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
char * TrajetSimple::GetVilleDepart() const
{
  return VilleDepart;
}

char * TrajetSimple::GetVilleArrivee() const
{
  return VilleArrivee;
}

void TrajetSimple::Afficher() const
{
  cout << "Trajet Simple de : " << VilleDepart << " à " << VilleArrivee << " en " << MoyenTransport << endl;
}

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple (char * unDepart, char * uneArrivee, char * unTransport)
// Algorithme : Initialise le TrajetSimple
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
  VilleDepart = unDepart;
  VilleArrivee = uneArrivee;
  MoyenTransport = unTransport;
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
// Algorithme : Détruit le TrajetSimple
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif

  delete[] VilleDepart;
  delete[] VilleArrivee;
  delete[] MoyenTransport;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
