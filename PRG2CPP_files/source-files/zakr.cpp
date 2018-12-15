#include <iostream>
using namespace std;

class Zakresy {
    int    licz[3];
    double min, max;
public:
    Zakresy(double min, double max)
        : min(min), max(max) {
        licz[0]=licz[1]=licz[2]=0;
    }

    int& operator[](double x) {
        int i;

        if      ( x >  max ) i = 2;
        else if ( x >= min ) i = 1;
        else                 i = 0;

        return licz[i];
    }

    friend ostream& operator<<(ostream&, const Zakresy&);
};

ostream& operator<<(ostream& str, const Zakresy& z) {
    return str << "Zakres = [" << z.min << ", " << z.max
               << "]:  " << "Ponizej " << z.licz[0]
               << "; w zakr. " << z.licz[1] << "; Powyzej "
               << z.licz[2];
}

int main() {
    Zakresy zakres(3.0, 5.5);
    double x;
    cout << "Podaj liczby (zero konczy)" << endl;

    while ( ( cin >> x) && x ) zakres[x]++;

    cout << zakres << endl;
    cout << "x = 4.7 -> licz = " << zakres[4.7] << endl;
}
