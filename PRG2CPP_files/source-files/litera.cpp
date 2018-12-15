#include <iostream>
#include <cstring>
using namespace std;

class Litera {
    char* napis;
public:
    Litera(const Litera& k)
        : napis(strcpy(new char[strlen(k.napis)+1],
                       k.napis))
    { }

    Litera(const char* napis)
        : napis(strcpy(new char[strlen(napis)+1],
                       napis))
    { }

    Litera& operator=(const Litera&);
    char& operator[](int);

    ~Litera() { delete [] napis; }

    friend ostream& operator<<(ostream&,const Litera&);
};

char& Litera::operator[](int n) {
    int len = strlen(napis);
    if ( n < 0 || n >= len )
        // zwracamy odnosnik do NUL jesli zly indeks
        return napis[len];
    else
        return napis[n];
}

Litera& Litera::operator=(const Litera& k) {
    if (this == &k ) return *this;
    delete [] napis;
    napis = strcpy(new char[strlen(k.napis)+1],k.napis);
    return *this;
}

ostream& operator<<(ostream& str, const Litera& k) {
    return str << k.napis;
}

int main() {
    Litera a("Kasia");
    cout << "a=" << a << endl;

    char c = a[100];
    if (c == '\0') cout << "Zly zakres!" << endl;
    else           cout << "znak: " << c << endl;

    c = a[0];
    if (c == '\0') cout << "Zly zakres!" << endl;
    else           cout << "znak: " << c << endl;

    a[0] = 'B';
    cout << "a=" << a << endl;
}
