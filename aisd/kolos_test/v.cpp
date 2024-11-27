#include <iostream>
using namespace std;

void narysuj_v(int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++)
            cout << " ";
        cout << "o";
        for (int j=0; j<n-1-i; j++)
            cout << " ";
        if (i!=n-1)
        {
            for (int j=0; j<n-2-i; j++)
                cout << " ";
            cout << "o";
        }
        cout << endl;
    }
}

void narysuj_odwrocone_v(int n) {
    for (int i=n; i>0; i--) {
        for (int j = 0; j < i; j++)
            cout << " ";
        cout << "o";
        if (i != n) {
            for (int j = 0; j < 2 * (n - i) - 1; j++)
                cout << " ";
            cout << "o";
        }

        cout << endl;
    }
}

void narysuj_trojkat_do_dolu(int n) {
    for (int i=n-1; i>=0; i--) {
        for (int j=0; j<n-i; j++)
            cout << " ";
        for (int j=0; j<2*i+1; j++)
            cout << "*";

        cout << endl;
    }
}

void narysuj_trojkat_do_gory(int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-i; j++)
            cout << " ";
        for (int j=0; j<2*i+1; j++)
            cout << "*";

        cout << endl;
    }
}

void narysuj_klepsydre(int n) {
    for (int i = n / 2; i >= 0; i--) {
        for (int j = 0; j < n / 2 - i; j++)
            cout << " ";
        for (int j = 0; j < 2 * i + 1; j++)
            cout << "*";
        cout << endl;
    }
    for (int i = 1; i <= n / 2; i++) {
        for (int j = 0; j < n / 2 - i; j++)
            cout << " ";
        for (int j = 0; j < 2 * i + 1; j++)
            cout << "*";
        cout << endl;
    }
}

void narysuj_x(int n) {
    for (int i = n / 2; i >= 0; i--) {
        for (int j = 0; j < n / 2 - i; j++)
            cout << " ";
        cout << "*";

        if (2 * i > 0) {
            for (int j = 0; j < 2 * i - 1; j++)
                cout << " ";
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 1; i <= n / 2; i++) {
        for (int j = 0; j < n / 2 - i; j++)
            cout << " ";
        cout << "*";

        if (2 * i > 0) {
            for (int j = 0; j < 2 * i - 1; j++)
                cout << " ";
            cout << "*";
        }
        cout << endl;
    }
}

void narysuj_romb(int n) {
    for (int i=0; i<n/2; i++) {
        for (int j=0; j<n/2-i; j++)
            cout << " ";
        for (int j=0; j<2*i+1; j++)
            cout << "*";

        cout << endl;
    }
    for (int i=n/2-2; i>=0; i--) {
        for (int j=0; j<n/2-i; j++)
            cout << " ";
        for (int j=0; j<2*i+1; j++)
            cout << "*";

        cout << endl;
    }
}

void narysuj_ramke(int n) {
    for (int i=0; i<n; i++)
        cout << "*";
    cout << endl;
    for (int i=0; i<n-2; i++) {
        cout << "*";
        for (int i=0; i<n-2; i++)
            cout << " ";
        cout << "*";
        if (i+1!=n-2)
            cout << endl;
    }
    cout << endl;
    for (int i=0; i<n; i++)
        cout << "*";
}

void narysuj_zapelniony_kwadrat(int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            cout << "*";
        cout << endl;
    }
}

void narysuj_trojkat_prostokatny(int n) {
    for (int i=0; i<n; i++) {
        for (int j=1; j<=i+1; j++)
            cout << "*";
        cout << endl;
    }
}

int main() {
    int n;
//    cin >> n;
    n = 7;
    narysuj_x(n);
    return 0;
}