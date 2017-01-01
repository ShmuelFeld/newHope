/*
 * TaxiCentre.h
 *
 *  Created on: Nov 30, 2016
 *      Author: ran
 */

#ifndef TAXICENTRE_H_
#define TAXICENTRE_H_

#include "Driver.h"
#include "Cab.h"
#include "TripInfo.h"
#include <vector>

using namespace std;

class TaxiCentre {
private:
    vector<Cab *> cabs;
    vector<Cab *> takenCabs;
    vector<Driver *> drivers;
    vector<TripInfo *> tripinfo;
public:
    /**
     * constructor.
     */
    TaxiCentre();

    /**
     * destructor.
     */
    virtual ~TaxiCentre();

    /**
     * add driver to the listener list.
     * @param d is the new driver.
     */
    void addDriver(Driver* d);

    /**
     * give a trip info to a specific driver.
     * @param t is the trip info.
     */
    Driver *matchDriver(TripInfo *t);
    /**
     * add cab to the list of the cabs.
     * @param id is the id number if the cab.
     * @param manu is the manufacture of the cab.
     * @param color is the color of the cab;
     */
    //assign free cabs to free drivers.
    Cab* assignCabToDriver();
    /**
     * add Cab to the listener list.
     * @param c is the new driver.
     */
    void addCab(Cab *c);
    /**
     * tells all the drivers to move one step.
     */
    void moveAll();
    /**
     * prints the location of a specific driver.
     * @param id
     */
    void printLoc(int id);
    /**
     * add trip information to the list.
     * @param trp is the tripinformation.
     */
    void addRide(TripInfo *trp);
    /**
     * match for each driver ride.
     */
    TripInfo* matchRide(int time);
};

#endif /* TAXICENTRE_H_ */