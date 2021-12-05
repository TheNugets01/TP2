/*************************************************************************
                           TrajetSimple  -  implemente un TrajetSimple
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

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetSimple::Afficher() const
// Algorithme : Permet d'afficher le contenu du trajetsimple
//
{
  cout << "Trajet Simple de : " << endl << " - " << VilleDepart << " à " << VilleArrivee << " en " << MoyenTransport << endl << endl;
} //----- Fin de Afficher

void TrajetSimple::Afficher(int mode) const
// Algorithme : Permet d'afficher le contenu du trajet simple au sein d'un trajet compose
//
{
  cout << " - " << VilleDepart << " à " << VilleArrivee << " en " << MoyenTransport << endl;
} //----- Fin de Afficher
//----------------------------------------------------------------Getteur

char * TrajetSimple::GetVilleDepart() const
// Algorithme : Permet d'accéder a la ville de depart du trajet
//
{
  return VilleDepart;
} //----- Fin de GetVilleDepart
char * TrajetSimple::GetVilleArrivee() const
// Algorithme : Permet d'accéder a la ville d'arrive du trajet
//
{
  return VilleArrivee;
} //----- Fin de GetVilleArrivee

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
