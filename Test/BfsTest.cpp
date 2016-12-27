//
// Bfs checking methods
//

#include "gtest/gtest.h"
#include "../Bfs.h"
#include "../Grid.h"

using namespace std;
class BfsTest: public ::testing::Test {
protected:
    Bfs bfs;
    Grid *g;
    BFSPoint *ps;
    BFSPoint *pe;
    BFSPoint *px;
    BFSPoint* pl;
    std::vector<Node*> vis;

    virtual void SetUp() {
        cout << "setting up" << endl;


    }

    virtual void TearDown() {
        cout << "tear down" << endl;
    }

public:
    BfsTest() {
        g = new Grid(8, 6);
        ps = new BFSPoint(1, 1), pe = new BFSPoint(7, 5), px = new BFSPoint(2,2), pl = new BFSPoint(7,5);
    }
    ~BfsTest() {
        delete g, ps, pe, px, pl;
    }
};
/* check whether bfs search makes sense and return a various of expected values*/
TEST_F(BfsTest, pathTest) {
    EXPECT_TRUE((bfs.path(g->root(), ps))->equal(ps));
    EXPECT_TRUE(bfs.path(bfs.path(g->root(), ps), pe)->equal(pe));
    pe->set(0,0);
    ps->set(4,3);
    EXPECT_TRUE(bfs.path(bfs.path(g->root(), ps), pe)->equal(g->root()));
    pe->set(10,10);
    ASSERT_FALSE(bfs.path(bfs.path(g->root(), ps), pe)->equal(pe));
    pe->set(0,0);
    ps->set(0,0);
    EXPECT_TRUE(bfs.path(bfs.path(g->root(), ps), pe)->equal(g->root()));
}

/* check supposely equal heights*/
TEST_F(BfsTest, HeightTest) {
    px->set(4,3);
    pe = (BFSPoint*)bfs.path(g->root(), px);
    EXPECT_EQ(pe->getHeight(), 7);
    BFSPoint* pk = (BFSPoint*)bfs.path(pe, pl);
    EXPECT_EQ(pk->getHeight(), 5);
}