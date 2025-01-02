#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct node {
    node *prev;
    int number;
    node *next;

    node() : next(nullptr), prev(nullptr) {}
};

struct list {
    node *first;
    node *last;

    list() : first(nullptr), last(nullptr) {}

    void add(int value) {
        node *new_node = new node();
        new_node->number = value;
        if (first == nullptr) first = last = new_node;
        else {
            last->next = new_node;
            new_node->prev = last;
            last = new_node;
        }
    }

    void insert(int number, int position) {
        node *new_node = new node();
        new_node->number = number;

        if (first == nullptr || position == 0) {

        }
    }

    void remove(int position) {

    }

    void clean() {

    }

    void print() {

    }

    void reversed_print() {

    }

    void move(int position1, int position2) {

    }
};

int main(int argc, char* argv[]) {
    ifstream file("R:\\PROGRAMOWANIE\\AGH_IM\\aisd\\8Lab_Listy\\lista_10.txt");
    string line;
    list lista;

    if (!file.is_open()) return -1;

    while(getline(file, line)) {
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