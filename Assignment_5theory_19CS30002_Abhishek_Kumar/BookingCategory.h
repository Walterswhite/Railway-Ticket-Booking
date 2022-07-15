#ifndef _BOOKINGCATEGORY_H
#define _BOOKINGCATEGORY_H

#include <iostream> 
#include "Booking_class.h"
#include "Booking.h"

class Booking_Category{
    protected :
        string name_;
        
    public:
        string GetName();
        Booking* CreateBooking(Booking_class a ,Station b, Date c );
};

class General : public Booking_Category{
    private:
        static General *sInstance;
    public:
        static const General& Type();
};

class Tatkal : public Booking_Category{
    private:
        static Tatkal *sInstance;
    public:
        static const Tatkal& Type();    
};

class PremiumTatkal : public Booking_Category{
    private:
        static PremiumTatkal *sInstance;
    public:
        static const PremiumTatkal& Type();
};

class Concession : public Booking_Category{
    private:
        static Concession *sInstance;
    public:
        static const Concession& Type();
};

class SeniorCitizen : public Concession{
    private:
        static SeniorCitizen *sInstance;
    public:
        static const SeniorCitizen& Type();
};

class Ladies : public Concession{
    private:
        static Ladies *sInstance;
    public:
        static const Ladies& Type();
};

class Divyaang : public Concession{
    private:
        static Divyaang *sInstance;
    public:
        static const Divyaang& Type();
};

class SCMale : public SeniorCitizen{
    private:
        static SCMale *sInstance;
    public:
        static const SCMale& Type();
};

class SCFemale : public SeniorCitizen{
    private:
        static SCFemale *sInstance;
    public:
        static const SCFemale& Type();
};

class Blind : public Divyaang{
    private:
        static Blind *sInstance;
    public:
        static const Blind& Type();
};

class CancerPatient : public Divyaang{
    private:
        static CancerPatient *sInstance;
    public:
        static const CancerPatient& Type();
};

class TBPatient : public Divyaang{
    private:
        static TBPatient *sInstance;
    public:
        static const TBPatient& Type();
};

class OpHandicapped : public Divyaang{
    private:
        static OpHandicapped *sInstance;
    public:
        static const OpHandicapped& Type();
};
#endif