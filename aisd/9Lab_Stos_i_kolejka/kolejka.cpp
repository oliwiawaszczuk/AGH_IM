#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const int nr_space = 3;
const int name_and_surname_space = 25;
const int age_space = 4;
const int weight_space = 5;

string get_string_with_good_space(string txt, int space, bool center=false) {
    int how_many_white_space = space-txt.length();
//    if (how_many_white_space/)
    if (center) how_many_white_space/=2;

    string new_txt = "";
    for (int i=0; i<how_many_white_space; i++)
        new_txt += " ";
    new_txt += txt;

    if (center) for (int i=0; i<how_many_white_space; i++) new_txt += " ";

    return new_txt;
}

struct Person {
    string name, surname, age, weight;

    Person *next;
    Person() : next(nullptr) {}
};

struct Queue {
    Person *first_person;

    void add(string name, string surname, string age, string weight) {
        Person *new_person_to_queue = new Person;
        new_person_to_queue->name = name;
        new_person_to_queue->surname = surname;
        new_person_to_queue->age = age;
        new_person_to_queue->weight = weight;

        if (first_person == nullptr) first_person = new_person_to_queue;
        else {
            Person *current_person = first_person;
            while (current_person->next != nullptr)
                current_person = current_person->next;
            cout << "- " << new_person_to_queue->surname << endl;
            current_person->next = new_person_to_queue;
        }
    }

    void print() {
        if (first_person == nullptr) {
            cout << "Kolejka jest pusta." << endl;
            return;
        }

        cout << "Kolejka: " << endl;
        cout << get_string_with_good_space("NR", nr_space+2, true) << "|";
        cout << get_string_with_good_space("IMIE", name_and_surname_space+2, true) << " |";
        cout << get_string_with_good_space("NAZWISKO", name_and_surname_space+2, true) << " |";
        cout << get_string_with_good_space("WIEK", age_space+2, true) << "|";
        cout << get_string_with_good_space("WAGA", weight_space+2, true) << endl;

        int counter = 1;
        for (Person *current_person = first_person; current_person != nullptr; current_person = current_person->next) {
            cout << get_string_with_good_space(to_string(counter), nr_space) << " | ";
            cout << get_string_with_good_space(current_person->name, name_and_surname_space) << " | ";
            cout << get_string_with_good_space(current_person->surname, name_and_surname_space) << " | ";
            cout << get_string_with_good_space(current_person->age, age_space) << " | ";
            cout << get_string_with_good_space(current_person->weight, weight_space) << endl;
            counter++;
        }
    }

    void get_one_person_from_queue() {
        if (first_person == nullptr) {
            cout << "Kolejka jest pusta, nie można pobrać elementu." << endl;
            return;
        }
        Person *person_to_delete = first_person;
        first_person = person_to_delete->next;

        delete person_to_delete;
    }

    void size() {
        int count = 0;

        for(Person *current_person = first_person; current_person != nullptr; current_person = current_person->next)
            count++;

        if (count > 0)
            cout << "Rozmiar kolejki: " << count << endl;
        else
            cout << "Kolejka jest pusta." << endl;
    }

    Queue() : first_person(nullptr) {}
};


int main(int argc, char* argv[]) {
    Queue queue;

    ifstream file("kolejka_10.txt"); //argv[1]
    string line;

    while(getline(file, line)) {
        stringstream ss(line);
        string command;
        ss >> command;

        if (command == "zakolejkuj") {
            string name, surname, age, weight;
            ss >> name >> surname >> age >> weight;
//            cout << "Adding " << name << endl;
            queue.add(name, surname, age, weight);
        } else if (command == "wypisz") queue.print();
        else if (command == "pobierz") queue.get_one_person_from_queue();
        else if (command == "rozmiar") queue.size();
    }

    return 0;
} 