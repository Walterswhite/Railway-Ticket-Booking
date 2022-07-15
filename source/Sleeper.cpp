#include <iostream>
#include "Booking_class.h"
#include "Sleeper.h"

Sleeper *Sleeper::sInstance = NULL;
 
Sleeper::Sleeper(float a, string b, bool c, bool d) : Tier3(a, b, c, d){}

const Sleeper& Sleeper::Type(){
    if(!sInstance){
        sInstance = new Sleeper();
    }
    return *sInstance;
}

float Sleeper::GetLoadFactor() const{
    return (*this).loadFactor_;
}

string Sleeper::GetName() const{
    return (*this).name_;
}

bool Sleeper::IsSitting() const{
    return (*this).sitting_;
}

bool Sleeper::IsAC() const{
    return (*this).ac_notac_;
}

int Sleeper::GetNumberOfTiers() const{
    return (*this).tier_no_;
}

bool Sleeper::IsLuxury() const{
    return (*this).lux_notlux_;
}

void Sleeper::UnitTest(){
    Sleeper b_class_SL;
    if(b_class_SL.GetLoadFactor()!=1.00f){
        cout << "Sleeper Class : Error in GetLoadFactor Function" << endl;
    }
    if(b_class_SL.GetName()!="Sleeper"){
        cout << "Sleeper Class : Error in GetName Function" << endl;
    }
    if(b_class_SL.IsSitting()!=false){
        cout << "Sleeper Class : Error in IsSitting Function" << endl;
    }
    if(b_class_SL.IsAC()!=false){
        cout << "Sleeper Class : Error in IsAC Function" << endl;
    }
    if(b_class_SL.GetNumberOfTiers()!=3){
        cout << "Sleeper Class : Error in GetNumberOfTiers Function" << endl;
    }
    if(b_class_SL.IsLuxury()!=false){
        cout << "Sleeper Class : Error in IsLuxury Function" << endl;
    }
}

Sleeper::~Sleeper(){}