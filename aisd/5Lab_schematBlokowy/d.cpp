#include <iostream>
using namespace std;

int main() {
    int n, a, suma=0;
    cout << "N: \n";
    cin >> n;
    if (n<0) {
        cout << "N musi być większe niż 0";
        return 0;
    }
    cout << "A: \n";
    cin >> a;
    if (a<0) {
        cout << "A nie jest liczbą naturalną" << endl;
        return 0;
    }
    for (int i=0; i<n; i++)
        suma += a+i;

    cout << "Suma = " << suma;
    return 0;
}
