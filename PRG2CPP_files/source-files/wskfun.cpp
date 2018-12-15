#include <iostream>
#include <cmath>
using namespace std;

const double PI = 4*atan(1.);

double nasza(double);

int main() {
    double (*f)(double);

    f = sin;
    cout << "sin(PI/2) =  " << (*f)(PI/2) << endl;

    f = &cos;
    cout << "  cos(PI) = "  << f(PI)      << endl;

    f = nasza;
    cout << " nasza(3) =  " << f(3)       << endl;
}

double nasza(double x) {
    return x*x;
}
