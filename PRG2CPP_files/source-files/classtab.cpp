#include <iostream>
#include <string>
using namespace std;

class Klasa {
    string imie;
    int    wiek;
public:
    Klasa(const string& imie = "No Name", int wiek = 100) {
        this->imie = imie;
        this->wiek = wiek;
        cout << "konstrukcja " << this->imie << endl;
    }

    int     getAge() { return wiek; }

    string getImie() { return imie; }
};

int main() {
    Klasa ob("Celestyna");

    Klasa ktab[5] = { Klasa("Honoratka", 17),
                      Klasa("Albertyna"),
                      Klasa("Hortensja", 26),
                      ob
                    };

    for (int i = 0; i < 5; i++)
        cout << ktab[i].getImie() << " lat "
             << ktab[i].getAge()  << endl;
}
