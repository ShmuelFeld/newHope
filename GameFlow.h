/*
 * GameFlow.h
 *
 *  Created on: Nov 30, 2016
 *      Author: ran
 */

#ifndef GAMEFLOW_H_
#define GAMEFLOW_H_
#include "TripInfo.h"
#include "Grid.h"
#include "TaxiCentre.h"
#include "Passenger.h"
#include "Driver.h"
#include "StandartCab.h"
#include "LuxuryCab.h"

class GameFlow {
private:
    Grid* g;
    BFSPoint* root;
    TaxiCentre *c;
    Driver *d;
    TripInfo *ti;
    Bfs bfs;
    StandartCab* s;
    LuxuryCab *l;
    BFSPoint *start, *end;
public:
    /**
     * default constructor.
     */
    GameFlow();
    /**
     * destructor.
     */
    virtual ~GameFlow();
    /**
     * notify all the listeners that moment passed.
     */
    void momentPassed();
    /*
     * Run and everlasting menu of input choices
     */
    int menu();
    /**
     * creates Obstacles according to the user's input.
     * @param numOfObstacles
     */
    void createObstacles(int numOfObstacles);
};

#endif /* GAMEFLOW_H_ */