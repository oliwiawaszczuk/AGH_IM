#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct number {
    int nr;
    number *next;
    number() : next(nullptr) {}
};

struct list {
    number *first;
    list() : first(nullptr) {}

    void add(int new_nr) {
        number *new_number = new number();
        new_number->nr = new_nr;
        if (first == nullptr) first = new_number;
        else {
            number *current = first;
            while (current->next != nullptr)
                current = current->next;
            current->next = new_number;
        }
    }

    void print() {
        for(number *current = first; current !=nullptr; current=current->next)
            cout << current->nr << " ";
        cout << endl;
    }

    void clean() {
        for(number *current = first; current != nullptr; current=current->next)
            delete current;
    }

    void insert(int new_nr, int position) {
        number *new_number = new number();
        new_number->nr = new_nr;

        if (position == 0 || first == nullptr) {
            new_number->next = first;
            first = new_number;
        } else {
            number *current = first;
            for (int i=0; i != position-1 && current->next != nullptr; i++)
                current = current->next;
            new_number->next = current->next;
            current->next = new_number;
        }
    }

    void remove(int position) {
        number *current = first;
        if (position == 0) {
            first = current->next;
            delete current;
        } else {
            number *current = first;
            for (int i=0; i != position-1 && current->next != nullptr; i++)
                current = current->next;
            number *to_delete = current->next;
            current->next = to_delete->next;
            delete to_delete;
        }
    }

    void reversed_print() {
        reversed_print(first);
        cout << endl;
    }

    void reversed_print(number *nr) {
        if (nr == nullptr) return;
        reversed_print(nr->next);
        cout << nr->nr << " ";
    }

    void move(int position1, int position2) {
        if (position1 == position2) return;
        number *nr_1 = nullptr, *prev_1 = nullptr;
        number *nr_2 = nullptr, *prev_2 = nullptr;

        int i=0;
        for (number *temp = first; temp != nullptr; temp = temp->next) {
            if (i == position1) nr_1 = temp;
            if (i+1 == position1) prev_1 = temp;
            if (i == position2) nr_2 = temp;
            if (i+1 == position2) prev_2 = temp;
            i++;
        }

        if (nr_1 && nr_2) {
            if (prev_1) prev_1->next = nr_1;
            if (prev_2) prev_2->next = nr_2;

            number *temp_next = nr_1->next;
            nr_1->next = nr_2->next;
            nr_2->next = temp_next;

            if (position1 == 0) first = nr_1;
            if (position2 == 0) first = nr_2;
        }
    }

    void sort_ascending() {
        for (number *i = first; i != nullptr; i = i->next) {
            for (number *j = i->next; j != nullptr; j = j->next) {
                if (i->nr > j->nr) {
                    swap(i->nr, j->nr);
                }
            }
        }
    }

    void sort_descending() {
        for (number *i = first; i != nullptr; i = i->next) {
            for (number *j = i->next; j != nullptr; j = j->next) {
                if (i->nr < j->nr) {
                    swap(i->nr, j->nr);
                }
            }
        }
    }
};

int main(int argc, char* argv[]) {
    list lista;

    ifstream file("R:\\PROGRAMOWANIE\\AGH_IM\\aisd\\8Lab_Listy\\lista_10.txt");
    string line;

    if (!file.is_open()) return -1;

    while (getline(file, line)) {
        stringstream ss(line);
        string command;
        ss >> command;

        if (command == "dodaj") {
            int value;
            ss >> value;
            lista.add(value);
        } else if (command == "wstaw") {
            int number, position;
            ss >> number >> position;
            lista.insert(number, position);
        } else if (command == "usun") {
            int position;
            ss >> position;
            lista.remove(position);
        } else if (command == "wyczysc") {
            lista.clean();
        } else if (command == "wypisz") {
            lista.print();
        } else if (command == "wypisz_odwrotnie") {
            lista.reversed_print();
        } else if (command == "zamien") {
            int position1, position2;
            ss >> position1 >> position2;
            lista.move(position1, position2);
        }
    }

    return 0;
}