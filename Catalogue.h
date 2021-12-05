/*************************************************************************
                           Catalogue  -  interface de la classe Catalogue
                             -------------------
    début                : 19/11/2021
    copyright            : (C) 2021 par Hugo Blaess & Octave Duvivier
    e-mail               : hugo.blaess@insa-lyon.fr & octave.duvivier@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées

#include "ListeChainee.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
// Catalogue sert à implémenter un Catalogue
//
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Inserer(Trajet * unTrajet);
    // Mode d'emploi :
    //
    // Contrat :
    // Permet d'inserer un trajet au catalogue
    void Afficher () const ;
    // Mode d'emploi :
    //
    // Contrat :
    // Permet d'afficher le contenu du catalogue
    void Rechercher (char * depart, char * arrivee);
    // Mode d'emploi :
    //
    // Contrat :
    // Permet de chercher un trajet



//-------------------------------------------- Constructeurs - destructeur

    Catalogue ();
    // Mode d'emploi : Donne en paramètre le contenu du Catalogue 
    //
    // Contrat :
    // Créer le Catalogue

    virtual ~Catalogue ( );
    // Mode d'emploi :
    //
    // Contrat :
    // Détruit le Catalogue

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    ListeChainee * listeParcours;
};

#endif // CATALOGUE_H

