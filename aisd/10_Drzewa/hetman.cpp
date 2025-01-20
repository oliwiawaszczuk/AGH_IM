#include <iostream>
using namespace std;

void print_board(int **board, int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            if (board[i][j] == 0)
                cout << ".";
            else
                cout << "*";
        cout << endl;
    }
}

bool is_safe(int **board, int row, int col, int n) {
    // sprawdzanie w tej samej kolumnie
    for (int i=0; i<col; i++)
        if (board[row][i] == 1)
            return false;

    // sprawdzanie lewej gornej przekatnej
    for (int i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // sprawdzanie lewej dolnej przekatnej
    for (int i=row, j=col; i<n, j>=0; i--, j--)
        if(board[i][j] == 1)
            return false;

    return true;
}

bool solve(int **board, int col, int n) {
    if (col >= n)
        return true;

    for (int row=0; row<n; row++) {
        if (is_safe(board, row, col, n)) {
            board[row][col] = 1;

            if (solve(board, col+1, n))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

int main(int argc, char* argv[]) {
    int n;
    cin >> n;

    int **board = new int*[n];
    for (int i=0; i<n; i++)
        board[i] = new int[n];

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            board[i][j] = 0;

    if (solve(board, 0, n))
        print_board(board, n);
    else
        cout << "Brak rozwiazan" << endl;

    return 0;
}