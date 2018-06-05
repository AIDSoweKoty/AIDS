//
// Created by Piotr on 01.06.2018.
//

#ifndef PROGRAM_PLECAK_H
#define PROGRAM_PLECAK_H

class plecak {
public:
    int ladownosc; // ile może maksymalnie zmieścić plecak
    int size; // liczba paczek
    int** tab; //tablicza w której są informacje o paczkach w tab[i][0] jest waga paczki, a tab[i][1] wartość paczki
public:
    plecak(int s, float b); // podajesz jako s ile jest paczek a jako b floata tak jak jest w pdfie od Sterny to bedzie potem potrzebne i wpływa na ładowność
    void wypisz_plecak();
    // zrobiłem heurystyki, zwracają jaki bedzię zysk z tych paczek, czyli sume po wartość wybranych paczek, jak patrzyłęm to chyba nie trzeba nigdzie zapisywać jakie psczki się wybrało wystarczy jaki będzie z nich zysk
    int GH1();
    int GH2();
    int GH3();
    int GH4();
    //zmienne które mają być by rekurencja nie zajmowała za dużo RAM-u
    void bruteForce(int waga=0,int wartosc=0, int bit=0);
    void bruteForceMadry(int waga=0,int wartosc=0, int bit=0);
    bool *tmp;  //pomocnicza by każda rekurencja nie tworzyła swojej własnej tablicy o rozmiarze size
    bool *tmp2; //pod koniec funkcji wynik jest tutaj, na sam koniec jest spowrotem wyzerowana
    int m;      //najlepsza wartość jest tutaj przechowywana, na sam koniec jest spowrotem ustawiana na 0
    int** prog;
    int vent;
    //programowanie dynamicze
    int programowanieDynamiczne(); //płaczę :.(
private: // to funkcje sortujące do heurystyk
    void sortuj_plecak(bool po_s , bool rosnaco );
    void sortuj_polecak_po_sredniej();

};


#endif //PROGRAM_PLECAK_H
