/*************************************************************************
                           TrajetSimple  -  interface de la classe TrajetSimple
                             -------------------
    début                : 19/11/2021
    copyright            : (C) 2021 par Hugo Blaess & Octave Duvivier
    e-mail               : hugo.blaess@insa-lyon.fr & octave.duvivier@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées

#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Afficher( int mode = 0) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

//----------------------------------------------------------------Getteur

    char * GetVilleDepart() const;
    // Mode d'emploi :
    //
    // Contrat :
    //
    char * GetVilleArrivee() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    
    TrajetSimple (char * unDepart, char * uneArrivee, char * unTransport);
    // Mode d'emploi :
    //
    // Contrat :
    //
    virtual ~TrajetSimple ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
char * VilleArrivee;
char * VilleDepart;
char * MoyenTransport;
};

#endif // TRAJETSIMPLE_H

