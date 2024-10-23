// Napisz program, który pobiera liczbę całkowitą określającą przekroczoną prędkość w stosunku do obowiązującego limitu. Program, wykorzystując instrukcję warunkową ‘switch-case’, podaje (wypisuje na ekran) wartość mandatu nałożonego za wykroczenie wynikającą z przekroczonej prędkości według schematu: 
// 0 ... 10 – 50 PLN,
// 11 ... 20 – 100 PLN,
// 21 – 110 PLN,
// 22 – 120 PLN,
// 23, 27 i 29 – 140 PLN,
// 24, 25 i 28 – 150 PLN,
// 26 – 145 PLN,
// 30 i więcej – 200 PLN..

#include <iostream>
#include <cctype>
#include "main.h"
using namespace std;

void b() {
    int v;
    cin >> v;
    if (v < 0)
        cout << "Prędkość nie może być ujemna" << endl;
    else {
        cout << "Prędkość:" << endl;

        switch (v) {
            case 10:
                cout << "Mandat wynosi 50 PLN" << endl;
                break;
            case 20:
                cout << "Mandat wynosi 100 PLN" << endl;
                break;
            case 21:
                cout << "Mandat wynosi 110 PLN" << endl;
                break;
            case 22:
                cout << "Mandat wynosi 120 PLN" << endl;
                break;
            case 23:
            case 27:
            case 29:
                cout << "Mandat wynosi 140 PLN" << endl;
                break;
            case 24:
            case 25:
            case 28:
                cout << "Mandat wynosi 150 PLN" << endl;
                break;
            case 26:
                cout << "Mandat wynosi 145 PLN" << endl;
                break;
            default:
                switch (v/10) {
                    case 0:
                        cout << "Mandat wynosi 50 PLN" << endl;
                        break;
                    case 1:
                        cout << "Mandat wynosi 100 PLN" << endl;
                        break;
                    default:
                        cout << "Mandat wynosi 200 PLN" << endl;
                }
        }
    }
}