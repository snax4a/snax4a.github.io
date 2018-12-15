#include <iostream>
using namespace std;

int main() {
    int i = 1, m = 2;
    const int *const pi = &i;

    cout << "Przed *pi = " << *pi << endl;
    i = 3;
    cout << "Po    *pi = " << *pi << endl;

    *pi = 4; // NIE: pi jest wskaznikiem do stalej
    pi = &m; // NIE: pi jest ustalonym wskaznikiem
}
