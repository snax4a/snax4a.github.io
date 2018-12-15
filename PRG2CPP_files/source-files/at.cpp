#include <vector>
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;

int main() {
    vector<string> vs;

    vs.push_back("Ola");
    vs.push_back("Ula");
    vs.push_back("Ela");
    vs.push_back("Ala");

    try {
        for ( int i = 0; i < 5 /* BLAD */; i++ )
            cout << vs.at(i) << " " ;
    } catch(out_of_range) {
        cout << "\n*** Zly indeks! *** "
             << " wektor ma tylko " << vs.size()
             << " elementy!" << endl;
    }
    cout << endl;

    cout << "Pierwszy element: " << vs.front() << endl;
    cout << "Ostatni  element: " << vs.back()  << endl;

    vs.pop_back();

    cout << "Po pop_back: ";
    int size = (int)vs.size();
    for ( int i = 0; i < size; i++)
        cout << vs[i] << " " ;
    cout << endl;
}
