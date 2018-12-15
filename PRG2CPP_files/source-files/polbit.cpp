#include <iostream>
using namespace std;

class Czcionka {
    unsigned  kroj : 3;
    unsigned  waga : 1;
    unsigned kolor : 2;
public:
    enum  Kroj { HELVETICA, TIMES, ARIAL,
                 COURIER, BOOKMAN, SYMBOL};
    enum  Waga { NORMAL, BOLD };
    enum Kolor { BLACK, RED, GREEN, BLUE };

    Czcionka(Kroj kroj, Waga waga, Kolor kolor) {
        this->kroj  = kroj;
        this->waga  = waga;
        this->kolor = kolor;
    }

    void opis() {
        cout << "Kroj nr " << kroj << "; Waga nr "
             << waga << "; Kolor nr " << kolor << endl;
    }
};

int main() {
    Czcionka tytul(Czcionka::ARIAL,  Czcionka::BOLD,
                                     Czcionka::RED);
    Czcionka tekst(Czcionka::TIMES,  Czcionka::NORMAL,
                                     Czcionka::BLACK);
    Czcionka greka(Czcionka::SYMBOL, Czcionka::BOLD,
                                     Czcionka::BLUE);
    tytul.opis();
    tekst.opis();
    greka.opis();
    cout << "Rozmiar obiektu: " << sizeof(Czcionka) << endl;
}
