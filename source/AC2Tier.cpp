#include <iostream>
#include "Booking_class.h"
#include "AC2Tier.h"

AC2Tier *AC2Tier::sInstance = NULL;
 
AC2Tier::AC2Tier(float a, string b, bool c, bool d) : Tier2(a, b, c, d){}

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

void AC2Tier::UnitTest(){
    AC2Tier b_class_2A;
    if(b_class_2A.GetLoadFactor()!=2.00f){
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
}

AC2Tier::~AC2Tier(){}