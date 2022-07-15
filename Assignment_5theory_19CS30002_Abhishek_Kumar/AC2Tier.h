#ifndef _AC2TIER_H
#define _AC2TIER_H

#include <iostream> 
#include "Booking_class.h"

class AC2Tier : public Booking_class{
    private:
        static AC2Tier *sInstance;
        AC2Tier(const float loadfactor = 4.00f, const string name = "AC 2 Tier", const bool isac = true, const bool islux = false, const int tier_no_ = 2,
        const bool is_sitting = false, const float tatkalLoadFactor_ = 0.3, const int miniTatkalCharge_ = 400, const int maxiTatkalCharge_ = 500, 
        const int miniTatkalDistance_ = 500, const int reservationCharges_ = 50);
    public:
        
        static const AC2Tier& Type();
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
        friend ostream& operator<<(ostream& os, const AC2Tier& ac);
        static void UnitTest();
        ~AC2Tier();
};


#endif