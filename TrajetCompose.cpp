/*************************************************************************
                           TrajetCompose  -  implemente un TrajetCompose
                             -------------------
    début                : 19/11/2021
    copyright            : (C) 2021 par Hugo Blaess & Octave Duvivier
    e-mail               : hugo.blaess@insa-lyon.fr & octave.duvivier@insa-lyon.fr
*************************************************************************/

// -- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel

#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetCompose::Afficher() const
// Algorithme : Permet d'Afficher le TrajetCompose
//
{
  cout << "Trajet Composee de : " << endl;
  listeTrajets->Afficher(1);
  cout << endl;
} //----- Fin de Afficher

void TrajetCompose::Afficher(int mode) const {}

//----------------------------------------------------------------Getteur

char * TrajetCompose::GetVilleDepart() const
// Algorithme : Permet d'accéder a la ville de depart du trajet
//
{
  #ifdef GETSET
    cout << "Appel a GetVilleDepart de <TrajetCompose>" << endl;
  #endif

  return listeTrajets->GetDebut()->GetTrajet()->GetVilleDepart();
} //----- Fin de GetVilleDepart

char * TrajetCompose::GetVilleArrivee() const
// Algorithme : Permet d'accéder a la ville d'arrive du trajet
//
{
  #ifdef GETSET
    cout << "Appel a GetVilleArrivee de <TrajetCompose>" << endl;
  #endif

  return listeTrajets->GetFin()->GetTrajet()->GetVilleArrivee();
} //----- Fin de GetVilleArrive

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose (ListeChainee * trajets)
// Algorithme : Initialise le TrajetCompose
//
{
  #ifdef MAP
      cout << "Appel au constructeur de <TrajetCompose>" << endl;
  #endif
  listeTrajets = trajets;
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme : Détruit le TrajetCompose
//
{
  #ifdef MAP
      cout << "Appel au destructeur de <TrajetCompose>" << endl;
  #endif
  delete listeTrajets;
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées