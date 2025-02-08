#include <iostream>
using namespace std;

// Z TYM ZADANIEM JEST COŚ MOCNO NIE TAK!!!

int f1(int x) {
    if (x > 50) return 9;
    return 5 * f1(x + 3) + 7;
}

int f2(int x) {
    while (x <= 50) {
        x = 5 * (x+3) + 7;
    }
    return 9;
}

int main(int argc, char* argv[]) {
    for (int i=0; i<20; i++) {
        cout << "f1( " << i << " )" << f1(i) << endl;
        cout << "f2( " << i << " )" << f2(i) << endl;
    }
    return 0;
}