#include <cmath>
#include <iostream>
using namespace std;

void wypelnij(int *array, int N, int limit) {
    for (int i = 0; i < N; i++) {
        array[i] = rand() % limit + 1;
    }
}
void wypisz(int *array, int N) {
    cout << "[";
    for (int i = 0; i < N-1; i++) {
        cout << array[i] << ", ";
    }
    cout << array[N-1] << "]" << endl;
}
int max(int *array, int N) {
    int max_number = array[0];

    for (int i = 0; i < N; i++)
        if (array[i] > max_number)
            max_number = array[i];

    return max_number;
}
int min(int *array, int N) {
    int min_number = array[0];

    for (int i = 0; i < N; i++)
        if (array[i] < min_number)
            min_number = array[i];

    return min_number;
}
bool is_primary(int number) {
    if (number <= 1)
        return false;
    if (number == 2)
        return true;
    if (number % 2 == 0)
        return false;

    for (int i = 3; i <= sqrt(number); i+=2)
        if (number % i == 0)
            return false;
    return true;
}
void liczby_pierwsze(int *array, int N) {
    for (int i = 0; i < N; i++) {
        if (is_primary(array[i])) {
            cout << array[i];
            if (i<N-1)
                cout << ", ";
        }
    }
    cout << endl;
}
int suma(int * tab, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += tab[i];
    return sum;
}

enum Warunek { FIBONACCI, KWADRAT, SZESCIAN, SILNIA };
bool isFibonacci(int n) {
    int a = 0, b = 1;
    if (n == a || n == b) return true;
    int c = a + b;
    while (c <= n) {
        if (c == n) return true;
        a = b;
        b = c;
        c = a + b;
    }
    return false;
}
bool isSquare(int n) {
    int root = sqrt(n);
    return (root * root == n);
}
bool isCube(int n) {
    int root = round(cbrt(n));
    return (root * root * root == n);
}
bool isFactorial(int n) {
    int fact = 1;
    for (int i = 1; fact <= n; i++) {
        fact *= i;
        if (fact == n) return true;
    }
    return false;
}
void wypisz_warunkowo(int *tab, int n, Warunek w) {
    for (int i = 0; i < n; i++) {
        switch (w) {
            case FIBONACCI:
                if (isFibonacci(tab[i]))
                    cout << tab[i] << ", ";
            break;
            case KWADRAT:
                if (isSquare(tab[i]))
                    cout << tab[i] << ", ";
            break;
            case SZESCIAN:
                if (isCube(tab[i]))
                    cout << tab[i] << ", ";
            break;
            case SILNIA:
                if (isFactorial(tab[i]))
                    cout << tab[i] << ", ";
            break;
        }
    }
    cout << endl;
}
int main() {
    int seed, N, limit;
    cin >> seed >> N >> limit;
    cout << "Ziarno: \nN:\nZakres:\n";

    srand(seed);
    int array[N];
    wypelnij(array, N, limit);
    wypisz(array, N);
    cout << "Maksimum: " << max(array, N) << endl;
    cout << "Minimum: " << min(array, N) << endl;
    cout << "Suma: " << suma(array, N) << endl;
    cout << "Liczby pierwsze: ";
    liczby_pierwsze(array, N);
    cout << "Kwadraty liczb: ";
    wypisz_warunkowo(array, N, KWADRAT);
    cout << "Sześciany liczb: ";
    wypisz_warunkowo(array, N, SZESCIAN);
    cout << "Silnie liczb: ";
    wypisz_warunkowo(array, N, SILNIA);
    cout << "Liczb z ciągu Fibonacciego: ";
    wypisz_warunkowo(array, N, FIBONACCI);


    return 0;
}
