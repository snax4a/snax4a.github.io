#include <iostream>
using namespace std;

int main() {
    cout << "Wpisuj linie tekstu. Zakoncz znakiem konca "
            "pliku\n(Ctrl-Z w Windows, Ctrl-D w Linuksie) "
            "Komentarze\nod \'//\' do konca linii beda "
            "pomijane.\n";
    char c;
    while ( cin.get(c) ) {
        if ( c == '/' )
            if ( cin.peek() == '/') {
                cin.ignore(1024,'\n');
                cout << endl;
                continue;
            }
        cout << c;
    }
}
