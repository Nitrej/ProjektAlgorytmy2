#pragma once
#include <vector>
#include <string>

/// <summary>
/// Klasa reprezentuj�ca kopalnie.
/// </summary>
class Krasnoludek
{
public:
	/// <summary>
	/// Wydajno�� krasnoludka
	/// </summary>
	int wydajnosc;
	/// <summary>
	/// Surowiec w jakim wydobyciu specjalizuje si� krasnoludek
	/// </summary>
	std::string preferowanyFach;
	/// <summary>
	/// Id krasnoludka
	/// </summary>
	int idKrasnoludka;
	/// <summary>
	/// Wsp�rz�dna x krasnoludka
	/// </summary>
	int polozenieX;
	/// <summary>
	/// Wsp�rz�dna y krasnoludka
	/// </summary>
	int polozenieY;

	/// <summary>
	/// Konstruktor kopalnii.
	/// </summary>
	/// <param name="tmpwydajnosc">Wydajno�� krasnoludka</param>
	/// <param name="tmppreferowanyFach">Surowiec w jakim wydobyciu specjalizuje si� krasnoludek</param>
	/// <param name="tmpidKrasnoludka">Id krasnoludka</param>
	/// <param name="tmppolozenieX">Wsp�rz�dna x krasnoludka</param>
	/// <param name="tmppolozenieY">Wsp�rz�dna y krasnoludka</param>
	Krasnoludek(int tmpwydajnosc, std::string tmppreferowanyFach, int tmpidKrasnoludka, int tmppolozenieX, int tmppolozenieY) {
		this->wydajnosc = tmpwydajnosc;
		this->preferowanyFach = tmppreferowanyFach;
		this->idKrasnoludka = tmpidKrasnoludka;
		this->polozenieX = tmppolozenieX;
		this->polozenieY = tmppolozenieY;
	}
};
