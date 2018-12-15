#include <iostream>
#include <cmath>    // sqrt
using namespace std;

struct Punkt {
    double x, y;
    static Punkt srodek;
};
Punkt Punkt::srodek;

void ustal_srodek(double,double);
double odl_od_srodka(const Punkt&);

int main() {
    Punkt P = {3, 4};
    cout << "Punkt P = (" << P.x << "," << P.y << ")\n";

    ustal_srodek(0,0);
    cout << "Odl. P-srodek: " << odl_od_srodka(P) << endl;

    ustal_srodek(9,-4);
    cout << "Odl. P-srodek: " << odl_od_srodka(P) << endl;
}

void ustal_srodek(double xx,double yy) {
    Punkt::srodek.x = xx;
    Punkt::srodek.y = yy;
    cout << "Srodek w p-cie (" << xx << "," << yy << ")\n";
}

double odl_od_srodka(const Punkt& p) {
    return
        sqrt((p.x-Punkt::srodek.x)*(p.x-Punkt::srodek.x) +
             (p.y-Punkt::srodek.y)*(p.y-Punkt::srodek.y));
}
