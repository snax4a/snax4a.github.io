#include <iostream>
#include <cmath>
using namespace std;

struct Punkt {
    double x, y;
    Punkt(double x = 0, double y = 0)
        : x(x), y(y)
    { }
    double r2() { return  x*x + y*y; }
    double dd() { return sqrt(r2()); }
};

int main() {
    double  Punkt::*wi[2];
    double (Punkt::*wf[2])();

    wi[0] = &Punkt::x;
    wi[1] = &Punkt::y;

    wf[0] = &Punkt::r2;
    wf[1] = &Punkt::dd;

    Punkt P(3,4), *p = &P;

    cout << " P.*wi[0]     = " <<  P.*wi[0]     << endl;
    cout << " P.*wi[1]     = " <<  P.*wi[1]     << endl;
    cout << "(P.*wf[0])()  = " << (P.*wf[0])()  << endl;
    cout << "(P.*wf[1])()  = " << (P.*wf[1])()  << endl;

    cout << endl;

    cout << " p->*wi[0]    = " <<  p->*wi[0]    << endl;
    cout << " p->*wi[1]    = " <<  p->*wi[1]    << endl;
    cout << "(p->*wf[0])() = " << (p->*wf[0])() << endl;
    cout << "(p->*wf[1])() = " << (p->*wf[1])() << endl;
}
