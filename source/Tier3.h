#ifndef _TIER3_H
#define _TIER3_H

#include <iostream>
#include "Booking_class.h"
#include "Berth.h"

class Tier3 : public Berth{
    public:
        Tier3(float a, string b, bool c, bool d, const int e = 3):Berth(a, b, c, d, e){}
        virtual ~Tier3(){}
};

#endif