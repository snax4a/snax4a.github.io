#include <iostream>
#include <cmath>
using namespace std;

double potegi(double&,double*);
int*   kwadrat(int*);
int&   funmax(int[],int);

int main() {

      // argumenty wskaznikowe i referencyjne
    double u = 4, v;
    double szesc = potegi(u, &v);
    cout << "Szescian: " << szesc  << "; kwadrat: "
         << u << "; pierwiastek: " << v  << endl;

      // to tez ma sens
    int i = 4;
    cout << "20? : " << ++*kwadrat(&i)+3 << endl;

    // funkcja zwracajaca referencje
    int tab[] = {1,4,6,2};
    cout << "Tablica przed: ";
    for ( i = 0; i < 4; i++ ) cout << tab[i] << " ";
    cout << endl;

    funmax(tab,4) = 0;

    cout << "Tablica po   : ";
    for ( i = 0; i < 4; i++ ) cout << tab[i] << " ";
    cout << endl;
}

double potegi(double& u, double* v) {
    double x = u;
    u *= u;
    *v = sqrt(x);
    return u*x;
}

int* kwadrat(int* p) {
    *p *= *p;
    return p;
}

int& funmax(int* tab, int ile) {
    int i, ind = 0;
    for ( i = 1; i < ile; i++ )
        if ( tab[i] > tab[ind] ) ind = i;
    return tab[ind];
}
