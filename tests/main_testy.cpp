#include "gtest/gtest.h"
#include "obliczOdlegloscTest.h"

//Testy jednostkowe dla funkcji compareDwarfs,
//przyporzadkujKrasnaleMaksWydobycie,
//przyporzadkujKrasnaleMaksWydobycieMaloOwsianki

int test_main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}