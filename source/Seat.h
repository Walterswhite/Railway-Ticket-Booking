#ifndef _SEAT_H
#define _SEAT_H

#include <iostream>
#include "Booking_class.h"
using namespace std;

class Seat : public Booking_class{
    public:
        Seat(float a, string b, bool c, bool d, int e, const bool f = true):Booking_class(a, b, c, d, e, f){}
        virtual ~Seat(){}
};

#endif