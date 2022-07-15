#include <iostream>
#include "Booking_class.h"
#include "SecondSitting.h"

SecondSitting *SecondSitting::sInstance = NULL;
 
SecondSitting::SecondSitting(float a, string b, bool c, bool d, int e, bool f, float g, int h, int i, int j, int k) 
: Booking_class(a, b, c, d, e, f, g, h, i, j, k){}

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

float SecondSitting::GetTatkalLoadFactor() const{
    return (*this).tatkalLoadFactor_;
}

int SecondSitting::GetMiniTatkalCharge() const{
    return (*this).miniTatkalCharge_;
}

int SecondSitting::GetMaxTatkalCharge() const{
    return (*this).maxiTatkalCharge_;
}

int SecondSitting::GetMinTatkalDistance() const{
    return (*this).miniTatkalDistance_;
}

int SecondSitting::GetReservationCharges() const{
    return (*this).reservationCharges_;
}

ostream& operator<<(ostream& os, const SecondSitting& ac){
    os<<"Travel Class = Second Sitting"<<endl;
    os<<" : Mode: "<<"Sitting"<<endl;
    os<<" : Comfort: "<<"AC"<<endl;
    os<<" : Bunks: "<<"0"<<endl;
    os<<" : luxury: "<<"No"<<endl;
    return os;
}

void SecondSitting::UnitTest(){
    SecondSitting b_class_2S;
    if(b_class_2S.GetLoadFactor()!=0.60f){
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
    if(b_class_2S.GetTatkalLoadFactor()!=0.1){
        cout << "AC2Tier Class : Error in GetTatkalLoadFactor Function" << endl;
    }
    if(b_class_2S.GetMiniTatkalCharge()!=10){
        cout << "AC2Tier Class : Error in GetMiniTatkalCharge Function" << endl;
    }
    if(b_class_2S.GetMaxTatkalCharge()!=15){
        cout << "AC2Tier Class : Error in GetMaxTatkalCharge Function" << endl;
    }
    if(b_class_2S.GetMinTatkalDistance()!=100){
        cout << "AC2Tier Class : Error in GetMinTatkalDistance Function" << endl;
    }
    if(b_class_2S.GetReservationCharges()!= 15){
        cout << "AC2Tier Class : Error in GetReservationCharges Function" << endl;
    }
}

SecondSitting::~SecondSitting(){}