#include "pch.h"


#include"../Krasnoludki-Owsianka-Jab³ka/Funkcje.h"
#include"../Krasnoludki-Owsianka-Jab³ka/kopalnia.h"
#include"../Krasnoludki-Owsianka-Jab³ka/krasnoludek.h"
#include"../Krasnoludki-Owsianka-Jab³ka/otoczka.h"

TEST(compareDwarfsTest, Test_1) {

	Krasnoludek k1 = Krasnoludek(7, "zloto", 1, 2, 3);
	Krasnoludek k2 = Krasnoludek(9, "srebro", 2, 0, 1);

	EXPECT_EQ(compareDwarfs(k1, k2), false);

	Krasnoludek k3 = { 12, "miedz", 4, 1, 2};

	Krasnoludek k4 = { 4, "srebro", 3, 5, 3};

	EXPECT_EQ(compareDwarfs(k3, k4), true);
}



TEST(przyporzadkujKrasnaleMaksWydobycieTest, Test_2) {

	vector<Krasnoludek> krasnoludki = {
		{4, "zloto", 2, 1, 1},
		{3, "srebro", 1, 0, 0},
		{5, "miedz", 3, 2, 2}
	};

	vector<Kopalnia> kopalnie = {
		{2, "zloto", 2, 3, 3},
		{3, "srebro", 1, 4, 4}
	};

	przyporzadkujKrasnaleMaksWydobycie(krasnoludki, kopalnie);

	int n = 0;

	for (int i = 0; i < kopalnie.size(); i++)
	{
		if (kopalnie[i].indeksyPracujacychKrasnali.size() > 0) n++;
	}
	ASSERT_EQ(n, 2);

}


TEST(przyporzadkujKrasnaleMaksWydobycieMaloOwsiankiTest, Test_3) {

	vector<Krasnoludek> krasnoludki = {
		{4, "zloto", 2, 0, 0},
		{3, "srebro", 1, 1, 1},
		{5, "miedz", 3, 2, 2}
	};

	vector<Kopalnia> kopalnie = {
		{3, "zloto", 2, 3, 3},
		{2, "srebro", 1, 4, 4},
		{4, "miedz", 2, 5, 5},
		{1, "zloto", 2, 6, 6}
	};

	przyporzadkujKrasnaleMaksWydobycieMaloOwsianki(krasnoludki, kopalnie);


	int n = 0;

	for (int i = 0; i < kopalnie.size(); i++)
	{
		if (kopalnie[i].indeksyPracujacychKrasnali.size() > 0) n++;
	}
	ASSERT_EQ(n, 3);
}

TEST(orientationTest, Test_4) {

	EXPECT_EQ(orientation({ 0, 0}, { 2,2 }, { 3,3 }), 0);
	EXPECT_EQ(orientation({ 0,0 }, { 2,2 }, { 0,3 }), 2);
	EXPECT_EQ(orientation({ 0,0 }, { 2,2 }, { 4,3 }), 1);
}

TEST(ObliczOdlegloscTest, TEST_5) {
	// Przypadek 1: Odleg³oœæ miêdzy punktami (0, 0) i (3, 4) powinna byæ równa 5
	EXPECT_EQ(obliczOdleglosc(0, 0, 3, 4), 5);

	// Przypadek 2: Odleg³oœæ miêdzy punktami (1, 1) i (1, 1) powinna byæ równa 0
	EXPECT_EQ(obliczOdleglosc(1, 1, 1, 1), 0);
	
}