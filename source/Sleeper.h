#ifndef _SLEEPER_H
#define _SLEEPER_H

#include <iostream> 
#include "Booking_class.h"
#include "Berth.h"
#include "Tier3.h"

class Sleeper : public Tier3{
    private:
        static Sleeper *sInstance;
        Sleeper(const float loadfactor = 1.00f, const string name = "Sleeper", const bool isac = false, const bool islux = false);
    public:
        
        static const Sleeper& Type();
        float GetLoadFactor() const;
        string GetName() const;
        bool IsSitting() const;
        bool IsAC() const;
        int GetNumberOfTiers() const;
        bool IsLuxury() const;
        static void UnitTest();
        ~Sleeper();
};


#endif