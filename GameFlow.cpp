/*
 * GameFlow.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: ran
 */
#include "GameFlow.h"
#include "StandartCab.h"
#include "LuxuryCab.h"

using namespace std;

GameFlow::GameFlow() {
}

GameFlow::~GameFlow() {
	delete g;
}

void GameFlow::momentPassed() {
}

int GameFlow::menu() {
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
				int vehicle_id, age, exp, driver_id;
				char status, space;
				cin >> driver_id >> space >> age >> space >> status
					>> space >> exp >> space >> vehicle_id;
				c->addDriver(new Driver(driver_id, age, status,
										exp, vehicle_id, g->root()));
				break;
			}
			case 2: {
				int id, x_s, y_s, x_e, y_e, pass;
				char space;
				double tariff;
				cin >> id >> space >> x_s >> space >> y_s
					>> space >> x_e >> space >> y_e >> space
					>> pass >> space >> tariff ;
				BFSPoint start(x_s, y_s);
                BFSPoint end(x_e, y_e);
				ti = new TripInfo(id,(BFSPoint *)bfs.path(root, &start), (BFSPoint *)bfs.path(root, &end), pass, tariff);
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
			case 6:
				c->assignCabToDriver();
				c->matchRide();
				c->moveAll();
				break;
			case 7:
                delete c;
				return 0;
			default:
				return 1;
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