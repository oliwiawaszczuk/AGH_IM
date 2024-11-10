#include <iostream>
using namespace std;

long long silnia(int n) {
    cout << n << endl;
    if (n<=1)
        return 1;
    return n*silnia(n-1);
}

int main() {
    int n;
    cin >> n;
    if (n<0) {
        cout << "N musi być nieujemne\n";
        return 0;
    }
    cout << "Silnia: " << silnia(n);
    return 0;
}
