#include <iostream>
using namespace std;

int main() {
    const int st_size = 7;

    int oceny[][st_size] = { { 5, 4, 3, 3, 3, 4, 4 },
                             { 5, 3, 3, 3, 4, 2, 3 },
                             { 4, 4, 4, 4, 3, 3, 5 } };

    int gr_size = sizeof(oceny)/sizeof(oceny[0]);

    bool jestDwoja = false;

    for (int grupa = 0; grupa < gr_size; grupa++)
        for (int student = 0; student < st_size; student++)
            if ( oceny[grupa][student] == 2 ) {
                jestDwoja = true;
                goto KONIEC;
            }
KONIEC:
    if (jestDwoja) cout << "Byla dwojka"   << endl;
    else           cout << "Nie ma dwojki" << endl;
}
