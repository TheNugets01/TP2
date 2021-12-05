/*************************************************************************
                           Maillon  -  interface de la classe Maillon
                             -------------------
    début                : 19/11/2021
    copyright            : (C) 2021 par Hugo Blaess & Octave Duvivier
    e-mail               : hugo.blaess@insa-lyon.fr & octave.duvivier@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Maillon> (fichier Maillon.h) ----------------
#if ! defined ( MAILLON_H )
#define MAILLON_H

//--------------------------------------------------- Interfaces utilisées

#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
// Rôle de la classe <Maillon>
//
// Maillon sert à implémenter la liste chainee

class Maillon
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
//-------------------------------------------- Constructeurs - destructeur
    Maillon ( Trajet * contenu);
    // Mode d'emploi :
    //
    // Contrat :
    //
    virtual ~Maillon ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
//----------------------------------------------------------------Getteur
    const Trajet * GetTrajet() const;
    // Mode d'emploi :
    //
    // Contrat :
    //
    Maillon * GetProchain() const;
    // Mode d'emploi :
    //
    // Contrat :
    //
//----------------------------------------------------------------Setteur
    void SetTrajet( Trajet * unTrajet );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void SetProchain( Maillon * unProchain);
    // Mode d'emploi :
    //
    // Contrat :
    //

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
    const Trajet * trajet;
    Maillon * prochain;

};

#endif // MAILLON_H

