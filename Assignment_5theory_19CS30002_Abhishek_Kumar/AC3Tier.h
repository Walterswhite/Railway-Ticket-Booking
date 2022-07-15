#ifndef _AC3TIER_H
#define _AC3TIER_H

#include <iostream> 
#include "Booking_class.h"

class AC3Tier : public Booking_class{
    private:
        static AC3Tier *sInstance;
        AC3Tier(const float loadfactor = 2.50f, const string name = "AC 3 Tier", const bool isac = true, const bool islux = false, const int tier_no_ = 3,
        const bool is_sitting = false, const float tatkalLoadFactor_ = 0.3, const int miniTatkalCharge_ = 300, const int maxiTatkalCharge_ = 400, 
        const int miniTatkalDistance_ = 500, const int reservationCharges_ = 40);
    public:
        
        static const AC3Tier& Type();
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
        friend ostream& operator<<(ostream& os, const AC3Tier& ac);
        static void UnitTest();
        ~AC3Tier();
};


#endif