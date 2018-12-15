#include <iostream>
#include <cmath>     // sin, cos
using namespace std;

struct Punkt {
    double x, y;
};

struct Trojkat {
    Punkt A, B, C;
};

void info(const Punkt*);
void info(const Trojkat*);
void rot(Punkt*,double);
void rot(Trojkat*,double);

int main() {
    Punkt A;
    A.x = -1;
    A.y =  2;

    Punkt B = { -1, 1 };

    Punkt C = { 2 };
    C.y = -1;

    Trojkat T = { A, B };
    T.C = C;

    cout << "Wyjsciowe punty: ";
    info(&A); info(&B); info(&C);
    cout << "\nTrojkat: ";
    info(&T);
    cout << endl;

    rot(&A,90); rot(&B,90); rot(&C,90);
    cout << "A, B, C po obrocie o 90 stopni:\n    ";
    info(&A); info(&B); info(&C);
    cout << endl;

    rot(&T,90); rot(&T,90);
    cout << "T po obrocie dwa razy o 90 stopni:\n    ";
    info(&T);

    rot(&T,180);
    cout << "T po obrocie o nastepne 180 stopni:\n    ";
    info(&T);
}

void info(const Punkt* pP) {
    cout << "(" << pP->x << ", " << pP->y << ") ";
}

void info(const Trojkat* pT) {
    cout << "A="; info(&pT->A);
    cout << "B="; info(&pT->B);
    cout << "C="; info(&pT->C);
    cout << endl;
}

void rot(Punkt* pP, double phi) {
    static double conver = atan(1.)/45;
    phi = phi*conver; // stopnie -> radiany

    double c = pP->x;
    pP->x = pP->x * cos(phi) - pP->y * sin(phi);
    pP->y =     c * sin(phi) + pP->y * cos(phi);
}

void rot(Trojkat* pT, double phi) {
    rot( &pT->A, phi);
    rot( &pT->B, phi);
    rot( &pT->C, phi);
}
