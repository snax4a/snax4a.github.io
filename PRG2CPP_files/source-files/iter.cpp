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

    for ( vector<string>::iterator ite = vs.begin();
                                   ite!= vs.end(); ++ite)
        cout << *ite << " ";
    cout << endl;

    // albo

    vector<string>::iterator it, kon = vs.end();

    for ( it = vs.begin(); it != kon; ++it )
        cout << *it << " ";
    cout << endl;

    // albo

    typedef vector<string>::iterator SIT;

    SIT iter, koniec = vs.end();

    for ( iter = vs.begin(); iter != koniec; ++iter )
        cout << *iter << " ";
    cout << endl;
}
