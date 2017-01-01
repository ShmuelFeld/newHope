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
#include "../Driver.h"
#include "../GameFlow.h"
#include "../Grid.h"
#include <unistd.h>

using namespace std;
using namespace boost::archive;
std::stringstream ss;

int main(int argc, char* argv[]) {
    GameFlow g;
    g.menu();
}
