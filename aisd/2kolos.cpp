#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {return 0;}

// RANDOMOWE LICZBY Z PRZEDZIALY <from, to>
srand(time(0));
int get_random_number(int from, int to) {
    return rand() % (to - from + 1) + from;
}

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