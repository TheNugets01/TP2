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

char * TrajetCompose::GetVilleDepart() const
{
  return listeTrajets->GetDebut()->GetTrajet()->GetVilleDepart();
}

char * TrajetCompose::GetVilleArrivee() const
{
  return listeTrajets->GetFin()->GetTrajet()->GetVilleArrivee();
}

void TrajetCompose::Afficher() const
{
  cout << "Trajet Composee de : " << endl;
  listeTrajets->Afficher(1);
}

void TrajetCompose::Afficher(int mode) const
{
  cout << "Trajet Composee de : " << endl;
  listeTrajets->Afficher(mode);
}

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