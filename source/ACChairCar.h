#ifndef _ACCHAIRCAR_H
#define _ACCHAIRCAR_H

#include <iostream>
#include "Booking_class.h"
#include "Seat.h"
#include "Tier0.h"

class ACChairCar : public Tier0{
    private:
        static ACChairCar *sInstance;
        ACChairCar(const float loadfactor = 1.25f, const string name = "AC Chair Car", const bool isac = true, const bool islux = false);
    public:
        
        static const ACChairCar& Type();
        float GetLoadFactor() const;
        string GetName() const;
        bool IsSitting() const;
        bool IsAC() const;
        int GetNumberOfTiers() const;
        bool IsLuxury() const;
        friend ostream& operator<<(ostream& out, const ACChairCar& xyz); 
        static void UnitTest();
        ~ACChairCar();
};


#endif