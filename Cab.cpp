//
// Created by shmuel on 02/01/17.
//

#include "Cab.h"
/**
 * default constructor.
 */
Cab::Cab(){}
/**
 * destructor.
 */
Cab::~Cab(){}
/**
 * the price for specified trip.
 * @param ti is the trip information.
 */
double Cab::charge(TripInfo* ti){}
/**
 * sets the kilometer that the cab already drove.
 * @param l is the increasing value.
 */
void Cab::setKiloPassed(long l){}
/**
 * @return a pointer to the cab to know which kind is it.
 */
int Cab::getType(){}
/**
 * @return the charge for the trip.
 */
int Cab::getCharge(){}
/**
 * @return the vehicle id.
 */