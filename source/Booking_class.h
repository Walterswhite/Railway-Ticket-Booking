#ifndef _BOOKING_CLASS_H
#define _BOOKING_CLASS_H

#include <iostream>
using namespace std;

class Booking_class{
    protected:
        float loadFactor_;
        string name_;
        bool ac_notac_;
        bool lux_notlux_;
        int tier_no_;
        bool sitting_;
    public:
        Booking_class(float a, string b, bool c, bool d, int f, bool e);
        virtual float GetLoadFactor() const = 0;
        virtual string GetName() const = 0;
        virtual bool IsAC() const = 0;
        virtual bool IsLuxury() const = 0;
        virtual bool IsSitting() const = 0;
        virtual int GetNumberOfTiers() const = 0;
        virtual ~Booking_class();
};

#endif