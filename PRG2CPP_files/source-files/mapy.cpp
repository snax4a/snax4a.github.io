#include <iostream>
#include <iomanip>   // left, setw
#include <string>
#include <map>
#include <utility>   // pair
#include <algorithm>
using namespace std;

typedef pair<string,int> Emp;
typedef map<string,Emp>  MAP;

class Zakr {
    int min,max;
public:
    Zakr(int min,int max) : min(min), max(max) {}

    bool operator()(const pair<const string,Emp>& p) const {
        int zarobki = p.second.second;
        return  (min < zarobki) && (zarobki < max);
    }
};

void druk(const MAP& m) {
    MAP::const_iterator it, fin=m.end();

    for (it = m.begin(); it != fin; it++)
        cout << "Klucz: "   << left << setw(7) << it->first
             << "Imie: "    << setw(10) << it->second.first
             << "Zarobki: " << it->second.second << endl;
}

int main() {
    MAP emp;

    emp["jan"]    = Emp("Jan K.",    1900);
    emp["piotr"]  = Emp("Piotr M.",  2100);
    emp["ola"]    = Emp("Ola S.",    3100);
    emp["prezes"] = Emp("Prezes",    9900);
    emp["adam"]   = Emp("Adam A.",   1600);
    emp["emilia"] = Emp("Emilia P.", 2600);

    druk(emp);

    int mn = 0, mx = 2000;
    int ile = count_if(emp.begin(),emp.end(),Zakr(mn,mx));

    cout << ile << " osob ma zarobki w zakresie od "
         << mn << " do " << mx << endl;
}
