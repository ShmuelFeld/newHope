/*
 * bfs.h
 *
 *  Created on: Nov 20, 2016
 *      Author: ran
 */

#ifndef BFS_H_
#define BFS_H_
#include <list>
#include <queue>
#include <vector>
#include <stack>
#include "BFSPoint.h"
using namespace std;
/**
 * this class is the implement of the bfs algorithm.
 */
class Bfs {
private:
    std::queue<Node*> queue;
    std::vector<Node*> vis;
public:
/**
 * default constructor.
 */
    Bfs();
/**
 * destructor.
 */
    virtual ~Bfs();
    /**
     *
     * @param r is the start node for the search.
     * @param s the destination
     * @return node s after initilaize all the sons from s to r.
     */
    Node* path(Node* r, Node* s);
    /**
     * this function checks if the node was already visited by the algorithm.
     * @param n is the node we want to check it about him.
     * @return true if wisited, false otherwise.
     */
    bool visited(Node* n);
};
#endif /* BFS_H_ */