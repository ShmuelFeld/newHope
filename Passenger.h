/*
 * Passenger.h
 *
 *  Created on: Nov 30, 2016
 *      Author: ran
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include "BFSPoint.h"


class Passenger {
private:
    BFSPoint* start;
    BFSPoint* end;
    int numOfPassengers;
public:
    /**
     * constructor.
     * @param st is the start point of the trip.
     * @param en is the end point of the trip.
     */
    Passenger(BFSPoint *st, BFSPoint *en);
    /**
     * default constructor.
     */
    Passenger();
    /**
     * destructor.
     */
    virtual ~Passenger();
    /**
     * @return the start point.
     */
    BFSPoint* getStart();
    /**
     * @return the end point.
     */
    BFSPoint* getEnd();
    /**
     * @return a random int between 1-5.
     */
    int randSatisfaction();
    /**
     * @return the num of the passengers.
     */
    int getNumOfPassengers();
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & start;
        ar & end;
        ar & numOfPassengers;
    }
};

#endif /* PASSENGER_H_ */