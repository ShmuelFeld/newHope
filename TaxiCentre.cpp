/*
 * TaxiCentre.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: ran
 */

#include "TaxiCentre.h"
TaxiCentre::TaxiCentre() {
}

TaxiCentre::~TaxiCentre() {
    for (int i = 0; i < drivers.size(); i++) {
        delete drivers.at((unsigned long)i);
    }
    for (int i = 0; i < tripinfo.size(); i++) {
        delete tripinfo.at((unsigned long)i);
    }
    drivers.clear();
    cabs.clear();
    takenCabs.clear();
    tripinfo.clear();
}

void TaxiCentre::addDriver(Driver* d) {
    drivers.push_back(d);
}

Driver* TaxiCentre::matchDriver(TripInfo* t) {
    Driver* closest = drivers.at(0);
    int closestInt = closest->findShortPath(t);
    for (int i = 0; i < drivers.size(); i++) {
        Driver* cur = drivers.at((unsigned long)i);
        int dist = drivers.at((unsigned long)i)->findShortPath(t);
        if (dist == closestInt) {
            if (cur->getId() < closest->getId()) {
                closest = cur;
                closestInt = closest->findShortPath(t);
            }
        }
        else if (dist < closestInt) {
            closest = cur;
            closestInt = closest->findShortPath(t);
        }
    }
    return closest;
}

void TaxiCentre::addCab(Cab* c) {
    cabs.push_back(c);
}

void TaxiCentre::moveAll() {
    for (int i = 0; i < drivers.size(); i++) {
       if (drivers.at((unsigned long)i)->occupied()) {
           drivers.at((unsigned long)i)->drive();
       }
    }
}
Cab* TaxiCentre::assignCabToDriver() {
    for(int i = 0; i < drivers.size(); i++) {
        for (int j = 0; j < cabs.size(); ++j) {
            if (drivers.at((unsigned long)i)->myVehicleId()
                == cabs.at((unsigned long)j)->getID()) {
                Cab *s = cabs.at((unsigned long)j);
                drivers.at((unsigned long)i)->setCab(s);
                takenCabs.push_back(s);
                return s;
            }
        }
    }
}

void TaxiCentre::printLoc(int id) {
    for (int i = 0; i < drivers.size(); i++) {
        if (drivers.at((unsigned long)i)->getId() == id) {
            cout <<"(" << drivers.at((unsigned long)i)->getLocation()->getX()
                 << ","<<drivers.at((unsigned long)i)->
                    getLocation()->getY() << ")"<<endl;
        }
    }
}

void TaxiCentre::addRide(TripInfo *trp) {
    tripinfo.push_back(trp);
}

TripInfo* TaxiCentre::matchRide(int time) {
    for (int i = 0; i < drivers.size(); i++) {
        Driver *d = drivers.at((unsigned long)i);
        for (int l = 0; l < tripinfo.size(); l++) {
            if (d->getLocation()->equal(tripinfo.at
                    ((unsigned long)l)->getStart())) {
                if (time = tripinfo.at
                        ((unsigned long)l)->getTripTime()) {
                    d->setTripInfo(tripinfo.at((unsigned long) l));
                    d->setOccupied();
                    return tripinfo.at((unsigned long) l);
                }
            }
        }
    }
}
