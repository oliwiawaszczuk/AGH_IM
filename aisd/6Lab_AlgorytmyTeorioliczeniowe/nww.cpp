#include <iostream>

using namespace std;

int nwd(int a, int b) {
    while (a!=b) {
        if (a>b) a=a-b;
        else b=b-a;
    }
    return a;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << "Podaj liczbę naturalną a:\n" << "Podaj liczbę naturalną b:\n" << "Najmniejsza wspólna wielokrotność liczb " << a << " i " << b << " to " << (a*b)/nwd(a, b);

    return 0;
}