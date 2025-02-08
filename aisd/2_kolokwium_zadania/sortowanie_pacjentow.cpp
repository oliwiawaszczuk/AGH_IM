#include <iostream>
#include <ctime>
using namespace std;

struct Pacjent {
    float waga;
};

void sortowanie(Pacjent *pacjenci, int n) {
    for (int i=0; i<n; i++)
        for (int j=0; j<n-i-1; j++)
            if (pacjenci[j].waga > pacjenci[j+1].waga)
                swap(pacjenci[j], pacjenci[j+1]);
}

void print(Pacjent *pacjenci, int n) {
    for (int i=0; i<n; i++)
        cout << i+1 << ". " << pacjenci[i].waga << endl;
}

int main(int argc, char* argv[]) {
    srand(time(0));
    int n = 10;
    Pacjent *pacjenci = new Pacjent[n];

    for (int i=0; i<n; i++)
        pacjenci[i].waga = rand()%100;

    cout << "Przed sortowaniem: " << endl;
    print(pacjenci, n);

    sortowanie(pacjenci, n);

    cout << "Po sortowaniu: " << endl;
    print(pacjenci, n);

    return 0;
}