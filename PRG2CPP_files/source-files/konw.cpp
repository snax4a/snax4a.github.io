#include <iostream>
using namespace std;

int konwert(char* nap) {
    int w = 0, i = 0, c;
    while (c = nap[i++], c >= '0' && c <= '9')
        w = 10*w + c - '0';
    return w;
}

int main() {
    char tab1[] = "123a";
    char tab2[] = "456 1";
    char tab3[] = " 56";

    cout << "tab1 -> " << konwert(tab1) << endl;
    cout << "tab2 -> " << konwert(tab2) << endl;
    cout << "tab3 -> " << konwert(tab3) << endl;
}
