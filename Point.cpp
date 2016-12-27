/*
 * Point.cpp
 *
 *  Created on: Nov 17, 2016
 *      Author: shmuel
 */

#include "Point.h"
using namespace std;
Point::Point(int a, int b) {
    x = a;
    y = b;
}
Point::Point() {
    x = 0;
    y = 0;
}
int Point::getX() {
    return x;
}
int Point::getY() {
    return y;
}
void Point::set(int a, int b){
    x = a;
    y = b;
}
void Point::print() {
    cout<<"("<< x <<","<< y <<")"<<"\n";
}
Point::~Point() {
}
const Point Point::operator+(const Point& point)const {
    return Point(x + point.x, y + point.y);
}
bool Point::operator== (const Point& point)const {
    return (x == point.x && y == point.y);
}
bool Point::operator!=(const Point& point)const {
    return !(*this == point);
}