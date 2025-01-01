#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


struct person {
    string date;
    string nameAndSurname;
    string pesel;
    person *next;

    person() : next(nullptr) {}
};


struct list {
    person *first;

    void add(string date, string name, string pesel) {
        person *new_person = new person;
        new_person->date = date;
        new_person->nameAndSurname = name;
        new_person->pesel = pesel;

        if (first == nullptr) first = new_person;
        else {
            person *current_person = first;
            while (current_person->next != nullptr)
                current_person = current_person->next;
            current_person->next = new_person;
        }
    }

    void print(string filter_type) {
        int counter = 1;
        cout << "Lista: " << filter_type << endl;
        for (person *current_person = first; current_person != nullptr; current_person = current_person->next) {
            cout << counter << " | " << current_person->date << " | " << current_person->pesel << " | " << current_person->nameAndSurname << endl;
            counter++;
        }
    }

    void remove(string date) {
        for (person *current_person = first; current_person->next != nullptr; current_person = current_person->next) {
            if (current_person->next->date == date) {
                person *person_to_delete = current_person->next;
                current_person->next = person_to_delete->next;
                cout << "deleting person: " << current_person->nameAndSurname << endl;
                delete person_to_delete;
            }
        }
    }

    list() : first(nullptr) {}
};


int main(int argc, char* argv[]) {
    list lista;

    ifstream file("pacjenci_10.txt"); //argv[1]

    if(!file.is_open()) return -1;

    string line;
    while(getline(file, line)) {
        stringstream ss(line);
        string command;
        ss >> command;

        if (command == "dodaj") {
            string date, hour, name, surname, pesel;
            ss >> date >> hour >> pesel >> name >> surname;
            lista.add(date+" "+hour, name+" "+surname, pesel);
//            cout << date+" "+hour << " | " << name+" "+surname << " | " << pesel << endl;
        } else if (command == "wypisz") {
            string filter_type;
            ss >> filter_type;
            lista.print(filter_type);
        } else if (command == "usun") {
            string date, hour;
            ss >> date >> hour;
            lista.remove(date+" "+hour);
        }
    }

    return 0;
}