#include <iostream>
#include <string>
using namespace std;

struct Person {
    string surname;
};

bool czy_slowo_ma_polski_znak(string slowo) {
    for (int i=0; i<slowo.length(); i++) {
        int literka = static_cast<int>(slowo[i]);
        cout << "Literka " << slowo[i];
        if ((literka >= 65 && literka <= 90) || (literka >= 97 && literka <= 122))
            continue;
        else
            return true;
    }

    return false;
}

int policz_polskie_nazwiska(Person *people) {
    return 0;
}

int main(int argc, char* argv[]) {
//    int n=2;
//    Person *people = new Person[n];

    czy_nazwisko_ma_polski_znak("aąćę");
    return 0;
}