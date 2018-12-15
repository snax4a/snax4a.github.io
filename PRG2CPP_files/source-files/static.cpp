#include <iostream>
using namespace std;

int licznik;

void fun1() {
    static int licznik;
    licznik++;   // lokalna
    ::licznik++; // globalna
    cout << "Wywolan   fun1: " << licznik << endl;
}

void fun2() {
    static int licznik;
    licznik++;   // lokalna
    ::licznik++; // globalna
    cout << "Wywolan   fun2: " << licznik << endl;
}

int main() {
    fun1(); fun1(); fun2(); fun1(); fun2();
    cout << "Wywolan fun1/2: " << licznik << endl;
}
