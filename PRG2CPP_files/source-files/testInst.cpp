/*
 * Test instalacji. Program powinien wypisac nazwy
 * 4 jezykow programowania w porzadku alfabetycznym.
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    vector<string> vs{"Python", "Haskell",
                      "C++",    "Java"};
    sort(vs.begin(),vs.end());
    for (const auto& e : vs) cout << e << " ";
    cout << endl;
}
