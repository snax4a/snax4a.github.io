#include <iostream>
using namespace std;

void napisz (const char* tab) {
    cout << "Napis: " << tab << endl;
}

int main() {
    char  tab1[] = "Kasia";
    char  tab2[] = {'B', 'a', 's', 'i', 'a', '\0'};
    const char *tab3 = "Wisia";
    cout << "Wymiar    tab1: "  << sizeof(tab1)   << endl;
    cout << "Wymiar    tab2: "  << sizeof(tab2)   << endl;
    cout << "Wymiar    tab3: "  << sizeof(tab3)   << endl;
    cout << "Wymiar \'Wisia\': "<< sizeof("Wisia")<< endl;

    tab1[0] = 'B';
    tab2[0] = 'K';
    //tab3[0] = 'C'; // ZLE

    napisz(tab1);
    napisz(tab2);
    napisz(tab3);
}
