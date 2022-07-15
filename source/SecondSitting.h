#ifndef _SECONDSITTING_H
#define _SECONDSITTING_H

#include <iostream>
#include "Booking_class.h"
#include "Seat.h"
#include "Tier0.h"

class SecondSitting : public Tier0{
    private:
        static SecondSitting *sInstance;
        SecondSitting(const float loadfactor = 0.50f, const string name = "Second Sitting", const bool isac = false, const bool islux = false);
    public:
        
        static const SecondSitting& Type();
        float GetLoadFactor() const;
        string GetName() const;
        bool IsSitting() const;
        bool IsAC() const;
        int GetNumberOfTiers() const;
        bool IsLuxury() const;
        static void UnitTest();
        ~SecondSitting();
};


#endif