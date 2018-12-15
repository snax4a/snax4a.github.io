#include <iostream>
#include <cstring>
using namespace std;

void  first_last(char**,char*&,char*&);

int main() {

    char *nam[] = { "Katarzyna", "Magdalena",
                       "Alicja",     "Wanda",
                      "Izabela",    "Aldona", "" },
                  *p,*q;

    first_last(nam,p,q);

    cout << "Pierwsza: " << p << endl
         << "Ostatnia: " << q << endl;
}

void first_last(char** s, char*& p, char*& q) {
    p = q = *s;
    while ( **++s ) {
        if ( strcmp(*s, p) < 0 ) p = *s;
        if ( strcmp(*s, q) > 0 ) q = *s;
    }
}
