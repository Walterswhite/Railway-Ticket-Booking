#ifndef _TIER2_H
#define _TIER2_H

#include <iostream>
#include "Booking_class.h"
#include "Berth.h"

class Tier2 : public Berth{
    public:
        Tier2(float a, string b, bool c, bool d, const int e = 2):Berth(a, b, c, d, e){}
        virtual ~Tier2(){}
};

#endif