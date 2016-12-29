//
// Created by shmuel on 29/12/16.
//

#include "Clock.h"
namespace std{

    Clock::Clock() {
        counter = 0;
    }
    Clock::~Clock() {}
    void Clock::increase() {
        counter++;
    }
}