// Napisz program, który pobiera liczbę całkowitą ‘wysokosc’. Następnie program, wykorzystując dowolne pętle, rysuje w konsoli choinkę ze znaków '*'. 

#include <iostream>
using namespace std;

int main() {
    int height = 0;
    cout << "Podaj wysokosc choinki: ";
    cin >> height;

    for (int h=0; h<height; h++) {
        for (int i=0; i<height-h-1; i++)
            cout << " ";
        for (int i=0; i<2*h+1; i++)
            cout << "*";
        cout << endl;
    }

    return 0;
} 