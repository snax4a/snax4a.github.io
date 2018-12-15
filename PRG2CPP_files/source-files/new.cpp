#include <iostream>
#include <new>
using namespace std;

int main() {
    int* itab = new int[8];
    for (int i = 0; i < 8; i++) itab[i] = i+1;

    double* dtab = new (itab+2) double[2];
    for (int i = 0; i < 2; i++) dtab[i] = (1+i)/3.;

    cout << "\nTablica dtab:\n\n";
    for (int i = 0; i < 2; i++)
        cout << "  dtab[" << i << "] = " << dtab[i] << endl;

    cout << "\nTablica itab:\n" << endl;
    for (int i = 0; i < 8; i++)
        cout << "  itab[" << i << "] = " << itab[i] << endl;

    delete [] itab;
}
