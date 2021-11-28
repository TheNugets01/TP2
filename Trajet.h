/*************************************************************************
                           Trajet  -  interface de la classe Trajet
                             -------------------
    début                : 19/11/2021
    copyright            : (C) 2021 par Hugo Blaess & Octave Duvivier
    e-mail               : hugo.blaess@insa-lyon.fr & octave.duvivier@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
// Trajet sert à implémenter un Trajet
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
  virtual void Afficher() const =0;

  char * GetVilleDepart();
  char * GetVilleArrivee();


//-------------------------------------------- Constructeurs - destructeur

  Trajet ( const char* depart, const char* arrivee);

  virtual ~Trajet ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
char * villeDepart ;
char * villeArrivee;
};

#endif // TRAJET_H

