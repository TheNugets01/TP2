/*************************************************************************
                           ListeChainee  -  implémente une liste chainée
                             -------------------
    début                : 19/11/2021
    copyright            : 2021 par Hugo Blaess & Octave Duvivier
    e-mail               : hugo.blaess@insa-lyon.fr & octave.duvivier@insa-lyon.fr
*************************************************************************/

// -- Réalisation de la classe <ListeChainee> (fichier ListeChainee.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ListeChainee.h"
#include "Maillon.h"
#include "Trajet.h"
//--------------------------------------------------------------Constantes

//------------------------------------------------------------------PUBLIC

//----------------------------------------------------- Méthodes publiques
Maillon * ListeChainee::GetDebut() const
{
  return debut;
}

Maillon * ListeChainee::GetFin() const
{
  return fin;
}

void ListeChainee::AjouterTri( Trajet * contenu)
{
  
  if(debut == nullptr)
  {
    debut = new Maillon(contenu);
  }
  else
  {

    Maillon * actuelle = debut;
    //Trie par ordre alphabetique
    if( actuelle -> GetProchain() != nullptr)
    {
      while ( ( actuelle->GetProchain()->GetTrajet()->GetVilleDepart() )[0] < (contenu->GetVilleDepart())[0] )
      { 
        actuelle = actuelle -> GetProchain();
      }
    }


    Maillon * nouveau = new Maillon(contenu);
    nouveau -> SetTrajet(contenu);
    
    Maillon * MemSuivant = actuelle->GetProchain();

    nouveau -> SetProchain( MemSuivant );
    actuelle -> SetProchain( nouveau );
  }
}

void ListeChainee::AjouterFin( Trajet * contenu)
{
  
  if(debut == nullptr)
  {
    debut = new Maillon(contenu);
    fin = debut;
  }
  else
  {
    Maillon * nouveau = new Maillon(contenu);
    fin -> SetProchain( nouveau );
    fin = nouveau;
  }
}

void ListeChainee::Afficher () const
{
  Maillon * courant = debut;
  while( courant->GetProchain() != nullptr )
  {
    courant -> GetTrajet()->Afficher();
    courant = courant->GetProchain();
  }
  courant->GetTrajet()->Afficher();
}

void ListeChainee::Afficher (int mode) const
{
  Maillon * courant = debut;
  while( courant->GetProchain() != nullptr )
  {
    courant -> GetTrajet()->Afficher(mode);
    courant = courant->GetProchain();
  }
  courant->GetTrajet()->Afficher(mode);
}

//---------------------------- Constructeurs - destructeur
ListeChainee::ListeChainee ( )
// Algorithme :
//
{
  #ifdef MAP
      cout << "Appel au constructeur de <ListeChainee>" << endl;
  #endif

  debut = nullptr;
  fin = debut;

} //----- Fin de ListeChainee


ListeChainee::~ListeChainee ( )
// Algorithme :
//
{
  #ifdef MAP
      cout << "Appel au destructeur de <ListeChainee>" << endl;
  #endif

  delete debut; //les maillons intermediaire sont supprimé grace a ~Maillon -> pas de delete fin
} //----- Fin de ~ListeChainee


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

