/*
 * Point.cpp
 *
 *  Created on: Nov 13, 2016
 *      Author: ran
 */
#include "BFSPoint.h"
using namespace std;

BFSPoint::BFSPoint(int a, int b) {
    po = new Point(a, b);
    left = 0;
    up = 0;
    right = 0;
    down = 0;
    height = 0;
    next = 0;
    father = 0;
    valid = true;
}

BFSPoint::BFSPoint() {
    po = 0;
    left = 0;
    up = 0;
    right = 0;
    down = 0;
    height = 0;
    height = 0;
    next = 0;
    father = 0;
    valid = true;
}
int BFSPoint::getX() {
    return po->getX();
}
int BFSPoint::getY() {
    return po->getY();
}
int* BFSPoint::vals() {
    arr[0] = getX();
    arr[1] = getY();
    return arr;
}
bool BFSPoint::equal(Node *p) {
    int* d = p->vals();
    return ((getX() == d[0]) && (getY() == d[1]));
}
int BFSPoint::getHeight() {
    return height;
}
BFSPoint* BFSPoint::get_left() {
    return left;
}
BFSPoint* BFSPoint::get_up() {
    return up;
}
BFSPoint* BFSPoint::get_right() {
    return right;
}
BFSPoint* BFSPoint::get_down() {
    return down;
}
void BFSPoint::set_left(BFSPoint* p) {
    left = p;
}
void BFSPoint::set_up(BFSPoint* p) {
    up = p;
}
void BFSPoint::set_right(BFSPoint* p) {
    right = p;
}
void BFSPoint::set_down(BFSPoint* p) {
    down = p;
}
void BFSPoint::set(int x, int y) {
    delete po;
    po = new Point(x, y);
}
void BFSPoint::setFather(Node* p) {
    father = p;
}
Node* BFSPoint::getFather() {
    return father;
}
int BFSPoint::numOfSons() {
    return 4;
}
vector<Node*>* BFSPoint::sons(){
    vector<Node*>* p;
    chil.push_back(get_left());
    chil.push_back(get_up());
    chil.push_back(get_right());
    chil.push_back(get_down());
    p = &chil;
    return p;
}
void BFSPoint::setHeight(int i) {
    height = i;
}

BFSPoint::~BFSPoint() {
    delete po;
}
void BFSPoint::setNext(Node* n) {
    next = n;
}
Node* BFSPoint::getNext() {
    return next;
}

bool BFSPoint::amIValid() {
    return valid;
}
void BFSPoint::setValid() {
    valid = !valid;
}