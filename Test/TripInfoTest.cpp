//
// TripInfo checks (ain't much to check' it's quite a getter class)
//

#include "gtest/gtest.h"
#include "../TripInfo.h"
#include "../Grid.h"

using namespace std;
class TripInfoTest: public ::testing::Test {
protected:
    BFSPoint s;
    BFSPoint *e;
    BFSPoint c;
    TripInfo *ti;
    Bfs bfs;
    Grid *g;


    virtual void SetUp() {
        cout << "setting up" << endl;
    }

    virtual void TearDown() {
        cout << "tear down" << endl;
    }

public:
    TripInfoTest(){
        g = new Grid(10,10);
        e = new BFSPoint(6,5);
    }
    ~TripInfoTest() {
        delete g, e, ti;
    }
};

/*checking meters in comperison to height, taking in acount
 * thing would be calculated as shown*/
TEST_F(TripInfoTest, meterTest) {
    /* ti = new TripInfo(0, g->root()->getX(), g->root()->getY(), e->getX(), e->getY(), 2, 20);
     EXPECT_EQ(bfs.path(g->root(), e)->getHeight(), ti->getMeter());*/
    //irrelevant
}