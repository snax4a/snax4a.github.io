#include <iostream>
using namespace std;

int main() {
    // starszy bajt: 'a'; mlodszy bajt: 'b'
    short sh = 'b'+256*'a';

    void *v = static_cast<void*>(&sh);
    char *c = static_cast<char*>(v);
    cout << "Kolejnosc w pamieci: najpierw "
         << c[0] << " potem " << c[1] << endl;
}
