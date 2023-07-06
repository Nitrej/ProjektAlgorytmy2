#pragma once
#include <vector>
#include <string>

/// <summary>
/// Klasa reprezentujaca kopalnie.
/// </summary>
class Kopalnia
{
public:
	/// <summary>
	/// Id kopalnii.
	/// </summary>
	int idKopalni;
	/// <summary>
	/// Wydobywany surowiec.
	/// </summary>
	std::string wydobywanySurowiec;
	/// <summary>
	/// Maksymalna pojemnosc kopalnii.
	/// </summary>
	int limitMiejsc;
	/// <summary>
	/// Wspolrzedna x kopalnii.
	/// </summary>
	int polozenieX;
	/// <summary>
	/// Wspolrzedna y kopalnii.
	/// </summary>
	int polozenieY;
	/// <summary>
	/// Wektor liczb calkowitych reprezentujacych id pracuj¹cych krasnoludkow. 
	/// </summary>
	std::vector<int> indeksyPracujacychKrasnali = {};

	/// <summary>
	/// Konstruktor kopalnii.
	/// </summary>
	/// <param name="idKopalni">Id kopalnii</param>
	/// <param name="tmpwydobywanySurowiec">Wydobywany surowiec</param>
	/// <param name="tmplimitMiejsc">Maksymalna pojemnoœæ kopalnii</param>
	/// <param name="tmpPolozenieX">Wspolrzedna x kopalnii</param>
	/// <param name="tmpPolozenieY">Wspolrzedna y kopalnii</param>
	Kopalnia(int idKopalni, std::string tmpwydobywanySurowiec,int tmplimitMiejsc, int tmpPolozenieX, int tmpPolozenieY) {
		this->idKopalni = idKopalni;
		this->wydobywanySurowiec = tmpwydobywanySurowiec;
		this->limitMiejsc = tmplimitMiejsc;
		this->polozenieX = tmpPolozenieX;
		this->polozenieY = tmpPolozenieY;
	}

};
