/*************************************************************************
                           ListeChainee  -  Interface de la classe ListeChainee
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

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ListeChainee>
//  Implemente la liste chainee avec pointeur de debut et de fin
//  Utile pour creer des trajets compose et le catalogue
//------------------------------------------------------------------------

class ListeChainee
{
public:
//--------------------------- Méthodes publiques
    void AjouterTri( Trajet * contenu);
    // Mode d'emploi :
    //
    // Contrat :
    //
    void AjouterFin( Trajet * contenu);
    // Mode d'emploi :
    //
    // Contrat :
    //
    void Afficher ( int mode = 0 ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //
//----------------------------------------------------------------Getteur
    Maillon * GetDebut() const;
    // Mode d'emploi :
    //
    // Contrat :
    //
    Maillon * GetFin() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    int GetNbMaillon() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

//---- Constructeurs - destructeur
    ListeChainee ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    virtual ~ListeChainee ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

protected:
//------------ Méthodes protégées

//--- Attributs protégés
  Maillon * debut;
  Maillon * fin;
  int nbMaillon;

};

//------------------------ Autres définitions dépendantes de <ListeChainee>

#endif // LISTECHAINEE_H

