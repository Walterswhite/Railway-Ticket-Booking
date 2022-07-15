#include <iostream>
#include "Booking_class.h"
#include "AC3Tier.h"

AC3Tier *AC3Tier::sInstance = NULL;
 
AC3Tier::AC3Tier(float a, string b, bool c, bool d) : Tier3(a, b, c, d){}

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

void AC3Tier::UnitTest(){
    AC3Tier b_class_3A;
    if(b_class_3A.GetLoadFactor()!=1.75f){
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
}

AC3Tier::~AC3Tier(){}