// Krasnoludki-Owsianka-Jabłka.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <algorithm>

#include "Funkcje.h"
#include "kopalnia.h"
#include "krasnoludek.h"
#include "otoczka.h"


using namespace std;

vector<Krasnoludek> krasnoludki;
vector<Kopalnia> kopalnie;

int main()
{
    cout << "Krolestwo Sniezki wita!\n";
    if (!wczytanieDanych(&kopalnie,&krasnoludki)) {
        cout << "Czegos tu brakuje!" << endl;
        return 0;
    }
    //Sortowanie krasnoludkow
    sort(krasnoludki.begin(), krasnoludki.end(), compareDwarfs);

    cout << "\nDo naszego krolestwa przybyli: " << endl;

    for (int i = 0; i < krasnoludki.size(); i++)
    {
        cout << "Krasnal " << krasnoludki[i].idKrasnoludka << " " << krasnoludki[i].preferowanyFach << endl;
    }
    for (int i = 0; i < kopalnie.size(); i++)
    {
        cout << "Kopalnia " << kopalnie[i].idKopalni << " " << kopalnie[i].wydobywanySurowiec << endl;
    }

    cout << "\nKrolewna Sniezka nakazuje im nastepujace prace: " << endl;

    przyporzadkujKrasnaleMaksWydobycie(krasnoludki, kopalnie);

    wypiszInfoPrzyporzadkowanie(krasnoludki, kopalnie);
    
    cout << "Otoczka wypukla: " << endl;

    otoczkaWypukla(&kopalnie);

}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
