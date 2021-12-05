#include <iostream>
#include <cstring>
using namespace std;

char fun(char * c)
{
    return c[0];
}

int main()
{
    char * k = "manger";
    cout << fun(k) << endl;

    return 0;

}