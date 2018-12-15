#include <iostream>
using namespace std;

void   pisztab(ostream&,const int[],size_t);
void   inssort(int[],size_t);
double minmaxmed(const int[],size_t,int&,int&);

int main() {
    int tab[] = {7,2,6,4,7,5}, min, max;
    size_t size = sizeof(tab)/sizeof(tab[0]);

    double mediana = minmaxmed(tab,size,min,max);

    cout << "min = " << min << ", max = " << max
         << ", mediana = "  <<  mediana   << endl;

    cout << "Tablica  oryginalna: ";
    pisztab(cout, tab, size);

    inssort(tab, size);

    cout << "Tablica posortowana: ";
    pisztab(cout, tab, size);
}

void pisztab(ostream& str, const int t[], size_t size) {
    str << "[ ";
    for (size_t i = 0; i < size; ++i) str << t[i] << " ";
    str << "]" << endl;
}

void inssort(int a[], size_t siz) {
    size_t indmin = 0;
    for (size_t i = 1; i < siz; ++i)
        if (a[i] < a[indmin]) indmin = i;
    if (indmin != 0) {
        int p = a[0];
        a[0] = a[indmin];
        a[indmin] = p;
    }
    for (size_t i = 2; i < siz; ++i) {
        size_t j = i;
        int v = a[i];
        while (v < a[j-1]) { a[j] = a[j-1]; j--; }
        if (i != j ) a[j] = v;
    }
}

double minmaxmed(const int t[], size_t size,
                 int& min, int& max) {
    int* tab = new int[size];

    // byloby lepiej za pomoca memcpy...
    for (size_t i = 0; i < size; ++i) tab[i] = t[i];

    inssort(tab, size);

    min = tab[0];
    max = tab[size-1];

    double mediana = size%2 == 0 ?
                0.5*(tab[size/2] + tab[size/2-1])
              : tab[size/2];
    delete [] tab;
    return mediana;
}
