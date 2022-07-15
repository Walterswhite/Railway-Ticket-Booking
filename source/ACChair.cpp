#include <iostream>
#include "Booking_class.h"
#include "ACChairCar.h"

ACChairCar *ACChairCar::sInstance = NULL;
 
ACChairCar::ACChairCar(float a, string b, bool c, bool d) : Tier0(a, b, c, d){}

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

ostream& operator<<(ostream& out , const ACChairCar& xyz){
   out << "Travel Class = AC Chair Car" << endl;
   out << " : Mode: Sitting" << endl;
   out << " : Comfort: AC" << endl;
   out << " : Bunks: 0" << endl;
   out << " : luxury: No" << endl;
    return out ;
}

void ACChairCar::UnitTest(){
    ACChairCar b_class_CC;
    if(b_class_CC.GetLoadFactor()!=1.25f){
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
}

ACChairCar::~ACChairCar(){}