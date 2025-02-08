#include <iostream>
using namespace std;

struct Pacjent {
    string nazwisko;
    int waga;
};

bool wyszukiwanieRekurencyjne(Pacjent *pacjenci, int lewy, int prawy, string nazwisko) {
    if (lewy > prawy)
        return false;

    int srodek = lewy + (prawy - lewy) / 2;

    if (pacjenci[srodek].nazwisko == nazwisko)
        return true;

    if (pacjenci[srodek].nazwisko < nazwisko) // szukanie w prawo
        return wyszukiwanieRekurencyjne(pacjenci, srodek + 1, prawy, nazwisko);
    else // szukanie w lewo
        return wyszukiwanieRekurencyjne(pacjenci, lewy, srodek - 1, nazwisko);
}

int main() {
    Pacjent pacjenci[] = {
        {"Adamski", 75},
        {"Borkowski", 82},
        {"Kowalski", 90},
        {"Nowak", 68},
        {"Zieliński", 77}
    };

    int n = sizeof(pacjenci) / sizeof(pacjenci[0]);

    string szukane_nazwisko;
    cout << "Podaj nazwisko pacjenta: ";
    cin >> szukane_nazwisko;

    if (wyszukiwanieRekurencyjne(pacjenci, 0, n - 1, szukane_nazwisko))
        cout << "Pacjent " << szukane_nazwisko << " jest w bazie.\n";
    else
        cout << "Pacjent " << szukane_nazwisko << " nie został znaleziony.\n";

    return 0;
}