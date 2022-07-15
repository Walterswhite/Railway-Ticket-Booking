#ifndef _ACFIRSTCLASS_H
#define _ACFIRSTCLASS_H

#include <iostream> 
#include "Booking_class.h"
#include "Berth.h"
#include "Tier2.h"

class ACFirstClass : public Tier2{
    private:
        static ACFirstClass *sInstance;
        ACFirstClass(const float loadfactor = 3.00f, const string name = "AC First Class", const bool isac = true, const bool islux = true);
    public:
        
        static const ACFirstClass& Type();
        float GetLoadFactor() const;
        string GetName() const;
        bool IsSitting() const;
        bool IsAC() const;
        int GetNumberOfTiers() const;
        bool IsLuxury() const;
        static void UnitTest();
        ~ACFirstClass();
};


#endif