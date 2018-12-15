#include <fstream>
#include <string>
#include <utility>   // pair
#include <vector>
#include <algorithm> // copy, sort, itd.
#include <iostream>
using namespace std;

typedef pair<string,int> PARA;
typedef vector<PARA>     VECT;
typedef VECT::iterator   VECTIT;

template <typename P>
class niepelnoletni {
    int wiek;
public:
    niepelnoletni(int wiek) : wiek(wiek) { }

    bool operator()(const P& p) const {
        return p.second < wiek;
    }
};

template <typename P1, typename P2>
ostream& operator<<(ostream& str, const pair<P1,P2>& p) {
    return str << "[" << p.first << "," << p.second << "]";
}

template <typename P1, typename P2>
istream& operator>>(istream& str, pair<P1,P2>& p) {
    return str >> p.first >> p.second;
}

template <typename P>
bool komp(const P& p1, const P& p2) {
    return p1.second < p2.second;
}

int main() {
    ifstream plik("pary.dat");

    PARA   p;
    VECT vec;
    VECTIT it, fin;

    while (plik >> p) vec.push_back(p);

    cout << "Po wczytaniu:\n";
    fin=vec.end();
    for (it = vec.begin(); it != fin; ++it)
        cout << *it << " ";

    cout << "\nNajstarsza "
         << *max_element(vec.begin(),vec.end(),komp<PARA>)
         << ", najmlodsza "
         << *min_element(vec.begin(),vec.end(),komp<PARA>);

    it = remove_if(vec.begin(),fin,
                   niepelnoletni<PARA>(18));
    vec.erase(it,vec.end());

    cout << "\nPo usunieciu niepelnoletnich:\n";
    fin=vec.end();
    for (it = vec.begin(); it != fin; ++it)
        cout << *it << " ";

    sort(vec.begin(),fin,komp<PARA>);

    cout << "\nPo uporzadkowaniu:\n";
    fin=vec.end();
    for (it = vec.begin(); it != fin; ++it)
        cout << *it << " ";

    cout << endl;
}
