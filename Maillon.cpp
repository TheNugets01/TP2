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

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
Trajet * Maillon::GetTrajet() const
// Algorithme : Permet d'accéder au trajet contenu par le maillon
//
{
  return trajet;
} //----- Fin de GetTrajet

Maillon * Maillon::GetProchain() const
// Algorithme : Permet d'accéder au prochain maillon de la chaine
//
{
  return Prochain;
} //----- Fin de GetProchain

void Maillon::SetTrajet( Trajet * unTrajet )
// Algorithme : Permet de modifier le trajet contenu par le maillon
//
{
  trajet = unTrajet;
} //----- Fin de SetTrajet

void Maillon::SetProchain( Maillon* unProchain )
// Algorithme : Permet de modifier le prochain maillon de la chaine
//
{
  Prochain = unProchain;
} //----- Fin de SetProchain

//-------------------------------------------- Constructeurs - destructeur
Maillon::Maillon ( Trajet * contenu) : trajet(contenu),Prochain(nullptr)
// Algorithme : Initialise le maillon avec la donnée et sans maillon suivant
//
{
  #ifdef MAP
      cout << "Appel au constructeur de <Maillon>" << endl;
  #endif
} //----- Fin de Maillon


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
