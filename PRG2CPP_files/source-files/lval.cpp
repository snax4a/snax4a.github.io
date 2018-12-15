#include <iostream>
using namespace std;

int& razydwa(int& m) {
    static int licz;
    cout << " W funkcji: licz = " << licz << endl;
    m *= 2;
    return licz;
}

void printTab(const int *tab, int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++)
        cout << tab[i] << " ";
    cout << "]" << endl;
}

int main() {
    int i = 1, j = 2, k = 3;

    // przypisanie jako l-nazwa
    (i=j) = k;
    cout << " A: i = " << i << " j = " << j
         <<    " k = " << k << endl;           // 3,2,3

    int tab[] = {1,2,3,4}, *p = tab;
    cout << " B: przed "; printTab(tab,4);
    *++++++p = 8;
    cout << " B:    po "; printTab(tab,4);

    // teraz p wskazuje na ostatni element!
    cout << " C: ++*----p = " << ++*----p << endl; // 3
    cout << " C:   tab "; printTab(tab,4);

    // konwersja jako l-nazwa
    int m = 7;
    razydwa( (int&)m=8 )++;  // konwersja niepotrzebna!
    cout << "D1: m = " << m << endl;
    razydwa(m)++;
    cout << "D2: m = " << m << endl;
    int n = razydwa(m) = 10;
    cout << "D3: m = " << m << endl;
    cout << "D4: n = " << n << endl;

    // operator przecinkowy
    k = (i=1, j=2) + 1;
    cout << " E: i = " << i << " j = " << j
         <<    " k = " << k << endl;          // 1,2,3

    // selektor jako l-nazwa
    (k > 2 ? i : j) = 5;
    cout << " F: i = " << i << " j = " << j
         <<    " k = " << k << endl;          // 5,2,3
}
