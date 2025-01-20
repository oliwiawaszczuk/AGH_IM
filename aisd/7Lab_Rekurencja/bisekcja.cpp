#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Funkcja do obliczania wartości wielomianu w punkcie x
double evaluate_polynomial(const vector<double>& coefficients, double x) {
    double result = 0.0;
    int n = coefficients.size();
    for (int i = 0; i < n; ++i) {
        result += coefficients[i] * pow(x, i); // Dodajemy każdy współczynnik razy x do odpowiedniej potęgi
    }
    return result;
}

// Rekurencyjna funkcja do znajdowania miejsca zerowego wielomianu
double find_root(const vector<double>& coefficients, double a, double b, double epsilon) {
    double mid = (a + b) / 2.0; // Środek przedziału
    double value_mid = evaluate_polynomial(coefficients, mid);

    if (fabs(value_mid) < epsilon) { // Jeśli wartość wielomianu jest wystarczająco bliska zeru
        return mid;
    }

    double value_a = evaluate_polynomial(coefficients, a);

    // Decydujemy, w której części przedziału znajduje się miejsce zerowe
    if (value_a * value_mid < 0) {
        return find_root(coefficients, a, mid, epsilon); // Miejsce zerowe jest w lewej połowie
    } else {
        return find_root(coefficients, mid, b, epsilon); // Miejsce zerowe jest w prawej połowie
    }
}

int main() {
    double a, b;
    int n;

    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "n: ";
    cin >> n;

    vector<double> coefficients(n + 1); // Współczynniki wielomianu

    for (int i = 0; i <= n; ++i) {
        cout << "x" << n+i-1 << ": ";
        cin >> coefficients[i];
    }

    double epsilon = 0.001; // Dokładność
    double root;

    // Sprawdzamy, czy na przedziale a-b istnieje zmiana znaku
    double value_a = evaluate_polynomial(coefficients, a);
    double value_b = evaluate_polynomial(coefficients, b);

    if (value_a * value_b > 0) {
        cout << "Brak miejsca zerowego w zadanym przedziale" << endl;
        return 1;
    }

    try {
        root = find_root(coefficients, a, b, epsilon);
        cout << fixed << setprecision(3);
        cout << "Miejsce zerowe: " << root << endl;
    } catch (const exception& e) {
        cout << "Wystąpił błąd: " << e.what() << endl;
    }

    return 0;
}
