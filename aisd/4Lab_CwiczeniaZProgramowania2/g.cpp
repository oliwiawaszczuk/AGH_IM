#include <iostream>
#include <fstream>

using namespace std;

float N(float x, float y) {
    return 0;
}

int main()
{
    ofstream plik;
    plik.open("obrazek.pgm", ios::out | ios::binary);

    int szerokosc = 256, wysokosc = 256;
    plik << "P5\n" << szerokosc << " " << wysokosc << "\n255\n";

    for (int i = 0; i < wysokosc; i++)
    {
        for (int j = 0; j < szerokosc; j++)
        {
            float y = (float)i/szerokosc;
            float x = (float)j/wysokosc;
            plik.put((x * (1-y))*255);
        }

    }


    return 0;
}