/*************************************************************************
                           ListeChainee  -  implemente une liste chainee
                             -------------------
    début                : 19/11/2021
    copyright            : 2021 par Hugo Blaess & Octave Duvivier
    e-mail               : hugo.blaess@insa-lyon.fr & octave.duvivier@insa-lyon.fr
*************************************************************************/

// -- Réalisation de la classe <ListeChainee> (fichier ListeChainee.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ListeChainee.h"
//--------------------------------------------------------------Constantes

//------------------------------------------------------------------PUBLIC

//----------------------------------------------------- Méthodes publiques
void NouveauEnSuite(  Trajet * contenu , Maillon * actuelle ) //explication 
{
  Maillon * nouveau = new Maillon(contenu);
  nouveau -> SetTrajet(contenu);
  
  Maillon * MemSuivant = actuelle->GetProchain();

  nouveau -> SetProchain( MemSuivant );
  actuelle -> SetProchain( nouveau );
}

Maillon * NouveauEnDebut( Trajet * contenu , Maillon * actuelle ,  Maillon * debut ) // explication
{
  Maillon * nouveau = new Maillon(contenu);
  nouveau -> SetTrajet(contenu);
  nouveau -> SetProchain(actuelle);
  return debut = nouveau;
}

Maillon * ListeChainee::GetDebut() const
{
  return debut;
} //----- Fin de GetDebut

Maillon * ListeChainee::GetFin() const
{
  return fin;
} //----- Fin de GetFin

void ListeChainee::AjouterTri( Trajet * contenu)
// Algorithme : Permet d'ajouter un trajet à la liste en triant d'abord par ordre alphabétique de la ville de depart puis d'arrivée
//
{
  #ifdef MAP
      cout << "Appel a la fonction AjouterTri de <ListeChainee>" << endl;
  #endif

  if(debut == nullptr)
  //Si la chaine est vide
  {
    debut = new Maillon(contenu);
  }
  else if( debut->GetProchain() == nullptr )
  //Si il n'y a qu'un seul Maillon
  {
    Maillon * actuelle = debut;

    if( strcmp( actuelle->GetTrajet()->GetVilleDepart() ,  contenu->GetVilleDepart()) > 0 )
    //Si l'ajout se trie avant le debut par rapport a la ville de depart
    {
      debut = NouveauEnDebut(contenu , actuelle , debut );
    }
    else if( strcmp(actuelle->GetTrajet()->GetVilleDepart(), contenu->GetVilleDepart()) == 0 && strcmp(actuelle->GetTrajet()->GetVilleArrivee() , contenu->GetVilleArrivee()) > 0)
    //Si l'ajout se trie avant le debut par rapport a la ville d'arrivée
    {
      debut = NouveauEnDebut(contenu , actuelle , debut );
    }
    else
    {
      NouveauEnSuite( contenu , actuelle );
    }
  }
  else
  {
    Maillon * actuelle = debut;
    while ( actuelle -> GetProchain() != nullptr && ( strcmp(actuelle->GetProchain()->GetTrajet()->GetVilleDepart() , contenu->GetVilleDepart()) < 0 ) )
    //Positionement par rapport a la ville de depart
    { 
      actuelle = actuelle -> GetProchain();
    }

    if( strcmp(actuelle->GetProchain()->GetTrajet()->GetVilleDepart() , contenu->GetVilleDepart()) == 0 )
    //Si depart identique
    {
      while( actuelle -> GetProchain() != nullptr && ( strcmp(actuelle->GetProchain()->GetTrajet()->GetVilleArrivee() , contenu->GetVilleArrivee()) < 0 ) )
      //Positionement par rapport a la ville d'arrivée
      { 
        actuelle = actuelle -> GetProchain();
      }
    }

    if(debut == actuelle)
    //Si l'ajout se trie avant le debut
    {
      debut = NouveauEnDebut(contenu , actuelle , debut );
    }
    else
    {
      NouveauEnSuite( contenu , actuelle );
    }
  }
} //----- Fin de AjouterTri

void ListeChainee::AjouterFin( Trajet * contenu)
{
  #ifdef MAP
      cout << "Appel a la fonction AjouterFin de <ListeChainee>" << endl;
  #endif
  
  if(debut == nullptr) // Si liste vide on place le nouveau maillon en debut et fin
  {
    debut = new Maillon(contenu);
    fin = debut;
  }
  else // Sinon on le place en fin de liste
  {
    Maillon * nouveau = new Maillon(contenu);
    fin -> SetProchain( nouveau );
    fin = nouveau;
  }
} //----- Fin de AjouterFin

void ListeChainee::Afficher () const
{
  #ifdef MAP
      cout << "Appel a la fonction Afficher() de <ListeChainee>" << endl;
  #endif

  Maillon * courant = debut;
  while( courant->GetProchain() != nullptr )
  {
    courant -> GetTrajet()->Afficher();
    courant = courant->GetProchain();
  }
  courant->GetTrajet()->Afficher();
} //----- Fin de Afficher

void ListeChainee::Afficher (int mode) const
{
  #ifdef MAP
      cout << "Appel a la fonction Afficher(int) de <ListeChainee>" << endl;
  #endif

  Maillon * courant = debut;
  while( courant->GetProchain() != nullptr )
  {
    courant -> GetTrajet()->Afficher(mode);
    courant = courant->GetProchain();
  }
  courant->GetTrajet()->Afficher(mode);
} //----- Fin de Afficher

//---------------------------- Constructeurs - destructeur
ListeChainee::ListeChainee ( )
{
  #ifdef MAP
      cout << "Appel au constructeur de <ListeChainee>" << endl;
  #endif

  debut = nullptr;
  fin = debut;

} //----- Fin de ListeChainee


ListeChainee::~ListeChainee ( )
{
  #ifdef MAP
      cout << "Appel au destructeur de <ListeChainee>" << endl;
  #endif

  delete debut; // Detruit le premier maillon de la liste (les autres seront detruit en cascade par ~Maillon)
} //----- Fin de ~ListeChainee


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

