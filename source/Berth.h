#ifndef _BERTH_H
#define _BERTH_H

#include <iostream>
#include "Booking_class.h"
using namespace std;

class Berth : public Booking_class{
    public:
        Berth(float a, string b, bool c, bool d, int e, const bool f = false):Booking_class(a, b, c, d, e, f){}
        virtual ~Berth(){}
};

#endif