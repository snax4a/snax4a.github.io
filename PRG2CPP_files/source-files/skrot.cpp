#include <iostream>
using namespace std;

bool fun(int k) {
    k = k - 3;
    cout << "Fun zwraca " << k << endl;
    return k;
}

int main() {
    if ( fun(1) && fun(2) && fun(3) && fun(4) )
        cout << "Koniunkcja true"   << endl;
    else
        cout << "Koniunkcja false"  << endl;

    if ( fun(1) || fun(2) || fun(3) || fun(4) )
        cout << "Alternatywa true"  << endl;
    else
        cout << "Alternatywa false" << endl;
}
