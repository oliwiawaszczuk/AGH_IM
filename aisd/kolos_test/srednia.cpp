#include <iostream>
#include <iomanip>
using namespace std;

double srednia(float* tab, int n) {
    double wynik = 0;
    int suma = 0;

    for(int i=0; i<n; i++) {
        suma += tab[i];
    }

    wynik = (double)suma/n;

    return wynik;
}

int main() {
    int n;
    cout << "N: ";
    cin >> n;
    if (n<=0) {
        cout << "Nie można policzyć średniej";
        return 1;
    }
    float* tab = new float[n];
    for (int i=0; i<n; i++) {
        cout << "a: ";
        cin >> tab[i];
    }

    cout << fixed;
    cout << setprecision(2);
    cout << "Średnia: " << srednia(tab, n);
    return 0;
}
