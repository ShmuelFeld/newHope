//
// Normal cab checks
//

#include "gtest/gtest.h"
#include "../StandartCab.h"


using namespace std;
class StandartCabTest: public ::testing::Test {
protected:
    BFSPoint *p1;
    BFSPoint *p2;
    BFSPoint *p3;
    TripInfo *ti, *si;
    int id1;
    virtual void SetUp() {
        cout << "setting up" << endl;
    }

    virtual void TearDown() {
        cout << "tear down" << endl;
    }

public:
    StandartCabTest() {
        p1 = new BFSPoint(0,1);
        p2 = new BFSPoint(3,9);
        p3 = new BFSPoint(8,9);
        ti = new TripInfo(id1,p1, p2, 2, 20, 0);
        si = new TripInfo(id1,p1,p3,2, 40, 0);
    }
    ~StandartCabTest() {
        delete si,ti, p1 ,p2, p3;
    }
};

/*check a rational charge*/
TEST_F(StandartCabTest, chargeTest) {
    double x = ti->getTariff();
    double y = si->getTariff();
    EXPECT_GT(y, x);
}