#include <iostream>
using namespace std;

int main() {
    int a = 0xdf, b = 0771, c = 123;

    cout << "dec (default): "
         << dec << a << " " << b << " " << c << endl;

    cout << "hex bez showbase: "
         << hex << a << " " << b << " " << c << endl;

    cout.setf(ios::showbase);

    cout << "hex z showbase:   "
         << a << " " << b << " " << c << endl;

    cout << "oct z showbase:   "
         << oct << a << " " << b << " " << c << endl;

    cout.unsetf(ios::showbase);

    cout << "oct bez showbase: "
         << a << " " << b << " " << c << endl;
}
