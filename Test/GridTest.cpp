//
// Grid checks
//

#include "gtest/gtest.h"
#include "../BFSPoint.h"
#include "../Grid.h"


using namespace std;
class GridTest: public ::testing::Test {
protected:
    Grid *g;
    BFSPoint* root;

    virtual void SetUp() {
        cout << "setting up" << endl;
        root = g->root();

    }

    virtual void TearDown() {
        cout << "tear down" << endl;
    }

public:
    GridTest()  {
        g = new Grid(3,2);
    }
    ~GridTest()  {
        delete g;
    }
};

/* check neighbors from different sides were created as expected
 * by the constructor*/
TEST_F(GridTest, rc) {
    EXPECT_EQ(root->getX(), 0);
    EXPECT_EQ(root->getX(), 0);
    EXPECT_EQ(root->get_up()->getY(), root->get_right()->get_up()->getY());
    EXPECT_EQ(root->get_right()->getX(), root->get_right()->get_up()->getX());
}

/* check limits and whether exeptions are thrown as expected*/
TEST_F(GridTest, __EXCEPTIONS) {
    EXPECT_THROW(Grid g2(12,2), invalid_argument);
    EXPECT_THROW(Grid g2(1,20), invalid_argument);
    EXPECT_THROW(Grid g2(0,2), invalid_argument);
    EXPECT_THROW(Grid g2(3,-2), invalid_argument);

}