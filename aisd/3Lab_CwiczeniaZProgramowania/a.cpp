// Napisz program, który pobiera liczbę całkowitą ‘rozmiar’. Następnie program, wykorzystując pętlę ‘for’, rysuje szachownicę o zadanym rozmiarze. Szachownicę proszę narysować ze znaków podwójnej spacji ‘  ‘ i podwójnego znaku hash ‘##’.

#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string space = "  ", hash = "##";
    string current = hash;
    int size;
    cout << "Podaj rozmiar szachownicy: ";
    cin >> size;

    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            cout << current;
            current = current == space ? hash : space; 
        }
        cout << endl;
        if (size % 2 == 0) 
            current = current == space ? hash : space; 
    }

    return 0;
}