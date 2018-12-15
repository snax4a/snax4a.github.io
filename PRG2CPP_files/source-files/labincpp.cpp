#include <iostream>
using namespace std;

int main() {
    int tab[2][2][2]{{{1,2},{3,4}},{{5,6},{7,8}}};
    bool jest = false;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                if (tab[i][j][k] == 5) {
                    jest = true;
                    goto LAB;
                }
    LAB:if(jest)
        cout << "5 jest w tablicy" << endl;
    else
        cout << "5 nie wystepuje w w tablicy" << endl;
}
