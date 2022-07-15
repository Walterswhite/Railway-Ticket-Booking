#include "Booking.h"
#include <iostream>
#include "SecondSitting.h"
#include <cmath> //for round off
using namespace std;

float Booking::sFarePerKM = 0.50f;
float Booking::sACcharge = 50.00f;
float Booking::sTaxPercent = 0.25f;
int Booking::sPNR = 1;
vector<Booking*> Booking::sBookings = {};

Booking::Booking(Station fromStation, Station toStation, Date date, const Booking_class& booked):fromStation(fromStation),toStation(toStation),date(date),booked(booked){
    bookingStatus_=true;
    bookingMessage_="BOOKING SUCCEEDED:";
    name_=booked.GetName();
    if(booked.IsAC()){
        ac_notac_ = "AC";
    }
    else{
        ac_notac_ = "Non - AC";
    }
    if(booked.IsLuxury()){
        lux_notlux_ = "Yes";
    }
    else{
        lux_notlux_ = "No";
    }
    if(booked.GetNumberOfTiers()==0){
        tier_no_ = 0;
    }
    else if(booked.GetNumberOfTiers()==2){
        tier_no_ = 2;
    }
    else{
        tier_no_ = 3;
    }
    if(booked.IsSitting()){
        sitting_ = "Sitting";
    }
    else{
        sitting_ = "Sleeping";
    }
    Booking::sBookings.push_back(this);
}

int Booking:: ComputeFare() const{
    if(fromStation.GetName() == toStation.GetName()){
        return 0;
    }
    int distance = Railways::railways().GetDistance(fromStation,toStation);
    float baseFare = Booking::sFarePerKM*distance;
    float Tfair = booked.GetLoadFactor()*baseFare;
    if(booked.IsAC()){
        Tfair += Booking::sACcharge;
    }
    if(booked.IsLuxury()){
        Tfair += Booking::sTaxPercent*Tfair;
    }
    return round(Tfair);
}

ostream& operator<<(ostream& out, const Booking& xyz){
    
    out << endl;
    out << xyz.bookingMessage_<<endl;
    out << "PNR Number = "<<Booking::sPNR++<<endl;
    out << "From Station = "<<xyz.fromStation<<endl;
    out << "To Station = "<<xyz.toStation<<endl;
    out << "Travel Date = ";
    xyz.date.print();
    out << "Travel Class = "<<xyz.name_<<endl;
    out << " : Mode: "<<xyz.sitting_<<endl;
    out << " : Comfort: "<<xyz.ac_notac_<<endl;
    out << " : Bunks: "<<xyz.tier_no_<<endl; 
    out << " : luxury: "<<xyz.lux_notlux_<<endl;
    out << "Fare = "<<xyz.ComputeFare()<<endl;
    return out;
}

Booking :: ~Booking(){
    Booking :: sBookings.pop_back();
    Booking :: sPNR = Booking::sBookings.size() + 1;
};

void Booking :: UnitTest(){
    Booking btest(Station("Mumbai"), Station("Delhi"), Date(22, 5, 2021), SecondSitting::Type());
    if(btest.ComputeFare() != 362){
        cout<<"Date class : Error in the computeFare function  "<<endl;
    }
    if(btest.toStation.GetName() != "Delhi"){
        cout<<"Date class : Error in the tostation member"<<endl;
    }
    if(btest.fromStation.GetName() != "Mumbai"){
        cout<<"Date class : Error in the fromStation member"<<endl;
    }
    if(btest.booked.GetName() != "Second Sitting"){
        cout<<"Date class : Error in the BookingClasses object"<<endl;
    }
    if(Booking::sFarePerKM != 0.50){
        cout<<"Date class : Error in the static data member sBaseFarePerKM"<<endl;
    }
    if(Booking::sACcharge != 50.00){
        cout<<"Date class : Error in the static data member sACSurcharge"<<endl;
    }
    if(Booking::sTaxPercent != 0.25){
        cout<<"Date class : Error in the static data member sLuxuryTaxPercent"<<endl;
    }
}
