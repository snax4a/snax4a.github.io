#include "sortint.h"  // tylko plik naglowkowy!
#include <iostream>
using namespace std;

int main() {
    int tab[] = {9,7,2,6,4,5,6,2,7,9,2,9,5,2},
        size  = sizeof(tab)/sizeof(tab[0]);

    cout << "Tablica  oryginalna: ";
    pisztab(tab, size);

    sort(tab, size);

    cout << "Tablica posortowana: ";
    pisztab(tab, size);
}
