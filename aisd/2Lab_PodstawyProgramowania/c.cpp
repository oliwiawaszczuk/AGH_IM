// Napisz program, który wczyta ze standardowego wejścia informację o aktualnym położeniu skoczka (konik) szachowego na pustej standardowej szachownicy 8x8, której pola opisane są literami [a-h] oraz liczbami [1-8]. Program wczyta nową pozycję skoczka i poda informację, czy nowa pozycja jest prawidłowym ruchem szachowym

#include <iostream>
using namespace std;

void check_move(char current_poz, int current_poz_i, char new_poz, int new_poz_i) {
    int check_char = abs(current_poz - new_poz);
    int check_i= abs(current_poz_i - new_poz_i);

    cout << "char: " << check_char << " int: " << check_i << endl;

    string wyn_string = (check_i + check_char == 3) ? "" : "nie";
    cout << "Nowa pozycja jest ruchem " << wyn_string << "prawidłowym.";
}

int main() {
    char current_poz, new_poz;
    int current_poz_i, new_poz_i;
    
    cin >> current_poz >> current_poz_i >> new_poz >> new_poz_i;

    cout << "Aktualna pozycja skoczka: " << current_poz << current_poz_i << "\nNowa pozycja skoczka: " << new_poz << new_poz_i << "\n";

    check_move(current_poz, current_poz_i, new_poz, new_poz_i);
    
    return 0;
} 