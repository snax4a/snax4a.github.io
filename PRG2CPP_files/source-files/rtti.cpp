#include <iostream>
#include <typeinfo>
using namespace std;

struct Pojazd { };
struct Samochod : Pojazd { };

struct Budynek {
    virtual ~Budynek() { }
};
struct Stacja : Budynek { };



int main() {
    Pojazd    poj;
    Samochod  sam1,sam2;
    Samochod* p_sam1 = &sam1;
    Pojazd*   p_sam2 = &sam2;
    Pojazd&   r_sam1 = sam1;
    cout << "    poj: " << typeid(poj).name()     << endl
         << "   sam1: " << typeid(sam1).name()    << endl
         << "   sam2: " << typeid(sam2).name()    << endl
         << " p_sam1: " << typeid(p_sam1).name()  << endl
         << " p_sam2: " << typeid(p_sam2).name()  << endl
         << "*p_sam1: " << typeid(*p_sam1).name() << endl
         << "*p_sam2: " << typeid(*p_sam2).name() << endl
         << " r_sam1: " << typeid(r_sam1).name()  << endl;

    cout << "Typy *p_sam1 i *p_sam2 sa "
         << (typeid(*p_sam1) == typeid(*p_sam2) ?
                    "takie same\n" : "rozne\n")   << endl;

    Budynek  bud;
    Stacja   sta1,sta2;
    Stacja*  p_sta1 = &sta1;
    Budynek* p_sta2 = &sta2;
    Budynek& r_sta1 = sta1;
    cout << "    bud: " << typeid(bud).name()     << endl
         << "   sta1: " << typeid(sta1).name()    << endl
         << "   sta2: " << typeid(sta2).name()    << endl
         << " p_sta1: " << typeid(p_sta1).name()  << endl
         << " p_sta2: " << typeid(p_sta2).name()  << endl
         << "*p_sta1: " << typeid(*p_sta1).name() << endl
         << "*p_sta2: " << typeid(*p_sta2).name() << endl
         << " r_sta1: " << typeid(r_sta1).name()  << endl;

    cout << "Typy *p_sta1 i *p_sta2 sa "
         << (typeid(*p_sta1) == typeid(*p_sta2) ?
                    "takie same\n" : "rozne\n");
}
