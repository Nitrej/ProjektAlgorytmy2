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

void wypiszKrasnale(vector<Krasnoludek>& krasnale) 
{
    cout << "\nDo naszego krolestwa przybyli: " << endl;
    for (int i = 0; i < krasnale.size(); i++)
    {
        cout << "Krasnal " << krasnale[i].idKrasnoludka << " preferuje wydobycie " << krasnale[i].preferowanyFach << endl;
    }
}

void wypiszKopalnie(vector<Kopalnia>& kopalnie)
{
    cout << "\nOdkryto nastepujace kopalnie: " << endl;
    for (int i = 0; i < kopalnie.size(); i++)
    {
        cout << "Kopalnia " << kopalnie[i].idKopalni << " jest bogata w zloze " << kopalnie[i].wydobywanySurowiec << endl;
    }
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

//Maksymalne wydobycie, Zlozonosc O(n^2) gdzie n-liczba krasnoludkow 
void przyporzadkujKrasnaleMaksWydobycie(vector<Krasnoludek>& dwarves, vector<Kopalnia>& mines) {
    for (Krasnoludek& dwarf : dwarves) {
        int best_mine = -1;
        int best_efficiency = -1;

        for (size_t i = 0; i < mines.size(); i++) {
            Kopalnia& mine = mines[i];

            if (mine.wydobywanySurowiec == dwarf.preferowanyFach && mine.indeksyPracujacychKrasnali.size() < mine.limitMiejsc) {
                if (best_mine == -1 || dwarf.wydajnosc > best_efficiency) {
                    best_mine = i;
                    best_efficiency = dwarf.wydajnosc;
                }
            }
        }

        if (best_mine == -1) {
            // Przypisanie do kopalni z wolnym miejscem
            for (size_t i = 0; i < mines.size(); i++) {
                Kopalnia& mine = mines[i];
                if (mine.indeksyPracujacychKrasnali.size() < mine.limitMiejsc) {
                    best_mine = i;
                    break;
                }
            }
        }

        if (best_mine != -1) {
            mines[best_mine].indeksyPracujacychKrasnali.push_back(&dwarf - &dwarves[0]);
        }
    }
}

//Maksymalne wydobycie z minimalnymi odleglosciami od kopalni, Zloznosc O(n^2) gdzie n-liczba krasnoludkow
void przyporzadkujKrasnaleMaksWydobycieMaloOwsianki(vector<Krasnoludek>& dwarves, vector<Kopalnia>& mines) {
    for (Krasnoludek& dwarf : dwarves) {
        int best_mine = -1;
        int best_efficiency = -1;
        int best_distance = numeric_limits<int>::max();

        for (size_t i = 0; i < mines.size(); i++) {
            Kopalnia& mine = mines[i];

            if (mine.wydobywanySurowiec == dwarf.preferowanyFach && mine.indeksyPracujacychKrasnali.size() < mine.limitMiejsc) {
                int distance = obliczOdleglosc(dwarf.polozenieX, dwarf.polozenieY, mine.polozenieX, mine.polozenieY);

                if (best_mine == -1 || (dwarf.wydajnosc > best_efficiency) ||
                    (dwarf.wydajnosc == best_efficiency && distance < best_distance)) {
                    best_mine = i;
                    best_efficiency = dwarf.wydajnosc;
                    best_distance = distance;
                }
            }
        }

        if (best_mine == -1) {
            // Przypisanie kopalni z najbli¿szym preferowanym surowcem
            int closest_mine = -1;
            int closest_distance = numeric_limits<int>::max();

            for (size_t i = 0; i < mines.size(); i++) {
                Kopalnia& mine = mines[i];
                if (mine.indeksyPracujacychKrasnali.size() < mine.limitMiejsc) {
                    int distance = obliczOdleglosc(dwarf.polozenieX, dwarf.polozenieY, mine.polozenieX, mine.polozenieY);
                    if (distance < closest_distance) {
                        closest_mine = i;
                        closest_distance = distance;
                    }
                }
            }

            best_mine = closest_mine;
        }

        if (best_mine != -1) {
            mines[best_mine].indeksyPracujacychKrasnali.push_back(&dwarf - &dwarves[0]);
        }
    }
}

//Funkcja wypisujaca info o krasnoludkach
void wypiszInfoPrzyporzadkowanie(vector<Krasnoludek>& krasnoludki, vector<Kopalnia>& kopalnie) {

    int sumarycznaOdleglosc = 0;
    int wydobycieZloto = 0;
    int wydobycieSrebro = 0;
    int wydobycieMiedz = 0;

    for (const auto& kopalnia : kopalnie) {
        cout << "Kopalnia (Surowiec: " << kopalnia.wydobywanySurowiec << ", Polozenie: (" << kopalnia.polozenieX << ", " << kopalnia.polozenieY << "))\n";

        for (int krasnalID : kopalnia.indeksyPracujacychKrasnali) {
            const Krasnoludek& krasnal = krasnoludki[krasnalID];

            int odleglosc = obliczOdleglosc(krasnal.polozenieX, krasnal.polozenieY, kopalnia.polozenieX, kopalnia.polozenieY);
            cout << "Krasnoludek z domku " << krasnal.idKrasnoludka << ", Polozenie: (" << krasnal.polozenieX << ", " << krasnal.polozenieY << "), Odleglosc od kopalnii: " << odleglosc << ")\n";
            
            sumarycznaOdleglosc += odleglosc;

            string tmp = kopalnia.wydobywanySurowiec;
            if (tmp == "zloto") {
                if (krasnoludki[krasnalID].preferowanyFach == tmp) {
                    wydobycieZloto += krasnal.wydajnosc;
                }
                else {
                    wydobycieZloto += 1;
                }
            }
            else if (tmp == "srebro") {
                if (krasnoludki[krasnalID].preferowanyFach == tmp) {
                    wydobycieSrebro += krasnal.wydajnosc;
                }
                else {
                    wydobycieSrebro += 1;
                }
            }
            else if (tmp == "miedz") {
                if (krasnoludki[krasnalID].preferowanyFach == tmp) {
                    wydobycieMiedz += krasnal.wydajnosc;
                }
                else {
                    wydobycieMiedz += 1;
                }
            }
            
        }
        cout << endl;
    }

    cout << "Sniezka musi ugotowac " << sumarycznaOdleglosc << " owsianki" << endl;
    cout << "Wydobywane zloto: " << wydobycieZloto <<  " jednostek" << endl;
    cout << "Wydobywane srebro: " << wydobycieSrebro << " jednostek" << endl;
    cout << "Wydobywane miedz: " << wydobycieMiedz << " jednostek" << endl;
}
