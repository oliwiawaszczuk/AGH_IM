#include <cmath>
#include <iostream>
using namespace std;

int h() {
    int N, M;
    cin >> N >> M;
    int **tab = new int*[N];
    for (int i = 0; i < N; i++)
        tab[i] = new int[M];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> tab[i][j];

    int a = 0, b = N*M - 1;
    bool isNieparzysta = false;

    while (b>a) {
        int row_a = a / M, col_a = a % M;
        int row_b = b / M, col_b = b % M;

        if (tab[row_a][col_a] % 2 != 0)
            a++;
        if (tab[row_b][col_b] % 2 == 0)
            b--;

        if (tab[row_a][col_a] % 2 == 0 && tab[row_b][col_b] % 2 != 0) {
            swap(tab[row_a][col_a], tab[row_b][col_b]);
            isNieparzysta = true;
            a++;
            b--;
        }
    }

    if (!isNieparzysta) {
        cout << "0 0" << endl;
        return 0;
    }

    int last_x=0, last_y=0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tab[i][j] % 2 == 0) {
                cout << last_x+1 << " " << last_y+1 << endl;
                return 0;
            }
            last_x = i;
            last_y = j;
        }
    }
    return 0;
}
