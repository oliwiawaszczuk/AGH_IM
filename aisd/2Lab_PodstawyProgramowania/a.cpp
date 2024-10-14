// Napisz program, który dla podanego jako parametr wywołania programu (odczytanego przez argc/argv) ciągu liczb całkowitych obliczy i poda sumę liczb parzystych i sumę liczb nieparzystych tego ciągu.

#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int suma_parzystych = 0;
    int suma_nieparzystych = 0;

    for (int i = 0; i < argc; i++) {
        int num = atoi(argv[i]);
        if (num%2 == 0)
            suma_parzystych += num;
        else 
            suma_nieparzystych += num;
    }
    

    cout << "Suma liczb parzystych = " << suma_parzystych << "\nSuma liczb nieparzystych = " << suma_nieparzystych << "\n";
    return 0;
} 