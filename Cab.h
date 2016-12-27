/*
 * Cab.h
 *
 *  Created on: Nov 30, 2016
 *      Author: shmuel
 */

#ifndef CAB_H_
#define CAB_H_
#include "TripInfo.h"
/**
 * enum class of the cab's color.
 */
enum class Color{
    RED,
    BLUE,
    GREEN,
    PINK,
    WHITE
};
/**
 * enum class of the cab's manufacture.
 */
enum class Manufacture{
    HONDA,
    SUBARO,
    TESLA,
    FIAT
};
namespace std {
/**
 * interface of cab.
 * every kind of cab needs to implement this interface.
 */
    class Cab {
    public:
        /**
         * default constructor.
         */
        Cab();
        /**
         * destructor.
         */
        virtual ~Cab();
        /**
         * the price for specified trip.
         * @param ti is the trip information.
         */
        virtual double charge(TripInfo* ti) = 0;
        /**
         * sets the kilometer that the cab already drove.
         * @param l is the increasing value.
         */
        virtual void setKiloPassed(long l) = 0;
        /**
         * @return a pointer to the cab to know which kind is it.
         */
        virtual int getType() = 0;
        /**
         * @return the charge for the trip.
         */
        virtual int getCharge() = 0;
        /**
         * @return the vehicle id.
         */
        virtual int getID() = 0;
    };

} /* namespace std */

#endif /* CAB_H_ */