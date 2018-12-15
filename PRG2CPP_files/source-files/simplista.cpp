#include <iostream>
using namespace std;

struct Wezel {
    double szer;
    double wyso;
    Wezel *next;
};

void wstaw_dane(Wezel* n, double s, double w, Wezel* next);
void drukuj_liste(const Wezel* n);
void drukuj_liste_odwrotnie(const Wezel* n);

int main() {
    Wezel A = {4, 44, nullptr};
    Wezel B, D, *head;

    Wezel* pC = new Wezel;

    wstaw_dane(&B,3,33,&A);
    wstaw_dane(pC,2,22,&B);
    wstaw_dane(&D,1,11,pC);

    head = &D;

    drukuj_liste(head);
    drukuj_liste_odwrotnie(head);

    delete pC;
}

void wstaw_dane(Wezel* n, double s, double w, Wezel* next) {
    n->szer = s;
    n->wyso = w;
    n->next = next;
}

void drukuj_liste(const Wezel* n) {
    for ( ; n; n = n->next )
        cout << n->szer << " " << n->wyso << "; ";
    cout << endl;
}

void drukuj_liste_odwrotnie(const Wezel* n) {
    if (n == nullptr) return;  // pusta lista
    if (n->next != nullptr)
        drukuj_liste_odwrotnie(n->next);
    cout << n->szer << " " << n->wyso << "; ";
}
