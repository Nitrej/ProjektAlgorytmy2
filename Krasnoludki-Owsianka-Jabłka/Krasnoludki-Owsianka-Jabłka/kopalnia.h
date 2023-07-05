#pragma once
#include <vector>
#include <string>
class Kopalnia
{
public:
	int idKopalni;
	std::string wydobywanySurowiec;
	int limitMiejsc;
	int polozenieX;
	int polozenieY;
	std::vector<int> indeksyPracujacychKrasnali = {};

	Kopalnia(int idKopalni, std::string tmpwydobywanySurowiec,int tmplimitMiejsc, int tmpPolozenieX, int tmpPolozenieY) {
		this->idKopalni = idKopalni;
		this->wydobywanySurowiec = tmpwydobywanySurowiec;
		this->limitMiejsc = tmplimitMiejsc;
		this->polozenieX = tmpPolozenieX;
		this->polozenieY = tmpPolozenieY;
	}

};
