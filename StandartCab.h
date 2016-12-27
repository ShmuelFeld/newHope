/*
 * StandartCab.h
 *
 *  Created on: Nov 30, 2016
 *      Author: shmuel
 */

#ifndef STANDARTCAB_H_
#define STANDARTCAB_H_
#include "Cab.h"
namespace std {

    class StandartCab:Cab {
    private:
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
        StandartCab(int id, char manu, char col);
        /**
         * constructor.
         */
        StandartCab();
        /**
         * destructor.
         */
        virtual ~StandartCab();
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
         * @return pointer to the cab.
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
        /**
         *
         * @param color is a shortcut of the vehicle's color.
         * @return Color.
         */
        Color myColor(char color);
        /**
         *
         * @param mf is a shortcut of the vehicle's Manufacture.
         * @return Manufacture.
         */
        Manufacture myManufacture(char mf);
    };

} /* namespace std */

#endif /* STANDARTCAB_H_ */