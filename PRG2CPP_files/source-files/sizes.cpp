#include <iostream>
#include <typeinfo>
using namespace std;

typedef int TABINT15[15];

void siz(TABINT15 t1, TABINT15& t2) {
   cout << "G. t1 w siz: " << sizeof t1 << endl;
   cout << "H. t2 w siz: " << sizeof t2 << endl;
}

int main() {
   TABINT15 tab1;
   int      tab2[15];
   int     *tab3 = tab2;

   if (typeid(tab1) == typeid(tab2))
      cout << "A. Typy tab1 i tab2 takie same"     << endl;
   else
      cout << "A. Typy tab1 i tab2 nie takie same" << endl;

   if (typeid(tab2) == typeid(tab3))
      cout << "B. Typy tab2 i tab3 takie same"     << endl;
   else
      cout << "B. Typy tab2 i tab3 nie takie same" << endl;

   cout << "C. TABINT15: " << sizeof(TABINT15) << endl;
   cout << "D. tab1    : " << sizeof tab1      << endl;
   cout << "E. tab2    : " << sizeof(tab2)     << endl;
   cout << "F. tab3    : " << sizeof tab3      << endl;
   siz(tab2, tab2);
}
