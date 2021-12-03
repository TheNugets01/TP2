#include "ListeChainee.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include <iostream>
#include <cstring>

using namespace std;

#define TAILLEBUFFER 100



char * Saisi(  );

int main()
{
    ListeChainee * test = new ListeChainee();
    Trajet * t1 = new TrajetSimple( Saisi() , Saisi() , Saisi() );
    Trajet * t2 = new TrajetSimple( Saisi() , Saisi() , Saisi() );
    test->AjouterFin(t1); 
    test->AjouterFin(t2);

    ListeChainee * test2 = new ListeChainee();
    Trajet * t3 = new TrajetSimple("AZ" , "ER" , "PR");
    Trajet * t4 = new TrajetSimple("LA" , "MO" , "NB");
    test2->AjouterFin(t3);
    test2->AjouterFin(t4);

    Trajet * t5 = new TrajetCompose(test2);
    test->AjouterFin(t5);
    
    test -> Afficher();

    delete test ;
    delete test2 ;

    return 0;
}

char * Saisi()
{
    char unMot[TAILLEBUFFER];
    cin >> unMot;

    char * LeMot = new char[strlen(unMot)];

    for( int i = 0 ; i < int(strlen(unMot)) ; ++i)
    {
        LeMot[i] = unMot[i];
    }

    return LeMot;
}