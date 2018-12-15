#include <iostream>
using namespace std;

int main() {
    int *p, k = 5, m = 7;

    const int stala = 3;       // stala
    const int *q = &k;         // q - wskaznik na stala
    int *const r = &k;         // r - staly wskaznik
    const int tab[] = {1,2,3}; // tablica stalych

    p = &stala;
    stala = 1;
    *q = m;
    q = &m;
    r = &m;
    k = 10;
    tab[1] = 9;
}
