/*************************************************************************
                           ListeChainee  -  interface de la classe maillon
                             -------------------
    début                : 19/11/2021
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//----Interface de la classe <ListeChainee> (fichier ListeChainee.h) -----
#if ! defined ( LISTECHAINNEE_H )
#define LISTECHAINNEE_H

//--------------------------------------------------- Interfaces utilisées
#include "Maillon.h"
#include "Trajet.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Xxx>
//
//
//------------------------------------------------------------------------

class ListeChainee
{
public:
//--------------------------- Méthodes publiques
  void Ajouter( Trajet * contenu) ;
  void Afficher () const;

//---- Constructeurs - destructeur
  ListeChainee ( );
  virtual ~ListeChainee ( );
    
protected:
//------------ Méthodes protégées

//--- Attributs protégés
  Maillon * Debut;
  Maillon * Fin;
  int nbMaillons;

};

//------------------------ Autres définitions dépendantes de <ListeChainee>

#endif // XXX_H

