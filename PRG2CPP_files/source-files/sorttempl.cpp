#include <iostream>
#include <cstring>    // memcpy
using namespace std;

template<typename T>
void pisztab(ostream&,const T[],int);

template<typename T>
void inssort(T[],int);

template<typename T>
double minmaxmed(const T[],int,T&,T&);

template<typename T>
void test(T[],int);

int main() {
    cout << "\n===tablica int===" << endl;
    int tabi[] = {9,7,2,6,6,2,7,9,2,9,5,2};
    test(tabi,sizeof(tabi)/sizeof(int));

    cout << "\n===tablica double===" << endl;
    double tabd[] = {9.5,2.5,6,7.5,9,2,5,2.5};
    test(tabd,sizeof(tabd)/sizeof(double));

    cout << "\n===tablica unsigned===" << endl;
    unsigned tabu[] = {23,32,12,76,21,45,20,67};
    test(tabu,sizeof(tabu)/sizeof(unsigned));
}

template<typename T>
void test(T tab[],int size) {
    T min, max;

    double mediana = minmaxmed(tab,size,min,max);

    cout << "min = " << min << ", max = " << max
         << ", mediana = "  <<  mediana   << endl;

    cout << "Tablica  oryginalna: ";
    pisztab(cout, tab, size);

    inssort(tab, size);

    cout << "Tablica posortowana: ";
    pisztab(cout, tab, size);
}

template<typename T>
void pisztab(ostream& str, const T t[], int size) {
    str << "[ ";
    for (int i = 0; i < size; ++i) str << t[i] << " ";
    str << "]" << endl;
}

template<typename T>
void inssort(T a[], int size) {
    int i, indmin = 0;            // wartownik
    for (i = 1; i < size; ++i)
        if (a[i] < a[indmin]) indmin = i;
    if (indmin != 0) {
        T p = a[0];
        a[0] = a[indmin];
        a[indmin] = p;
    }

    for (i = 2; i < size; ++i) {  // sortowanie
        int j = i;
        T v = a[i];
        while (v < a[j-1]) {
            a[j] = a[j-1];
            j--;
        }
        if (i != j ) a[j] = v;
    }
}

template<typename T>
double minmaxmed(const T t[], int size, T& min, T& max) {
    T* tab = new T[size];
    memcpy(tab,t,size*sizeof(T));

    inssort(tab, size);

    min            = tab[0];
    max            = tab[size-1];
    double mediana = size%2 == 0 ?
                       0.5*(tab[size/2] + tab[size/2-1])
                     : tab[size/2];

    delete [] tab;
    return mediana;
}
