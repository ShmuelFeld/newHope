/*
 * TripInfo.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: shmuel
 */

#include "TripInfo.h"

namespace std {
    TripInfo::TripInfo(int ride_id, BFSPoint* st, BFSPoint *en,
                       int numOfPassengers, double ride_tariff, int t) {
        start = st;
        end = en;
        passengers = numOfPassengers;
        id = ride_id;
        meter = 0;
        tariff = ride_tariff;
        time = t;
    }
    TripInfo::TripInfo() {
        start = NULL;
        end = NULL;
        passengers = 0;
        id = 0;
        meter = 0;
        tariff = 0;
    }

TripInfo::~TripInfo() {

}
    void TripInfo::setMeter(int i){
        meter = i;
    }
    int TripInfo::getMeter() {
        return meter;
    }
    BFSPoint* TripInfo::getStart() {
        return start;
    }
    BFSPoint* TripInfo::getEnd() {
        return end;
    }
    BFSPoint* TripInfo::getCurrentPoint() {
        return NULL;
    }
    double TripInfo::getTariff() {
        return tariff;
    }
    int TripInfo::getTripTime() {
        return this->time;
    }

} /* namespace std */