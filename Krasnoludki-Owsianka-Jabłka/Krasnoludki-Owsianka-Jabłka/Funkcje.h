#pragma once
#include <fstream>
#include "krasnoludek.h"

bool wczytanieDanych() {

	return false;
}

// Funkcja porównuj¹ca dla sortowania
bool compareDwarfs(const Krasnoludek& krasnoludek1, const Krasnoludek& krasnoludek2) {
	return krasnoludek1.wydajnosc > krasnoludek2.wydajnosc;
}