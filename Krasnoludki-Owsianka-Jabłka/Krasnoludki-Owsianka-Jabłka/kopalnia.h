#pragma once
#include <vector>
#include <string>

/// <summary>
/// Klasa reprezentuj¹ca kopalnie.
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
	/// Maksymalna pojemnoœæ kopalnii.
	/// </summary>
	int limitMiejsc;
	/// <summary>
	/// Wspó³rzêdna x kopalnii.
	/// </summary>
	int polozenieX;
	/// <summary>
	/// Wspó³rzêdna y kopalnii.
	/// </summary>
	int polozenieY;
	/// <summary>
	/// Wektor liczb ca³kowitych reprezentujacych id pracuj¹cych krasnoludków. 
	/// </summary>
	std::vector<int> indeksyPracujacychKrasnali = {};

	/// <summary>
	/// Konstruktor kopalnii.
	/// </summary>
	/// <param name="idKopalni">Id kopalnii</param>
	/// <param name="tmpwydobywanySurowiec">Wydobywany surowiec</param>
	/// <param name="tmplimitMiejsc">Maksymalna pojemnoœæ kopalnii</param>
	/// <param name="tmpPolozenieX">Wspó³rzêdna x kopalnii</param>
	/// <param name="tmpPolozenieY">Wspó³rzêdna y kopalnii</param>
	Kopalnia(int idKopalni, std::string tmpwydobywanySurowiec,int tmplimitMiejsc, int tmpPolozenieX, int tmpPolozenieY) {
		this->idKopalni = idKopalni;
		this->wydobywanySurowiec = tmpwydobywanySurowiec;
		this->limitMiejsc = tmplimitMiejsc;
		this->polozenieX = tmpPolozenieX;
		this->polozenieY = tmpPolozenieY;
	}

};
