#include <iostream>
#include <cstring>
using namespace std;

class Osoba {   // troche lepsza klasa
public:
    int   wiek;
    char* imie;
    Osoba(int w, const char* im) { // zwykly konstruktor
        wiek = w;
        imie = new char[strlen(im)+1];
        strcpy(imie,im);
    }
    Osoba(const Osoba& os) {      // konstruktor kopiujacy
        wiek = os.wiek;
        imie = new char[strlen(os.imie)+1];
        strcpy(imie,os.imie);
    }
    ~Osoba() {                    // destruktor
        delete [] imie;
    }
};

int main() {
    char imie[] = "Basia";

    Osoba basia(29, imie);
    Osoba kasia(basia);

    cout << "Po utworzeniu:   basia " << basia.imie << endl;
    cout << "                 kasia " << kasia.imie << endl;

    kasia.imie[0] = 'K';

    cout << "Po zmianie Kasi: basia " << basia.imie << endl;
    cout << "                 kasia " << kasia.imie << endl;
}
