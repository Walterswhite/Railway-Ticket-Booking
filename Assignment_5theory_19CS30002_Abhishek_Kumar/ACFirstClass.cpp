#include <iostream>
#include "Booking_class.h"
#include "ACFirstClass.h"

ACFirstClass *ACFirstClass::sInstance = NULL;
 
ACFirstClass::ACFirstClass(float a, string b, bool c, bool d, int e, bool f, float g, int h, int i, int j, int k) 
: Booking_class(a, b, c, d, e, f, g, h, i, j, k){}
 
const ACFirstClass& ACFirstClass::Type(){
    if(!sInstance){
        sInstance = new ACFirstClass();
    }
    return *sInstance;
}

float ACFirstClass::GetLoadFactor() const{
    return (*this).loadFactor_;
}

string ACFirstClass::GetName() const{
    return (*this).name_;
}
 
bool ACFirstClass::IsSitting() const{
    return (*this).sitting_;
}

bool ACFirstClass::IsAC() const{
    return (*this).ac_notac_;
}

int ACFirstClass::GetNumberOfTiers() const{
    return (*this).tier_no_;
}

bool ACFirstClass::IsLuxury() const{
    return (*this).lux_notlux_;
}

float ACFirstClass::GetTatkalLoadFactor() const{
    return (*this).tatkalLoadFactor_;
}

int ACFirstClass::GetMiniTatkalCharge() const{
    return (*this).miniTatkalCharge_;
}

int ACFirstClass::GetMaxTatkalCharge() const{
    return (*this).maxiTatkalCharge_;
}

int ACFirstClass::GetMinTatkalDistance() const{
    return (*this).miniTatkalDistance_;
}

int ACFirstClass::GetReservationCharges() const{
    return (*this).reservationCharges_;
}

ostream& operator<<(ostream& os, const ACFirstClass& ac){
    os<<"Travel Class = AC First Class"<<endl;
    os<<" : Mode: "<<"Sleeping"<<endl;
    os<<" : Comfort: "<<"AC"<<endl;
    os<<" : Bunks: "<<"3"<<endl;
    os<<" : luxury: "<<"Yes"<<endl;
    return os;
}

void ACFirstClass::UnitTest(){
    ACFirstClass b_class_1A;
    if(b_class_1A.GetLoadFactor()!=6.50f){
        cout << "ACFirstClass Class : Error in GetLoadFactor Function" << endl;
    }
    if(b_class_1A.GetName()!="AC First Class"){
        cout << "ACFirstClass Class : Error in GetName Function" << endl;
    }
    if(b_class_1A.IsSitting()!=false){
        cout << "ACFirstClass Class : Error in IsSitting Function" << endl;
    }
    if(b_class_1A.IsAC()!=true){
        cout << "ACFirstClass Class : Error in IsAC Function" << endl;
    }
    if(b_class_1A.GetNumberOfTiers()!=2){
        cout << "ACFirstClass Class : Error in GetNumberOfTiers Function" << endl;
    }
    if(b_class_1A.IsLuxury()!=true){
        cout << "ACFirstClass Class : Error in IsLuxury Function" << endl;
    }
    if(b_class_1A.GetTatkalLoadFactor()!=0.3){
        cout << "AC2Tier Class : Error in GetTatkalLoadFactor Function" << endl;
    }
    if(b_class_1A.GetMiniTatkalCharge()!=400){
        cout << "AC2Tier Class : Error in GetMiniTatkalCharge Function" << endl;
    }
    if(b_class_1A.GetMaxTatkalCharge()!=500){
        cout << "AC2Tier Class : Error in GetMaxTatkalCharge Function" << endl;
    }
    if(b_class_1A.GetMinTatkalDistance()!=500){
        cout << "AC2Tier Class : Error in GetMinTatkalDistance Function" << endl;
    }
    if(b_class_1A.GetReservationCharges()!= 60){
        cout << "AC2Tier Class : Error in GetReservationCharges Function" << endl;
    }
}

ACFirstClass::~ACFirstClass(){}