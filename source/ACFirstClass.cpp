#include <iostream>
#include "Booking_class.h"
#include "ACFirstClass.h"

ACFirstClass *ACFirstClass::sInstance = NULL;
 
ACFirstClass::ACFirstClass(float a, string b, bool c, bool d) : Tier2(a, b, c, d){}

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

void ACFirstClass::UnitTest(){
    ACFirstClass b_class_1A;
    if(b_class_1A.GetLoadFactor()!=3.00f){
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
}

ACFirstClass::~ACFirstClass(){}