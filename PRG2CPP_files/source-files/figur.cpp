#include <iostream>
using namespace std;

class Figura {
protected:
    int  height;
public:
    Figura(int height = 0) : height(height)
    { }

    virtual void what() {
        cout << "Figura: h=" << height <<endl;
    }
};

class Prostokat : public Figura {
private:
    int  base;
    void what() {
        cout << "Prostokat: (h,b)=(" << height
             << "," << base << ")\n";
    }
public:
    Prostokat(int height = 0, int base = 0)
        : Figura(height), base(base)
    { }
};

int main() {
    Figura    *f = new Prostokat(4,5)  , &rf = *f;
    Prostokat *p = new Prostokat(40,50);

      // what w Prostokat private, ale w Figura nie!
    f->what();                         // Prostokat
    rf.what();                         // Prostokat

      // p->what(); nie, bo what prywatne w Prostokat
      // Ale ponizsze legalne!
    ((Figura*)p)->what();              // Prostokat
    ((Figura&)*p).what();              // Prostokat

      // OK: wersja publiczna z klasy bazowej Figura
    p->Figura::what();                 // Figura
}
