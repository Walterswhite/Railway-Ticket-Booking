#ifndef _ACFIRSTCLASS_H
#define _ACFIRSTCLASS_H

#include <iostream> 
#include "Booking_class.h"
 
class ACFirstClass : public Booking_class{
    private:
        static ACFirstClass *sInstance;
        ACFirstClass(const float loadfactor = 6.40f, const string name = "AC First Class", const bool isac = true, const bool islux = true, const int tier_no_ = 2,
        const bool is_sitting = false, const float tatkalLoadFactor_ = 0.3, const int miniTatkalCharge_ = 400, const int maxiTatkalCharge_ = 500, 
        const int miniTatkalDistance_ = 500, const int reservationCharges_ = 60);
    public:
        static const ACFirstClass& Type();
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
        friend ostream& operator<<(ostream& os, const ACFirstClass& ac);
        static void UnitTest();
        ~ACFirstClass();
};
 

#endif