/*
 * LuxuryCab.h
 *
 *  Created on: Nov 30, 2016
 *      Author: shmuel
 */

#ifndef LUXURYCAB_H_
#define LUXURYCAB_H_
#include "StandartCab.h"
namespace std {

    class LuxuryCab: Cab {
    private:
        StandartCab* sc;
        int id;
        long kilometerPassed;
        Manufacture manu;
        Color color;
    public:
        /**
         * constructor.
         * @param id the identity number of the cab.
         * @param km kilometer that the cab drive
         * @param manu the manufacture of the cab.
         * @param col the cab's color.
         */
        LuxuryCab(int id, char manu, char col);
        /**
         * constructor.
         */
        LuxuryCab();
        /**
         * destructor.
         */
        virtual ~LuxuryCab();
        /**
         * the price for specified trip information.
         * @param ti is the trip information.
         */
        double charge(TripInfo* ti);
        /**
         * sets the kilometraze of the cab.
         * @param l the value we want to add.
         */
        void setKiloPassed(long l);
        /**
         * @return an integer that represent the type of the cab.
         */
        int getType();
        /**
         * @return the price for trip.
         */
        int getCharge();
        /**
         * @return the price for trip.
         */
        int getID();
    };

} /* namespace std */

#endif /* LUXURYCAB_H_ */