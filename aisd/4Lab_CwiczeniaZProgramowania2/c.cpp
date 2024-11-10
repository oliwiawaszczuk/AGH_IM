#include <iostream>
using namespace std;

void printNumber(int number) {
    int len = 1;
    if (number >= 10)
        len = 2;
    for (int i = 0; i < 6-len; i++)
        cout << " ";

    cout << number;
}

int main() {
    int N, M;
    cin >> N >> M;
    cout << "\nN:\nM:\nA:\n";
    int **A = new int*[N];
    for (int i = 0; i < N; i++)
        A[i] = new int[M];

    int counter = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j] = counter;
            counter++;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printNumber(A[i][j]);
        }
        cout << endl;
    }

    cout << "B:\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printNumber(A[j][i]);
        }
        cout << endl;
    }

    for (int i = 0; i < N; i++)
        delete[] A[i];
    delete[] A;

    return 0;
}
