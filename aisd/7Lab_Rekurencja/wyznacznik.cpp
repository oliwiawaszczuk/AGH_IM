#include <iostream>
using namespace std;

void print_matrix(int** matrix, int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++)
            cout << (matrix[i][j]<10 ? "   " : "  ") << matrix[i][j];
        cout << endl;
    }
}

int** get_minor(int** old_matrix, int size, int wiersz, int kolumna) {
    int **new_matrix = new int*[size-1];
    for (int i=0; i<size-1; i++)
        new_matrix[i] = new int[size-1];

    int temp_wiersz=0;
    for (int i=0; i<size; i++) {
        if (i==wiersz) continue;
        int temp_komlumna=0;

        for (int j=0; j<size; j++) {
            if (j==kolumna) continue;

            new_matrix[temp_wiersz][temp_komlumna] = old_matrix[i][j];
            temp_komlumna++;
        }
        temp_wiersz++;
    }

    return new_matrix;
}

int oblicz_det(int** matrix, int size) {
    if (size == 1)
        return matrix[0][0];

    int det = 0;

    for (int wiersz_poz=0; wiersz_poz < size; wiersz_poz++) {
        int **minor = get_minor(matrix, size, wiersz_poz, 0);
        det += ((wiersz_poz % 2 == 0) ? 1 : -1) * matrix[wiersz_poz][0] * oblicz_det(minor, size-1);
    }

    return det;
}

int main(int argc, char* argv[]) {
    int size;
    cin >> size;

    cout << "Rozmiar:\nMacierz" << endl;

    int **matrix = new int*[size];
    for (int i=0; i<size; i++)
        matrix[i] = new int[size];

    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            cin >> matrix[i][j];

    cout << "Wyznacznik: " << oblicz_det(matrix, size);

    return 0;
}