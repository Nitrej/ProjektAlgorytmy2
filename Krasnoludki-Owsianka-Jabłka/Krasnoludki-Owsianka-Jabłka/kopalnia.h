#pragma once
#include <vector>
#include <string>

/// <summary>
/// Klasa reprezentuj�ca kopalnie.
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
	/// Maksymalna pojemno�� kopalnii.
	/// </summary>
	int limitMiejsc;
	/// <summary>
	/// Wsp�rz�dna x kopalnii.
	/// </summary>
	int polozenieX;
	/// <summary>
	/// Wsp�rz�dna y kopalnii.
	/// </summary>
	int polozenieY;
	/// <summary>
	/// Wektor liczb ca�kowitych reprezentujacych id pracuj�cych krasnoludk�w. 
	/// </summary>
	std::vector<int> indeksyPracujacychKrasnali = {};

	/// <summary>
	/// Konstruktor kopalnii.
	/// </summary>
	/// <param name="idKopalni">Id kopalnii</param>
	/// <param name="tmpwydobywanySurowiec">Wydobywany surowiec</param>
	/// <param name="tmplimitMiejsc">Maksymalna pojemno�� kopalnii</param>
	/// <param name="tmpPolozenieX">Wsp�rz�dna x kopalnii</param>
	/// <param name="tmpPolozenieY">Wsp�rz�dna y kopalnii</param>
	Kopalnia(int idKopalni, std::string tmpwydobywanySurowiec,int tmplimitMiejsc, int tmpPolozenieX, int tmpPolozenieY) {
		this->idKopalni = idKopalni;
		this->wydobywanySurowiec = tmpwydobywanySurowiec;
		this->limitMiejsc = tmplimitMiejsc;
		this->polozenieX = tmpPolozenieX;
		this->polozenieY = tmpPolozenieY;
	}

};
