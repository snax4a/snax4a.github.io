#include <iostream>
using namespace std;

int main() {
    auto k = 7;             // k jest typu int
    auto x = 1.;            // x jest typu double
    decltype(x) y = 7;      // y jest typu double, choc
                            // '7' jest literalem typu int
    decltype(k*x) z = 7;    // iloczyn k*x jest typu double
    cout << "k/2="   << k/2 << ", y/2=" << y/2
         << ", z/2=" << z/2 << endl;
}
