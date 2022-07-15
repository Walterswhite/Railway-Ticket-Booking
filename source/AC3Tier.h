#ifndef _AC3TIER_H
#define _AC3TIER_H

#include <iostream> 
#include "Booking_class.h"
#include "Berth.h"
#include "Tier3.h"

class AC3Tier : public Tier3{
    private:
        static AC3Tier *sInstance;
        AC3Tier(const float loadfactor = 1.75f, const string name = "AC 3 Tier", const bool isac = true, const bool islux = false);
    public:
        
        static const AC3Tier& Type();
        float GetLoadFactor() const;
        string GetName() const;
        bool IsSitting() const;
        bool IsAC() const;
        int GetNumberOfTiers() const;
        bool IsLuxury() const;
        static void UnitTest();
        ~AC3Tier();
};


#endif