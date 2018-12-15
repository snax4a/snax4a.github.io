#include <iostream>
using namespace std;

struct Punkt {
    double x, y;

    Punkt(double x, double y)
        : x(x), y(y)
    { }

    void show() const {
        cout << "(" <<  x << "," << y << ")";
    }
};

struct Trojkat {
    Punkt a, b, c;

    Trojkat(const Punkt&,const Punkt&,const Punkt&);
    Trojkat(double,double,double,double,double,double);

    void show() const {
        cout << "Trojkat ";
        a.show(); cout << "-";
        b.show(); cout << "-";
        c.show(); cout << endl;
    }
};

Trojkat::Trojkat(const Punkt &a, const Punkt &b,
                                 const Punkt &c)
    : a(a), b(b), c(c)
{ }

Trojkat::Trojkat(double x1, double y1, double x2,
                 double y2, double x3, double y3)
    : a(x1,y1), b(x2,y2), c(x3,y3)
{ }

int main() {
    Punkt a1(1,1), b1(2,2), c1(3,3);

    Trojkat T1(a1,b1,c1);

    Trojkat T2(11,22,22,33,33,44);

    T1.show();
    T2.show();
}
