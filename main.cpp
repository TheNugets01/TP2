#include "ListeChainee.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include <iostream>

using namespace std;

#define TAILLEBUFFER 100



char * Saisi(  );

int main()
{
    ListeChainee * test = new ListeChainee();
    Trajet * t1 = new TrajetSimple( Saisi() , Saisi() , Saisi() );
    Trajet * t2 = new TrajetSimple( Saisi() , Saisi() , Saisi() );
    test->Ajouter(t1); 
    test->Ajouter(t2);

    // ListeChainee * test2 = new ListeChainee();
    // Trajet * t3 = new TrajetSimple("Paris","Londres","Avion");
    // Trajet * t4 = new TrajetSimple("Schweighouse","Haguenau","Train");
    // test2->Ajouter(t3);
    // test2->Ajouter(t4);

    // Trajet * t5 = new TrajetCompose("ok","oui",test2);
    // test->Ajouter(t5);
    
    test -> Afficher();

    delete test ;

    return 0;
}

char * Saisi()
{
    char nom[TAILLEBUFFER];
    cin >> nom;

    int Taille = 0;

    for(int i=0 ; nom[i] != '\0' && i < TAILLEBUFFER ; ++i)
    {
        ++Taille;
    }

    char * LeMot = new char[Taille];

    for( int i = 0 ; i < Taille ; ++i)
    {
        LeMot[i] = nom[i];
        
    }

    return LeMot;
}
