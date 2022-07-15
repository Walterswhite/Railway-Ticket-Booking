#include <iostream>
#include "Date.h" 
#include "Gender.h"
#include "Passenger.h"
using namespace std;

bool Passenger::CheckAadhar(){
    try {
        if(aadhar_.length()!=12){
            throw "Bad_aadhar";
        }
    }
    catch (char const *e){
        cout << "Invalid Aadhar Number" << endl;
    }
}

bool Passenger::CheckName(){
    try {
        if(first_name_.length()+last_name_.length()==0){
            throw "Bad_name";
        }
    }
    catch (char const *e){
        cout << "Incorrect Name" << endl;
    }
}

bool Passenger::CheckDOB(){
    try {
        if((*this).dob_.CalculateAge(Date(9,4,2021),Date((*this).dob_.year_,(*this).dob_.month_,(*this).dob_.date_)) < 0){
            throw "Bad_dob";
        }
    }
    catch (char const *e){
        cout << "Invalid Date of Birth" << endl;
    }
}

bool Passenger::CheckMobile(){
    try {
        if(mobile_no_.length()!=10&&mobile_no_.length()!=0){
            throw "Bad_mobile";
        }
    }
    catch (char const *e){
        cout << "Invalid Mobile Number" << endl;
    }
}

bool Passenger::CheckDisability(){
    try {
        if(disabilityType_!="Blind"&&disabilityType_!="Cancer Patient"&&disabilityType_!="TB Patient"&&disabilityType_!="Orthopadically Handicapped"){
            throw "Bad_Disability";
        }
    }
    catch (char const *e){
        cout << "Incorrect Disability Type" << endl;
    }
}

string Passenger::GetAadhar() {
    return (*this).aadhar_;
}

string Passenger::GetName() {
    return (*this).first_name_+middle_name_+last_name_;
}

string Passenger::GetGender() {
    return (*this).gender_->GetName();
}

string Passenger::GetMobile() {
    return (*this).mobile_no_;
}

string Passenger::GetdisabilityID() {
    return (*this).disabilityId_;
}

string Passenger::GetDisabilityType() {
    return (*this).disabilityType_;;
}