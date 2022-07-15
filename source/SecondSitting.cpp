#include <iostream>
#include "Booking_class.h"
#include "SecondSitting.h"

SecondSitting *SecondSitting::sInstance = NULL;
 
SecondSitting::SecondSitting(float a, string b, bool c, bool d) : Tier0(a, b, c, d){}

const SecondSitting& SecondSitting::Type(){
    if(!sInstance){
        sInstance = new SecondSitting();
    }
    return *sInstance;
}

float SecondSitting::GetLoadFactor() const{
    return (*this).loadFactor_;
}

string SecondSitting::GetName() const{
    return (*this).name_;
}

bool SecondSitting::IsSitting() const{
    return (*this).sitting_;
}

bool SecondSitting::IsAC() const{
    return (*this).ac_notac_;
}

int SecondSitting::GetNumberOfTiers() const{
    return (*this).tier_no_;
}

bool SecondSitting::IsLuxury() const{
    return (*this).lux_notlux_;
}

void SecondSitting::UnitTest(){
    SecondSitting b_class_2S;
    if(b_class_2S.GetLoadFactor()!=0.50f){
        cout << "SecondSitting Class : Error in GetLoadFactor Function" << endl;
    }
    if(b_class_2S.GetName()!="Second Sitting"){
        cout << "SecondSitting Class : Error in GetName Function" << endl;
    }
    if(b_class_2S.IsSitting()!=true){ 
        cout << "SecondSitting Class : Error in IsSitting Function" << endl;
    }
    if(b_class_2S.IsAC()!=false){
        cout << "SecondSitting Class : Error in IsAC Function" << endl;
    }
    if(b_class_2S.GetNumberOfTiers()!=0){
        cout << "SecondSitting Class : Error in GetNumberOfTiers Function" << endl;
    }
    if(b_class_2S.IsLuxury()!=false){
        cout << "SecondSitting Class : Error in IsLuxury Function" << endl;
    }
}

SecondSitting::~SecondSitting(){}