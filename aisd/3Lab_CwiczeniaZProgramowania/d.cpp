// Napisz program, który wczyta linię tekstu ze standardowego wejścia a następnie wypiszę ją zmieniając wielkość liter:
// 1. małe
// 2. WIELKIE
// 3. Tytułowe

#include <iostream>
using namespace std;

string lower = "aąbcćdeęfghijklłmnńoópqrsśtuvwxyzźż";
string upper = "AĄBCĆDEĘFGHIJKLŁMNŃOÓPQRSŚTUVWXYZŹŻ";

void conv_to_lower(string text) {
    string lowered_text = "";

    for (int i = 0; i < text.length(); i++) {
        if (upper.find(text[i]) != string::npos)
            lowered_text += lower[upper.find(text[i])];
        else
            lowered_text += text[i];
    }

    cout << lowered_text << endl;
}

void conv_to_upper(string text) {
    string uppered_text = "";

    for (int i = 0; i < text.length(); i++) {
        if (lower.find(text[i]) != string::npos)
            uppered_text += upper[lower.find(text[i])];
        else
            uppered_text += text[i];
    }

    cout << uppered_text << endl;
}

void conv_for_title(string text) {
    string for_title = "";

    for (int i=0; i<text.length(); i++) {
        if (i == 0 || text[i-1] == ' ') {
            if (lower.find(text[i]) != string::npos)
                for_title += upper[lower.find(text[i])];
            else
                for_title += text[i];
        } else {
            if (upper.find(text[i]) != string::npos)
                for_title += lower[upper.find(text[i])];
            else
                for_title += text[i];
        }
    }

    cout << for_title << endl;
}

int main() {
    string text;
    getline(cin, text);

    cout << "Tekst: \nKonwersja: \n1. małe \n2. WIELKIE \n3. Tytułowe\nWybór: \n";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            conv_to_lower(text);
        break;
        case 2:
            conv_to_upper(text);
        break;
        case 3:
            conv_for_title(text);
        break;
        default:
            cout << "Invalid input! Please try again!\n";
    }

    return 0;
}
