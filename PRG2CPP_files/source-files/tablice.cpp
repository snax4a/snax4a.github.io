#include <iostream>
using namespace std;

void fun1(double tab[]) {
   cout << "Wymiar \'tab\' w fun1: " << sizeof(tab) << endl;
   cout << "Wartosc *tab w fun1: "   << tab[0]      << endl;
}

void fun2(double* tab) {
   cout << "Wymiar \'tab\' w fun2: " << sizeof(tab) << endl;
   cout << "Wartosc *tab w fun2: "   << tab[0]      << endl;
}

int main() {
   double tab[] = {6,2,3,2,1};
   cout << "Wymiar \'tab\' w main: " << sizeof(tab) << endl;
   cout << "Wartosc *tab w main: "   << *tab        << endl;
   fun1(tab);
   fun2(tab);
}
