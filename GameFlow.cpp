/*
 * GameFlow.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: ran
 */
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
#include "GameFlow.h"
#include <boost/lexical_cast.hpp>
#include "StandartCab.h"
#include "LuxuryCab.h"
#include "Udp.h"
#include "Clock.h"

using namespace std;

GameFlow::GameFlow() {
}

GameFlow::~GameFlow() {
	delete g;
}

void GameFlow::momentPassed() {
}

int GameFlow::menu() {
    Clock *clock = new Clock();
    TaxiCentre *c = new TaxiCentre();
	int x_grid, y_grid, numOfObstacles, command;
	cin >> x_grid >> y_grid >> numOfObstacles;
	g = new Grid(x_grid, y_grid);
    root = g->root();
	if (numOfObstacles != 0) {
		createObstacles(numOfObstacles);
	}
	command = 0;
	while (true) {
		cin >> command;
		switch (command) {
			case 1: {
				int numOfDrivers,portNum = 5555, i = 0;
				cin >> numOfDrivers;
                while (i != numOfDrivers) {
                    Udp udp(1, portNum - i);
                    udp.initialize();
                    char buffer[1024];
                    udp.reciveData(buffer, sizeof(buffer));
                    Cab *cc = c->assignCabToDriver(); //checkkkkkkk
                    std::string serial_str;
                    boost::iostreams::back_insert_device<std::string>
                            inserter(serial_str);
                    boost::iostreams::stream<boost::iostreams
                    ::back_insert_device<std::string> > s(inserter);
                    boost::archive::binary_oarchive oa(s);
                    oa << cc;
                    s.flush();
                    udp.sendData(serial_str);
                    std::string str2;
                    Grid *g = new Grid(5,5);
                    boost::iostreams::back_insert_device<std::string>
                            inserter2(str2);
                    boost::iostreams::stream<boost::iostreams
                    ::back_insert_device<std::string> > s2(inserter2);
                    boost::archive::binary_oarchive oa2(s2);
                    oa2 << g;
                    s2.flush();
                    udp.sendData(str2);
                    i++;
                }
                break;
			}
			case 2: {
				int id, x_s, y_s, x_e, y_e, pass, TripTIme;
				char space;
				double tariff;
				cin >> id >> space >> x_s >> space >> y_s
					>> space >> x_e >> space >> y_e >> space
					>> pass >> space >> tariff >> space >> TripTIme ;
				BFSPoint start(x_s, y_s);
                BFSPoint end(x_e, y_e);
				ti = new TripInfo(id,(BFSPoint *)bfs.path(root, &start),
                                  (BFSPoint *)bfs.path(root, &end), pass, tariff, TripTIme);
				c->addRide(ti);
				break;
			}
			case 3: {
				int id, type;
				char man, colo, space;
				cin >> id >> space >> type >> space >> man
					>> space >> colo;
				if (type == 1) {
					s = new StandartCab(id, man, colo);
					c->addCab((Cab*)s);
				}
				else {
					l = new LuxuryCab(id, man, colo);
					c->addCab((Cab*)l);
				}
				break;
			}
			case 4: {
				int driverId;
				cin >> driverId;
				c->printLoc(driverId);
				break;
			}
			case 6: {
                c->matchRide(clock->getVlue());
                c->moveAll();
                break;
            }
			case 7: {
                delete c;
                return 0;
                default:
                    return 1;
            }
            case 9: {
                delete c;
                return 0;
                default:
                    return 1;
            }
		}
	}
}
void GameFlow::createObstacles(int numOfObstacles) {
	int x, y;
	char space;
	for(int i = 0; i < numOfObstacles; i++) {
		cin >> x >> space >> y;
		g->search(x, y)->setValid();
	}
}

Cab* GameFlow::createCab(int type, int id, char man, char colo) {
    if (type == 1) {
        return (Cab*)(new StandartCab(id, man, colo));
    }
    else {
        return (Cab*)new LuxuryCab(id, man, colo);
    }
}