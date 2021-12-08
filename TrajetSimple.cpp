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

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetSimple::Afficher() const
{
  cout << "Trajet Simple de : " << villeDepart << ", jusqu'a " << villeArrivee << " en utilisant le " << moyenTransport << endl;
}

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple (const char* depart, const char* arrivee, const char* transport) : Trajet(depart,arrivee)
// Algorithme : Initialise le TrajetSimple
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif

  //Evite le Segmentation Fault car char * moyenTransport initialement aléatoire
  char Transport[sizeof(transport)];
  moyenTransport = Transport;
  
  for(int i=0; i < sizeof(transport) ; ++i)
    moyenTransport[i] = transport[i];
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
// Algorithme : Détruit le TrajetSimple
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées