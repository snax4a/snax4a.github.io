#include <iostream>
#include <cctype>
using namespace std;

int uplow(char* s) {
    int cnt = 0;
    do {
        if (isalpha(*s))
            if ( cnt == 0 || !isalpha(*(s-1))) {
                *s = (char)toupper(*s);
                cnt++;
            } else
                *s = (char)tolower(*s);
    } while (*s++);
    return cnt;
}

int main() {
    char napis[] = "to jEST DlUgI,dluGI nAPIs!";

    int ile = uplow(napis);
    cout << ile << " slow, napis = \'" << napis << "\'\n";
}
