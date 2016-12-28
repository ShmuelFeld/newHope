//============================================================================
// Name        : Ex1.cpp
// Author      : Shmuel Feld & Ran Perry
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <gtest/gtest.h>
#include "Udp.h"
#include "BFSPoint.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include "Udp.h"
#include <unistd.h>

using namespace std;
using namespace boost::archive;
std::stringstream ss;

class Poind {
    int x, y;

    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & x;
        ar & y;
    }
public:
    Poind(int x, int y) : x(x), y(y) {}

    Poind() : x(0), y(0) {}
    int getX() {return this->x;}
    int getY() {return this->y;}

};

class GridPoint {
    Poind *p;

    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & p;
    }

public:
    GridPoint(Poind *p) : p(p) {};
    GridPoint() : p(NULL) {}
    virtual ~GridPoint() {
        delete p;
    }
    friend std::ostream& operator<< (std::ostream &os, const GridPoint &p);
};

std::ostream& operator<< (std::ostream &os, const GridPoint &p) {
    os << '(' << p.p->getX() << ',' << p.p->getY() << ')';
    return os;
}

class D3GridPoint : public GridPoint {
    int z;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & boost::serialization::base_object<GridPoint>(*this);
        ar & z;
    }
public:
    D3GridPoint(Poind *p, int z) : GridPoint(p), z(z) {};
};

int main(int argc, char* argv[]) {



    Udp udp(1, 5555);
    udp.initialize();

    char buffer[1024];
    udp.reciveData(buffer, sizeof(buffer));
    std::string serial_str = buffer;
    GridPoint *gp2;
    boost::iostreams::basic_array_source<char> device(serial_str.c_str(), serial_str.size());
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::binary_iarchive ia(s2);
    ia >> gp2;

    cout << *gp2;
    udp.sendData("sup?");


//
//    usleep(5000);
    Udp udp2(1, 5554);
    udp2.initialize();

    char buffer2[1024];
    udp2.reciveData(buffer2, sizeof(buffer2));
    cout << buffer2 << endl;
    udp2.sendData("sup?");

    // support more than one client?
    return 0;
}
