#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, a;
    cout << "N: ";
    cin >> n;
    cout << "\nA: ";
    cin >> a;
    int maks = a;
    for (int i = 0; i < n-1; i++) {
        maks = max(maks, a);
        cout << "\nA: ";
        cin >> a;
    }
    cout << "\nMaksimum = " << maks << endl;
    return 0;
}
