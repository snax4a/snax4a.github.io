#include <iostream>
using namespace std;

struct Sam {
    double predk;
    int    roczn;
} skoda, fiat{100, 1998};

void pr(const char*,const Sam*);

int main() {
    Sam toyota, *mojsam = &toyota, *vw;

    cout << "Obiekty \'Sam\' maja rozmiar "
         << sizeof(Sam) << " bajtow\n";
    skoda.predk =  120;
    skoda.roczn = 1995;

    toyota.roczn  = 2012;
    mojsam->predk =  180;

    vw = new Sam{175,2003};

    pr("Skoda ",&skoda);
    pr("Fiat  ",&fiat);
    pr("Toyota",&toyota);
    pr("mojsam", mojsam);
    pr("VW    ", vw);

    delete vw;
}

void pr(const char *nazwa, const Sam *sam) {
    cout << nazwa << ": predkosc " << sam->predk
         << ", rocznik " << sam->roczn << endl;
}
