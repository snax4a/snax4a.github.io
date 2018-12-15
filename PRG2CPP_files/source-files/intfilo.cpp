#include <iostream>
#include <strstream>
#include <cstdlib>   // free
using namespace std;

int main() {
    // wersja "gumowa"
    ostrstream napis1;
    napis1 << "Poczatek, " << "dalszy ciag, "
           << "koniec."    << ends;
    char* n = napis1.str();
    cout << "Napis jest: " << n << endl;
    free(n);

    // wersja tablicowa
    char tab[30];
    ostrstream napis2(tab,sizeof(tab));
    napis2 << "Magda " << "Kasia " << "Marta" << ends;
    cout << tab << endl;
}
