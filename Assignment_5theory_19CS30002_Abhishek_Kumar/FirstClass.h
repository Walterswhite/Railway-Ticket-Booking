#ifndef _FIRSTCLASS_H
#define _FIRSTCLASS_H

#include <iostream> 
#include "Booking_class.h"

class FirstClass : public Booking_class{
    private:
        static FirstClass *sInstance;
        FirstClass(const float loadfactor = 3.00f, const string name = "First Class", const bool isac = false, const bool islux = true, const int tier_no_ = 2,
        const bool is_sitting = false, const float tatkalLoadFactor_ = 0.3, const int miniTatkalCharge_ = 400, const int maxiTatkalCharge_ = 500, 
        const int miniTatkalDistance_ = 500, const int reservationCharges_ = 50);
    public:
        
        static const FirstClass& Type();
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
        friend ostream& operator<<(ostream& os, const FirstClass& ac);
        static void UnitTest();
        ~FirstClass();
};


#endif