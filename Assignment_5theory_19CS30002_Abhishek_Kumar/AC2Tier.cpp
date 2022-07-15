#include <iostream>
#include "Booking_class.h"
#include "AC2Tier.h"

AC2Tier *AC2Tier::sInstance = NULL;
 
AC2Tier::AC2Tier(float a, string b, bool c, bool d, int e, bool f, float g, int h, int i, int j, int k) 
: Booking_class(a, b, c, d, e, f, g, h, i, j, k){}

const AC2Tier& AC2Tier::Type(){
    if(!sInstance){
        sInstance = new AC2Tier();
    }
    return *sInstance;
}

float AC2Tier::GetLoadFactor() const{
    return (*this).loadFactor_;
}

string AC2Tier::GetName() const{
    return (*this).name_;
}

bool AC2Tier::IsSitting() const{
    return (*this).sitting_;
}

bool AC2Tier::IsAC() const{
    return (*this).ac_notac_;
}

int AC2Tier::GetNumberOfTiers() const{
    return (*this).tier_no_;
}

bool AC2Tier::IsLuxury() const{
    return (*this).lux_notlux_;
}

float AC2Tier::GetTatkalLoadFactor() const{
    return (*this).tatkalLoadFactor_;
}

int AC2Tier::GetMiniTatkalCharge() const{
    return (*this).miniTatkalCharge_;
}

int AC2Tier::GetMaxTatkalCharge() const{
    return (*this).maxiTatkalCharge_;
}

int AC2Tier::GetMinTatkalDistance() const{
    return (*this).miniTatkalDistance_;
}

int AC2Tier::GetReservationCharges() const{
    return (*this).reservationCharges_;
}

ostream& operator<<(ostream& os, const AC2Tier& ac){
    os<<"Travel Class = AC2Tier"<<endl;
    os<<" : Mode: "<<"Sleeping"<<endl;
    os<<" : Comfort: "<<"AC"<<endl;
    os<<" : Bunks: "<<"3"<<endl;
    os<<" : luxury: "<<"No"<<endl;
    return os;
}

void AC2Tier::UnitTest(){
    AC2Tier b_class_2A;
    if(b_class_2A.GetLoadFactor()!=4.00f){
        cout << "AC2Tier Class : Error in GetLoadFactor Function" << endl;
    }
    if(b_class_2A.GetName()!="AC 2 Tier"){
        cout << "AC2Tier Class : Error in GetName Function" << endl;
    }
    if(b_class_2A.IsSitting()!=false){
        cout << "AC2Tier Class : Error in IsSitting Function" << endl;
    }
    if(b_class_2A.IsAC()!=true){
        cout << "AC2Tier Class : Error in IsAC Function" << endl;
    }
    if(b_class_2A.GetNumberOfTiers()!=2){
        cout << "AC2Tier Class : Error in GetNumberOfTiers Function" << endl;
    }
    if(b_class_2A.IsLuxury()!=false){
        cout << "AC2Tier Class : Error in IsLuxury Function" << endl;
    }
    if(b_class_2A.GetTatkalLoadFactor()!=0.3){
        cout << "AC2Tier Class : Error in GetTatkalLoadFactor Function" << endl;
    }
    if(b_class_2A.GetMiniTatkalCharge()!=400){
        cout << "AC2Tier Class : Error in GetMiniTatkalCharge Function" << endl;
    }
    if(b_class_2A.GetMaxTatkalCharge()!=500){
        cout << "AC2Tier Class : Error in GetMaxTatkalCharge Function" << endl;
    }
    if(b_class_2A.GetMinTatkalDistance()!=500){
        cout << "AC2Tier Class : Error in GetMinTatkalDistance Function" << endl;
    }
    if(b_class_2A.GetReservationCharges()!= 50){
        cout << "AC2Tier Class : Error in GetReservationCharges Function" << endl;
    }
}

AC2Tier::~AC2Tier(){}