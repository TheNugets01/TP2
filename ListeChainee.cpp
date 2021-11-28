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
void ListeChainee::Ajouter(Trajet * contenu)
{
  
  if(debut == nullptr)
  {
    debut = new Maillon(contenu);
    ++nbMaillons;
  }
  else
  {
    Maillon * actuelle = debut;
    //Trie par ordre alphabetique
    if(actuelle->GetProchain() != nullptr)
    {
      cout<<"yo"<<endl;
      while ((actuelle->GetProchain()->GetDonnee()->GetVilleDepart()) >(contenu->GetVilleDepart()))
      { 
        actuelle = actuelle->GetProchain();
      }
    }


    Maillon * nouveau = new Maillon(contenu);
    nouveau->SetDonnee(contenu);
    
    Maillon * MemSuivant = actuelle->GetProchain();

    nouveau->SetProchain(MemSuivant);
    actuelle->SetProchain(nouveau);
    
    ++nbMaillons;
  }
}

void ListeChainee::Afficher ()
{
  Maillon * courant = debut;
  while( courant->GetProchain() != nullptr )
  {
    courant->GetDonnee()->Afficher();
    courant = courant->GetProchain();
  }
  courant->GetDonnee()->Afficher();
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
nbMaillons = 0;

} //----- Fin de ListeChainee


ListeChainee::~ListeChainee ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Xxx>" << endl;
#endif
delete debut; //les maillons intermediaire sont supprimé grace a ~Maillon
// delete fin; non nécessaire
} //----- Fin de ~ListeChainee


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

