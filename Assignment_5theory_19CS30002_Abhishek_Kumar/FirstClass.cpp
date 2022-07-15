#include <iostream>
#include "Booking_class.h"
#include "FirstClass.h"

FirstClass *FirstClass::sInstance = NULL;
 
FirstClass::FirstClass(float a, string b, bool c, bool d, int e, bool f, float g, int h, int i, int j, int k) : 
Booking_class(a, b, c, d, e, f, g, h, i, j, k){}

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

float FirstClass::GetTatkalLoadFactor() const{
    return (*this).tatkalLoadFactor_;
}

int FirstClass::GetMiniTatkalCharge() const{
    return (*this).miniTatkalCharge_;
}

int FirstClass::GetMaxTatkalCharge() const{
    return (*this).maxiTatkalCharge_;
}

int FirstClass::GetMinTatkalDistance() const{
    return (*this).miniTatkalDistance_;
}

int FirstClass::GetReservationCharges() const{
    return (*this).reservationCharges_;
}

ostream& operator<<(ostream& os, const FirstClass& ac){
    os<<"Travel Class = First Class"<<endl;
    os<<" : Mode: "<<"Sleeping"<<endl;
    os<<" : Comfort: "<<"Non-AC"<<endl;
    os<<" : Bunks: "<<"2"<<endl;
    os<<" : luxury: "<<"Yes"<<endl;
    return os;
}

void FirstClass::UnitTest(){
    FirstClass b_class_FC;
    if(b_class_FC.GetLoadFactor()!=3.00f){
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
    if(b_class_FC.GetTatkalLoadFactor()!=0.3){
        cout << "AC2Tier Class : Error in GetTatkalLoadFactor Function" << endl;
    }
    if(b_class_FC.GetMiniTatkalCharge()!=400){
        cout << "AC2Tier Class : Error in GetMiniTatkalCharge Function" << endl;
    }
    if(b_class_FC.GetMaxTatkalCharge()!=500){
        cout << "AC2Tier Class : Error in GetMaxTatkalCharge Function" << endl;
    }
    if(b_class_FC.GetMinTatkalDistance()!=500){
        cout << "AC2Tier Class : Error in GetMinTatkalDistance Function" << endl;
    }
    if(b_class_FC.GetReservationCharges()!= 50){
        cout << "AC2Tier Class : Error in GetReservationCharges Function" << endl;
    }
}

FirstClass::~FirstClass(){}