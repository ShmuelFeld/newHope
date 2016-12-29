//
// Created by shmuel on 29/12/16.
//

#ifndef NEWHOPE_CLOCK_H
#define NEWHOPE_CLOCK_H


class Clock {
private:
    int counter;
public:
    /**
     * constructor.
     */
    Clock();
    /**
     * destructor.
     */
    virtual ~Clock();
    /**
     * increase counter by one.
     */
    void increase();
};


#endif //NEWHOPE_CLOCK_H
