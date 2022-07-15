#ifndef _SLEEPER_H
#define _SLEEPER_H

#include <iostream> 
#include "Booking_class.h"

class Sleeper : public Booking_class{
    private:
        static Sleeper *sInstance;
        Sleeper(const float loadfactor = 1.00f, const string name = "Sleeper", const bool isac = false, const bool islux = false, const int tier_no_ = 3,
        const bool is_sitting = false, const float tatkalLoadFactor_ = 0.3, const int miniTatkalCharge_ = 100, const int maxiTatkalCharge_ = 200, 
        const int miniTatkalDistance_ = 500, const int reservationCharges_ = 20);
    public:
        
        static const Sleeper& Type();
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
        friend ostream& operator<<(ostream& os, const Sleeper& ac);
        static void UnitTest();
        ~Sleeper();
};


#endif