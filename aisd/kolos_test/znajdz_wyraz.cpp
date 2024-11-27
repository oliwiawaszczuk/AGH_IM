#include <iostream>
using namespace std;

int znajdz_wyraz(char * tekst, int n_tekst, char * wyraz, int n_wyraz) {
    for (int i=0; i<n_tekst; i++) {
        if (tekst[i] == wyraz[0]) {
            int j;
            for (j = 0; j < n_wyraz; j++)
                if (tekst[i + j] != wyraz[j])
                    break;
            if (j == n_wyraz)
                return i;
        }
    }
    return -1;
}

int main() {
    znajdz_wyraz("Ala ma kota", 11, "ma", 2);
    return 0;
}
