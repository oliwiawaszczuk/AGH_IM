#include <iostream>
#include <fstream>
#include <string>
#include <thread>

using namespace std;

struct str {
    string s;
    str *next;
    str() : next(nullptr) {}
};

struct stos {
    str *first;

    stos() : first(nullptr) {}

    void odloz(string new_str) {
        str *new_s = new str;
        new_s->s = new_str;
        new_s->next = first;
        first = new_s;
    }

    void zdejmij() {
        if (first != nullptr) {
            str *temp = first;
            first = first->next;
            delete temp;
        } else cout << "Stos jest pusty, nie można zdjąć elementu." << endl;
    }

    void podejrzyj() {
        if (first != nullptr) cout << "Na wierzchu stosu: " << first->s << endl;
        else cout << "Stos jest pusty." << endl;
    }

    void rozmiar() {
        int size = 0;

        str *temp = first;
        while(temp != nullptr) {
            size++;
            temp = temp->next;
        }

        cout << "Rozmiar stosu: " << size << endl;
    }

    void czy_pusty() {
        if (first == nullptr) cout << "Stos jest pusty." << endl;
        else cout << "Stos nie jest pusty" << endl;
    }

    void wypisz() {
        if (first == nullptr) {
            cout << "Stos jest pusty." << endl;
            return;
        }

        str *temp = first;
        int idx = 0;

        cout << "Stos: " << endl;
        while(temp) {
            cout << "[ " << idx << "]" << temp->s << endl;
            temp = temp->next;
            idx++;
        }
    }
};

int main(int argc, char* argv[]) {
    stos s;

    ifstream file("stos_10.txt");
    string text;

    if (!file.is_open()) {
        cout << "Nie mozna otworzyc pliku" << endl;
        return 1;
    }

    while (getline(file, text)) {
        size_t position_of_space = text.find(" ");

        string operation = "", rest = "";

        if (position_of_space < text.length()) {
            operation = text.substr(0, position_of_space);
            rest = text.substr(position_of_space+1);
        } else operation = text;

        if (operation == "odloz")
            s.odloz(rest);
        else if (operation == "podejrzyj")
            s.podejrzyj();
        else if (operation == "rozmiar")
            s.rozmiar();
        else if (operation == "czy_pusty")
            s.czy_pusty();
        else if (operation == "zdejmij")
            s.zdejmij();
        else if (operation == "wypisz")
            s.wypisz();

//        cout << operation << endl;
    }

    file.close();

    return 0;
}