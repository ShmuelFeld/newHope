//
// Cab centre checks
//

#include "gtest/gtest.h"
#include "../TaxiCentre.h"
#include "../Grid.h"
#include "../StandartCab.h"

using namespace std;
class TaxiCentreTest: public ::testing::Test {
protected:
    Driver *d1, *d2, *d3, *d4, *d5;
    StandartCab *c1, *c2,*c3;
    TripInfo *ti, *ti2;
    TaxiCentre tc;
    BFSPoint *en, *en2;
    int passngers, id2;
    Bfs bfs;
    Grid *g;
    BFSPoint *root;

    virtual void SetUp() {
        cout << "setting up" << endl;
        Grid g(10,10);
        Driver d1(1, 1, 'M', 0, 1, g.root());
        Driver d2(2, 1, 'M', 0, 2, g.root());
        Driver d3(3, 1, 'M', 0, 3, g.root());
        StandartCab c1(1,'H','B');
        StandartCab c2(2,'T','G');
        StandartCab c3(3,'F','P');
    }

    virtual void TearDown() {
        cout << "tear down" << endl;
    }

public:
    TaxiCentreTest() {

    }
};

/* check whether matched driver is indeed holds the same id as
 * the one known to be the closest of (taking in acount trips
 * made by each driver) */
TEST_F(TaxiCentreTest, assignCabToDriver) {
    tc.addDriver(d1);
    tc.addDriver(d2);
    tc.addDriver(d3);
    tc.addCab((Cab *)c1);
    tc.addCab((Cab *)c2);
    tc.addCab((Cab *)c3);
    tc.assignCabToDriver();
    EXPECT_EQ(d1->getCab()->getID(), d1->getId());
    EXPECT_EQ(d2->getCab()->getID(), d2->getId());
    EXPECT_EQ(d3->getCab()->getID(), d3->getId());

}

/*
 * move all cabs and check their location with bfs expected points
 * and extreme cases of going of grid
 */
TEST_F(TaxiCentreTest, moveAll) {
    BFSPoint *root = g->root();
    BFSPoint en(2,1);
    BFSPoint en2(4,5);
    TripInfo ti(id2, root, &en, passngers, 20);
    TripInfo ti2(id2, root, &en2, passngers, 20);
    Driver d4(1, 25, 'M', 0, 1, g->root());
    d4.setTripInfo(&ti);
    d4.setCab((Cab *)c1);
    d4.drive();
    BFSPoint* actual = d4.getLocation();
    BFSPoint* expected = (BFSPoint*)bfs.path(root, &en);
    EXPECT_TRUE(actual->equal(expected));
    Driver d5(2, 25, 'M', 0, 2, g->root());
    d5.setCab((Cab *)c1);
    d5.setTripInfo(&ti2);
    d5.drive();
    BFSPoint* actual2 = d5.getLocation();
    BFSPoint* expected2 = (BFSPoint*)bfs.path(root, &en);
    EXPECT_TRUE(actual->equal(expected2));
}