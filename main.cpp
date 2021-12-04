#include "ListeChainee.h"
#include "Trajet.h"
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include <iostream>
#include <cstring>

using namespace std;

#define TAILLEBUFFER 100



char * Saisi(  );

int main()
{
    Catalogue * notreCatalogue = new Catalogue();
    Trajet * t1 = new TrajetSimple( Saisi() , Saisi() , Saisi() );
    Trajet * t2 = new TrajetSimple( Saisi(), Saisi() , Saisi() );
    notreCatalogue->Inserer(t1); 
    notreCatalogue->Inserer(t2);

    ListeChainee * test2 = new ListeChainee();
    Trajet * t3 = new TrajetSimple(Saisi() , Saisi() , Saisi());
    Trajet * t4 = new TrajetSimple(Saisi() , Saisi() , Saisi());
    test2->AjouterFin(t3);
    test2->AjouterFin(t4);

    Trajet * t5 = new TrajetCompose(test2);
    notreCatalogue->Inserer(t5);
    
    notreCatalogue -> Afficher();
    notreCatalogue -> Rechercher(Saisi() , Saisi());
    delete notreCatalogue ;

    return 0;
}

char * Saisi( )
{
    //char * unMot = "LA";
    char unMot[TAILLEBUFFER];
    cin >> unMot;

    char * LeMot = new char[strlen(unMot)];

    for( int i = 0 ; i < int(strlen(unMot)) ; ++i)
    {
        LeMot[i] = unMot[i];
    }

    return LeMot;
}