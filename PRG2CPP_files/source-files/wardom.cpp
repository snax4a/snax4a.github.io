#include <iostream>
using namespace std;

double PI = 3;

double kolo(double, double = PI);

int main() {
    double r = 1;

    cout << "1. PI = " << PI << " Pow = "
                       << kolo(r) << endl;
    double PI = 3.14;
    cout << "2. PI = " << PI << " Pow = "
                       << kolo(r) << endl;
    ::PI = 3.14;
    cout << "3. PI = " << PI << " Pow = "
                       << kolo(r) << endl;
}

double kolo(double r, double pi) {
    return pi*r*r;
}
