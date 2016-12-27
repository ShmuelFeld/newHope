/*
 * Passenger.h
 *
 *  Created on: Nov 30, 2016
 *      Author: ran
 */
#include "Passenger.h"

Passenger::Passenger(BFSPoint *st, BFSPoint *en){
    start = st;
    end = en;
}
Passenger::Passenger() {
    start = NULL;
    end = NULL;
}
Passenger:: ~Passenger() {

}
BFSPoint* Passenger::getStart() {
    return start;
}
BFSPoint* Passenger::getEnd() {
    return end;
}
int Passenger::randSatisfaction() {
    return 1 + (rand()%4);
}
int Passenger::getNumOfPassengers() {
    return 0;
}