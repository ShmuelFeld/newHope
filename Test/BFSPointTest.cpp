
/* This test class will check all possible BFSPoint function from those
 * who are changeable (unlike height,next,father which will be checked
 * on the Bft test*/

#include "gtest/gtest.h"
#include "../BFSPoint.h"

using namespace std;
class BFSPointTest: public ::testing::Test {
protected:
    BFSPoint p1;
    BFSPoint p2;
    BFSPoint p3;
    BFSPoint p4;
    int* arg;

    virtual void SetUp() {
        cout << "setting up" << endl;
        p2.set_left(&p1); p2.set_right(&p3); p4.set_down(&p1); p1.set_right(&p2);
    }

    virtual void TearDown() {
        cout << "tear down" << endl;
    }

public:
    BFSPointTest() : p2(2,2), p1(1,1),p3(3,3), p4(4,4) {}
};

//checking equal method before and after change
TEST_F(BFSPointTest, equals) {
    // EXPECT_FALSE(p1.equal(&p2));
    p1.set(2,2);
    // EXPECT_TRUE(p1.equal(&p2));
}

//checking vlas method by comparing with getters
TEST_F(BFSPointTest, val) {
    arg = p1.vals();
    EXPECT_EQ(p1.getX(), arg[0]);
    EXPECT_EQ(p1.getY(), arg[1]);
}

//comparing sons method with neighbors getters
TEST_F(BFSPointTest, son) {
    vector<Node*>* p;
    p = p4.sons();
    EXPECT_EQ(p->at(0),  p4.get_left());
    EXPECT_EQ(p->at(1),  p4.get_up());
    EXPECT_EQ(p->at(2),  p4.get_right());
    EXPECT_EQ(p->at(3),  p4.get_down());

}

//checking possible neighbors regardless of the grid,
//in which tests limits will also be checked
TEST_F(BFSPointTest, neighbors) {
    EXPECT_EQ(p1.getX(), 1);
    EXPECT_EQ(p1.getY(), 1);
    p1.set(2,2);
    EXPECT_EQ(p1.getX(), p2.getX());
    EXPECT_EQ(p1.getY(), p2.getY());
    //EXPECT_TRUE(p2.get_left()->equal(&p2));
    EXPECT_EQ(p2.get_right()->getX(), 3);
    EXPECT_EQ(p4.get_down()->get_right()->getY(), 2);
    EXPECT_EQ(p2.numOfSons(), 4);
}