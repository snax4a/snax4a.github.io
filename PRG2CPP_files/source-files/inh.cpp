#include <iostream>
#include <cstring>
using namespace std;

class Osoba {
    char* nazwis;
public:
    Osoba()
        : nazwis(strcpy(new char[14], "Nazw.Nieznane"))
    {
        cout << "Konstr. domyslny Osoba: "
             << nazwis << endl;
    }

    Osoba(const char* n)
        : nazwis(strcpy(new char[strlen(n)+1], n))
    {
        cout << "Konstr. char* Osoba: " << nazwis << endl;
    }

    Osoba(const Osoba& os)
        : nazwis(strcpy(new char[strlen(os.nazwis)+1],
                                           os.nazwis))
    {
        cout << "Konstr. kopiujacy Osoba: "
             << nazwis << endl;
    }

    Osoba& operator=(const Osoba& os) {
        if ( this != &os ) {
            delete [] nazwis;
            nazwis = strcpy(new char[strlen(os.nazwis)+1],
                                               os.nazwis);
            cout << "Przypisanie Osoba: "
                 << nazwis << endl;
        }
        return *this;
    }

    ~Osoba() {
        cout << "Usuwamy Osoba: " << nazwis << endl;
        delete [] nazwis;
    }

    const char* getNazwisko() const { return nazwis; }
};

class Pracownik : public Osoba {
    char* funkcja;
public:
    Pracownik()
        : funkcja(strcpy(new char[14], "Stan.Nieznane"))
    {
        cout << "Konstruktor domyslny Pracownik: "
             << funkcja << endl;
    }

    Pracownik(const char* s, const char* n)
        : Osoba(n),funkcja(strcpy(new char[strlen(s)+1], s))
    {
        cout << "Konstruktor char* char* Pracownik: "
             << funkcja << endl;
    }

    Pracownik(const Pracownik& prac)
        : Osoba(prac), funkcja(strcpy(new
              char[strlen(prac.funkcja)+1],prac.funkcja))
    {
        cout << "Konstruktor kopiujacy Pracownik: "
             << funkcja << endl;
    }

    Pracownik& operator=(const Pracownik& prac) {
        if ( this != &prac ) {
            (Osoba&)(*this) = prac;
            delete [] funkcja;
            funkcja = strcpy(new
                char[strlen(prac.funkcja)+1],
                prac.funkcja);
            cout << "Przypisanie Pracownik: "
                 << funkcja << endl;
        }
        return *this;
    }

    ~Pracownik() {
        cout << "Usuwamy Pracownik: " << funkcja << endl;
        delete [] funkcja;
    }

    const char* getFunkcja() const { return funkcja; }
};

int main() {
    cout << "\nMain: Tworzymy obiekt nem" << endl;
    Pracownik nem;
    cout << "Main: obiekt nemo utworzony: "
         << nem.getFunkcja() << " "
         << nem.getNazwisko()   << endl;

    cout << "\nMain: Tworzymy obiekt mal" << endl;
    Pracownik mal("Szef", "Malinowski");
    cout << "Main: obiekt mal utworzony: "
         << mal.getFunkcja() << " "
         << mal.getNazwisko()   << endl;

    cout << "\nMain: Kopiujemy mal -> kop" << endl;
    Pracownik kop(mal);
    cout << "Main: obiekt kop utworzony: "
         << kop.getFunkcja() << " "
         << kop.getNazwisko()   << endl;

    cout << "\nMain: Przypisujemy nem = kop" << endl;
    nem = kop;
    cout << "Main: nem = kop przypisane: "
         << nem.getFunkcja()  << " "
         << nem.getNazwisko() << endl << endl;
}
