#include <iostream>
#include "Booking_class.h"
#include "ExecutiveChairCar.h"

ExecutiveChairCar *ExecutiveChairCar::sInstance = NULL;
 
ExecutiveChairCar::ExecutiveChairCar(float a, string b, bool c, bool d, int e, bool f, float g, int h, int i, int j, int k) 
: Booking_class(a, b, c, d, e, f, g, h, i, j, k){}

const ExecutiveChairCar& ExecutiveChairCar::Type(){
    if(!sInstance){
        sInstance = new ExecutiveChairCar();
    }
    return *sInstance;
}

float ExecutiveChairCar::GetLoadFactor() const{
    return (*this).loadFactor_;
}

string ExecutiveChairCar::GetName() const{
    return (*this).name_;
}

bool ExecutiveChairCar::IsSitting() const{
    return (*this).sitting_;
}

bool ExecutiveChairCar::IsAC() const{
    return (*this).ac_notac_;
}

int ExecutiveChairCar::GetNumberOfTiers() const{
    return (*this).tier_no_;
}

bool ExecutiveChairCar::IsLuxury() const{
    return (*this).lux_notlux_;
}

float ExecutiveChairCar::GetTatkalLoadFactor() const{
    return (*this).tatkalLoadFactor_;
}

int ExecutiveChairCar::GetMiniTatkalCharge() const{
    return (*this).miniTatkalCharge_;
}

int ExecutiveChairCar::GetMaxTatkalCharge() const{
    return (*this).maxiTatkalCharge_;
}

int ExecutiveChairCar::GetMinTatkalDistance() const{
    return (*this).miniTatkalDistance_;
}

int ExecutiveChairCar::GetReservationCharges() const{
    return (*this).reservationCharges_;
}

ostream& operator<<(ostream& os, const ExecutiveChairCar& ac){
    os<<"Travel Class = ExecutiveChairCar"<<endl;
    os<<" : Mode: "<<"Sitting"<<endl;
    os<<" : Comfort: "<<"AC"<<endl;
    os<<" : Bunks: "<<"0"<<endl;
    os<<" : luxury: "<<"Yes"<<endl;
    return os;
}

void ExecutiveChairCar::UnitTest(){
    ExecutiveChairCar b_class_2A;
    if(b_class_2A.GetLoadFactor()!=5.00f){
        cout << "ExecutiveChairCar Class : Error in GetLoadFactor Function" << endl;
    }
    if(b_class_2A.GetName()!="Executive Chair Car"){
        cout << "ExecutiveChairCar Class : Error in GetName Function" << endl;
    }
    if(b_class_2A.IsSitting()!=true){
        cout << "ExecutiveChairCar Class : Error in IsSitting Function" << endl;
    }
    if(b_class_2A.IsAC()!=true){
        cout << "ExecutiveChairCar Class : Error in IsAC Function" << endl;
    }
    if(b_class_2A.GetNumberOfTiers()!=0){
        cout << "ExecutiveChairCar Class : Error in GetNumberOfTiers Function" << endl;
    }
    if(b_class_2A.IsLuxury()!=true){
        cout << "ExecutiveChairCar Class : Error in IsLuxury Function" << endl;
    }
    if(b_class_2A.GetTatkalLoadFactor()!=0.3){
        cout << "ExecutiveChairCar Class : Error in GetTatkalLoadFactor Function" << endl;
    }
    if(b_class_2A.GetMiniTatkalCharge()!=400){
        cout << "ExecutiveChairCar Class : Error in GetMiniTatkalCharge Function" << endl;
    }
    if(b_class_2A.GetMaxTatkalCharge()!=500){
        cout << "ExecutiveChairCar Class : Error in GetMaxTatkalCharge Function" << endl;
    }
    if(b_class_2A.GetMinTatkalDistance()!=250){
        cout << "ExecutiveChairCar Class : Error in GetMinTatkalDistance Function" << endl;
    }
    if(b_class_2A.GetReservationCharges()!= 60){
        cout << "ExecutiveChairCar Class : Error in GetReservationCharges Function" << endl;
    }
}

ExecutiveChairCar::~ExecutiveChairCar(){}