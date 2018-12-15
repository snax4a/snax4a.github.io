#include <iostream>
#include <cstring>
#include <cstdio>  // FILE, fopen, fclose
using namespace std;

class A {
    struct nazw {
        char* n;
        nazw(const char* n)
            : n(strcpy(new char[strlen(n)+1],n))
        { }
        ~nazw() {
            cerr << "dtor nazw: " << n << endl;
            delete [] n;
        }
    };

    nazw Nazwisko;
    FILE*    plik;
public:
    A(const char* n, const char* p)
        : Nazwisko(n)
    {
        plik = fopen(p,"r");
        // ...
//      throw 1;
        // ...
    }

    // inne pola i metody

    ~A() {
        cerr << "dtor A" << endl;
        if (plik) fclose(plik);
    }
};

int main() {
    try {
        A a("Kowalski","zasob.cpp");
    } catch(...) {
        cerr << "Nie udalo sie skonstruowac obiektu\n";
    }
}
