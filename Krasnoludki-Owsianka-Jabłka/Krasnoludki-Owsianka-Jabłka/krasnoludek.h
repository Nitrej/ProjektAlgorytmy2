#pragma once
#include <vector>
#include <string>

/// <summary>
/// Klasa reprezentujaca kopalnie.
/// </summary>
class Krasnoludek
{
public:
	/// <summary>
	/// Wydajnosc krasnoludka
	/// </summary>
	int wydajnosc;
	/// <summary>
	/// Surowiec w jakim wydobyciu specjalizuje siê krasnoludek
	/// </summary>
	std::string preferowanyFach;
	/// <summary>
	/// Id krasnoludka
	/// </summary>
	int idKrasnoludka;
	/// <summary>
	/// Wspolrzedna x krasnoludka
	/// </summary>
	int polozenieX;
	/// <summary>
	/// Wspolrzedna y krasnoludka
	/// </summary>
	int polozenieY;

	/// <summary>
	/// Konstruktor kopalnii.
	/// </summary>
	/// <param name="tmpwydajnosc">Wydajnosc krasnoludka</param>
	/// <param name="tmppreferowanyFach">Surowiec w jakim wydobyciu specjalizuje siê krasnoludek</param>
	/// <param name="tmpidKrasnoludka">Id krasnoludka</param>
	/// <param name="tmppolozenieX">Wspolrzedna x krasnoludka</param>
	/// <param name="tmppolozenieY">Wspolrzedna y krasnoludka</param>
	Krasnoludek(int tmpwydajnosc, std::string tmppreferowanyFach, int tmpidKrasnoludka, int tmppolozenieX, int tmppolozenieY) {
		this->wydajnosc = tmpwydajnosc;
		this->preferowanyFach = tmppreferowanyFach;
		this->idKrasnoludka = tmpidKrasnoludka;
		this->polozenieX = tmppolozenieX;
		this->polozenieY = tmppolozenieY;
	}
};
