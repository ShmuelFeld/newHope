//
// Checking methods for driver
//
#include "gtest/gtest.h"
#include "../Driver.h"
#include "../Grid.h"
#include "../StandartCab.h"
#include "../LuxuryCab.h"
#include "../Cab.h"

using namespace std;
class DriverTest: public ::testing::Test {
protected:
    Driver *driver1, *driver2;
    StandartCab *sc;
    LuxuryCab *lc;
    BFSPoint *st;
    BFSPoint *en, *en2;
    BFSPoint *loc;
    Grid *grid;
    Bfs bfs;
    int id1, id2;
    TripInfo *ti;
    TripInfo *ti2;
    TripInfo *t3;


    virtual void SetUp() {
        cout << "setting up" << endl;
    }

    virtual void TearDown() {
        cout << "tear down" << endl;
    }

public:
    DriverTest () {
        en = new BFSPoint(6, 5);
        en2 = new BFSPoint(1,1);
        grid = new Grid(10,10);
        st = grid->root();
        driver1 = new Driver(30546,25,'M', 2, 1, st);
        driver2 = new Driver(30546,25,'M', 2, 1, st);
        sc = new StandartCab(0,'H','G');
        lc = new LuxuryCab(1, 'F', 'B');
        id1 = 0;
        id2 = 1;
        ti = new TripInfo(id1,st, en, 2, 20, 0);
        ti2 = new TripInfo(id2,st, en2, 2, 20, 0);
        t3 = new TripInfo(id2, en, en2,2,20, 0);
    }
    ~DriverTest() {
        delete grid, driver1, driver2, ti, ti2, en, en2, sc,lc;
    }

};
TEST_F(DriverTest, drive) {
    driver1->setCab((Cab*)sc);
    driver1->setTripInfo(ti);
    driver1->getLocation();
    driver1->drive();
    driver1->setTripInfo(t3);
    driver1->drive();
    driver1->getLocation();
    BFSPoint* actual = driver1->getLocation();
    Node* expected = bfs.path(grid->root(), en2);
    EXPECT_TRUE(actual->equal(expected));
}

/* check chortest path method by comparing values with bfs*/
TEST_F(DriverTest, findShortestPath) {
    loc = driver1->getLocation();
    int x = bfs.path(loc, st)->getHeight();
    int y = driver1->findShortPath(ti);
    EXPECT_EQ(x, y);
}

/* check driving method by moving one step and compare to the expected
 * node while using bfs path */
