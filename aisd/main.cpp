#include <iostream>
using namespace std;

int suma = 0;
int countFields = 0;
float bestSumaCountFieldRatio = 0;
int bestSuma = 0;
int bestCountFields = 0;

bool foundMoreField = false;

int width, height;
int **map;

void printNumber(int number) {
    int len = 1;
    if (number >= 10)
        len = 2;
    for (int i = 0; i < 4-len; i++)
        cout << " ";

    cout << number;
}

void checkField(int x, int y) {
    suma += map[x][y];
    map[x][y] = 0;
    countFields++;

    if (y+1 < height && map[x][y+1] > 0) { // S
        checkField(x, y+1);
    } if (y-1 >= 0 && map[x][y-1] > 0) { // N
        checkField(x, y-1);
    } if (x-1 >= 0 && map[x-1][y] > 0) { // W
        checkField(x-1, y);
    } if (x+1 < width && map[x+1][y] > 0) { // E
        checkField(x+1, y);
    }
}

int main() {
    cin >> height >> width;
    map = new int*[width];
    for (int i = 0; i < width; i++)
        map[i] = new int[height];

    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            cin >> map[x][y];

    // for (int y = 0; y < height; y++) {
    //     for (int x = 0; x < width; x++)
    //         printNumber(map[x][y]);
    //     cout << endl;
    // }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (map[x][y] > 0) {
                checkField(x, y);

                if ((float)suma/countFields > bestSumaCountFieldRatio) {
                    bestSumaCountFieldRatio = (float)suma/countFields;
                    bestSuma = suma;
                    bestCountFields = countFields;
                    foundMoreField = false;
                } else if ((float)suma/countFields == bestSumaCountFieldRatio) {
                    foundMoreField = true;
                }
                suma = 0;
                countFields = 0;
            }
        }
    }

    if (foundMoreField) {
        cout << -1;
    } else if (bestSumaCountFieldRatio == 0) {
        cout << 0;
    } else
        cout << bestSuma << " " << bestCountFields << endl;

    for (int i = 0; i < width; i++)
        delete map[i];
    delete map;

    return 0;
}
