#include <iostream>
#include "sortint.h"   // wlaczamy naglowek
                       // z deklaracjami
using namespace std;

// implementacja funkcji sort
void sort(int a[], int size) {
    int i, indmin = 0;
    for (i = 1; i < size; ++i)
        if (a[i] < a[indmin]) indmin = i;
    if (indmin != 0) {
        int p = a[0];
        a[0] = a[indmin];
        a[indmin] = p;
    }

    for (i = 2; i < size; ++i) {
        int j = i, v = a[i];
        while (v < a[j-1]) {
            a[j] = a[j-1];
            j--;
        }
        if (i != j ) a[j] = v;
    }
}

// implementacja funkcji pisztab
void pisztab(const int t[], int size) {
    cout << "[ ";
    for (int i = 0; i < size; ++i)
        cout << t[i] << " ";
    cout << "]" << endl;
}
