#include <iostream>
using namespace std;

int sumaazdo(int *tab, int size) {
    int suma = 0;
    for (int i = 0; i < size; i++) {
        if ( tab[i] <= 0 ) break;
        suma += tab[i];
    }
    return suma;
}

int main() {
    int tab[] = { 1, 3, 5, 7, 0, 4, 9 };
    int suma = sumaazdo(tab, sizeof(tab)/sizeof(tab[0]));
    cout << "Suma: " << suma << endl;
}
