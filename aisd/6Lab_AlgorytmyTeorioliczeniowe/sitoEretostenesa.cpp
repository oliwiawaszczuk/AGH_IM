#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cout << "N: ";
    cin >> n;

    bool *sito = new bool[n+1];

    for (int i=0; i<=n; i++)
        sito[i] = true;

    sito[0] = sito[1] = false;

    for (int i=2; i<=sqrt(n); i++)
        if (sito[i])
            for (int j=i*i; j<=n; j+=i)
                sito[j] = false;

    cout << "Liczby pierwsze do " << n << " to: ";
    for (int i = 2; i <= n; i++)
        if (sito[i])
            cout << i << " ";

    return 0;
}
