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

    wypiszKrasnale(krasnoludki);

    wypiszKopalnie(kopalnie);

    cout << "\nKrolewna Sniezka nakazuje im nastepujace prace: " << endl;

    przyporzadkujKrasnaleMaksWydobycie(krasnoludki, kopalnie);

    wypiszInfoPrzyporzadkowanie(krasnoludki, kopalnie);

    cout << "\nRanna trasa Ksiecia wyglada wiec nastepujaco: " << endl;

    otoczkaWypukla(&kopalnie);

    //Clear kopalni
    for (Kopalnia& kopalnia : kopalnie) {
        kopalnia.indeksyPracujacychKrasnali.clear();
    }

    cout << "\nPo uwzglenieniu lepszych mozliwosci przydzialu pracy dla krasnoludkow Krolewna zadecydowala tak: " << endl;

    przyporzadkujKrasnaleMaksWydobycieMaloOwsianki(krasnoludki, kopalnie);

    wypiszInfoPrzyporzadkowanie(krasnoludki, kopalnie);

    cout << "\nZmieniona zostala takze ranna trasa Ksiecia i wyglada teraz tak: " << endl;

    otoczkaWypukla(&kopalnie);

}

