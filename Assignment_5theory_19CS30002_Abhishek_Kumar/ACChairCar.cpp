#include <iostream>
#include "Booking_class.h"
#include "ACChairCar.h"

ACChairCar *ACChairCar::sInstance = NULL;
 
ACChairCar::ACChairCar(float a, string b, bool c, bool d, int e, bool f, float g, int h, int i, int j, int k) 
: Booking_class(a, b, c, d, e, f, g, h, i, j, k){}

const ACChairCar& ACChairCar::Type(){
    if(!sInstance){
        sInstance = new ACChairCar();
    }
    return *sInstance;
}
 
float ACChairCar::GetLoadFactor() const{
    return (*this).loadFactor_;
}

string ACChairCar::GetName() const{
    return (*this).name_;
}

bool ACChairCar::IsSitting() const{
    return (*this).sitting_;
}

bool ACChairCar::IsAC() const{
    return (*this).ac_notac_;
} 

int ACChairCar::GetNumberOfTiers() const{
    return (*this).tier_no_;
}

bool ACChairCar::IsLuxury() const{
    return (*this).lux_notlux_;
}

float ACChairCar::GetTatkalLoadFactor() const{
    return (*this).tatkalLoadFactor_;
}

int ACChairCar::GetMiniTatkalCharge() const{
    return (*this).miniTatkalCharge_;
}

int ACChairCar::GetMaxTatkalCharge() const{
    return (*this).maxiTatkalCharge_;
}

int ACChairCar::GetMinTatkalDistance() const{
    return (*this).miniTatkalDistance_;
}

int ACChairCar::GetReservationCharges() const{
    return (*this).reservationCharges_;
}

ostream& operator<<(ostream& os, const ACChairCar& ac){
    os<<"Travel Class = AC Chair Car"<<endl;
    os<<" : Mode: "<<"Sitting"<<endl;
    os<<" : Comfort: "<<"AC"<<endl;
    os<<" : Bunks: "<<"0"<<endl;
    os<<" : luxury: "<<"No"<<endl;
    return os;
}

void ACChairCar::UnitTest(){
    ACChairCar b_class_CC;
    if(b_class_CC.GetLoadFactor()!=2.00f){
        cout << "ACChairCar Class : Error in GetLoadFactor Function" << endl;
    }
    if(b_class_CC.GetName()!="AC Chair Car"){
        cout << "ACChairCar Class : Error in GetName Function" << endl;
    }
    if(b_class_CC.IsSitting()!=true){
        cout << "ACChairCar Class : Error in IsSitting Function" << endl;
    }
    if(b_class_CC.IsAC()!=true){
        cout << "ACChairCar Class : Error in IsAC Function" << endl;
    }
    if(b_class_CC.GetNumberOfTiers()!=0){
        cout << "ACChairCar Class : Error in GetNumberOfTiers Function" << endl;
    }
    if(b_class_CC.IsLuxury()!=false){
        cout << "ACChairCar Class : Error in IsLuxury Function" << endl;
    }
    if(b_class_CC.GetTatkalLoadFactor()!=0.3){
        cout << "AC2Tier Class : Error in GetTatkalLoadFactor Function" << endl;
    }
    if(b_class_CC.GetMiniTatkalCharge()!=125){
        cout << "AC2Tier Class : Error in GetMiniTatkalCharge Function" << endl;
    }
    if(b_class_CC.GetMaxTatkalCharge()!=225){
        cout << "AC2Tier Class : Error in GetMaxTatkalCharge Function" << endl;
    }
    if(b_class_CC.GetMinTatkalDistance()!=500){
        cout << "AC2Tier Class : Error in GetMinTatkalDistance Function" << endl;
    }
    if(b_class_CC.GetReservationCharges()!= 40){
        cout << "AC2Tier Class : Error in GetReservationCharges Function" << endl;
    }
}

ACChairCar::~ACChairCar(){}