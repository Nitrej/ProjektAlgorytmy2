#pragma once
#include <fstream>
#include <vector>
#include <cmath>
#include "krasnoludek.h"
#include "kopalnia.h"

using namespace std;

bool wczytanieDanych(vector<Kopalnia> *kopalnie, vector<Krasnoludek> *krasnoludki)
{
    
    try
    {
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

            krasnoludki -> push_back(Krasnoludek(wydajnosc, preferowanyFach, idKrasnoludka, polozenieX, polozenieY));

        }

        for (int i = 0; i < iloscKopalni; i++)
        {
            int idKopalni;
            std::string wydobywanySurowiec;
            int limitMiejsc;
            int polozenieX;
            int polozenieY;

            f >> idKopalni >>wydobywanySurowiec >> limitMiejsc >> polozenieX >> polozenieY;

            kopalnie -> push_back(Kopalnia(idKopalni,wydobywanySurowiec, limitMiejsc, polozenieX, polozenieY));

        }
        return true;
    }
    catch (const std::exception&)
    {
        return false;
    }
    return false;
}

bool compareDwarfs(const Krasnoludek& krasnoludek1, const Krasnoludek& krasnoludek2) {
    return krasnoludek1.wydajnosc > krasnoludek2.wydajnosc;
}

//Funkcja do obliczania odleglosci
int obliczOdleglosc(int kopalniaX, int kopalniaY, int krasnoludekX, int krasnoludekY) {
    int dx = abs(kopalniaX - krasnoludekX);
    int dy = abs(kopalniaY - krasnoludekY);
    return sqrt(dx * dx + dy * dy);
}