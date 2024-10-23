#include <iostream>
using namespace std;

float dodaj(float a, float b) {
    return a+b;
}
float odejmij(float a, float b) {
    return a-b;
}
float pomnoz(float a, float b) {
    return a*b;
}
float podziel(float a, float b) {
    return a/b;
}

int b()
{
    float a, b;
    char op;
    cout<<"Działanie: ";
    cin>>a>>op>>b;

    float (*wsk)(float, float);
    if (op=='+') wsk = dodaj;
    else if (op=='-') wsk = odejmij;
    else if (op=='*') wsk = pomnoz;
    else if (op=='/') wsk = podziel;
    else {
        cout << "Nieprawidłowe działanie" << endl;
        return 0;
    }

    float wynik = wsk(a,b);
    cout << "Wynik: " << wynik << endl;

    return 0;
}