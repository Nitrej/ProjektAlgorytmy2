#pragma once
#include <vector>
#include <string>

/// <summary>
/// Klasa reprezentuj¹ca kopalnie.
/// </summary>
class Krasnoludek
{
public:
	/// <summary>
	/// Wydajnoœæ krasnoludka
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
	/// Wspó³rzêdna x krasnoludka
	/// </summary>
	int polozenieX;
	/// <summary>
	/// Wspó³rzêdna y krasnoludka
	/// </summary>
	int polozenieY;

	/// <summary>
	/// Konstruktor kopalnii.
	/// </summary>
	/// <param name="tmpwydajnosc">Wydajnoœæ krasnoludka</param>
	/// <param name="tmppreferowanyFach">Surowiec w jakim wydobyciu specjalizuje siê krasnoludek</param>
	/// <param name="tmpidKrasnoludka">Id krasnoludka</param>
	/// <param name="tmppolozenieX">Wspó³rzêdna x krasnoludka</param>
	/// <param name="tmppolozenieY">Wspó³rzêdna y krasnoludka</param>
	Krasnoludek(int tmpwydajnosc, std::string tmppreferowanyFach, int tmpidKrasnoludka, int tmppolozenieX, int tmppolozenieY) {
		this->wydajnosc = tmpwydajnosc;
		this->preferowanyFach = tmppreferowanyFach;
		this->idKrasnoludka = tmpidKrasnoludka;
		this->polozenieX = tmppolozenieX;
		this->polozenieY = tmppolozenieY;
	}
};
