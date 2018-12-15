#include <iostream>
#include <cstring>
using namespace std;

class Osoba2 { // niezupelnie dobra klasa...
public:
    int   wiek;
    char* imie;
    Osoba2(int w, const char* im) {
        wiek = w;
        imie = new char[strlen(im)+1];
        strcpy(imie,im);
    }
};

int main() {
    char imie[] = "Basia";

    Osoba2 basia(29, imie);
    Osoba2 kasia(basia);      // uzycie konstr. kopiujacego

    cout << "Po utworzeniu:   basia " << basia.imie << endl;
    cout << "                 kasia " << kasia.imie << endl;

    kasia.imie[0] = 'K';

    cout << "Po zmianie Kasi: basia " << basia.imie << endl;
    cout << "                 kasia " << kasia.imie << endl;
}
