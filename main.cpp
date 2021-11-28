#include "ListeChainee.h"
#include "TrajetCompose.h"
#include <iostream>
using namespace std;


int main()
{
    ListeChainee * test = new ListeChainee();
    Trajet * t1 = new TrajetSimple("Paris","Londre","Train");
    Trajet * t2 = new TrajetSimple("Schweighouse","Haguenau","Train");
    test->Ajouter(t1); 
    test->Ajouter(t2);

    ListeChainee * test2 = new ListeChainee();
    Trajet * t3 = new TrajetSimple("Paris","Londres","Avion");
    Trajet * t4 = new TrajetSimple("Schweighouse","Haguenau","Train");
    test2->Ajouter(t3);
    test2->Ajouter(t4);

    Trajet * t5 = new TrajetCompose("ok","oui",test2);
    test->Ajouter(t5);
    
    test->Afficher();
    cout << "je rajoute un cout pour test" << endl;
    return 0;
}
