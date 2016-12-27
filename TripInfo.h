/*
 * TripInfo.h
 *
 *  Created on: Nov 30, 2016
 *      Author: shmuel
 */

#ifndef TRIPINFO_H_
#define TRIPINFO_H_
#include "BFSPoint.h"
#include "Bfs.h"

namespace std {

    class TripInfo {
    private:
        int id;
        int meter;
        int passengers;
        BFSPoint* start;
        BFSPoint* end;
        double tariff;
    public:
        /**
         *
         * @param id the tripinfo's id
         * @param st start point
         * @param en nd point
         * @param numOfPassengers number of passenger in the trip.
         * @param tariff of the ride.
         */
        TripInfo(int id, BFSPoint* st, BFSPoint *en, int numOfPassengers, double tariff);
        /**
         * default constructor.
         */
        TripInfo();
        /**
         * destructor.
         */
        virtual ~TripInfo();
        /**
         * sets the distance in the trip information.
         * @param i
         */
        void setMeter(int i);
        /**
         * @return the distance in the trip information.
         */
        int getMeter();
        /**
         * @return the start point of the trip.
         */
        BFSPoint* getStart();
        /**
         * @return the end point of the trip.
         */
        BFSPoint* getEnd();
        /**
         * @return the current point in the trip.
         */
        BFSPoint* getCurrentPoint();
        /**
         * @return the tariff for this trip.
         */
        double getTariff();
    };

} /* namespace std */

#endif /* TRIPINFO_H_ */