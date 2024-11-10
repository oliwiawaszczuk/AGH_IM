#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << "Podaj liczbę naturalną a:\nPodaj liczbę naturalną b:\nNajwiększy wspólny dzielnik liczb " << a << " i " << b << " to ";
    while (a!=b) {
        if (a>b) a=a-b;
        else b=b-a;
    }
    cout << a << ".";
    return 0;
}
