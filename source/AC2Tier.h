#ifndef _AC2TIER_H
#define _AC2TIER_H

#include <iostream> 
#include "Booking_class.h"
#include "Berth.h"
#include "Tier2.h"

class AC2Tier : public Tier2{
    private:
        static AC2Tier *sInstance;
        AC2Tier(const float loadfactor = 2.00f, const string name = "AC 2 Tier", const bool isac = true, const bool islux = false);
    public:
        
        static const AC2Tier& Type();
        float GetLoadFactor() const;
        string GetName() const;
        bool IsSitting() const;
        bool IsAC() const;
        int GetNumberOfTiers() const;
        bool IsLuxury() const;
        static void UnitTest();
        ~AC2Tier();
};


#endif