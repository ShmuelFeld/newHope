/*
 * Node.h
 *
 *  Created on: Nov 14, 2016
 *      Author: ran & shmuel
 */

#ifndef NODE_H_
#define NODE_H_
using namespace std;
#include <string>
#include <vector>
#include <boost/serialization/access.hpp>
#include <boost/serialization/vector.hpp>
/**
 * this abstract class defines generic node for the bfs algorithm.
 */
class Node {
protected:
    Node* father;
    int height;
    Node* next;
    std::vector<Node*> chil;
    bool valid;
public:
    /**
     * default constructor.
     */
    Node();
    /**
     * destructor.
     */
    virtual ~Node();
    /**
     * check if the node is equal to another node.
     * @param n is the other node
     * @return true if they are equal, otherwise false.
     */
    virtual bool equal(Node *n) = 0;
    /**
     * @return the height of the node.
     */
    virtual int getHeight() = 0;
    /**
     * @return array of the values of the node.
     */
    virtual int* vals() = 0;
    /**
     * @return the node's father.
     */
    virtual Node* getFather() = 0;
    /**
     * @return the next node in the chain.
     */
    virtual Node* getNext() = 0;
    /**
     * sets the father of the node.
     * @param n  is the new father.
     */
    virtual void setFather(Node* n) = 0;
    /**
     * sets the next node in the chain.
     * @param n is the next node.
     */
    virtual void setNext(Node* n) = 0;
    /**
     * @return vector of the node's sons.
     */
    virtual vector<Node*>* sons() = 0;
    /**
     * @return the num of the suns.
     */
    virtual int numOfSons() = 0;
    /**
     * sets the height of the node in the chain.
     * @param i is the new height
     */
    virtual void setHeight(int i) = 0;
    /**
     * set the boolean value valid.
     */
    virtual void setValid() = 0;
    /**
     * @return the boolean value valid.
     */
    virtual bool amIValid() = 0;
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & chil;
        ar & father;
        ar & height;
        ar & valid;
        ar & next;
    }
};

#endif /* NODE_H_ */