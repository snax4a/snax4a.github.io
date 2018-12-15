#include <iostream>
#include <string>
using namespace std;

int main() {
    long double ld = 0;
    string      st = "Hermenegilda";
    short       sh = 0;
    long       *lo = nullptr;
    cout << "long double: " << sizeof ld         << endl
         << "double     : " << sizeof(double)    << endl
         << "float      : " << sizeof(float)     << endl
         << "long long  : " << sizeof(long long) << endl
         << "long       : " << sizeof(long)      << endl
         << "int        : " << sizeof(int)       << endl
         << "short      : " << sizeof sh         << endl
         << "char       : " << sizeof(char)      << endl
         << "wchar_t    : " << sizeof(wchar_t)   << endl
         << "char16_t   : " << sizeof(char16_t)  << endl
         << "char32_t   : " << sizeof(char32_t)  << endl
         << "bool       : " << sizeof(bool)      << endl
         << "string     : " << sizeof st         << endl
         << "long*      : " << sizeof lo         << endl;
}
