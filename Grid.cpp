/*
 * Grid.cpp
 *
 *  Created on: Nov 17, 2016
 *      Author: ran
 */

#include "Grid.h"
using namespace std;
Grid::Grid() {
    size_x = 0;
    size_y = 0;
}

Grid::Grid(int x, int y) {
    if ((x > 10) or (x < 1) or (y > 10) or (y < 1)) {
        __throw_invalid_argument("Bad argument");
    }
    size_x = x + 1;
    size_y = y;
    BFSPoint *p;
    for (int k = 0; k < size_x; k++) {
        std::vector<BFSPoint*> temp;
        for (int n = 0; n < size_y; n++) {
            p = new BFSPoint(k,n);
            temp.push_back(p);
        }
        matrix.push_back(temp);
    }
    //sets the bfspoints sons.
    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            BFSPoint* p = matrix.at(i).at(j);
            if (p->getX() != 0) {
                BFSPoint* l = matrix.at(i - 1).at(j);
                p->set_left(l);
            }
            if (p->getX() != size_x - 1) {
                BFSPoint* l = matrix.at(i + 1).at(j);
                p->set_right(l);
            }
            if (p->getY() != 0) {
                BFSPoint* l = matrix.at(i).at(j - 1);
                p->set_down(l);
            }
            if (p->getY() != size_y - 1) {
                BFSPoint* l = matrix.at(i).at(j + 1);
                p->set_up(l);
            }

        }
    }
}
Grid::~Grid() {
    for (int k = 0; k < size_x; k++) {
        for (int n = 0; n < size_y; n++) {
            delete matrix.at(k).at(n);
        }
    }
    for (int i = 0; i < matrix.size(); i++) {
        matrix.at(i).clear();
    }
    matrix.clear();
}
BFSPoint* Grid::root() {
    for (int k = 0; k < size_x; k++) {
        for (int n = 0; n < size_y; n++) {
            if (matrix.at(k).at(n)->getX() == 0
                && matrix.at(k).at(n)->getY() == 0) {
                return matrix.at(k).at(n);
            }
        }

    }
}
BFSPoint* Grid::search(int x, int y) {
    for (int k = 0; k < size_x; k++) {
        for (int n = 0; n < size_y; n++) {
            if (matrix.at(k).at(n)->getX() == x
                && matrix.at(k).at(n)->getY() == y) {
                return matrix.at(k).at(n);
            }
        }
    }
}