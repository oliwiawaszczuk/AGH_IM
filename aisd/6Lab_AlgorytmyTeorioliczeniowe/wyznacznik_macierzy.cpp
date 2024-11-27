#include <iostream>
#include <vector>
using namespace std;

// Funkcja do obliczania wyznacznika
double oblicz_wyznacznik(vector<vector<double>>& macierz, int n) {
    // Używamy algorytmu eliminacji Gaussa (bez rekurencji)
    double det = 1.0;  // Wartość wyznacznika
    for (int i = 0; i < n; i++) {
        // Jeśli element na diagonali jest zerowy, próbujemy zamienić wiersze
        if (macierz[i][i] == 0) {
            bool zamiana = false;
            for (int j = i + 1; j < n; j++) {
                if (macierz[j][i] != 0) {
                    // Zamiana wierszy
                    swap(macierz[i], macierz[j]);
                    det *= -1;  // Zamiana wierszy zmienia znak wyznacznika
                    zamiana = true;
                    break;
                }
            }
            // Jeśli po sprawdzeniu nie ma elementu różnego od zera, wyznacznik = 0
            if (!zamiana) {
                return 0;
            }
        }

        // Wykonanie eliminacji Gaussa
        for (int j = i + 1; j < n; j++) {
            if (macierz[j][i] != 0) {
                double faktor = macierz[j][i] / macierz[i][i];
                for (int k = i; k < n; k++) {
                    macierz[j][k] -= faktor * macierz[i][k];
                }
            }
        }
    }

    // Wyznacznik to iloczyn elementów na głównej przekątnej
    for (int i = 0; i < n; i++) {
        det *= macierz[i][i];
    }
    return det;
}

int main() {
    int n;
    cin >> n;

    vector<vector<double>> macierz(n, vector<double>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> macierz[i][j];
        }
    }

    double wynik = oblicz_wyznacznik(macierz, n);
    cout << "Wyznacznik: " << wynik << endl;

    return 0;
}
