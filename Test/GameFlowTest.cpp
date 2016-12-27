//
// Created by shmuel on 04/12/16.
//

//
// Created by shmuel on 02/12/16.
//

#include "gtest/gtest.h"
#include "../GameFlow.h"
#include "../TaxiCentre.h"

using namespace std;
class GameFlowTest: public ::testing::Test {
protected:
    GameFlow gf;
    Grid g;
    TaxiCentre tc;

    virtual void SetUp() {
        cout << "setting up" << endl;
    }

    virtual void TearDown() {
        cout << "tear down" << endl;
    }

public:
    GameFlowTest() :  gf()  {}
};
/**
 * the method move all in taxi center checks the same thing.
 */
/*TEST_F(GameFlowTest, momentPassed) {

}*/