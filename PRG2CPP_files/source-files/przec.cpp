#include <iostream>
using namespace std;

int main() {
    int r = 0;
    int k;

    while (cin >> k, k) {
       r += k > 0 ? (cout << "Dodatnia\n" , +1)
                  : (cout << "Ujemna\n"   , -1);
    }
    cout << "Roznica ilosci dodatnich i ujemnych : "
         << r << endl;
}
