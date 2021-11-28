/*************************************************************************
                           Maillon  -  implémente le Maillon d'une liste chainée
                             -------------------
    début                : 19/11/2021
    copyright            : (C) 2021 par Hugo Blaess & Octave Duvivier
    e-mail               : hugo.blaess@insa-lyon.fr & octave.duvivier@insa-lyon.fr
*************************************************************************/

// -- Réalisation de la classe <Maillon> (fichier Maillon.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Maillon.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
Trajet * Maillon::GetDonnee()
{
  return donnee;
}

Maillon * Maillon::GetProchain()
{
  return prochain;
}

void Maillon::SetDonnee( Trajet * uneDonnee )
{
  donnee = uneDonnee;
}

void Maillon::SetProchain( Maillon* unProchain )
{
  prochain = unProchain;
}

//-------------------------------------------- Constructeurs - destructeur
Maillon::Maillon (Trajet * contenu) : donnee(contenu),prochain(nullptr)
// Algorithme : Initialise le maillon avec la donnée et sans maillon suivant
//
{
  #ifdef MAP
      cout << "Appel au constructeur de <Maillon>" << endl;
  #endif
} //----- Fin de maillon


Maillon::~Maillon ( )
// Algorithme : Détruit le Maillon
//
{
  #ifdef MAP
      cout << "Appel au destructeur de <Maillon>" << endl;
  #endif

  if ( prochain != nullptr )
  {
    delete ( prochain );
  }
} //----- Fin de ~Maillon


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
