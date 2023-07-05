#pragma once
#include <fstream>
#include <vector>
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