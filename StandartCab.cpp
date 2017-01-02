/*
 * StandartCab.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: shmuel
 */

#include "StandartCab.h"
namespace std {

    StandartCab::StandartCab(int i, char man, char col) {
        id = i;
        manu = myManufacture(man);
        color = myColor(col);
    }
    StandartCab::StandartCab(){
        id = 0;
        kilometerPassed = 0;
    }
    StandartCab::~StandartCab() {
        // TODO Auto-generated destructor stub
    }
    double StandartCab::charge(TripInfo* ti){
        return ti->getTariff();
    }
    void StandartCab::setKiloPassed(long l) {
        kilometerPassed += l;
    }
    int StandartCab::getType(){
        return 1;
    }
    int StandartCab::getCharge() {
        return 0;
    }
    int StandartCab::getID() {
        return this->id;
    }
    Color StandartCab::myColor(char color) {
        switch (color) {
            case 'W':
                return Color::WHITE;
            case 'P':
                return Color::PINK;
            case 'G':
                return Color::GREEN;
            case 'B':
                return Color::BLUE;
            case 'R':
                return Color::RED;
            default:
                return  Color ::DEFAULT;
        }
    }
    Manufacture StandartCab::myManufacture(char mf) {
        switch (mf) {
            case 'H':
                return Manufacture ::HONDA;
            case 'F':
                return Manufacture ::FIAT;
            case 'T':
                return Manufacture ::TESLA;
            case 'S':
                return Manufacture ::SUBARO;
            default:
                return  Manufacture::DEFAULT;
        }
    }
    BFSPoint* StandartCab::drive(std::stack<Node*>* myWay) {
        if (myWay->size() != 0) {
            curruentLocation = (BFSPoint *) myWay->top();
            myWay->pop();
        }
        return curruentLocation;
    }
    BFSPoint* StandartCab::myLocation() {
        return curruentLocation;
    }
    void StandartCab::setMyLocation(BFSPoint *myLoc) {
        curruentLocation = myLoc;
    }
}
BOOST_CLASS_EXPORT(Cab)