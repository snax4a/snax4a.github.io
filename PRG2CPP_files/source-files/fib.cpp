#include <iostream>
#include <iomanip>
using namespace std;

int licznik;

int fib(int n) {
    licznik++;
    return (n < 2) ? n : fib(n-1) + fib(n-2);
}

int main() {
    cout << "\n  i       Fib(i)  # wywolan\n"
            "---------------------------" << endl;
    for (int i = 10; i <= 43; i += 3) {
        licznik = 0;
        int w = fib(i);
        cout << setw(3)  << i << setw(12) << w
             << setw(12) << licznik << endl;
    }
}
