#ifndef _ACCHAIRCAR_H
#define _ACCHAIRCAR_H

#include <iostream>
#include "Booking_class.h"

class ACChairCar : public Booking_class{
    private:
        static ACChairCar *sInstance;
        ACChairCar(const float loadfactor = 2.00f, const string name = "AC Chair Car", const bool isac = true, const bool islux = false, const int tier_no_ = 0,
        const bool is_sitting = true, const float tatkalLoadFactor_ = 0.3, const int miniTatkalCharge_ = 125, const int maxiTatkalCharge_ = 225, 
        const int miniTatkalDistance_ = 250, const int reservationCharges_ = 40);
    public:
        
        static const ACChairCar& Type();
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
        friend ostream& operator<<(ostream& os, const ACChairCar& ac); 
        static void UnitTest();
        ~ACChairCar();
};


#endif