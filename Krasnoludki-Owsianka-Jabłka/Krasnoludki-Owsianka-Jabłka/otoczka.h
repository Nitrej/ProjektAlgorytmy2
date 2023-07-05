#pragma once

#include<iostream>
#include<stack>
#include<vector>

#include "kopalnia.h"

using namespace std;

struct Punkt
{
    int x, y;
    int id;
};

Punkt p0;

Punkt nextToTop(std::stack<Punkt>& S)
{
    Punkt p = S.top();
    S.pop();
    Punkt res = S.top();
    S.push(p);
    return res;
}

void swap(Punkt& p1, Punkt& p2)
{
    Punkt temp = p1;
    p1 = p2;
    p2 = temp;
}

int distance(Punkt p1, Punkt p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) +
        (p1.y - p2.y) * (p1.y - p2.y);
}

int orientation(Punkt p, Punkt q, Punkt r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
        (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // wspolliniowe
    return (val > 0) ? 1 : 2; // z lub przeciwnie do ruchu wskazowek zegara
}

int compare(const void* vp1, const void* vp2)
{
    Punkt* p1 = (Punkt*)vp1;
    Punkt* p2 = (Punkt*)vp2;

    int orien = orientation(p0, *p1, *p2);
    if (orien == 0)
        return (distance(p0, *p2) >= distance(p0, *p1)) ? -1 : 1;

    return (orien == 2) ? -1 : 1;
}

//Algorytm Grahama
void otoczkaWypukla(vector<Kopalnia> *kopalnie) {
    
    int n = kopalnie->size();

    vector<Punkt> tmp;
    for (int i = 0; i < n; i++) 
    {
        if (kopalnie->at(i).indeksyPracujacychKrasnali.size() >0) {
            tmp.push_back({ kopalnie->at(i).polozenieX, kopalnie->at(i).polozenieY , kopalnie->at(i).idKopalni });
        }
        
    }
    n = tmp.size();
    int ymin = tmp[0].y , min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = tmp[i].y;

        //Wybranie max lewego i/lub max dolnego punktu
        if ((y < ymin) || (ymin == y && tmp[i].x < tmp[min].x)) 
        {
            ymin = tmp[i].y;
            min = i;
        }
            
    }

    //Ustawienie max lewego i/lub max dolnego punktu na pozycji startowej
    swap(tmp[0], tmp[min]);

    //Sortowanie wedlug wspolrzednych biegunowych
    p0 = tmp[0];
    qsort(&tmp[1], n - 1, sizeof(Punkt), compare);


    //Jezeli dwa lub wiecej punktow ma taki sam kat z p0 to biezemy tylko najdalszy
    int m = 1; //rozmiar zmodyfikowanej tablicy
    for (int i = 1; i < n; i++)
    {
        //usuwanie tych samych katow w stosunku do p0
        while (i < n - 1 && orientation(p0, tmp[i], tmp[i + 1]) == 0)
            i++;

        tmp[m] = tmp[i];
        m++;
    }

    //jezeli rozmiar mniejszy od 3 to otoczka niemozliwa
    //Wypisujemy wszystkie kopalnie, poniewaz sa w jednej linii lub jest ich mniej niz 3
    if (m < 3) 
    {
        for (int i = 0; i < n; i++) {
            cout << "Kopalnia nr: " << tmp[i].id << " (" << tmp[i].x << ", " << tmp[i].y << ")" << endl;
        }
        return;
    }

    //stos z 3 pierwszymi punktami
    std::stack<Punkt> S;
    S.push(tmp[0]);
    S.push(tmp[1]);
    S.push(tmp[2]);

    for (int i = 3; i < m; i++)
    {
        //zdejmujemy gorny punkt ze stosu jezeli punkty(przedostatni, ostatni, obecnie przerabiany) nie skrecaja w lewo
        while (S.size() > 1 && orientation(nextToTop(S), S.top(), tmp[i]) != 2)
            S.pop();
        S.push(tmp[i]);
    }

    // wypisanie
    while (!S.empty())
    {
        Punkt p = S.top();
        cout << "Kopalnia nr: "<<p.id<<" (" << p.x << ", " << p.y << ")" << endl;
        S.pop();
    }
};