#include <iostream>
#include <string>
using namespace std;

enum dni {pon, wto=0, sro=0, czw=0, pia=0, sob, nie};

void info(dni day) {
    static string  typDnia[]={" powszedni",
                              "   sobotni", "swiateczny"};
    int stawka = 200*(1 + day);
    cout << "Dzien "  << typDnia[day]   << ". "
         << "Stawka wynosi: " << stawka << " PLN\n";
}

int main() {
    info(pon);

    dni dzien = sob;
    info(dzien);

    dzien = nie;
    info(dzien);
}
