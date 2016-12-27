/*
 * fuck.cpp
 *
 *  Created on: Nov 18, 2016
 *      Author: ran
 */

#include "Node.h"
using namespace std;

Node::Node() {
    height = 0;
    next = 0;
    father = 0;
    valid = true;
}
Node::~Node() {
}
void Node::setFather(Node* n) {
    father = n;
}
Node* Node::getFather() {
    return 0;
}
int Node::getHeight() {
    return 0;
}
bool Node::equal(Node* n) {
    return false;
}
int* Node::vals() {
    return 0;
}
vector<Node*>* Node::sons() {
    return 0;
}
int Node::numOfSons(){
    return 0;
}
/**
 * sets the node's height in the bfs tree.
 */
void Node::setHeight(int i) {
    height = i;
}
void Node::setNext(Node* n) {
    next = n;
}
/**
 * return a node with the address of his father.
 */
Node* Node::getNext() {
    return 0;
}
void Node::setValid() {
    valid = false;
}
bool Node::amIValid() {
    return valid;
}