#ifndef _EXECUTIVECHAIRCAR_H
#define _EXECUTIVECHAIRCAR_H

#include <iostream> 
#include "Booking_class.h"

class ExecutiveChairCar : public Booking_class{
    private:
        static ExecutiveChairCar *sInstance;
        ExecutiveChairCar(const float loadfactor = 5.00f, const string name = "Executive Chair Car", const bool isac = true, const bool islux = true, const int tier_no_ = 0,
        const bool is_sitting = true, const float tatkalLoadFactor_ = 0.3, const int miniTatkalCharge_ = 400, const int maxiTatkalCharge_ = 500, 
        const int miniTatkalDistance_ = 250, const int reservationCharges_ = 60);
    public:
        
        static const ExecutiveChairCar& Type();
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
        friend ostream& operator<<(ostream& os, const ExecutiveChairCar& ac);
        static void UnitTest();
        ~ExecutiveChairCar();
};


#endif