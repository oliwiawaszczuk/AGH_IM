#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <ctime>

using namespace std;

struct Patient {
    string nazwisko;
    string imie;
    string pesel;
    string data_wizyty;

    // Funkcja obliczająca wiek na podstawie PESEL
    int age() const {
        int year = stoi(pesel.substr(0, 2));
        int month = stoi(pesel.substr(2, 2));

        if (month > 12) // PESEL dla osób urodzonych po 2000 roku
            year += 2000;
        else
            year += 1900;

        time_t now = time(nullptr);
        tm* current_time = localtime(&now);
        int current_year = 1900 + current_time->tm_year;
        return current_year - year;
    }
};

// Funkcja wczytująca pacjentów z pliku
void read_patients(const string& file_path, vector<Patient>& patients) {
    ifstream file(file_path);
    if (!file.is_open())
        throw runtime_error("Nie można otworzyć pliku: " + file_path);

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Patient patient;
        ss >> patient.nazwisko >> patient.imie >> patient.pesel >> patient.data_wizyty;
        if (ss.fail())
            throw runtime_error("Błąd w formacie danych pacjenta: " + line);
        patients.push_back(patient);
    }
    file.close();
}

// Funkcja zamieniająca miejscami dwóch pacjentów
void swap(Patient& a, Patient& b) {
    Patient temp = a;
    a = b;
    b = temp;
}

// Funkcja sortująca bąbelkowo według wybranego pola i porządku
void sort_patients(vector<Patient>& patients, const string& field, const string& order) {
    bool ascending = (order == "rosnaco");
    int n = patients.size();

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            bool swap_needed = false;

            if (field == "data") {
                if (ascending ? patients[j].data_wizyty > patients[j + 1].data_wizyty
                              : patients[j].data_wizyty < patients[j + 1].data_wizyty) {
                    swap_needed = true;
                }
            } else if (field == "wiek") {
                if (ascending ? patients[j].age() > patients[j + 1].age()
                              : patients[j].age() < patients[j + 1].age()) {
                    swap_needed = true;
                }
            } else if (field == "nazwisko") {
                if (patients[j].nazwisko == patients[j + 1].nazwisko) {
                    // Jeśli nazwiska są takie same, porównaj imiona
                    if (ascending ? patients[j].imie > patients[j + 1].imie
                                  : patients[j].imie < patients[j + 1].imie) {
                        swap_needed = true;
                    }
                } else if (ascending ? patients[j].nazwisko > patients[j + 1].nazwisko
                                     : patients[j].nazwisko < patients[j + 1].nazwisko) {
                    swap_needed = true;
                }
            }

            if (swap_needed) {
                swap(patients[j], patients[j + 1]);
            }
        }
    }
}

// Funkcja wypisująca pacjentów na ekran
void print_patients(const vector<Patient>& patients) {
    for (const auto& patient : patients) {
        cout << patient.nazwisko << " " << patient.imie << " " << patient.pesel << " " << patient.data_wizyty << endl;
    }
}

int main(int argc, char* argv[]) {

    string file_path = "triaz_10.txt";
    string field = "wiek";
    string order = "rosnaco";

    if (order != "rosnaco" && order != "malejaco") {
        cerr << "Nieprawidłowy porządek sortowania: " << order << endl;
        return 1;
    }

    vector<Patient> patients;
    try {
        read_patients(file_path, patients);
        sort_patients(patients, field, order);
        print_patients(patients);
    } catch (const exception& e) {
        cerr << "Błąd: " << e.what() << endl;
        return 1;
    }

    return 0;
}
