// Napisz program, który wczytuje ze standardowego wejścia oddzielone pojedynczymi spacjami ciągi znaków zbudowanych z [a-zA-Z]+ (małe i wielkie litery), a na wyjściu poinformuje, czy tak utworzony superciąg, ignorując wielkość liter, i spacje jest palindromem.

#include <iostream>
#include <cctype>
using namespace std;

string remove_white_characters_and_to_lower(string text) {
    string new_text;

    for (int i=0; i<text.size(); i++)
        if (text[i] != ' ')
            new_text += tolower(text[i]);

    return new_text;
}

bool is_palidrom(string text) {
    text = remove_white_characters_and_to_lower(text);

    for (int i=0; i<text.size()/2; i++) {
        int left = i;
        int right = text.size() - 1 - i;
        cout << text[left] + '0' << " - " << text[right] + '0' << endl;
        if (text[left] != text[right])
            return false;
    }

    return true;
}

void with_polish_chars(string text) {
      unsigned short *litery = new unsigned short[text.size()]; // na male litery bez spacji w formacje 16 bit
      for (int i=0; i<text.size(); i++) {
        unsigned char chr = static_cast<unsigned char>(text[i]); // poszczegolny znaczek
        if (chr == ' ') continue;
//        unsigned short
        if ((chr >> 5) == 0b110) {

        }
  }
}

int main() {
    string text;
    getline(cin, text);

    string palindrom = is_palidrom(text) ? "" : "nie ";

    cout << "Ciąg znaków: " << text << "\nCiąg " << text << " " << palindrom << "jest palindromem.";
    return 0;
} 
