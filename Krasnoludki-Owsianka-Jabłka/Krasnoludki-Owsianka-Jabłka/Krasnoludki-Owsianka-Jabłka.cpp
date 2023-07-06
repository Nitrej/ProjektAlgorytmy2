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
    cout << "=================================================================================================" <<endl;
    cout << "-------------------------------------Krolestwo Sniezki wita!-------------------------------------\n";
    cout << "=================================================================================================";

    if (!wczytanieDanych(&kopalnie,&krasnoludki)) {
        cout << "Czegos tu brakuje!" << endl;
        return 0;
    }
    //Sortowanie krasnoludkow
    sort(krasnoludki.begin(), krasnoludki.end(), compareDwarfs);

    wypiszKrasnale(krasnoludki);

    wypiszKopalnie(kopalnie);

    cout << "=================================================================================================" <<endl;
    cout << "Krolewna Sniezka nakazuje im nastepujace prace: " << endl;


    przyporzadkujKrasnaleMaksWydobycie(krasnoludki, kopalnie);

    wypiszInfoPrzyporzadkowanie(krasnoludki, kopalnie);
    cout << "=================================================================================================" <<endl;
    cout << "Ranna trasa Ksiecia wyglada wiec nastepujaco: " << endl;


    otoczkaWypukla(&kopalnie);

    //Clear kopalni
    for (Kopalnia& kopalnia : kopalnie) {
        kopalnia.indeksyPracujacychKrasnali.clear();
    }

    cout << "=================================================================================================" <<endl;
    cout << "Po uwzglednieniu lepszych mozliwosci przydzialu pracy dla krasnoludkow Krolewna zadecydowala tak: " << endl;


    przyporzadkujKrasnaleMaksWydobycieMaloOwsianki(krasnoludki, kopalnie);

    wypiszInfoPrzyporzadkowanie(krasnoludki, kopalnie);
    cout << "=================================================================================================" <<endl;
    cout << "Zmieniona zostala takze ranna trasa Ksiecia i wyglada teraz tak: \n" << endl;


    otoczkaWypukla(&kopalnie);
    cout << "=================================================================================================" <<endl;

}

