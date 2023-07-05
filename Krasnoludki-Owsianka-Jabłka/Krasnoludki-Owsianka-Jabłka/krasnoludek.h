#include <vector>
#include <string>

class Krasnoludek {
public:
	int wydajnosc;
	std::string preferowanyFach;
	int idKrasnoludka;
	int polozenieX;
	int polozenieY;

	Krasnoludek(int tmpwydajnosc, std::string tmppreferowanyFach, int tmpidKrasnoludka, int tmppolozenieX, int tmppolozenieY) {
		this->wydajnosc = tmpwydajnosc;
		this->preferowanyFach = tmppreferowanyFach;
		this->idKrasnoludka = tmpidKrasnoludka;
		this->polozenieX = tmppolozenieX;
		this->polozenieY = tmppolozenieY;
	}
};
