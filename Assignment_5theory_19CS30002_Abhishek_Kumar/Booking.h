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
    public:
        const Station fromStation;
        const Station toStation;
        const Date booking_date;
        const Date reservation_Date;
        const Booking_class &booked;
        Passenger passenger_;
        bool bookingStatus_;
        string bookingMessage_;
    public:
        Booking(Station fromstation, Station tostation, Date booking_date, Date reservation_Date, Passenger passenger_, const Booking_class& booked);
        virtual ~Booking();
        virtual int ComputeFare() const;
        static float sFarePerKM;
        static float sACcharge;
        static float sTaxPercent;
        static int sPNR;
        static vector<Booking*> sBookings;
        // friend ostream& operator<<(ostream& out, const Booking &xxyz);
       // static void UnitTest();
};

class General : public Booking{
    private:
        static float sConcessionFactor;
    public:
        General(Station a,Station b, Date c, Date d, Passenger e, Booking_class& f) : Booking(a,b,c,d,e,f) {}
        int ComputeFare() const;
        friend ostream& operator<<(ostream& out, const General &xxyz);
        static void UnitTest();
        virtual ~General();
};

class Tatkal : public Booking{
    private:
        static float sConcessionFactor;
    public:
        Tatkal(Station a,Station b, Date c, Date d, Passenger e, Booking_class& f) : Booking(a,b,c,d,e,f) {}
        int ComputeFare() const;
        friend ostream& operator<<(ostream& out, const Tatkal &xxyz);
        static void UnitTest();
        virtual ~Tatkal();   
};

class PremiumTatkal : public Booking{
    private:
        static float sConcessionFactor;
    public:
        PremiumTatkal(Station a,Station b, Date c, Date d, Passenger e, Booking_class& f) : Booking(a,b,c,d,e,f) {}
        int ComputeFare() const;
        friend ostream& operator<<(ostream& out, const PremiumTatkal &xxyz);
        static void UnitTest();
        virtual ~PremiumTatkal();
};

class Concession : public Booking{
    private:
        static float sConcessionFactor;
    public:
        Concession(Station a,Station b, Date c, Date d, Passenger e, Booking_class& f) : Booking(a,b,c,d,e,f) {}
        int ComputeFare() const;
        friend ostream& operator<<(ostream& out, const Concession &xxyz);
        static void UnitTest();
        virtual ~Concession();
};

class SeniorCitizen : public Concession{
    private:
        static float sConcessionFactor;
    public:
        SeniorCitizen(Station a,Station b, Date c, Date d, Passenger e, Booking_class& f) : Concession(a,b,c,d,e,f) {}
        int ComputeFare() const;
        friend ostream& operator<<(ostream& out, const SeniorCitizen &xxyz);
        static void UnitTest();
        virtual ~SeniorCitizen();
};

class Ladies : public Concession{
    private:
        static float sConcessionFactor;
    public:
        Ladies(Station a,Station b, Date c, Date d, Passenger e, Booking_class& f) : Concession(a,b,c,d,e,f) {}
        int ComputeFare() const;
        friend ostream& operator<<(ostream& out, const Ladies &xxyz);
        static void UnitTest();
        virtual ~Ladies();
};

class Divyaang : public Concession{
    private:
    public:
        Divyaang(Station a,Station b, Date c, Date d, Passenger e, Booking_class& f) : Concession(a,b,c,d,e,f) {}
        virtual ~Divyaang();
};

class SCMale : public SeniorCitizen{
    private:
        static float sConcessionFactor;
    public:
        SCMale(Station a,Station b, Date c, Date d, Passenger e, Booking_class& f) : SeniorCitizen(a,b,c,d,e,f) {}
        int ComputeFare() const;
        friend ostream& operator<<(ostream& out, const SCMale &xxyz);
        static void UnitTest();
        virtual ~SCMale();
};

class SCFemale : public SeniorCitizen{
    private:
        static float sConcessionFactor;
    public:
        SCFemale(Station a,Station b, Date c, Date d, Passenger e, Booking_class& f) : SeniorCitizen(a,b,c,d,e,f) {}
        int ComputeFare() const;
        friend ostream& operator<<(ostream& out, const SCFemale &xxyz);
        static void UnitTest();
        virtual ~SCFemale();
};

class Blind : public Divyaang{
    private:
        static float sConcessionFactor;
    public:
        Blind(Station a,Station b, Date c, Date d, Passenger e, Booking_class& f) : Divyaang(a,b,c,d,e,f) {}
        int ComputeFare() const;
        friend ostream& operator<<(ostream& out, const Blind &xxyz);
        static void UnitTest();
        virtual ~Blind();
};

class CancerPatient : public Divyaang{
    private:
        static float sConcessionFactor;
    public:
        CancerPatient(Station a,Station b, Date c, Date d, Passenger e, Booking_class& f) : Divyaang(a,b,c,d,e,f) {}
        int ComputeFare() const;
        friend ostream& operator<<(ostream& out, const CancerPatient &xxyz);
        static void UnitTest();
        virtual ~CancerPatient();
};

class TBPatient : public Divyaang{
    private:
        static float sConcessionFactor;
    public:
        TBPatient(Station a,Station b, Date c, Date d, Passenger e, Booking_class& f) : Divyaang(a,b,c,d,e,f) {}
        int ComputeFare() const;
        friend ostream& operator<<(ostream& out, const TBPatient &xxyz);
        static void UnitTest();
        virtual ~TBPatient();
};

class OpHandicapped : public Divyaang{
    private:
        static float sConcessionFactor;
    public:
        OpHandicapped(Station a,Station b, Date c, Date d, Passenger e, Booking_class& f) : Divyaang(a,b,c,d,e,f) {}
        int ComputeFare() const;
        friend ostream& operator<<(ostream& out, const OpHandicapped &xxyz);
        static void UnitTest();
        virtual ~OpHandicapped();
};
#endif