// Napisz program, który pobiera dwie liczby całkowite: ‘podstawę’ i ‘wykładnik’. Następnie program, wykorzystując pętlę ‘for’, oblicza wartość ‘podstawa’ do potęgi ‘wykładnik’ i wypisuje na ekran wynik. Wykładnik nie może być ujemny.

#include <iostream>
using namespace std;

int potega(int pod, int wyk) {
    int wynik = 1;
    for (int i=0; i<wyk; i++) {
        wynik *= pod;
    }
    return wynik;
}

int main() {
    int pod, wyk;
    cin >> pod >> wyk;
    if (wyk<0)
        cout << "Wykładnik nie może być ujemny";
    else {
        cout << "\nPodstawa: ";
        cout << "\nWykładnik: ";
        cout << "\n" << pod << " ^ " << wyk << " = " << potega(pod, wyk);
    }
    return 0;
}