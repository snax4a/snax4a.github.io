#include <iostream>
using namespace std;

void funtab(double[]);
void funref(double (&)[6]);

int main() {
    double tab[] = {1,2,3,4,5,6};
    cout << "Wymiar double : " << sizeof(double)  << endl;
    cout << "Wymiar double*: " << sizeof(double*) << endl;
    cout << "Wymiar tab w main: " << sizeof(tab)  << endl;
    funtab(tab);
    funref(tab);
}

void funtab(double t[]) {
    cout << "Wymiar t w funtab: " << sizeof(t) << endl;
}

void funref(double (&t)[6]) {
    cout << "Wymiar t w funref: " << sizeof(t) << endl;
}
