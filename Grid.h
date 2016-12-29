/*
 * Grid.h
 *
 *  Created on: Nov 17, 2016
 *      Author: ran
 */

#ifndef GRID_H_
#define GRID_H_
#include "BFSPoint.h"
#include <vector>
#include <boost/serialization/vector.hpp>
/**
 * this class creates the grid
 */
class Grid {
private:
    int size_x;
    int size_y;
    std ::vector<std ::vector<BFSPoint*>> matrix;

public:
    /**
     * constructor.
     * @param x is the size of x axis.
     * @param y is the size of y axis.
     */
    Grid(int x, int y);
    /**
     * default constructor.
     */
    Grid();
    /**
     * destructor.
     */
    virtual ~Grid();
    /**
     * @return the root of the grid.
     */
    BFSPoint* root();
    /**
     * search for a wanted point.
     * @param x the x value.
     * @param y the y value.
     * @return BFSPoint with those values.
     */
    BFSPoint* search(int x, int y);
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & size_x;
        ar & size_y;
        ar & matrix;
    }
};

#endif /* GRID_H_ */