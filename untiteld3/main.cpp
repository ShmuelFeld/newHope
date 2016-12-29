//============================================================================
// Name        : Ex1.cpp
// Author      : Shmuel Feld & Ran Perry
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <gtest/gtest.h>
#include "../Udp.h"
#include "../BFSPoint.h"
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
#include "../TripInfo.h"
#include "../Grid.h"
#include "../GameFlow.h"

#include <unistd.h>

using namespace std;
using namespace boost::archive;
std::stringstream ss;

int main(int argc, char* argv[]) {
    GameFlow *g;
    g->menu();
    /*BFSPoint *st = new BFSPoint(2,2);
    BFSPoint *en = new BFSPoint(8,9);
    Point *po = new Point(2,2);
    TripInfo *ti = new TripInfo(1, st, en, 2, 20);
    Grid *g = new Grid(7,8);
    std::string serial_str;
    boost::iostreams::back_insert_device<std::string> inserter(serial_str);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
    boost::archive::binary_oarchive oa(s);
    oa << g;
    s.flush();
    TripInfo *ti2;
    Point *po2;
    BFSPoint *yt;
    Grid *g2;
    boost::iostreams::basic_array_source<char> device(serial_str.c_str(), serial_str.size());
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::binary_iarchive ia(s2);
    ia >> g2;
    cout<< g2->search(6,5)->getX()<<g2->search(6,5)->getY()<<endl;

    Udp udp(1, 5555);
    udp.initialize();
    char buffer[1024];
    udp.reciveData(buffer, sizeof(buffer));
    cout<< buffer<<endl;
    udp.sendData(serial_str);


//
//    usleep(5000);
    Udp udp2(1, 5554);
    udp2.initialize();

    char buffer2[1024];
    udp2.reciveData(buffer2, sizeof(buffer2));
    cout << buffer2 << endl;
    udp2.sendData("sup?");

    // support more than one client?
    return 0;*/
}
