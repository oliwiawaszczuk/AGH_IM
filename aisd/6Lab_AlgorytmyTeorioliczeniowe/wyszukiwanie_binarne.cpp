#include <iostream>
using namespace std;

// Funkcja do wykonania wyszukiwania binarnego
int wyszukiwanie_binarne(int tablica[], int rozmiar, int szukana) {
    int lewy = 0;
    int prawy = rozmiar - 1;

    while (lewy <= prawy) {
        int srodek = lewy + (prawy - lewy) / 2;

        if (tablica[srodek] == szukana)
            return srodek;
        else if (tablica[srodek] < szukana)
            lewy = srodek + 1;
        else
            prawy = srodek - 1;
    }

    return -1;
}

int main() {
    int rozmiar;
    cout << "Rozmiar: ";
    cin >> rozmiar;

    int tablica[rozmiar];

    cout << "Elementy:\n";
    for (int i = 0; i < rozmiar; i++) {
        cin >> tablica[i];
    }

    int szukana;
    cout << "Szukana liczba: ";
    cin >> szukana;

    int znaleziono = wyszukiwanie_binarne(tablica, rozmiar, szukana);

    if (znaleziono == -1)
        cout << "Podanej liczby " << szukana << " nie ma w tablicy";
    else
        cout << "Liczba " << szukana << " znajduje się w polu o indeksie " << znaleziono+1;

    return 0;
}
