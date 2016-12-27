//
// Point checks
//

#include "gtest/gtest.h"
#include "../Point.h"

using namespace std;
class PointTest: public ::testing::Test {
protected:
    Point p1;
    Point p2;
    Point p3;

    virtual void SetUp() {
        cout << "setting up" << endl;
        p3 = p1+p2;
    }

    virtual void TearDown() {
        cout << "tear down" << endl;
    }

public:
    PointTest() : p1(1, 2), p2(3, 4), p3(0, 0) {}
};
/* overload checkers*/
TEST_F(PointTest, rc) {
    ASSERT_NE(p1, p2);
    ASSERT_NE(p1, p3);
    EXPECT_EQ(Point(4,6), p3);
}
/* getters - setters comparisons*/
TEST_F(PointTest, lc) {
    EXPECT_EQ(p1.getX(), 1);
    EXPECT_EQ(p1.getY(), 2);
    p1.set(1,1);
    EXPECT_EQ(p1.getX(), 1);
    EXPECT_EQ(p1.getY(), 1);
};