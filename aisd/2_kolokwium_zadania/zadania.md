# Zadania

---

## Grupa 1
![alt -histogram](20250126_203044.jpg)
![alt -szpital / PGM](20250126_203051.jpg)
![alt +polskie znaki](20250126_203126.jpg)
![alt +szukanie binarne nazwiska](20250126_203205.jpg)
![alt +piorytety](20250126_203153.jpg)


## Grupa 2
![alt +szukanie koncowek](462579167_617197550676557_7436047038297680426_n.png)
![alt +piorytety](472973934_1646242719311166_1687463524325255601_n.png)
![alt -szpital_PGM](474540930_1317567872611559_3321143730420751758_n.png)
![alt +szukanie binarne nazwiska](474546023_925806133033306_7486121946559395494_n.png)
![alt +sortowanie rosnaco wg wagi](474835424_1000734611884544_4833934253964448252_n.png)


## Grupa 3
![alt z --rek na inter](9eb80897-f2b7-497d-9384-1da4d827c5b8.jpg)
![alt +parzyste niemalejaco - nieparzyste nierosnaco](289ca97d-218c-4b94-85cb-a8f38519fc47.jpg)
![alt +losowanie kropek](f6a0c820-d126-4288-84b8-4dc0f1c0630a.jpg)
![alt --tablica z hashowaniem](f1070c06-7c65-4a96-a600-03ba445d2890.jpg)

## Grupa 4
![alt lista jednokierunkowa](4_1.PNG)
![alt z rekurentyjnej na interacyjna](4_2.PNG)
![alt losowanie 2 kul](4_3.PNG)


# WAŻNE FUNKCJE
### 1. Funkcja przyjmuje stringa i sprawdza czy jest w nim chociaż jeden polski znak
```cpp
bool czy_slowo_ma_polski_znak(string slowo) {
    for (int i=0; i<slowo.length(); i++) {
        int literka = static_cast<int>(slowo[i]);
        cout << "Literka " << slowo[i];
        if ((literka >= 65 && literka <= 90) || (literka >= 97 && literka <= 122))
            continue;
        else
            return true;
    }

    return false;
}
```
---
### 2. Funkcja sortuje pacjentów wg wagi
>  Jeśli ma sortować malejąco >
> 
>  Jeśli ma sortować rosnąco <
> 
>  Jeśli ma sortować coś innego niż wage to zamień .waga
```cpp
void sortowanie(Pacjent *pacjenci, int n) {
    for (int i=0; i<n; i++)
        for (int j=0; j<n-i-1; j++)
            if (pacjenci[j].waga > pacjenci[j+1].waga)
                swap(pacjenci[j], pacjenci[j+1]);
}
```
---
### 3. Funkcja rekurencyjna do wyszukiwania binarnego
> W przykładzie wyszukujemy nazwisko
```cpp
bool wyszukiwanieRekurencyjne(Pacjent *pacjenci, int lewy, int prawy, string nazwisko) {
    if (lewy > prawy)
        return false;

    int srodek = lewy + (prawy - lewy) / 2;

    if (pacjenci[srodek].nazwisko == nazwisko)
        return true;

    if (pacjenci[srodek].nazwisko < nazwisko) // szukanie w prawo
        return wyszukiwanieRekurencyjne(pacjenci, srodek + 1, prawy, nazwisko);
    else // szukanie w lewo
        return wyszukiwanieRekurencyjne(pacjenci, lewy, srodek - 1, nazwisko);
}
```