#pragma once
#include <fstream>
#include <vector>
#include "krasnoludek.h"
#include "kopalnia.h"

bool wczytanieDanych(vector<Kopalnia> &kopalnie, vector<Krasnoludek> &krasnoludki) {

    int iloscKrasnali, iloscKopalni;

    fstream f;

    f.open("dane.txt", ios::in);

    f >> iloscKrasnali >> iloscKopalni;

    for (int i = 0; i < iloscKrasnali; i++) 
    {
        int wydajnosc;
        std::string preferowanyFach;
        int idKrasnoludka;
        int polozenieX;
        int polozenieY;

        f >> wydajnosc >> preferowanyFach >> idKrasnoludka >> polozenieX >> polozenieY;

        krasnoludki.push_back(Krasnoludek(wydajnosc, preferowanyFach, idKrasnoludka, polozenieX, polozenieY));

    }

    for (int i = 0; i < iloscKopalni; i++) 
    {
        std::string wydobywanySurowiec;
        int limitMiejsc;
        int polozenieX;
        int polozenieY;

        f >> wydobywanySurowiec >> limitMiejsc >> polozenieX >> polozenieY;

        kopalnie.push_back(Kopalnia(wydobywanySurowiec, limitMiejsc, polozenieX, polozenieY));

    }

	return false;
}

// Funkcja porównuj¹ca dla sortowania
bool compareDwarfs(const Krasnoludek& krasnoludek1, const Krasnoludek& krasnoludek2) {
	return krasnoludek1.wydajnosc > krasnoludek2.wydajnosc;
}