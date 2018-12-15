#include <iostream>
using namespace std;

int zzz;     // globalne, inicjowane zerem

int fun1() {
    return zzz += 1;
}

int fun100() {
    return zzz += 100;
}

int main() {
    cout << fun1() << " " << fun100() << endl;
}
