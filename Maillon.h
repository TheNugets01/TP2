/*************************************************************************
                           Maillon  -  interface de la classe Maillon
                             -------------------
    début                : 19/11/2021
    copyright            : (C) 2021 par Hugo Blaess & Octave Duvivier
    e-mail               : hugo.blaess@insa-lyon.fr & octave.duvivier@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Maillon> (fichier Maillon.h) ----------------
#if ! defined ( XXX_H )
#define XXX_H

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
    virtual ~Maillon ( );
//----------------------------------------------------------------Getteur
    Trajet * GetTrajet() const;
    Maillon * GetProchain() const;
//----------------------------------------------------------------Setteur
    void SetTrajet( Trajet * unTrajet );
    void SetProchain( Maillon * unProchain);

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
    Trajet * trajet;
    Maillon * Prochain;

};

#endif // XXX_H

