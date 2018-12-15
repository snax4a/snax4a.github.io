#include <iostream>
using namespace std;

#include "wardom1h.h"

void kolor(int, int , int = 0, int);

int main() {
    kolor(100,150,250,199);
    kolor(100,150,250);
    kolor(100,150);
}

void kolor(int red, int green, int blue, int alpha) {
    cout << "Alpha = " << alpha << " (R,G,B) = (" << red
         << ","  << green  <<  "," << blue << ")" << endl;
}
