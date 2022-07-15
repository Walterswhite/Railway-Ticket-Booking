#include <iostream>
#include "Booking_class.h"
#include "FirstClass.h"

FirstClass *FirstClass::sInstance = NULL;
 
FirstClass::FirstClass(float a, string b, bool c, bool d) : Tier2(a, b, c, d){}

const FirstClass& FirstClass::Type(){
    if(!sInstance){
        sInstance = new FirstClass();
    }
    return *sInstance;
}

float FirstClass::GetLoadFactor() const{
    return (*this).loadFactor_;
}

string FirstClass::GetName() const{
    return (*this).name_;
}

bool FirstClass::IsSitting() const{
    return (*this).sitting_;
}

bool FirstClass::IsAC() const{
    return (*this).ac_notac_;
}

int FirstClass::GetNumberOfTiers() const{
    return (*this).tier_no_;
}

bool FirstClass::IsLuxury() const{
    return (*this).lux_notlux_;
}

void FirstClass::UnitTest(){
    FirstClass b_class_FC;
    if(b_class_FC.GetLoadFactor()!=2.00f){
        cout << "FirstClass Class : Error in GetLoadFactor Function" << endl;
    }
    if(b_class_FC.GetName()!="First Class"){
        cout << "FirstClass Class : Error in GetName Function" << endl;
    }
    if(b_class_FC.IsSitting()!=false){
        cout << "FirstClass Class : Error in IsSitting Function" << endl;
    }
    if(b_class_FC.IsAC()!=false){
        cout << "FirstClass Class : Error in IsAC Function" << endl;
    }
    if(b_class_FC.GetNumberOfTiers()!=2){
        cout << "FirstClass Class : Error in GetNumberOfTiers Function" << endl;
    }
    if(b_class_FC.IsLuxury()!=true){
        cout << "FirstClass Class : Error in IsLuxury Function" << endl;
    }
}

FirstClass::~FirstClass(){}