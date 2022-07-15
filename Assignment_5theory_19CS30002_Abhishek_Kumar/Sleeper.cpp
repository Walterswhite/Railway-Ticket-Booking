#include <iostream>
#include "Booking_class.h"
#include "Sleeper.h"

Sleeper *Sleeper::sInstance = NULL;
 
Sleeper::Sleeper(float a, string b, bool c, bool d, int e, bool f, float g, int h, int i, int j, int k) 
: Booking_class(a, b, c, d, e, f, g, h, i, j, k){}

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

float Sleeper::GetTatkalLoadFactor() const{
    return (*this).tatkalLoadFactor_;
}

int Sleeper::GetMiniTatkalCharge() const{
    return (*this).miniTatkalCharge_;
}

int Sleeper::GetMaxTatkalCharge() const{
    return (*this).maxiTatkalCharge_;
}

int Sleeper::GetMinTatkalDistance() const{
    return (*this).miniTatkalDistance_;
}

int Sleeper::GetReservationCharges() const{
    return (*this).reservationCharges_;
}

ostream& operator<<(ostream& os, const Sleeper& ac){
    os<<"Travel Class = Sleeper"<<endl;
    os<<" : Mode: "<<"Sleeping"<<endl;
    os<<" : Comfort: "<<"Non-AC"<<endl;
    os<<" : Bunks: "<<"3"<<endl;
    os<<" : luxury: "<<"No"<<endl;
    return os;
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
    if(b_class_SL.GetTatkalLoadFactor()!=0.3){
        cout << "AC2Tier Class : Error in GetTatkalLoadFactor Function" << endl;
    }
    if(b_class_SL.GetMiniTatkalCharge()!=100){
        cout << "AC2Tier Class : Error in GetMiniTatkalCharge Function" << endl;
    }
    if(b_class_SL.GetMaxTatkalCharge()!=200){
        cout << "AC2Tier Class : Error in GetMaxTatkalCharge Function" << endl;
    }
    if(b_class_SL.GetMinTatkalDistance()!=500){
        cout << "AC2Tier Class : Error in GetMinTatkalDistance Function" << endl;
    }
    if(b_class_SL.GetReservationCharges()!= 20){
        cout << "AC2Tier Class : Error in GetReservationCharges Function" << endl;
    }
}

Sleeper::~Sleeper(){}