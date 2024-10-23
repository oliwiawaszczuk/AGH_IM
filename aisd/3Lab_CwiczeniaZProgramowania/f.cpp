// Napisz program, który utworzy tablicę jednowymiarową o rozmiarze 'n' i wypełni ją liczbami pseudolosowymi, wykorzystując funkcję rand(), z zakresu [0, 100) (operator modulo). Program wczyta ziarno do ustawienia generatora liczby losowej fukcją srand(). Następnie program wypisze całą tablicę, a następnie sąsiadujące ze sobą pary liczb.  W programie nie można korzystać z operatora indeksowania [ ] i pętli for. Program wypisuje liczby na 6 miejscach.

#include <iostream>
using namespace std;

int main() {
    int n_size, seed;
    cin >> seed >> n_size;
    srand(seed);
    cout << "Ziarno: " << endl;
    cout << "N: " << endl;

    int *tab = new int [n_size];

    int i = 0;
    while (i < n_size) {
        tab[i] = rand() % 100;
        i++;
    }

    int *wsk = tab;
    i = 0;
    while (i < n_size) {
        cout << *wsk << " ";
        wsk++;
        i++;
    }

    cout << "\nPary: \n";
    wsk = tab;
    i = 0;
    while (i < n_size-1) {
        cout << *wsk << " ";
        wsk++;
        cout << *wsk << endl;
        i++;
    }

    delete [] tab;

    return 0;
} 