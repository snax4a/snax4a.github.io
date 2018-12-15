#include <iostream>
using namespace std;

class Klasa {
public:
    char imie[4];
    int  wiek;
};

int main() {
    Klasa ktab[5] = {{"Ala",17},{"Ola",32},
                     {"Ula",26},{"Iza",29}};
    ktab[4].wiek = 22;

    for (int i = 0; i < 5; i++)
        cout << ktab[i].imie << " lat "
             << ktab[i].wiek << endl;
}
