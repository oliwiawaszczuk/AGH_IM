// Napisz program, który bez wykorzystania rekurencji przekształci podaną liczbę 32-bitową na kod U2
#include <iostream>
using namespace std;

//string to_binary(const string& liczba, int baza_wejsciowa) {
//    int liczba_dziesietna = 0;
//    int potega = 1;
//
//    for (int i = liczba.size() - 1; i >= 0; --i) {
//        char cyfra = liczba[i];
//        int wartosc_cyfry;
//
//        if (cyfra >= '0' && cyfra <= '9') {
//            wartosc_cyfry = cyfra - '0';
//        } else if (cyfra >= 'A' && cyfra <= 'Z') {
//            wartosc_cyfry = cyfra - 'A' + 10;
//        } else {
//            cout << "Nieprawidłowy znak" << endl;
//            return "";
//        }
//
//        if (wartosc_cyfry >= baza_wejsciowa) {
//            cout << "Cyfra " << cyfra << " nie jest poprawna dla systemu o bazie " << baza_wejsciowa << endl;
//            return "";
//        }
//
//        liczba_dziesietna += wartosc_cyfry * potega;
//        potega *= baza_wejsciowa;
//    }
//
//    string liczba_binarna = "";
//    do {
//        liczba_binarna = char((liczba_dziesietna % 2) + '0') + liczba_binarna;
//        liczba_dziesietna /= 2;
//    } while (liczba_dziesietna > 0);
//
//    return liczba_binarna;
//}
//
//string from_binary(const string& liczba_binarna, int baza_docelowa) {
//    int liczba_dziesietna = 0;
//    int potega = 1;
//
//    for (int i = liczba_binarna.size() - 1; i >= 0; --i) {
//        char cyfra = liczba_binarna[i];
//        if (cyfra == '1') {
//            liczba_dziesietna += potega;
//        }
//        potega *= 2;
//    }
//
//    string liczba_docelowa = "";
//    do {
//        int reszta = liczba_dziesietna % baza_docelowa;
//        liczba_dziesietna /= baza_docelowa;
//
//        if (reszta < 10) {
//            liczba_docelowa = char('0' + reszta) + liczba_docelowa;
//        } else {
//            liczba_docelowa = char('A' + (reszta - 10)) + liczba_docelowa;
//        }
//    } while (liczba_dziesietna > 0);
//
//    return liczba_docelowa;
//}

string to_binary(int32_t n) {
    int bits[32] = {0};

    if (n>=0) {
        for (int i = 31; i >= 0 && n > 0; --i) {
            bits[i] = n % 2;
            n /= 2;
        }
    } else {
        n = -n;
        for (int i = 31; i >= 0 && n > 0; --i) {
            bits[i] = n % 2;
            n /= 2;
        }

        for (int i = 0; i < 32; ++i) {
            bits[i] = bits[i] == 0 ? 1 : 0;
        }

        for (int i = 31; i >= 0; --i) {
            if (bits[i] == 0) {
                bits[i] = 1;
                break;
            } else {
                bits[i] = 0;
            }
        }
    }

    string binaryRep = "";
    for (int i = 0; i < 32; ++i)
        binaryRep += (bits[i] == 1 ? '1' : '0');

    return binaryRep;
}

int main() {
    int32_t n;
    cout << "N: "; cin >> n;
    cout << "Bity: " << to_binary(n);
    return 0;
}