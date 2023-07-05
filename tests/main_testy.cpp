#include "gtest/gtest.h"
#include "obliczOdlegloscTest.h"
#include "compareDwarfsTest.h"
#include "przyporzadkujKrasnaleMaksWydobycieTest.h"
#include "przyporzadkujKrasnaleMaksWydobycieMaloOwsiankiTest.h"


// przy takim ustawieniu sie nie odpala wszytskie
int test_main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}