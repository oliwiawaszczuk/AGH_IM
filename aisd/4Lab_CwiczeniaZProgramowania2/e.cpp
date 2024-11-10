#include <cmath>
#include <iostream>
using namespace std;

const char * jednosci(int liczba) {
    const char * jednosci[] = { "zero", "jeden", "dwa", "trzy", "cztery", "pięć", "sześć", "siedem", "osiem", "dziewięć" };
    return jednosci[liczba];
}

const char * dziesiatki(int liczba) {
    const char * dziesiatki[] = { "", "dziesięć", "dwadzieścia", "trzydzieści", "czterdzieści", "pięćdziesiąt", "sześćdziesiąt", "siedemdziesiąt", "osiemdziesiąt", "dziewięćdziesiąt" };
    return dziesiatki[liczba];
}

const char * setki(int liczba) {
    const char * setki[] = { "", "sto", "dwieście", "trzysta", "czterysta", "pięćset", "sześćset", "siedemset", "osiemset", "dziewięćset" };
    return setki[liczba];
}


int main() {
    int liczba;
    cout << "Liczba: ";
    cin >> liczba;
    if (liczba < 0) {
        cout << "minus ";
        liczba = abs(liczba);
    }
    cout << setki(liczba / 100) << " ";
    cout << dziesiatki((liczba / 10) % 10) << " ";
    cout << jednosci(liczba % 10);
    return 0;
}
