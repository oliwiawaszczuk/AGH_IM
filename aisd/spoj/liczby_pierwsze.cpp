#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

bool is_primery(int number) {
    if (number < 2)
        return false;
    if (number==2)
        return true;
    if (number%2 == 0)
        return false;
    for(int i=3; i<=sqrt(number); i+=2) {
        if (number%i == 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    int *tab;
    tab = new int[n];
    for (int i=0; i<n; i++) {
        cin >> tab[i];
    }

    for (int i=0; i<n; i++) {
        cout << (is_primery(tab[i]) ? "TAK" : "NIE") << endl;
    }

    delete[] tab;
    return 0;
}