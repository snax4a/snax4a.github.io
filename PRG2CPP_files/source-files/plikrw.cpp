#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int tab[] = { 97, 105, 115, 255, 111 },k;

    int size = sizeof(tab)/sizeof(tab[0]);

    cout << "Tablica o  wymiarze: " << size << endl;
    for (int i = 0; i < size; ++i)
        cout << tab[i] << " ";
    cout << endl;

    ofstream file_out("file.dat",ios::out|ios::binary);
    if (! file_out ) {
        cout << "Nie mozna otworzyc file_out" << endl;
        return -1;
    }

    file_out.write((char*)tab, sizeof(tab));
    file_out.close();

    fstream file("file.dat",ios::in|ios::out|ios::binary);
    if (! file ) {
        cout << "Nie mozna otworzyc file" << endl;
        return -1;
    }

    file.seekg(0,ios::end);
    streamsize len = file.tellg();
    cout << "Plik ma dlugosc " << len << " bajtow\n";
    file.seekg(0);

    cout << "Kolejne bajty zawieraja:" << endl;
    while ( (k = file.get()) != EOF )
        cout << k << " ";
    cout << endl;

    file.clear(); // <-- KONIECZNE !!!

    file.seekg(4);
    file.read((char*)&k,4);
    cout << "Integer od pozycji 4: " << k << endl;

    file.seekp(12);
    file.write((char*)&k,4);

    file.seekg(0);
    cout << "Kolejne bajty pliku teraz zawieraja:" << endl;
    while ( (k = file.get()) != EOF )
        cout << k << " ";
    cout << endl;

    file.close();
}
