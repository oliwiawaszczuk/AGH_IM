#include <iostream>
using namespace std;

void wypiszNa6Miejscach(int number) {
    int len = 1;
    if (number >= 10)
        len = 2;
    for (int i = 0; i < 6-len; i++)
        cout << " ";

    cout << number;
}

int main()
{
    int rows=3, cols=4;
    int **tab = new int*[rows];

    for(int i=0; i<rows; i++)
        tab[i] = new int[cols];

    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            tab[i][j] = 0;

    int counter = 1;
    int top=0, bottom=rows-1, left=0, right=cols-1;
    while (top <= bottom && left <= right) {

//        for (int i = left; i <= right; i++) { // right
//            tab[top][i] = counter++;
//        }
//        top++;
//
//        for (int i = top; i <= bottom; i++) { // down
//            tab[i][right] = counter++;
//        }
//        right--;
//
//        if (top <= bottom) {
//            for (int i = right; i >= left; i--) { // left
//                tab[bottom][i] = counter++;
//            }
//            bottom--;
//        }
//
//        if (left <= right) {
//            for (int i = bottom; i >= top; i--) { // up
//                tab[i][left] = counter++;
//            }
//            left++;
//        }
        // z dolu do gory
//            for (int i = bottom; i >= top; i--) {
//                tab[i][right] = counter++;
//            }
//            right--;
//
//            // W lewo
//            if (left <= right) {
//                for (int i = right; i >= left; i--) {
//                    tab[top][i] = counter++;
//                }
//                top++;
//            }
//
//            // W górę
//            if (top <= bottom) {
//                for (int i = top; i <= bottom; i++) {
//                    tab[i][left] = counter++;
//                }
//                left++;
//            }
//
//            // W prawo
//            if (left <= right) {
//                for (int i = left; i <= right; i++) {
//                    tab[bottom][i] = counter++;
//                }
//                bottom--;
//            }
    }

    // Rysowanie slimaka
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++)
            wypiszNa6Miejscach(tab[i][j]);
        cout << endl;
    }

    for(int i=0;i<rows;i++)
        delete[] tab[i];
    delete[] tab;

    return 0;
}