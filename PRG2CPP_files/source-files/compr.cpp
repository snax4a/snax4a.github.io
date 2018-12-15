#include <iostream>
#include <cmath>      // sqrt
#include <vector>
#include <algorithm>  // sort, copy
#include <iterator>
using namespace std;

struct Komp {
   enum Sposoby {
       wg_sumy_cyfr,
       wg_ilosci_dzielnikow,
       wg_wartosci,
       wg_wart_odwrotnie
   };

   Komp(Sposoby sposob): sposob(sposob) { }

   int operator()(int n1, int n2);

   class BrakKomparatora { };

private:
   Sposoby sposob;

   static int suma_cyfr(int n);
   static int ilosc_dzi(int n);
};

int Komp::operator()(int n1, int n2) {
   switch (sposob) {
       case wg_sumy_cyfr:
           return suma_cyfr(n1) < suma_cyfr(n2);
       case wg_ilosci_dzielnikow:
           return ilosc_dzi(n1) < ilosc_dzi(n2);
       case wg_wartosci:
           return n1 < n2;
       case wg_wart_odwrotnie:
           return n2 < n1;
       default:
           throw BrakKomparatora();
                        // nigdy sie nie zdarzy
   }
}

int Komp::suma_cyfr(int n) {
   // suma cyfr liczby calkowitej n (liczac
   // wszystkie  cyfry ze znakiem  dodatnim)
   n = n >= 0 ? n : -n;
   int s = 0;
   while (n) { s += n%10; n /= 10; }
   return s;
}

int Komp::ilosc_dzi(int n) {
   // ilosc dodatnich dzielnikow liczby calkowitej
   // n (wliczajac jedynke i sama liczbe n)
   n = n > 0 ? n : -n;
   if ( n < 3 ) return n;
   int sr = (int) sqrt(n+0.5);
   int ilosc = (sr*sr == n ? 1 : 2);
   for (int i = 2; i <= sr; ++i) if (n%i == 0) ilosc += 2;
   return ilosc;
}

int main() {
   int tab[] = {7, 4, 8, 12, 13, 119, 16, 6};
   vector<int> v(tab,tab+sizeof(tab)/sizeof(int));
   v.push_back(64);

    // sortujemy roznymi sposobami i wyswietlamy wyniki

   cout <<   "Sortujemy wg. sumy cyfr\n";
   sort(v.begin(),v.end(),Komp(Komp::wg_sumy_cyfr));
   copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));

   cout << "\nSortujemy wg. ilosci dzielnikow\n";
   sort(v.begin(),v.end(),Komp(Komp::wg_ilosci_dzielnikow));
   copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));


   cout << "\nSortujemy wg. wartosci\n";
   sort(v.begin(),v.end(),Komp(Komp::wg_wartosci));
   copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));

   cout << "\nSortujemy wg. wartosci odwrotnie\n";
   sort(v.begin(),v.end(),Komp(Komp::wg_wart_odwrotnie));
   copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));

   cout << endl;
}
