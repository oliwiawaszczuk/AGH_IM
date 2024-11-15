#include <iostream>
#include <cmath>
using namespace std;

bool is_primary(int number) {
    if (number == 2)
        return true;

    if (number <= 1 || number % 2 == 0)
        return false;

    for (int i=3; i<=sqrt(number)+1; i+=2)
        if (number % i == 0)
            return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    cout << "N:\n";

    if (n==0 || n==1) {
        cout << "Liczba nie jest liczbą ani pierwszą ani złożoną";
        return 0;
    }

    cout << "Liczba jest liczbą " << (is_primary(n) ? "pierwszą" : "złożoną");

    return 0;
}