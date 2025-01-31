#include <iostream>
#include <string>
using namespace std;

string doz_wyrazy[] = {"ski", "ska", "wski", "wska", "cki", "cka"};
int liczba_wyrazow = 6;

struct Pacjent {
    string nazwisko;
};

bool czy_pasuje(const string& napis, int start, const string& wyraz) {
    for (int i = 0; i < wyraz.length(); i++) {
        if (start + i >= napis.length() || napis[start + i] != wyraz[i]) {
            return false;
        }
    }
    return true;
}

bool czy_zawiera_jakis_wyraz(const string& napis) {
    for (int i = 0; i < liczba_wyrazow; i++) {
        string wyraz = doz_wyrazy[i];
        for (int j = 0; j <= napis.length() - wyraz.length(); j++) {
            if (czy_pasuje(napis, j, wyraz)) {
                return true;
            }
        }
    }
    return false;
}

int policz_wyrazy(Pacjent* pacjenci, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (czy_zawiera_jakis_wyraz(pacjenci[i].nazwisko)) {
            count++;
        }
    }
    return count;
}

int main() {
    int n = 2;
    Pacjent* tab = new Pacjent[n];

    tab[0].nazwisko = "Kowalsweki";
    tab[1].nazwisko = "Nowacki";

    cout << "Nazwisk zawierających wyrazy z doz_wyrazy: " << policz_wyrazy(tab, n) << endl;

    delete[] tab;
    return 0;
}
