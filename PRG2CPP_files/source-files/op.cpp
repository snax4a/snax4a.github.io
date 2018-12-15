#include <iostream>
#include <cstring>   // memcpy
using namespace std;

class Tabint {
    static int ID;
    int        id;
    int      size;
    int      *tab;
public:
    Tabint(const int *t, int size)
        : id(++ID), size(size),
          tab((int*)memcpy(new int[size], t,
                           size*sizeof(int))) {
        cout << "Konstruktor: id = " << id << endl;
    }

    Tabint(const Tabint& t)
        : id(++ID), size(t.size),
          tab((int*)memcpy(new int[size], t.tab,
                           size*sizeof(int))) {
        cout << "Konstr. kop: " << t.id << "-->" << id
                                                 << endl;
    }

    ~Tabint() {
        cout << "Usuwamy:    id = " << id << endl;
        delete [] tab;
    }

    Tabint& operator=(const Tabint& t) {
        cout << "Przypisanie: " << id << "<--" << t.id
                                               << endl;
        if (this != &t) {
            delete [] tab;
            size = t.size;
            tab = (int*)memcpy(new int[size], t.tab,
                               size*sizeof(int));
        }
        return *this;
    }
};
int Tabint::ID = 0;

int main() {
    int tab[] = {1,2,3};
    int size  = sizeof(tab)/sizeof(int);

    Tabint* pt1 = new Tabint(tab,size);
    Tabint   t2 = *pt1;
    Tabint   t3(t2);

    *pt1 = t2;
}
