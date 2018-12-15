#include <iostream>
#include <string>
using namespace std;

struct maniparg {
    string str;
    maniparg(int ile, char c) : str(ile,c) { }
    ostream& operator()(ostream& s) const {
        return s << str;
    }
};

ostream& operator<<(ostream& s, const maniparg& manip) {
    return manip(s);
}

int main() {
    cout << maniparg(7,'*') << "To jest maniparg"
         << maniparg(3,'!') << maniparg(7,'*') << endl;

    maniparg trzywykrzykniki(3,'!');
    maniparg siedemgwiazdek (7,'*');

    cout << siedemgwiazdek  <<  "To jest maniparg"
         << trzywykrzykniki << siedemgwiazdek  << endl;
}
