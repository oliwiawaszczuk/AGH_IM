#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <unordered_map>

using namespace std;

int main(int argc, char* argv[]) {return 0;}

// FORMATOWANIE PO PRZECINKU
cout << fixed << setprecision(3);
cout << setw(3) << endl; // spacje


// TABLICE 2-WYMIAROWE
int **board = new int*[n];
for (int i=0; i<n; i++)
    board[i] = new int[n];


// RANDOMOWE LICZBY Z PRZEDZIALY <from, to>
srand(time(0)); // wrzucic na sam poczatek w main()
int get_random_number(int from, int to) {
    return rand() % (to - from + 1) + from;
}
double get_random_double(double from, double to) {
    double random = static_cast<double>(rand()) / RAND_MAX;
    return from + random * (to - from);
}

// STRINGSTREAM
string tekst = "123 456 test";
stringstream ss(tekst);
ss >> liczba1 >> liczba2 >> slowo;


// OBRAZY
struct PGM {
    string format = "P5";
    int width, height, max_gray=255;
    vector<vector<int>> pixels;

    PGM(int w, int h) : width(w), height(h) {
        pixels.resize(height, vector<int>(width, max_gray));
    }

    void print() const {
        for (const auto& row : pixels) {
            for (const auto& pixel : row)
                cout << pixel << " ";
            cout << endl;
        }
    }
};
PGM read_PGM(const string& filepath) {
    ifstream file(filepath, ios::binary);
    if (!file.is_open())
        throw runtime_error("Nie można otworzyć pliku.");

    PGM image(0, 0);
    file >> image.format;
    file >> image.width >> image.height;
    file >> image.max_gray;

    image.pixels.resize(image.height, vector<int>(image.width));

    if (image.format == "P2") {
        for (int i = 0; i < image.height; ++i)
            for (int j = 0; j < image.width; ++j)
                file >> image.pixels[i][j];

    } else if (image.format == "P5") {
        file.ignore();
        for (int i = 0; i < image.height; ++i)
            for (int j = 0; j < image.width; ++j)
                image.pixels[i][j] = file.get();
    }

    file.close();
    return image;
}
void writePGM(const PGM& image, const string& filename) {
    ofstream file(filename, ios::binary);
    if (!file.is_open())
        throw runtime_error("Nie można otworzyć pliku do zapisu.");

    file << image.format << "\n";
    file << image.width << " " << image.height << "\n";
    file << image.max_gray << "\n";

    if (image.format == "P2") {
        for (const auto& row : image.pixels) {
            for (const auto& pixel : row)
                file << pixel << " ";
            file << "\n";
        }
    } else if (image.format == "P5") {
        for (const auto& row : image.pixels)
            for (const auto& pixel : row)
                file.put(static_cast<unsigned char>(pixel));
    }

    file.close();
}

// PLIKI
vector<string> readFileLines(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) throw runtime_error("Nie można otworzyć pliku.");

    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    return lines;
}

// POLSKIE ZNAKI
string alfabetMale = "aąbcćdeęfghijklłmnńoóprsśtuwyzźż";
string alfabetDuze = "AĄBCĆDEĘFGHIJKLŁMNŃOÓPRSŚTUWYZŹŻ";
string usunPolskieZnaki(const string& tekst) {
    static const unordered_map<char, char> mapaPolskichZnakow = {
        {'ą', 'a'}, {'ć', 'c'}, {'ę', 'e'}, {'ł', 'l'}, {'ń', 'n'},
        {'ó', 'o'}, {'ś', 's'}, {'ź', 'z'}, {'ż', 'z'},
        {'Ą', 'A'}, {'Ć', 'C'}, {'Ę', 'E'}, {'Ł', 'L'}, {'Ń', 'N'},
        {'Ó', 'O'}, {'Ś', 'S'}, {'Ź', 'Z'}, {'Ż', 'Z'}
    };

    string wynik;
    for (char znak : tekst) {
        if (mapaPolskichZnakow.count(znak)) {
            wynik += mapaPolskichZnakow.at(znak);
        } else {
            wynik += znak; // Jeśli znak nie jest polski, pozostaje bez zmian
        }
    }
    return wynik;
}
map<wchar_t, int> liczLitery(const wstring& slowo) {
    map<wchar_t, int> licznik;
    for (wchar_t litera : slowo) {
        licznik[litera]++;
    }
    return licznik;
}
vector<pair<char, int>> mapToVector(const map<char, int>& mapa) {
    vector<pair<char, int>> wektor;
    for (const auto& [klucz, wartosc] : mapa) {
        wektor.emplace_back(klucz, wartosc);
    }
    return wektor;
}
bool czyPalindromBajtowy(const string& tekst1, const string& tekst2) {
    if (tekst1.size() != tekst2.size()) {
        return false;
    }

    for (size_t i = 0; i < tekst1.size(); ++i) {
        if (tekst1[i] != tekst2[tekst2.size() - 1 - i]) {
            return false;
        }
    }

    return true;
}

// LICZBY NA ROZNE SYSTEMY
int znakNaWartosc(char znak) {
    if (znak >= '0' && znak <= '9') return znak - '0';
    if (znak >= 'A' && znak <= 'Z') return znak - 'A' + 10;
    if (znak >= 'a' && znak <= 'z') return znak - 'a' + 10;
    return -1; // Nieprawidłowy znak
}
// Funkcja konwertująca liczbę dziesiętną na docelowy system liczbowy
std::string dziesietnyNaDowolny(double liczba, int bazaDocelowa) {
    if (bazaDocelowa < 2 || bazaDocelowa > 36) throw std::invalid_argument("Baza docelowa musi być w zakresie [2, 36].");

    std::string wynik;

    // Część całkowita
    long long czescCalkowita = static_cast<long long>(liczba);
    do {
        int reszta = czescCalkowita % bazaDocelowa;
        wynik += (reszta < 10) ? (reszta + '0') : (reszta - 10 + 'A');
        czescCalkowita /= bazaDocelowa;
    } while (czescCalkowita > 0);

    std::reverse(wynik.begin(), wynik.end());

    // Część ułamkowa
    double czescUlamkowa = liczba - static_cast<long long>(liczba);
    if (czescUlamkowa > 0) {
        wynik += '.';
        for (int i = 0; i < 10 && czescUlamkowa > 0; ++i) { // Maksymalnie 10 cyfr ułamkowych
            czescUlamkowa *= bazaDocelowa;
            int cyfra = static_cast<int>(czescUlamkowa);
            wynik += (cyfra < 10) ? (cyfra + '0') : (cyfra - 10 + 'A');
            czescUlamkowa -= cyfra;
        }
    }

    return wynik;
}
// Funkcja konwertująca liczbę z dowolnego systemu na dziesiętny
double dowolnyNaDziesietny(const std::string& liczba, int bazaWejsciowa) {
    if (bazaWejsciowa < 2 || bazaWejsciowa > 36) throw std::invalid_argument("Baza wejściowa musi być w zakresie [2, 36].");

    double wynik = 0;
    size_t pozycjaKropki = liczba.find('.');
    std::string czescCalkowita = liczba.substr(0, pozycjaKropki);
    std::string czescUlamkowa = (pozycjaKropki == std::string::npos) ? "" : liczba.substr(pozycjaKropki + 1);

    // Konwersja części całkowitej
    for (char znak : czescCalkowita) {
        wynik = wynik * bazaWejsciowa + znakNaWartosc(znak);
    }

    // Konwersja części ułamkowej
    double waga = 1.0 / bazaWejsciowa;
    for (char znak : czescUlamkowa) {
        wynik += znakNaWartosc(znak) * waga;
        waga /= bazaWejsciowa;
    }

    return wynik;
}
// Funkcja konwertująca liczbę zmiennoprzecinkową między systemami
std::string konwertujSystemy(const std::string& liczba, int bazaWejsciowa, int bazaDocelowa) {
    double liczbaDziesietna = dowolnyNaDziesietny(liczba, bazaWejsciowa);
    return dziesietnyNaDowolny(liczbaDziesietna, bazaDocelowa);
}

// HASHOWANIE
string words[] = {"kot", "pies", "kot", "mysz", "pies", "sowa"};
unordered_map<string, int> hashTable;
// Hashowanie i liczenie słów
for (const string& word : words) {
    hashTable[word]++;
}
// Wyświetlenie słów i ich liczby wystąpień
for (const auto& pair : hashTable) {
    cout << pair.first << ": " << pair.second << " razy" << endl;
}

// DODATKOWE
vector<vector<int>> transpose(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> result(cols, vector<int>(rows));
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result[j][i] = matrix[i][j];
    return result;
}
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rowsA = A.size(), colsA = A[0].size();
    int rowsB = B.size(), colsB = B[0].size();
    if (colsA != rowsB) throw invalid_argument("Nie można pomnożyć macierzy o takich wymiarach.");

    vector<vector<int>> result(rowsA, vector<int>(colsB, 0));
    for (int i = 0; i < rowsA; ++i)
        for (int j = 0; j < colsB; ++j)
            for (int k = 0; k < colsA; ++k)
                result[i][j] += A[i][k] * B[k][j];
    return result;
}
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
// znajdowanie wszystkich podciagow
vector<int> findSubstringOccurrences(const string& text, const string& pattern) {
    vector<int> occurrences;
    size_t pos = text.find(pattern);
    while (pos != string::npos) {
        occurrences.push_back(pos);
        pos = text.find(pattern, pos + 1);
    }
    return occurrences;
}
// Anagramy?
bool areAnagrams(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) return false;

    unordered_map<char, int> freq;
    for (char c : s1) freq[c]++;
    for (char c : s2) {
        if (--freq[c] < 0) return false;
    }
    return true;
}

// GRAFY
void DFS(const vector<vector<int>>& graph, int start, vector<bool>& visited) {
    visited[start] = true;
    cout << "Odwiedzono wierzchołek: " << start << endl;

    for (int neighbor : graph[start]) {
        if (!visited[neighbor]) {
            DFS(graph, neighbor, visited);
        }
    }
}
void BFS(const vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << "Odwiedzono wierzchołek: " << current << endl;

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}