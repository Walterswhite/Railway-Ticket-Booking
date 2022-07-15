#ifndef _FIRSTCLASS_H
#define _FIRSTCLASS_H

#include <iostream> 
#include "Booking_class.h"
#include "Berth.h"
#include "Tier2.h"

class FirstClass : public Tier2{
    private:
        static FirstClass *sInstance;
        FirstClass(const float loadfactor = 2.00f, const string name = "First Class", const bool isac = false, const bool islux = true);
    public:
        
        static const FirstClass& Type();
        float GetLoadFactor() const;
        string GetName() const;
        bool IsSitting() const;
        bool IsAC() const;
        int GetNumberOfTiers() const;
        bool IsLuxury() const;
        static void UnitTest();
        ~FirstClass();
};


#endif