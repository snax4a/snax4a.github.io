#include <iostream>
#include <string>
using namespace std;

int main() {
    string imie;
    int wzrost;
    double waga;
    cout << "Podaj imie, wzrost i wage: ";
    cin  >> imie >> wzrost >> waga;
    cout << imie << ", masz " << wzrost  << " cm wzrostu "
         << "i wazysz " << waga << " kg" << endl;
}
