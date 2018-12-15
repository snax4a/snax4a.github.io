#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class DoDruku {
protected:
    ostream& str;
public:
    DoDruku(ostream& str)
        : str(str)
    { }
    virtual void druk() const = 0;
};

class Osoba : public DoDruku {
    string imie;
    int    ur;
public:
    Osoba(string i, int u, ostream& str = cout)
        : DoDruku(str), imie(i), ur(u)
    { }

    void druk() const {
        str << imie + " (" << ur << ")" << endl;
    }
};

class Figura {
protected:
    static const double PI;
    string name;
public:
    virtual double getPole() const = 0;
    Figura(string name) : name(name) { }
};
const double Figura::PI = 4*atan(1.);

class Kolo : public Figura, public DoDruku {
    double prom;
public:
    Kolo(string n, double r, ostream& str = cout)
        : Figura(n), DoDruku(str), prom(r)
    { }
    double getPole() const { return PI*prom*prom; }
    void   druk() const {
        str << "kolo " << name << " o promieniu "
            << prom << " i polu " << getPole() << endl;
    }
};

class Kwadrat : public Figura {
    double side;
public:
    Kwadrat(string n, double s)
        : Figura(n),side(s)
    { }
    double getPole() const { return side*side; }
    void druk() const {
        cout << "kwadrat " << name << " o boku "
             << side << " i polu " << getPole() << endl;
    }
};

void drukTable(DoDruku* tab[], int size) {
    for (int i = 0; i < size; ++i)
        tab[i]->druk();
}

int main() {
    Kolo    ci1("pierwsze",2,cout),
          *pci2 = new Kolo("drugie",3);
    Kwadrat sq1("pierwszy",4),
          *psq2 = new Kwadrat("drugi",5);
    Osoba   ps1("Jim",1972),
          *pps2 = new Osoba("Tom",1978,cout);

    DoDruku* tab[] = {&ci1, &ps1, pci2, pps2};

    cout << "** Drukowanie obiektow typu DoDruku" << endl;
    drukTable(tab,4);

    cout << "** Drukowanie kwadratow" << endl;
    sq1.druk();
    psq2->druk();

    delete pci2;
    delete psq2;
    delete pps2;
}
