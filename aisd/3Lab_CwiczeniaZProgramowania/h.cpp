#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
    string line;
    int wzorce_count = 2;//argc - 2;
    string* wzorce = new string[wzorce_count];

    wzorce[0] = "wagon";
    wzorce[1] = "buch";
    // for (int i=0; i<wzorce_count; i++) {
    // wzorce[i] = argv[i + 2];
    // cout << wzorce[i] << endl;
    // }

    for (int i = 0; i < wzorce_count; i++) {
        ifstream file(argv[1]);
        cout << "Linie zawierające słowo \"" << wzorce[i] << "\"" << endl;
        if (file.is_open()) {
            while (getline(file, line)) {
                if (line.find("wagon") != string::npos) {
                    cout << line << endl;
                }
            }
            file.close();
        } else cout << "Unable to open file";
    }

    return 0;
}