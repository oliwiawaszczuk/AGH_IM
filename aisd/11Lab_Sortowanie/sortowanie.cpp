#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void wypisz(int *tab, int n) {
    for (int i=0; i<n; i++)
        cout << tab[i] << " ";
    cout << endl;
}

int sl(int *tab, int n) {
    int value = 0;

    for (int i=0; i<n; i++)
        value += tab[i];

    return value;
}

int swbr(int *tab, int n) {
    int value = 0;

    for (int i=1; i<n; i++)
        value += abs(tab[i]-tab[i-1]);

    return value;
}

void babelkowe(int *tab, int n) {
    for (int i=0; i<n; i++)
        for (int j=1; j<n; j++)
            if (tab[i] < tab[j-1])
                swap(tab[i], tab[j-1]);
}

void qs(int *tab, int min, int max) {
    int i = min;
    int j = max;

    int mid = tab[(min+max) / 2];

    while (i <= j) {
        while (tab[i] < mid) i++;
        while (tab[j] > mid) j--;

        if (i <= j) {
            swap(tab[i], tab[j]);
            i++;
            j--;
        }
    }

    if (min < j) qs(tab, min, j);
    if (max > i) qs(tab, i, max);
}

void wstawianie(int *tab, int n) {
    for (int i=0; i<n; i++) {
        int j = i-1;

        while (tab[i] < tab[j] && j >= 0) {
            tab[j+1] = tab[j];
            j--;
        }
        tab[j+1] = tab[i];
    }
}

int main(int argc, char* argv[])
{
    // string typ = argv[1];
    // string plik = argv[2];

    // cout << typ << " " << plik;

    int n = 10;
    int tab[] = {1, 6, 3, 8, 7, 2, 9, 0, 5, 4};

    cout << "Przed sortowaniem: \nSl: " << sl(tab, n) << "\nSWBR: " << swbr(tab, n) << "\n";

    wypisz(tab, n);
    qs(tab, 0, n);
    wypisz(tab, n);
}