#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cctype>
#include <cmath>
using namespace std;

// Funkcja zwracająca priorytet operatora
int priorytet(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3; // Potęgowanie
    return 0; // Dla nawiasów i innych znaków
}

// Funkcja przekształcająca infiks na ONP
string infixToONP(const string& wyrazenie) {
    stack<char> stos;
    string wynik;

    for (size_t i = 0; i < wyrazenie.length(); ++i) {
        char znak = wyrazenie[i];

        if (isdigit(znak)) { // Liczba
            wynik += znak;
            // Umożliwia obsługę liczb wielocyfrowych
            while (i + 1 < wyrazenie.length() && isdigit(wyrazenie[i + 1])) {
                wynik += wyrazenie[++i];
            }
            wynik += ' ';
        } else if (znak == '(') { // Nawias otwierający
            stos.push(znak);
        } else if (znak == ')') { // Nawias zamykający
            while (!stos.empty() && stos.top() != '(') {
                wynik += stos.top();
                wynik += ' ';
                stos.pop();
            }
            stos.pop(); // Usunięcie nawiasu otwierającego
        } else if (znak == '+' || znak == '-' || znak == '*' || znak == '/' || znak == '^') { // Operator
            while (!stos.empty() && priorytet(stos.top()) >= priorytet(znak)) {
                wynik += stos.top();
                wynik += ' ';
                stos.pop();
            }
            stos.push(znak);
        }
    }

    // Opróżnianie stosu z pozostałych operatorów
    while (!stos.empty()) {
        wynik += stos.top();
        wynik += ' ';
        stos.pop();
    }

    return wynik;
}

// Funkcja obliczająca wartość wyrażenia w ONP
double obliczONP(const string& wyrazenieONP) {
    stack<double> stos;
    stringstream ss(wyrazenieONP);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) { // Liczba
            stos.push(stod(token));
        } else { // Operator
            double b = stos.top(); stos.pop();
            double a = stos.top(); stos.pop();

            if (token == "+") stos.push(a + b);
            else if (token == "-") stos.push(a - b);
            else if (token == "*") stos.push(a * b);
            else if (token == "/") stos.push(a / b);
            else if (token == "^") stos.push(pow(a, b));
        }
    }

    return stos.top();
}

int main() {
    string wyrazenie;

    cout << "Podaj wyrażenie algebraiczne: ";
    getline(cin, wyrazenie);

    string onp = infixToONP(wyrazenie);
    double wynik = obliczONP(onp);

    cout << "Wyrażenie: " << wyrazenie << endl;
    cout << "ONP: " << onp << endl;
    cout << "Wynik: " << wynik << endl;

    return 0;
}
