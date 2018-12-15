#include <iostream>
using namespace std;

class Nazwisko {
    char* nazwis;
public:
    Nazwisko(const char* n)
        : nazwis(strcpy(new char[strlen(n)+1], n))
    {
        cout << "Ctor Nazwisko: " << nazwis << endl;
    }

    virtual
    ~Nazwisko() {
        cout << "Dtor Nazwisko: " << nazwis << endl;
        delete [] nazwis;
    }
};

class Pelne : public Nazwisko {
    char* imie;
public:
    Pelne(const char* i, const char* n)
        : Nazwisko(n),
          imie(strcpy(new char[strlen(i)+1], i))
    {
        cout << "Ctor Pelne, Imie: " << imie << endl;
    }

    ~Pelne() {
        cout << "Dtor Pelne, Imie: " << imie << endl;
        delete [] imie;
    }
};

int main() {
    Nazwisko* osoba = new Pelne("Jan", "Malinowski");
    delete osoba;
}
