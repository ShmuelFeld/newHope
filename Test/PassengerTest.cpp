//
// Created by shmuel on 04/12/16.
//
#include "gtest/gtest.h"
#include "../Passenger.h"

using namespace std;
class PassengerTest: public ::testing::Test {
protected:
    BFSPoint *start;
    BFSPoint *end;
    Passenger p1;


    virtual void SetUp() {
        cout << "setting up" << endl;

    }

    virtual void TearDown() {
        cout << "tear down" << endl;
    }

public:
    PassengerTest() : p1(start, end) {}
};
TEST_F(PassengerTest, randisatisfaction) {
    ASSERT_NE(p1.randSatisfaction(), p1.randSatisfaction());
}