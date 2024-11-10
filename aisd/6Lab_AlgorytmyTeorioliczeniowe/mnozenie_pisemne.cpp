#include <iostream>
#include <string>
using namespace std;

long a, b;
int size_a, size_b, n, m;
int** resultMatrix;

void wypisz_macierz() {
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cout << resultMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int pow(int podstawa, int wykladnik) {
    int wynik = 1;
    for (int i = 0; i<wykladnik; i++)
        wynik*=podstawa;
    return wynik;
}

int main() {
    cout << "Podaj a: \nPodaj b:\n";
    cin >> a >> b;

    string znak = "";
    if (a*b < 0)
        znak = " - ";

    size_a = to_string(a).length();
    size_b = to_string(b).length();

    // jesli ujemne to na dodatnie
    if (a<0)
        a = -a;
    if (b<0)
        b = -b;

    n = size_a + size_b - 1;
    m = size_b;

    // wrzucenie liczb do tablicy - na jedna komórkę przypada jedna cyfra
    int* cyfry_a = new int[size_a];
    for (int i = size_a - 1; i >= 0; --i) {
        cyfry_a[i] = a % 10;
        a /= 10;
    }
    int* cyfry_b = new int[size_b];
    for (int i = size_b - 1; i >= 0; --i) {
        cyfry_b[i] = b % 10;
        b /= 10;
    }

    // alokowanie pamieci tablicy z wynikami + wypelnienie jej 0
    resultMatrix = new int*[m];
    for(int i=0; i<m; i++)
        resultMatrix[i] = new int[n];

    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            resultMatrix[i][j] = 0;

    // wlasciwe liczenie - wrzucenie w macierz
    for (int j=size_b-1, y=0; j>=0; j--, y++) {
        int x = n - 1 - y;
        for(int i=size_a-1; i>=0; i--) {
            resultMatrix[y][x] = cyfry_a[i]*cyfry_b[j];
            x--;
        }
    }

    // dodawanie macierzy
    int k = 0;
    long result = 0;
    int beforeSum = 0;
    for (int i = n-1; i >= 0; i--) {
        int tempSum = beforeSum;
        for (int j = 0; j < m; j++) {
            tempSum += resultMatrix[j][i];
        }

        result += pow(10, k) * (tempSum % 10);
        beforeSum = tempSum / 10;
        k++;
    }

    if (beforeSum > 0)
        result += beforeSum * pow(10, k);

    cout << "Wynik: " << znak << result;

    return 0;
}
