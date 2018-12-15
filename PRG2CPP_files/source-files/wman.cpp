#include <iostream>
using namespace std;

ostream& naukowy(ostream&);
ostream& normalny(ostream&);
ostream& przec(ostream&);

int main() {
    double x = 123.456;
    cout << naukowy  << x << przec
         << normalny << x << endl;
}

ostream& naukowy(ostream& str) {
    str.setf(ios::showpos | ios::showpoint);
    str.setf(ios::scientific, ios::floatfield);
    str.precision(12);
    return str;
}

ostream& normalny(ostream& str) {
    str.flags((ios::fmtflags)0);
    return str;
}

ostream& przec(ostream& str) {
    return str << ", ";
}
