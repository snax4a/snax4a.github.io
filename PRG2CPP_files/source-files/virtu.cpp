#include <iostream>
#include <cmath>     // atan
using namespace std;

class Figura {
protected:
    static const double PI;
public:
    virtual double getPole()      = 0;
    virtual double getObwod()     = 0;
    virtual void   info(ostream&) = 0;
    static  double totalPole(Figura* tab[], int size) {
        double suma = 0;
        for (int i = 0; i < size; ++i)
            suma += tab[i]->getPole();
        return suma;
    }
    static  Figura* maxObwod(Figura* tab[], int size) {
        int ind = 0;
        for (int i = 0; i < size; ++i)
            if (tab[i]->getObwod() >
                    tab[ind]->getObwod())
                ind = i;
        return tab[ind];
    }
};
const double Figura::PI = 4*atan(1.);
void Figura::info(ostream& str) {
    str << "Figura: ";
}

class Kolo : public Figura {
    double promien;
public:
    Kolo(double r) : promien(r){ }
    double getPole()           { return PI*promien*promien; }
    double getObwod()          { return 2*PI*promien; }
    void   info(ostream& str)  {
        Figura::info(str);
        str << "kolo o promieniu  " << promien;
    }
};

class Kwadrat : public Figura {
    double bok;
public:
    Kwadrat(double s) : bok(s) { }
    double getPole()           { return bok*bok; }
    double getObwod()          { return 4*bok; }
    void   info(ostream& str)  {
        Figura::info(str);
        str << "kwadrat o boku    " << bok;
    }
};

int main() {
    Figura* tab[] = { new Kolo(1.), new Kwadrat(1.),
                      new Kolo(2.), new Kwadrat(3.)
                    };
    int size = sizeof(tab)/sizeof(tab[0]);
    for (int i = 0; i < size; ++i) {
        tab[i]->info(cout);
        cout << endl;
    }
    Figura* maxobw = Figura::maxObwod(tab,size);
    cout << "Suma pol: " << Figura::totalPole(tab,size)
         << "\nFigura o najwiekszym obwodzie: ";
    maxobw->info(cout);
    cout <<  "\n ma obwod "
         << maxobw->getObwod() << endl;
}
