#include <iostream>
using namespace std;

union Bag;

void wstaw(Bag*,float);
void wstaw(Bag*,long double);
void infor(const Bag*);

union Bag {
    float       liczbaF;
    long double liczbaLD;
} bag ;

int main() {
    cout << "      sizeof(float)=" << sizeof(float) << endl;
    cout << "sizeof(long double)="
         << sizeof(long double) << endl;
    cout << "        sizeof(Bag)=" << sizeof(Bag) << endl;

    wstaw(&bag, 3.14F);
    infor(&bag);

    wstaw(&bag, 3.14L);
    infor(&bag);
}

void wstaw(Bag *w, float f) {
    w->liczbaF = f;
}

void wstaw(Bag *w, long double ld) {
    w->liczbaLD = ld;
}

void infor(const Bag *w) {
    cout << "\nliczbaF : " << w->liczbaF  << endl;
    cout <<   "liczbaLD: " << w->liczbaLD << endl;
}
