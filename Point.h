/*
 * Point.h
 *
 *  Created on: Nov 17, 2016
 *      Author: shmuel
 */

#ifndef POINT_H_
#define POINT_H_
#include<iostream>
#include <boost/serialization/access.hpp>
/**
 * this class is sort of primitive class that represent point in the space.
 */
namespace std {
    class Point {
    private:
        int x, y;

    public:
        /**
         * default constructor.
         */
        Point();
        /**
         * constructor.
         * @param a x dimension.
         * @param b y dimension
         */
        Point(int a, int b);
        /**
         * destructor.
         */
        virtual ~Point();
        /**
         * @return x value.
         */
        int getX();
        /**
         * @return y value.
         */
        int getY();
        /**
         * sets the point.
         * @param a x dimension.
         * @param b y dimension.
         */
        void set(int a, int b);
        /**
         * prints the point.
         */
        void print();
        /**
         * operator overloading + operator.
         * @param point the other point we want to add to our point.
         * @return new point with the values of p1 and p2.
         */
        const Point operator+(const Point& point)const;
        /**
         * operator overloading == operator.
         * @param point the other point we want to compare to our point.
         * @return true if they are equal, otherwise false.
         */
        bool operator==(const Point& point)const;
        /**
         * operator overloading != operator.
         * @param point the other point we want to compare to our point.
         * @return true if they are not equal, otherwise false.
         */
        bool operator!=(const Point& point)const;
        friend class boost::serialization::access;

        template<class Archive>
        void serialize(Archive &ar, const unsigned int version)
        {
            ar & x;
            ar & y;
        }

    };



#endif /* POINT_H_ */
}