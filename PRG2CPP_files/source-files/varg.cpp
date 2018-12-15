#include <iostream>
#include <cstdarg>
using namespace std;

void typy(const char typ[] ...);

int main() {
    typy("SxS", "Jan", 0, "Maria");
    typy("issD", 17, "Jan", "Maria", 1.);
    typy("iDdsiI", 17, 19.5, 1.5, "OK", -1, 8);
}

void typy(const char typ[] ...) {
    int     i = 0, integ;
    char    c, *strin;
    double  doubl;

    va_list ap;

    va_start(ap,typ);

    while ( (c = typ[i++]) != '\0') {
        switch (c) {
            case 'i':
            case 'I':
                integ = va_arg(ap,int);
                cout << "Liczba int   : " << integ << endl;
                break;
            case 'd':
            case 'D':
                doubl = va_arg(ap,double);
                cout << "Liczba double: " << doubl << endl;
                break;
            case 's':
            case 'S':
                strin = va_arg(ap,char*);
                cout << "Napis        : " << strin << endl;
                break;
            default:
                cout << "Nielegalny kod typu!!!!!" << endl;
                goto KONIEC;
        }
    }
    KONIEC:
    cout << endl;

    va_end(ap);
}
