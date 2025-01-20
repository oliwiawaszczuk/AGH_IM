#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

struct PGM {
    string format = "P2";
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

int get_random_number(int from, int to) {
    return rand() % (to - from + 1) + from;
}
struct Point {
    double x, y;
};

Point apply_transformation(Point p, int choice) {
    switch (choice) {
        case 0:
            return {0.0, 0.16 * p.y};
        case 1:
            return {0.85 * p.x + 0.04 * p.y, -0.04 * p.x + 0.85 * p.y + 1.6};
        case 2:
            return {0.2 * p.x - 0.26 * p.y, 0.23 * p.x + 0.22 * p.y + 1.6};
        case 3:
            return {-0.15 * p.x + 0.28 * p.y, 0.26 * p.x + 0.24 * p.y + 0.44};
    }
    return p;
}

int choose_transformation() {
    double r = static_cast<double>(rand()) / RAND_MAX;
    if (r < 0.01) return 0;
    if (r < 0.86) return 1;
    if (r < 0.93) return 2;
    return 3;
}

void generate_barnsley_fern(PGM& image, int num_points) {
    Point p = {0.0, 0.0};
    for (int i = 0; i < num_points; ++i) {
        int choice = choose_transformation();
        p = apply_transformation(p, choice);

        int px = static_cast<int>((p.x + 2.5) / 5.0 * image.width);
        int py = static_cast<int>((10 - p.y) / 10.0 * image.height);

        if (px >= 0 && px < image.width && py >= 0 && py < image.height)
            image.pixels[py][px] = 0;
    }
}

int main(int argc, char* argv[]) {
    srand(time(0));

    string path = "paproc.pgm";
    int width = 400;
    int height = 600;
    int num_points = 500000;

    PGM image(width, height);

    generate_barnsley_fern(image, num_points);

    writePGM(image, path);

    return 0;
}