#include <iostream>
using namespace std;

void reverse(int *tab, int size) {
    if ( size < 2 ) return;

    for (int i = 0, k = size-1, aux; i < k; i++, k--) {
        aux    = tab[i];
        tab[i] = tab[k];
        tab[k] = aux;
    }
}

void printTab(int *tab, int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++)
        cout << tab[i] << " ";
    cout << "]" << endl;
}

int main() {
    int tab[] = { 1, 3, 5, 7, 2, 4, -9, 12 };
    int size = sizeof(tab)/sizeof(tab[0]);

    printTab(tab,size);
    reverse (tab,size);
    printTab(tab,size);
}
