#include <vector>
#include <iostream>
#include <string>
#include <cctype>    // tolower
#include <algorithm>
#include <iterator>
using namespace std;

bool czy_na_A(string& s) {
    return s[0] == 'A';
}

void mala(string& imie) {
    imie[0] = tolower(imie[0]);
}

int main() {
    vector<string> vs;

    vs.push_back("Magda");  vs.push_back("Anna");
    vs.push_back("Monika"); vs.push_back("Agata");
    vs.push_back("Ala");    vs.push_back("Urszula");

    vector<string>::iterator k;

    k = find(vs.begin(), vs.end(), "Anna");
    if ( k != vs.end() )
        cout << *k << " znaleziona\n";
    else
        cout << "Anna nie znaleziona\n";

    k = find(vs.begin(), vs.end(), "Basia");
    if ( k != vs.end() )
        cout << *k << " znaleziona\n";
    else
        cout << "Basia nie znaleziona\n";


    cout << "\nZ imion\n";
    copy(vs.begin(),vs.end(),
         ostream_iterator<string>(cout," "));
    cout << "\nnastepujace zaczynaja sie na \'A\':\n";
    k = vs.begin();
    while ( k < vs.end() ) {
        k = find_if(k, vs.end(), czy_na_A);
        if ( k != vs.end() ) cout << *k++ << " ";
    }
    cout << endl;

    for_each(vs.begin(),vs.end(),mala);
    cout << "\nPo zamianie na male:\n";
    copy(vs.begin(),vs.end(),
         ostream_iterator<string>(cout," "));
    cout << endl;
}
