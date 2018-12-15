#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

template <typename Data, int size>
class Stos {
    Data* data;
    int   top;
public:
    Stos();
    bool empty() const;
    void push(Data);
    Data pop();
    ~Stos();
};

template <typename Data, int size>
Stos<Data,size>::Stos() {
    data = new Data[size];
    top = 0;
}

template <typename Data, int size>
inline bool Stos<Data,size>::empty() const {
    return top == 0;
}

template <typename Data, int size>
inline void Stos<Data,size>::push(Data dat) {
    data[top++] = dat;
}

template <typename Data, int size>
inline Data Stos<Data,size>::pop() {
    return data[--top];
}

template <typename Data, int size>
inline Stos<Data,size>::~Stos() {
    delete [] data;
}

  // szablon funkcji globalnej
template <typename Data, int size>
void oproznij(Stos<Data,size>* p_stos) {
    cout << "Stos typu " << typeid(Data).name() << ": ";
    while ( ! p_stos->empty() ) {
        cout << p_stos->pop() << " ";
    }
    cout << endl;
}

int main() {
    Stos<int,20> stos_i;
    stos_i.push(11);
    stos_i.push(36);
    stos_i.push(49);
    stos_i.push(92);

    Stos<string,15> stos_s;
    stos_s.push("Ala");
    stos_s.push("Ela");
    stos_s.push("Ola");
    stos_s.push("Ula");

    oproznij(&stos_i);
    oproznij(&stos_s);
}
