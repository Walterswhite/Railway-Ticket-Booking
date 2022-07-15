#ifndef _BOOKING_H
#define _BOOKING_H
#include <iostream>
#include <vector>
#include "Station.h"
#include "Date.h"
#include "Booking_class.h"
#include "Railways.h"
#include "Passenger.h"
using namespace std;

class Booking{
    private:
        const Station fromStation;
        const Station toStation;
        const Date date;
        const Booking_class &booked;
        Passenger passenger_;
        string name_;
        bool ac_notac_;
        bool lux_notlux_;
        int tier_no_;
        bool sitting_;
        bool bookingStatus_;
        string bookingMessage_;
    public:
        Booking(Station fromstation, Station tostation, Date date, const Booking_class& booked);
        virtual ~Booking();
        virtual int ComputeFare() const;
        static float sFarePerKM;
        static float sACcharge;
        static float sTaxPercent;
        static int sPNR;
        static vector<Booking*> sBookings;
        friend ostream& operator<<(ostream& out, const Booking &xxyz);
        static void UnitTest();
};

#endif