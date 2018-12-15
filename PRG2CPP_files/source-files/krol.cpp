#include <iostream>
#include <iomanip>   /* setw */
using namespace std;

struct Krol{
    int   ur;
    char  imie[40];
};

void insertionSort(Krol*[],int);

int main() {
    Krol zygmunt   = {1467,               "Zygmunt Stary"},
         michal    = {1640, "Michal Korybut Wisniowiecki"},
         wladyslaw = {1351,          "Wladyslaw Jagiello"},
         anna      = {1523,            "Anna Jagiellonka"},
         jan       = {1459,                "Jan Olbracht"};

    Krol* krolowie[] = { &zygmunt, &michal, &wladyslaw,
                         &anna,    &jan};

    const int ile = sizeof(krolowie)/sizeof(Krol*);

    cout << "sizeof(Krol ) = " << sizeof(Krol ) << endl;
    cout << "sizeof(Krol*) = " << sizeof(Krol*) << endl
                                                << endl;
    insertionSort(krolowie, ile);

    for ( int i =0; i < ile; i++ )
        cout << setw(28) << krolowie[i]->imie
             << setw(5)  << krolowie[i]->ur << endl;
}

void insertionSort(Krol* a[], int wymiar) {
    if ( wymiar <= 1 ) return;

    for ( int i = 1 ; i < wymiar ; ++i ) {
        int j = i;
        Krol* v = a[i];
        while ( j >= 1 && v->ur < a[j-1]->ur ) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = v;
    }
}
