#ifndef PROJEKTALGORYTMY2_OBLICZODLEGLOSCTEST_H
#define PROJEKTALGORYTMY2_OBLICZODLEGLOSCTEST_H
#include <gtest/gtest.h>
// co jest nie tak w tej sciezce?
#include "Krasnoludki-Owsianka-Jabłka/Krasnoludki-Owsianka-Jabłka/Funkcje.h"

TEST(ObliczOdlegloscTest, TestCases) {
// Przypadek 1: Odległość między punktami (0, 0) i (3, 4) powinna być równa 5
EXPECT_EQ(obliczOdleglosc(0, 0, 3, 4), 5);

// Przypadek 2: Odległość między punktami (1, 1) i (1, 1) powinna być równa 0
EXPECT_EQ(obliczOdleglosc(1, 1, 1, 1), 0);

// Przypadek 3: Odległość między punktami (-5, -5) i (-2, -2) powinna być równa około 4.24 (ze względu na niedokładność liczb zmiennoprzecinkowych)
EXPECT_NEAR(obliczOdleglosc(-5, -5, -2, -2), 4.24, 0.01);
}

#endif PROJEKTALGORYTMY2_OBLICZODLEGLOSCTEST_H
