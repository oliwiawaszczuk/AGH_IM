#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

struct node {
    node *prev;
    int number;
    node *next;

    node() : prev(nullptr), next(nullptr), number(0) {}
};

struct list {
    node *first;
    node *last;

    list() : first(nullptr), last(nullptr) {}

    void add(int value) {
        node *new_node = new node();
        new_node->number = value;
        if (first == nullptr) {
            first = last = new_node;
        } else {
            last->next = new_node;
            new_node->prev = last;
            last = new_node;
        }
    }

    void insert(int number, int position) {
        node *new_node = new node();
        new_node->number = number;

        if (position == 0) {
            if (first == nullptr) {
                first = last = new_node;
            } else {
                new_node->next = first;
                first->prev = new_node;
                first = new_node;
            }
            return;
        }

        node *current = first;
        int index = 0;
        while (current != nullptr && index < position - 1) {
            current = current->next;
            index++;
        }

        if (current == nullptr) {
            add(number);
        } else {
            new_node->next = current->next;
            if (current->next != nullptr) {
                current->next->prev = new_node;
            }
            current->next = new_node;
            new_node->prev = current;

            if (new_node->next == nullptr) {
                last = new_node;
            }
        }
    }

    void remove(int position) {
        if (first == nullptr) return;

        if (position == 0) {
            node *to_delete = first;
            first = first->next;
            if (first != nullptr) {
                first->prev = nullptr;
            } else {
                last = nullptr;
            }
            delete to_delete;
            return;
        }

        node *current = first;
        int index = 0;
        while (current != nullptr && index < position) {
            current = current->next;
            index++;
        }

        if (current == nullptr) return;

        if (current->prev != nullptr) {
            current->prev->next = current->next;
        }
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
        if (current == last) {
            last = current->prev;
        }

        delete current;
    }

    void clean() {
        while (first != nullptr) {
            node *to_delete = first;
            first = first->next;
            delete to_delete;
        }
        last = nullptr;
    }

    void print() {
        cout << "[";
        node *current = first;
        while (current != nullptr) {
            cout << setw(3) << current->number;
            current = current->next;
        }
        cout << "]" << endl;
    }

    void reversed_print() {
        cout << "[";
        node *current = last;
        while (current != nullptr) {
            cout << setw(3) << current->number;
            current = current->prev;
        }
        cout << "]" << endl;
    }

    void move(int position1, int position2) {
        if (position1 == position2) return;

        node *current1 = first;
        node *current2 = first;
        int index1 = 0, index2 = 0;

        while (current1 != nullptr && index1 < position1) {
            current1 = current1->next;
            index1++;
        }

        while (current2 != nullptr && index2 < position2) {
            current2 = current2->next;
            index2++;
        }

        if (current1 == nullptr || current2 == nullptr) return;

        swap(current1->number, current2->number);
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <file_path>" << endl;
        return -1;
    }

    ifstream file(argv[1]);
    if (!file.is_open()) {
        cerr << "Could not open file: " << argv[1] << endl;
        return -1;
    }

    list lista;
    string line;

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
