//
// Luxury cab checks
//


#include "gtest/gtest.h"
#include "../LuxuryCab.h"
using namespace std;
class LuxuryCabTest: public ::testing::Test {
protected:
    BFSPoint *p1;
    BFSPoint *p2;
    BFSPoint *p3;
    LuxuryCab *lc;
    int id;
    char h;
    char color;
    TripInfo *ti;

    virtual void SetUp() {
        cout << "setting up" << endl;
        id =1;
        h = 'H';
        color = 'P';
    }

    virtual void TearDown() {
        cout << "tear down" << endl;
    }

public:
    LuxuryCabTest() {
        p1 = new BFSPoint(0,1);
        p2 = new BFSPoint(3,9);
        p3 = new BFSPoint(8,9);
        lc = new LuxuryCab(id, h, color);
        ti = new TripInfo(id,p1, p2, 2, 20);
    }
    ~LuxuryCabTest() {
        delete lc, ti, p1,p2,p3;
    }

};

/* check whethet charge is double the amount of regular charge*/
TEST_F(LuxuryCabTest, chargeTest) {
    /*lc->charge(ti);
    EXPECT_EQ(lc->getCharge(), 2 * ti->getTariff());*/

}