/*
 * Driver.h
 *
 *  Created on: Nov 30, 2016
 *      Author: shmuel
 */

#ifndef DRIVER_H_
#define DRIVER_H_

#include <string>
#include "TripInfo.h"
#include "Cab.h"
#include "BFSPoint.h"
#include "Bfs.h"
#include "Passenger.h"
/**
 * this enum class is the MaritalStatus of the driver.
 */
enum class MaritalStatus {
    SINGLE,
    MARRIED,
    DIVORCED,
    WIDOWED
};
namespace std {
    class Driver {
    private:
        int id, age, exp, clients, vehicleId;
        MaritalStatus maritalStatus;
        float satisfaction, memo;
        Cab *cab;
        Bfs b;
        BFSPoint *currentLocation;
        BFSPoint *myRoad;
        TripInfo *tripInfo;
        bool haveAPassengers, amIOccupied;
        Passenger *myPassenger;

    public:
        /**
         * constructor.
         * @param identity is the id of the driver.
         * @param age is the driver's age.
         * @param ms is the MaritalStatus of the driver.
         * @param exp is the driver's experience.
         * @param vID is the vehicle' ID.
         * @param r is the start location of the driver.
         */
        Driver(int identity, int age, char ms, int exp, int vId, BFSPoint* r);
        /**
         * default constructor.
         */
        Driver();
        /**
         * destructor.
         */
        virtual ~Driver();
        /**
         * @return the id of the driver.
         */
        int getId();
        /**
         * @return the age of the driver.
         */
        int gatAge();
        /**
         * @return the experience of the driver.
         */
        int getExp();
        /**
         * @return the number of clients of the driver.
         */
        int getClients();
        /**
         * @return the passenger's satisfaction from the driver.
         */
        double getStisfaction();
        /**
         * @return the driver's cab.
         */
        Cab* getCab();
        /**
         * sets the satisfaction after trip
         * @param st is the satisfaction.
         */
        void setSatisfaction(double st);
        /**
         * sets the driver's cab.
         * @param c is a pointer to his new cab.
         */
        void setCab(Cab* c);
        /**
         * @return the current location of the driver.
         */
        BFSPoint* getLocation();
        /**
         * the taxi center operates bfs from the current location
         * to a new trip start point,
         * and recives  the distance to the start point.
         * @param ti is the new trip info.
         * @return int the distance from current location to ti.startpoint.
         */
        int findShortPath(TripInfo* ti);
        /**
         * every driver is listener to the taxi center,
         * and this is the action that happens
         * every time that moment passed
         */
        void drive();
        /**
         * @return the marital status of the driver.
         */
        MaritalStatus getMaritalStatus();
        /**
         * sets the trip info.
         * @param ti is the new trip info.
         */
        void setTripInfo(TripInfo * ti);
        /**
         *
         * @param ms is a shortcut of the driver's maritalstatus.
         * @return the maritalstatus.
         */
        MaritalStatus myMaritalStatus(char ms);
        /**
         * @return the vehicle id.
         */
        int myVehicleId();
        /**
         * operates the bfs algorithm from the current location
         * to a specific point.
         */
        void road();
        /**
         * pick up a passenger.
         */
        void pickUp();
        /**
         * drop off the passenger in the end point of the trip.
         */
        void dropOff();
        /**
         * sets the boolean value amIOccupied.
         */
        void setOccupied();
        /**
         * @return the boolean value amIOccupied.
         */
        bool occupied();
    };

} /* namespace std */

#endif /* DRIVER_H_ */