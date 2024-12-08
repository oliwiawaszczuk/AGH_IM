// Napisz program, który wczyta ze standardowego wejścia liczbę naturalną zapisaną w systemie dziesiętnym, a na wyjściu poda liczność 1 (jedynek) w zapisie dwójkowym tej liczby.

#include <iostream>
using namespace std;

string reverse(string text) {
    string reversed_text ="";

    for (int i=text.size(); i>=0; --i) {
        reversed_text += text[i];
    }

    return reversed_text;
}

string change_for_binary_system(int decimal) {
    string binary;

    while (decimal > 0) {
        binary += (decimal % 2 == 0) ? "0" : "1";
        decimal /= 2;
    }

    return reverse(binary);
}

int count_number_in_string(int number, string text) {
    int count = 0;
    for (int i=0; i<text.size(); i++)
        if (text[i] - '0' == number)
            count++;
    return count;
}

int main() {
    int decimal;
    cout << "Podaj liczbe w systemie dziesietnym: ";
    cin >> decimal;
    
    string bin = change_for_binary_system(decimal);

    cout << "Wartość liczby w systemie dziesiętnym: " << decimal << "\nLiczność jedynek w zapisie dwójkowym: " << count_number_in_string(1, bin);
    return 0;
} 