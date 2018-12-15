#include <iostream>
using namespace std;

int main() {
    cout << "Plik:    " << __FILE__     << endl
         << "Data:    " << __DATE__     << endl
         << "Linia:   " << __LINE__     << endl
         << "Czas:    " << __TIME__     << endl
         << "Funkcja: " << __FUNCTION__ << endl;
}
