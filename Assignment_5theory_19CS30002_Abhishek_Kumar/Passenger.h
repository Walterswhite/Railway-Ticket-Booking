#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include "Date.h" 
#include "Gender.h"
using namespace std;

class Passenger {
    private:
        string first_name_;
        string middle_name_;
        string last_name_;
        Date dob_;
        Gender *gender_;
        string aadhar_;
        string mobile_no_;
        string disabilityType_;
        string disabilityId_;
    public:
        bool CheckAadhar();
        bool CheckName();
        bool CheckDOB();
        bool CheckMobile();
        bool CheckDisability();
        string GetAadhar() ;
        string GetName() ;
        string GetGender() ;
        string GetMobile() ;
        string GetdisabilityID() ;
        string GetDisabilityType() ;
};
#endif