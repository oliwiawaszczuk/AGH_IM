#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char jednostka;
    cin >> jednostka;
    cout << "Jednostka:\nTemperatura";
    float Temperatura, Tf, Tk, Tc;
    bool isGood = true;
    cin >> Temperatura;

    switch (jednostka) {
        case 'F':
            Tf = Temperatura;
            Tc = (Tf-32) * 5.f/9;
            Tk = Tc + 273.15;
            break;
        case 'K':
            Tk = Temperatura;
            Tc = Tk - 273.15;
            Tf = (Tc*(9.f/5)) + 32;
            break;
        case 'C':
            Tc = Temperatura;
            Tf = (Tc*(9.f/5)) + 32;
            Tk = Tc + 273.15;
            break;
        default:
            cout << "Nieprawidłowa jednostka";
            isGood = false;
    }

    if (isGood) {
        cout << fixed;
        cout << setprecision(2);
        cout << "\nF = " << Tf;
        cout << "\nC = " << Tc;
        cout << "\nK = " << Tk;
    }
    return 0;
}
