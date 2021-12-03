/*************************************************************************
                           TrajetCompose  -  implémente un TrajetCompose
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

char * TrajetCompose::GetVilleDepart() const //pas sur d'en avoir besoin
{
  return listeTrajets->GetDebut()->GetTrajet()->GetVilleDepart();
}
  
char * TrajetCompose::GetVilleArrivee() const{}

void TrajetCompose::Afficher() const
{
  cout << "Trajet Composee de : " << endl;
  //listeTrajets->Afficher();
}

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose (ListeChainee * trajets) : listeTrajets(trajets)
// Algorithme : Initialise le TrajetCompose
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme : Détruit le TrajetCompose
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
delete[] listeTrajets;
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées