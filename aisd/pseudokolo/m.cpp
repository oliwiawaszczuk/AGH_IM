#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Funkcja generująca losową sekwencję DNA o zadanej długości
string generateDNA(int length) {
    string dna = "";
    const string bases = "ACGT";

    for (int i = 0; i < length; ++i) {
        dna += bases[rand() % 4]; // Losowo wybiera A, C, G, T
    }
    return dna;
}

// Funkcja wprowadzająca mutacje do sekwencji DNA
string mutateDNA(const string &originalDNA, double mutationRate) {
    string mutatedDNA = originalDNA;
    const string bases = "ACGT";

    for (size_t i = 0; i < mutatedDNA.length(); ++i) {
        // Sprawdzamy, czy nastąpi mutacja
        if ((rand() % 100) < (mutationRate * 100)) {
            char originalBase = mutatedDNA[i];
            char newBase;

            // Generujemy nową zasadę azotową różną od oryginalnej
            do {
                newBase = bases[rand() % 4];
            } while (newBase == originalBase);

            mutatedDNA[i] = newBase; // Zmieniamy zasadę
        }
    }
    return mutatedDNA;
}

int main() {
    srand(time(0)); // Inicjalizacja generatora liczb pseudolosowych

    int dnaLength;
    double mutationRate;

    cout << "=== Symulator Losowych Mutacji DNA ===" << endl;

    // Użytkownik wprowadza długość DNA
    cout << "Podaj dlugosc sekwencji DNA: ";
    cin >> dnaLength;

    // Użytkownik wprowadza częstość mutacji
    cout << "Podaj czestosc mutacji (0.0 - 1.0): ";
    cin >> mutationRate;

    // Generowanie losowej sekwencji DNA
    string originalDNA = generateDNA(dnaLength);
    cout << "\nPierwotna sekwencja DNA: " << originalDNA << endl;

    // Mutowanie DNA
    string mutatedDNA = mutateDNA(originalDNA, mutationRate);
    cout << "Zmutowana sekwencja DNA:  " << mutatedDNA << endl;

    return 0;
}
