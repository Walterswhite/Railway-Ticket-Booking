#ifndef _TIER0_H
#define _TIER0_H

#include <iostream>
#include "Booking_class.h"
#include "Seat.h"

class Tier0 : public Seat{
    public:
        Tier0(float a, string b, bool c, bool d, const int e = 0):Seat(a, b, c, d, e){}
        virtual ~Tier0(){}
}; 

#endif