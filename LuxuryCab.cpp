/*
 * LuxuryCab.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: shmuel
 */

#include "LuxuryCab.h"

namespace std {

	LuxuryCab::LuxuryCab(int i, char man, char col) {
		id = i;
		sc = new StandartCab(id, man, col);
	}
	LuxuryCab::LuxuryCab() {
		sc = 0;
	}
	LuxuryCab::~LuxuryCab() {
		delete sc;
	}
	double LuxuryCab::charge(TripInfo* ti){
		return ti->getTariff() * 2;
	}
	void LuxuryCab::setKiloPassed(long l){
		kilometerPassed = l;
	}
	int LuxuryCab::getType(){
		return 2;
	}
	int LuxuryCab::getCharge() {
		return 0;
	}

	int LuxuryCab::getID() {
		return id;
	}

} /* namespace std */