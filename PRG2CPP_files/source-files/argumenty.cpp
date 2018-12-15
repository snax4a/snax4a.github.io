#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    cout << "Nazwa programu:   " << argv[0]  << endl
         << "Ilosc argumentow: " << argc     << endl;
    for (int i = 1; i < argc; i++)
        cout << "Argumentem nr " << i       << " jest "
                                 << argv[i] << endl;
}
