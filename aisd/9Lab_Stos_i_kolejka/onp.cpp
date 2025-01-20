#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

struct Stos {
    string znak;
    Stos *next = nullptr;
};

void ONP(string onp_znaki) {
    Stos stos;

    stringstream ss(onp_znaki);
    string znak;

    while(ss >> znak) {
        if (znak == "+" || znak == "/" || znak == "*" || znak == "-") {

        }

        cout << znak << endl;
    }
}

int main(int argc, char* argv[]) {
    string onp_znaki = "2 3 + 5 *";
    ONP(onp_znaki);
    return 0;
}