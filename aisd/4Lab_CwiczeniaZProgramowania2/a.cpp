#include <iostream>
#include <iomanip>

using namespace std;

int fib(int liczba) {
    int poprzednia = 1, nastepna = 1;
    do {
        int temp = nastepna;
        nastepna += poprzednia;
        poprzednia = temp;
    } while(liczba > nastepna);

    return nastepna;
}

int main()
{
    int liczba;
    cout << "Podaj wartość: ";
    cin >> liczba;
    if (liczba<0) {
        cout << "Wartość nie może być ujemna";
        return 0;
    }

    cout << "Następny wyraz ciągu to " << fib(liczba) << endl;
    return 0;
}