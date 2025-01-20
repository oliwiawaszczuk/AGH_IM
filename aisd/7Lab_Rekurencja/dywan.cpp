#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct PGM {
    string format;
    int width, height, max_gray;
    vector<vector<int>> pixels;

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

    PGM image;
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

PGM dywan(PGM image, int x_start, int y_start, int size, int steps) {
    if (steps < 1)
        return image;

    int section = size / 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == 1 && j == 1) { // Środkowa sekcja
                for (int x = x_start + section; x < x_start + 2 * section; ++x) {
                    for (int y = y_start + section; y < y_start + 2 * section; ++y) {
                        if (x < image.height && y < image.width) {
                            image.pixels[x][y] = 0;
                        }
                    }
                }
            } else { // Rekurencja dla pozostałych sekcji
                image = dywan(image, x_start + i * section, y_start + j * section, section, steps - 1);
            }
        }
    }
    return image;
}

int main() {
    string filepath = "dywan.pgm";
    int size = 243; // Rozmiar obrazu (musi być potęgą 3, np. 3, 9, 27, 81, 243)
    int steps = 5;  // Liczba kroków rekurencji

    PGM image;
    image.format = "P5";
    image.width = size;
    image.height = size;
    image.max_gray = 255;
    image.pixels.resize(image.height, vector<int>(image.width, 255)); // na białe piksele

    image = dywan(image, 0, 0, size, steps);

    writePGM(image, filepath);

    return 0;
}
