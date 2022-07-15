#include <iostream>
#include "Booking_class.h"
#include "AC3Tier.h"

AC3Tier *AC3Tier::sInstance = NULL;
 
AC3Tier::AC3Tier(float a, string b, bool c, bool d, int e, bool f, float g, int h, int i, int j, int k) 
: Booking_class(a, b, c, d, e, f, g, h, i, j, k){}
 
const AC3Tier& AC3Tier::Type(){
    if(!sInstance){
        sInstance = new AC3Tier(); 
    }
    return *sInstance;
}

float AC3Tier::GetLoadFactor() const{
    return (*this).loadFactor_;
}

string AC3Tier::GetName() const{
    return (*this).name_;
}

bool AC3Tier::IsSitting() const{
    return (*this).sitting_;
}

bool AC3Tier::IsAC() const{
    return (*this).ac_notac_;
}

int AC3Tier::GetNumberOfTiers() const{
    return (*this).tier_no_;
}

bool AC3Tier::IsLuxury() const{
    return (*this).lux_notlux_;
}

float AC3Tier::GetTatkalLoadFactor() const{
    return (*this).tatkalLoadFactor_;
}

int AC3Tier::GetMiniTatkalCharge() const{
    return (*this).miniTatkalCharge_;
}

int AC3Tier::GetMaxTatkalCharge() const{
    return (*this).maxiTatkalCharge_;
}

int AC3Tier::GetMinTatkalDistance() const{
    return (*this).miniTatkalDistance_;
}

int AC3Tier::GetReservationCharges() const{
    return (*this).reservationCharges_;
}

ostream& operator<<(ostream& os, const AC3Tier& ac){
    os<<"Travel Class = AC3Tier"<<endl;
    os<<" : Mode: "<<"Sleeping"<<endl;
    os<<" : Comfort: "<<"Non-AC"<<endl;
    os<<" : Bunks: "<<"3"<<endl;
    os<<" : luxury: "<<"No"<<endl;
    return os;
}

void AC3Tier::UnitTest(){
    AC3Tier b_class_3A;
    if(b_class_3A.GetLoadFactor()!=2.50f){
        cout << "AC3Tier Class : Error in GetLoadFactor Function" << endl;
    }
    if(b_class_3A.GetName()!="AC 3 Tier"){
        cout << "AC3Tier Class : Error in GetName Function" << endl;
    }
    if(b_class_3A.IsSitting()!=false){
        cout << "AC3Tier Class : Error in IsSitting Function" << endl;
    }
    if(b_class_3A.IsAC()!=true){
        cout << "AC3Tier Class : Error in IsAC Function" << endl;
    }
    if(b_class_3A.GetNumberOfTiers()!=3){
        cout << "AC3Tier Class : Error in GetNumberOfTiers Function" << endl;
    }
    if(b_class_3A.IsLuxury()!=false){
        cout << "AC3Tier Class : Error in IsLuxury Function" << endl;
    }
    if(b_class_3A.GetTatkalLoadFactor()!=0.3){
        cout << "AC3Tier Class : Error in GetTatkalLoadFactor Function" << endl;
    }
    if(b_class_3A.GetMiniTatkalCharge()!=300){
        cout << "AC3Tier Class : Error in GetMiniTatkalCharge Function" << endl;
    }
    if(b_class_3A.GetMaxTatkalCharge()!=400){
        cout << "AC3Tier Class : Error in GetMaxTatkalCharge Function" << endl;
    }
    if(b_class_3A.GetMinTatkalDistance()!=500){
        cout << "AC3Tier Class : Error in GetMinTatkalDistance Function" << endl;
    }
    if(b_class_3A.GetReservationCharges()!= 40){
        cout << "AC3Tier Class : Error in GetReservationCharges Function" << endl;
    }
}

AC3Tier::~AC3Tier(){}