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
void ListeChainee::Ajouter( Trajet * contenu)
{
  
  if(Debut == nullptr)
  {
    Debut = new Maillon(contenu);
    ++nbMaillons;
  }
  else
  {

    Maillon * actuelle = Debut;
    //Trie par ordre alphabetique
    if( actuelle -> GetProchain() != nullptr)
    {
      cout<<"yo"<<endl;
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
    
    ++nbMaillons;
  }
}

void ListeChainee::Afficher () const
{
  Maillon * courant = Debut;
  while( courant->GetProchain() != nullptr )
  {
    courant -> GetTrajet()->Afficher();
    courant = courant->GetProchain();
  }
  courant->GetTrajet()->Afficher();
}

//---------------------------- Constructeurs - destructeur
ListeChainee::ListeChainee ( )
// Algorithme :
//
{
  #ifdef MAP
      cout << "Appel au constructeur de <ListeChainee>" << endl;
  #endif

  Debut = nullptr;
  nbMaillons = 0;

} //----- Fin de ListeChainee


ListeChainee::~ListeChainee ( )
// Algorithme :
//
{
  #ifdef MAP
      cout << "Appel au destructeur de <ListeChainee>" << endl;
  #endif

  delete Debut; //les maillons intermediaire sont supprimé grace a ~Maillon

} //----- Fin de ~ListeChainee


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

