#ifndef _SECONDSITTING_H
#define _SECONDSITTING_H

#include <iostream>
#include "Booking_class.h"

class SecondSitting : public Booking_class{
    private:
        static SecondSitting *sInstance;
        SecondSitting(const float loadfactor = 0.60f, const string name = "Second Sitting", const bool isac = false, const bool islux = false, const int tier_no_ = 0,
        const bool is_sitting = true, const float tatkalLoadFactor_ = 0.1, const int miniTatkalCharge_ = 10, const int maxiTatkalCharge_ = 15, 
        const int miniTatkalDistance_ = 100, const int reservationCharges_ = 15);
    public:
        
        static const SecondSitting& Type();
        float GetLoadFactor() const;
        string GetName() const;
        bool IsSitting() const;
        bool IsAC() const;
        int GetNumberOfTiers() const;
        bool IsLuxury() const;
        float GetTatkalLoadFactor() const ;
        int GetMiniTatkalCharge() const;
        int GetMaxTatkalCharge() const;
        int GetMinTatkalDistance() const;
        int GetReservationCharges() const;
        friend ostream& operator<<(ostream& os, const SecondSitting& ac);
        static void UnitTest();
        ~SecondSitting();
};


#endif