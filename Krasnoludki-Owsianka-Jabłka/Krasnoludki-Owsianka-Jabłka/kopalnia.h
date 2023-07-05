#include <vector>
#include <string>
class Kopalnia{
public:
	std::string wydobywanySurowiec;
	int limitMiejsc;
	int polozenieX;
	int polozenieY;
	std::vector<int> indeksyPracujacychKrasnali = {};

	Kopalnia(std::string tmpwydobywanySurowiec,int tmplimitMiejsc, int tmpPolozenieX, int tmpPolozenieY) {
		this->wydobywanySurowiec = tmpwydobywanySurowiec;
		this->limitMiejsc = tmplimitMiejsc;
		this->polozenieX = tmpPolozenieX;
		this->polozenieY = tmpPolozenieY;
	}

};
