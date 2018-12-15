#include <iostream>
using namespace std;

int main()
{
    int k;
    while ( (k = cin.get()) != '\n' )
        cout << "Wprowadzono znak '" << (char)k
             << "', o kodzie ASCII " << k << endl;
}
