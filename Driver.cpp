/*
 * Driver.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: shmuel
 */

#include "Driver.h"

namespace std {
    Driver::Driver(int identity, int a, char ms, int e, int vId, BFSPoint* r) {
        clients = 0;
        satisfaction = 0;
        id = identity;
        age = a;
        exp = e;
        maritalStatus = myMaritalStatus(ms);
        cab = NULL;
        vehicleId = vId;
        currentLocation = r;
        haveAPassengers = false;
        amIOccupied = false;
        myRoad = NULL;
        myPassenger = NULL;
    }
    Driver::Driver() {
        clients = 0;
        satisfaction = 0;
        id = 0;
        age = 0;
        exp = 0;
        cab = NULL;
    }
    Driver::~Driver() {
        delete  cab;
    }
    int Driver::getId() {
        return id;
    }
    int Driver::gatAge(){
        return age;
    }
    int Driver::getExp() {
        return  exp;
    }
    int Driver::getClients() {
        return clients;
    }
    double Driver::getStisfaction() {
        return satisfaction;
    }
    Cab* Driver::getCab() {
        return cab;
    }
    void Driver::setSatisfaction(double st) {
        memo += st;
        satisfaction = memo / clients;
    }
    void Driver::setCab(Cab* c) {
        cab = c;
    }
    BFSPoint* Driver::getLocation() {
        return currentLocation;
    }
    int Driver::findShortPath(TripInfo* ti) {
        return b.path(currentLocation,ti->getStart())->getHeight();

    }
    void Driver::drive(){
        int type = getCab()->getType();
        switch (type) {
            case 1:
                //standart cab. progress one point each time.
                currentLocation = myRoad;
                pickUp();
                road();
                currentLocation = myRoad;
                dropOff();
                break;
            case 2:
                //luxury cab. progress two points each time.
                currentLocation = myRoad;
                pickUp();
                road();
                currentLocation = myRoad;
                dropOff();
                break;
            default:break;
        }

    }
    MaritalStatus Driver::getMaritalStatus() {
        return maritalStatus;
    }
    void Driver::setTripInfo(TripInfo * ti) {
        tripInfo = ti;
        road();
    }
    MaritalStatus Driver::myMaritalStatus(char ms) {
        switch (ms) {
            case 'W':
                return MaritalStatus::WIDOWED;
            case 'D':
                return MaritalStatus::DIVORCED;
            case 'S':
                return MaritalStatus::SINGLE;
            case 'M':
                return MaritalStatus::MARRIED;
            default:break;
        }
    }
    int Driver::myVehicleId() {
        return vehicleId;
    }
    void Driver::road() {
        BFSPoint *road;
        if (haveAPassengers) {
            road = (BFSPoint*)b.path(currentLocation, tripInfo->getEnd());
            tripInfo->setMeter(road->getHeight());
            cab->setKiloPassed(road->getHeight());
            myRoad = road;
        } else {
            road = (BFSPoint *) b.path(currentLocation, tripInfo->getStart());
            if (! currentLocation->equal(tripInfo->getStart())) {
                cab->setKiloPassed(road->getHeight());
            }
            myRoad = road;
        }
    }
    void Driver::pickUp() {
        haveAPassengers = true;
        clients++;
    }
    void Driver::dropOff() {
        setSatisfaction(myPassenger->randSatisfaction());
        haveAPassengers = false;
        setOccupied();
        //collect money.
    }
    void Driver::setOccupied() {
        amIOccupied = !amIOccupied;
    }
    bool Driver::occupied() {
        return amIOccupied;
    }

} /* namespace std */