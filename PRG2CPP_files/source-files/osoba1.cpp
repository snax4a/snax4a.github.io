#include <iostream>
#include <cstring>
using namespace std;

class Osoba1 { // niezupelnie dobra klasa...
public:
    int   wiek;
    char* imie;
    Osoba1(int w, const char* im) {
        wiek = w;
        imie = new char[strlen(im)+1];
        strcpy(imie,im);
    }
};

int main() {
    char imie[] = "Basia";

    Osoba1 basia(29, imie);

    imie[0] = 'K';

    cout << "Oryginal:  " << imie       << endl;
    cout << "Z obiektu: " << basia.imie << endl;
}
