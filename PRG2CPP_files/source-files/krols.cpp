#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void insertionSort(string[],int);

int main() {
    int i;
    string krolowie[] = {
          string("Zygmunt"),   string("Michal"),
          string("Wladyslaw"), string("Anna"),
          string("Jan"),       string("Boleslaw")
                        };

    const int ile = sizeof(krolowie)/sizeof(string);

    insertionSort(krolowie, ile);

    for ( i = 0; i < ile; i++ )
        cout << setw(10) << krolowie[i] << endl;
}

void insertionSort(string a[], int wymiar) {
    if ( wymiar <= 1 ) return;

    for ( int i = 1 ; i < wymiar ; ++i ) {
        int j = i;
        string v = a[i];
        while ( j >= 1 && v < a[j-1] ) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = v;
    }
}
