#include <iostream>
#include <cmath>
using namespace std;

typedef double (*TABFUN[])(double);
//typedef const char *TABNAP[];
using TABNAP = const char* [];  // C++11

void fundruk(TABFUN,TABNAP,double);

int main() {
    const double PIover4 = atan(1.);

    TABFUN tabfun = { sin,  cos,  tan };
    TABNAP tabnap = {"sin","cos","tan"};

    cout << "sizeof(tabfun) = " << sizeof(tabfun) << endl
         << "sizeof(tabnap) = " << sizeof(tabnap) << "\n\n";

    for (int i = 0; i < 3; i++) {
        cout << "tabfun[" <<   i   << "](pi/4) = "
             << tabfun[i](PIover4) << " ("
             << tabnap[i]          << ")\n";
    }

    fundruk(tabfun,tabnap,PIover4);
}

void fundruk(TABFUN f, TABNAP t, double x) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << "fundruk: " << t[i] << " "
             << "wartosc: " << f[i](x) << endl;
    }
}
