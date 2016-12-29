/*
 * Point.h
 *
 *  Created on: Nov 15, 2016
 *      Author: shmuel
 */

#ifndef BFSPOINT_H_
#define BFSPOINT_H_
#include "Node.h"
#include "Point.h"
#include <boost/serialization/vector.hpp>
/**
 * this class is the point that we are operating the bfs on.
 * holds a point, and inherit from node.
 */
class BFSPoint: public Node {
private:

    Point* po;
    int height;
    BFSPoint* left;
    BFSPoint* up;
    BFSPoint* right;
    BFSPoint* down;
    Node* father;
    Node* next;
    int arr[2];
    bool valid;
public:
    /**
     * default constructor.
     */
    BFSPoint();
    /**
     * constructor.
     * @param a x axis
     * @param b y axis
     */
    BFSPoint(int a, int b);
    /**
     * destructor.
     */
    virtual ~BFSPoint();
    /**
     * return x value.
     * @return int x.
     */
    int getX();
    /**
     * return y value.
     * @return int y.
     */
    int getY();
    /**
     * check if two nodes are equal.
     * @param p is the other node.
     * @return true if equal, false otherwise.
     */
    bool equal(Node *p);
    /**
     * return the height of the node.
     * @return int.
     */
    int getHeight();
    /**
     * check the vals of the the node
     * @return array with the values.
     */
    int* vals();
    /**
     * @return apointer to the node's father.
     */
    Node* getFather();
    /**
     * sets the father node.
     * @param p is a pointer to the father.
     */
    void setFather(Node* p);
    /**
     * @return vector with pointer to the node's sons.
     */
    vector<Node*>* sons();
    /**
     * @return int, number of suns.
     */
    int numOfSons();
    /**
     * sets the node's height.
     * @param i is the wanted height.
     */
    void setHeight(int i);
    /**
     * @return the left son
     */
    BFSPoint* get_left();
    /**
     * @return the up brother.
     */
    BFSPoint* get_up();
    /**
     * @return the right brother.
     */
    BFSPoint* get_right();
    /**
     * @return the down brother.
     */
    BFSPoint* get_down();
    /**
     * sets the point
     * @param x axis
     * @param yaxis
     */
    void set(int x, int y);
    /**
     * sets the left son
     */
    void set_left(BFSPoint*);
    /**
     * sets the up son
     */
    void set_up(BFSPoint*);
    /**
     * sets the right son
     */
    void set_right(BFSPoint*);
    /**
     * sets the down son
     */
    void set_down(BFSPoint*);
    /**
     *
     * @param n the next node in the path.
     */
    void setNext(Node* n);
    /**
     * @return the next node in the path.
     */
    Node* getNext();
    /**
     * checks is a point is vaild.
     * usually used to check if a point is an obstacle
     * @return true if valid false otherwise.
     */
    bool amIValid();
    /**
     * sets the validate of point.
     */
    void setValid();
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & height;
        ar & left;
        ar & up;
        ar & right;
        ar & down;
        ar & father;
        ar & next;
        for (int i = 0; i < 2; i++) {
            ar & arr;
        }
        ar & valid;
        ar & po;
    }
};
#endif /* POINT_H_ */