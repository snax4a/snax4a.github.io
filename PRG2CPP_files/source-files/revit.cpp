#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main() {
    vector<string> vs;

    vs.push_back("Ola");
    vs.push_back("Ula");
    vs.push_back("Ela");
    vs.push_back("Ala");

    typedef vector<string>::iterator         DO_PRZODU;
    typedef vector<string>::reverse_iterator DO_TYLU;

    DO_PRZODU piter, pkoniec = vs.end();
    DO_TYLU   titer, tkoniec = vs.rend();

    for ( piter = vs.begin(); piter != pkoniec; piter++ )
        cout << *piter << " ";
    cout << endl;

    for ( titer = vs.rbegin(); titer != tkoniec; titer++ )
        cout << *titer << " ";
    cout << endl;
}
