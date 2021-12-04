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
Trajet * Maillon::GetTrajet() const
{
  return trajet;
}

Maillon * Maillon::GetProchain() const
{
  return Prochain;
}

void Maillon::SetTrajet( Trajet * unTrajet )
{
  trajet = unTrajet;
}

void Maillon::SetProchain( Maillon* unProchain )
{
  Prochain = unProchain;
}

//-------------------------------------------- Constructeurs - destructeur
Maillon::Maillon ( Trajet * contenu) : trajet(contenu),Prochain(nullptr)
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

  if ( Prochain != nullptr )
  {
    delete Prochain;
  }
    delete trajet;
  
} //----- Fin de ~Maillon


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
