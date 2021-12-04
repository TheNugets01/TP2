#include <iostream>
#include <cstring>
using namespace std;

char * Saisi();

int main()
{
    char * arrive = Saisi();
    cout << &arrive << endl;
    while(1)
    {
        char * depart = new char[strlen(arrive)];
        strcpy(depart,arrive);
        char * arrive = Saisi();
        cout << &arrive << endl;
        cout << &depart << endl;
    }

    return 0;
}

char * Saisi(char * ici)
{
    char * unMot = ici;
    //char unMot[100];
    //cin >> unMot;

    char * LeMot = new char[strlen(unMot)];

    for( int i = 0 ; i < int(strlen(unMot)) ; ++i)
    {
        LeMot[i] = unMot[i]; // ya strcpy aussi je crois
    }

    return LeMot;
}