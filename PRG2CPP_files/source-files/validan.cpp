#include <fstream>
#include <iostream>
using namespace std;

int main() {
    const int DIM = 80;
    char      name[DIM];
    ifstream  inplik;
    double    x;

    do {
        cout << "Plik wejsciowy: ";
        cin.getline(name, DIM);

        inplik.clear();
        inplik.open(name);
    } while (!inplik);

    cout << "Plik = " << name << endl;
    inplik.close();

    do {
        if (!cin) {
            // wazna kolejnosc!
            cin.clear();
            cin.ignore(1024,'\n');
        };
        cout << "Podaj liczbe: ";
        cin >> x;
    } while (!cin);

    cout << "Liczba = " << x << endl;
}
