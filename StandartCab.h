/*
 * StandartCab.h
 *
 *  Created on: Nov 30, 2016
 *      Author: shmuel
 */

#ifndef STANDARTCAB_H_
#define STANDARTCAB_H_
#include "Cab.h"
#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/export.hpp>

namespace std {

    class StandartCab:public Cab {
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
        BFSPoint* drive(std::stack<Node*>* myWay);
        BFSPoint* myLocation();
        void setMyLocation(BFSPoint *myLoc);
        friend class boost::serialization::access;
        template<class Archive>
        void serialize(Archive &ar, const unsigned int version)
        {
            ar & boost::serialization::base_object<Cab>(*this);
        }
    };

} /* namespace std */

#endif /* STANDARTCAB_H_ */