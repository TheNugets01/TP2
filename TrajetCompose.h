/*************************************************************************
                           TrajetCompose  -  interface de la classe TrajetCompose
                             -------------------
    début                : 19/11/2021
    copyright            : (C) 2021 par Hugo Blaess & Octave Duvivier
    e-mail               : hugo.blaess@insa-lyon.fr & octave.duvivier@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées

#include "Trajet.h"
#include "ListeChainee.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//
// TrajetCompose sert à implémenter un TrajetCompose
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void Afficher() const;
    void Afficher(int mode) const;
    char * GetVilleDepart() const; //pas sur d'en avoir besoin
    char * GetVilleArrivee() const;

//-------------------------------------------- Constructeurs - destructeur

    TrajetCompose (ListeChainee * trajets);
    // Mode d'emploi : Donne en paramètre le contenu du TrajetCompose 
    //
    // Contrat :
    // Créer le TrajetCompose

    virtual ~TrajetCompose ( );
    // Mode d'emploi :
    //
    // Contrat :
    // Détruit le TrajetCompose

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    ListeChainee * listeTrajets;
};

#endif // TrajetCompose_H

