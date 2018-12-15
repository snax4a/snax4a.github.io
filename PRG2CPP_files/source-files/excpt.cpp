#include <iostream>
#include <string>
#include <sstream>   // ostringstream
#include <cmath>     // sqrt, log, atan
using namespace std;

struct Blad {
    virtual string opis() = 0;
};

class Ujemna : public Blad {
    double x;
public:
    Ujemna(double x) : x(x) { }
    string opis() {
        ostringstream strum;
        strum << "Ujemny argument: x = " << x;
        return strum.str();
    }
};

class PozaZakresem : public Blad {
    double x, min, max;
public:
    PozaZakresem(double x, double mi, double ma)
        : x(x), min(mi), max(ma)
    { }
    string opis() {
        ostringstream strum;
        strum << "Argument x = " << x << "\n    "
              << "    poza zakresem [" << min << ","
              << max << "]";
        return strum.str();
    }
};

double fun(double x) {
    if (x < 0 || x > 2) throw PozaZakresem(x,0,3);
    return sqrt(x*(3-x));
}

double logPI(double x) {
    static double LPI = log(4*atan(1.));
    if (x <= 0) throw Ujemna(x);
    return log(x)/LPI;
}

int main() {
    double x = 4*atan(1.);

    cout << "x = " << x << endl;
    try {
        double z1 = logPI(x);
        cout << "  z1 = " << z1 << endl;
        double z2 = fun(x);
        cout << "  z2 = " << z2 << endl;
    }
    catch(Blad& blad) {
        cerr << "  Blad: " << blad.opis() << endl;
    }
}
