#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

int main() {
    vector<string> vec;

#if   defined(__WIN32)
    cout << "Lista slow (^Z konczy): ";
#elif defined(__linux)
    cout << "Lista slow (^D konczy): ";
#else
    #error Nieznany system
#endif

    string s;
    while ( cin >> s ) vec.push_back(s);
    cin.clear();

    list<string> lis(vec.begin(),vec.end());

    cout << "Slowo do znalezienia: ";
    cin  >> s;

    vector<string>::iterator sit;
    list<string>::iterator   lit;

      // wektor
    for (sit = vec.begin(); sit != vec.end(); ++sit)
        if ( *sit == s ) break;
    if ( sit != vec.end() )
        cout << "Slowo " << s << " na pozycji "
             << sit - vec.begin() << endl;
    else
        cout << "Slowo " << s << " nie wystapilo" << endl;

      // lista
    for (lit = lis.begin(); lit != lis.end(); ++lit)
        if ( *lit == s ) break;
    if ( lit != lis.end() )
        cout << "Slowo " << s << " na pozycji "
             << distance(lis.begin(),lit) << endl;
    else
        cout << "Slowo " << s << " nie wystapilo" << endl;
}
