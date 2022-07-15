#include "Booking.h"
#include <iostream>
#include "SecondSitting.h"
#include <cmath> //for round off
using namespace std;

float Booking::sFarePerKM = 0.50f;
float Booking::sACcharge = 50.00f;
float Booking::sTaxPercent = 0.25f;
int Booking::sPNR = 1;
float General::sConcessionFactor = 0.00;
float Ladies::sConcessionFactor = 0.00;
float SCMale::sConcessionFactor = 0.40;
float SCFemale::sConcessionFactor = 0.50;
float Tatkal::sConcessionFactor = 0.00;
float PremiumTatkal::sConcessionFactor = 0.00;

vector<Booking*> Booking::sBookings = {};
  
Booking::Booking(Station fromstation, Station tostation, Date booking_date, Date reservation_date, Passenger passenger_, const Booking_class& booked)
:fromStation(fromStation),toStation(toStation),booking_date(booking_date),reservation_Date(reservation_date),passenger_(passenger_),booked(booked){
    bookingStatus_=true;
    bookingMessage_="BOOKING SUCCEEDED:";
    Booking::sBookings.push_back(this);
}

int Booking:: ComputeFare() const{
    // if(fromStation.GetName() == toStation.GetName()){
    //     return 0;
    // }
    // int distance = Railways::railways().GetDistance(fromStation,toStation);
    // float baseFare = Booking::sFarePerKM*distance;
    // float Tfair = booked.GetLoadFactor()*baseFare;
    // return round(Tfair);
}

Booking :: ~Booking(){
    Booking :: sBookings.pop_back();
    Booking :: sPNR = Booking::sBookings.size() + 1;
};

int General:: ComputeFare() const{
    if(fromStation.GetName() == toStation.GetName()){
        return 0;
    }
    int distance = Railways::railways().GetDistance(fromStation,toStation);
    float baseFare = Booking::sFarePerKM*distance;
    float Tfair = booked.GetLoadFactor()*baseFare;
    
    return round(Tfair);
}

ostream& operator<<(ostream& out, const General& xyz){
     
    out << endl;
    out << xyz.bookingMessage_<<endl;
    out << "PNR Number = "<<Booking::sPNR++<<endl;
    out << "From Station = "<<xyz.fromStation<<endl;
    out << "To Station = "<<xyz.toStation<<endl;
    out << "Travel Date = ";
    xyz.booking_date.print();
    out << "Reservation Date = ";
    xyz.reservation_Date.print();
    out << "Booking Class" << xyz.booked.GetName() << endl;
    out << "Fare = "<<xyz.ComputeFare()<<endl;
    return out;
}

int Tatkal:: ComputeFare() const{
    if(fromStation.GetName() == toStation.GetName()){
        return 0;
    }
    int distance = Railways::railways().GetDistance(fromStation,toStation);
    float baseFare = Booking::sFarePerKM*distance;
    float Tfair = booked.GetLoadFactor()*baseFare;
    if(distance>=booked.GetMinTatkalDistance()){
        float x=Tfair*booked.GetTatkalLoadFactor();
        if(x>booked.GetMaxTatkalCharge()){
            Tfair+=booked.GetMaxTatkalCharge();
        }
        else if(x<booked.GetMaxTatkalCharge()){
            Tfair+=booked.GetMaxTatkalCharge();
        }
        else{
            Tfair+=x;
        }
    }
    return round(Tfair);
}

ostream& operator<<(ostream& out, const Tatkal& xyz){
     
    out << endl;
    out << xyz.bookingMessage_<<endl;
    out << "PNR Number = "<<Booking::sPNR++<<endl;
    out << "From Station = "<<xyz.fromStation<<endl;
    out << "To Station = "<<xyz.toStation<<endl;
    out << "Travel Date = ";
    xyz.booking_date.print();
    out << "Reservation Date = ";
    xyz.reservation_Date.print();
    out << "Booking Class" << xyz.booked.GetName() << endl;
    out << "Fare = "<<xyz.ComputeFare()<<endl;
    return out;
}

int PremiumTatkal:: ComputeFare() const{
    if(fromStation.GetName() == toStation.GetName()){
        return 0;
    }
    int distance = Railways::railways().GetDistance(fromStation,toStation);
    float baseFare = Booking::sFarePerKM*distance;
    float Tfair = booked.GetLoadFactor()*baseFare;
    if(distance>=booked.GetMinTatkalDistance()){
        float x=Tfair*booked.GetTatkalLoadFactor();
        if(x>booked.GetMaxTatkalCharge()){
            Tfair+=2*booked.GetMaxTatkalCharge();
        }
        else if(x<booked.GetMaxTatkalCharge()){
            Tfair+=2*booked.GetMaxTatkalCharge();
        }
        else{
            Tfair+=2*x;
        }
    }
    return round(Tfair);
}

ostream& operator<<(ostream& out, const PremiumTatkal& xyz){
     
    out << endl;
    out << xyz.bookingMessage_<<endl;
    out << "PNR Number = "<<Booking::sPNR++<<endl;
    out << "From Station = "<<xyz.fromStation<<endl;
    out << "To Station = "<<xyz.toStation<<endl;
    out << "Travel Date = ";
    xyz.booking_date.print();
    out << "Reservation Date = ";
    xyz.reservation_Date.print();
    out << "Booking Class" << xyz.booked.GetName() << endl;
    out << "Fare = "<<xyz.ComputeFare()<<endl;
    return out;
}

int Ladies:: ComputeFare() const{
    if(fromStation.GetName() == toStation.GetName()){
        return 0;
    }
    int distance = Railways::railways().GetDistance(fromStation,toStation);
    float baseFare = Booking::sFarePerKM*distance;
    float Tfair = booked.GetLoadFactor()*baseFare;

    return round(Tfair);
}

ostream& operator<<(ostream& out, const Ladies& xyz){
     
    out << endl;
    out << xyz.bookingMessage_<<endl;
    out << "PNR Number = "<<Booking::sPNR++<<endl;
    out << "From Station = "<<xyz.fromStation<<endl;
    out << "To Station = "<<xyz.toStation<<endl;
    out << "Travel Date = ";
    xyz.booking_date.print();
    out << "Reservation Date = ";
    xyz.reservation_Date.print();
    out << "Fare = "<<xyz.ComputeFare()<<endl;
    return out;
}

int SCMale:: ComputeFare() const{
    if(fromStation.GetName() == toStation.GetName()){
        return 0;
    }
    int distance = Railways::railways().GetDistance(fromStation,toStation);
    float baseFare = Booking::sFarePerKM*distance;
    float Tfair = booked.GetLoadFactor()*baseFare;
    Tfair-=(*this).sConcessionFactor;
    return round(Tfair);
}

ostream& operator<<(ostream& out, const SCMale& xyz){
     
    out << endl;
    out << xyz.bookingMessage_<<endl;
    out << "PNR Number = "<<Booking::sPNR++<<endl;
    out << "From Station = "<<xyz.fromStation<<endl;
    out << "To Station = "<<xyz.toStation<<endl;
    out << "Travel Date = ";
    xyz.booking_date.print();
    out << "Reservation Date = ";
    xyz.reservation_Date.print();
    out << "Booking Class" << xyz.booked.GetName() << endl;
    out << "Fare = "<<xyz.ComputeFare()<<endl;
    return out;
}

int SCFemale:: ComputeFare() const{
    if(fromStation.GetName() == toStation.GetName()){
        return 0;
    }
    int distance = Railways::railways().GetDistance(fromStation,toStation);
    float baseFare = Booking::sFarePerKM*distance;
    float Tfair = booked.GetLoadFactor()*baseFare;
    Tfair-=(*this).sConcessionFactor;
    return round(Tfair);
}

ostream& operator<<(ostream& out, const SCFemale& xyz){
     
    out << endl;
    out << xyz.bookingMessage_<<endl;
    out << "PNR Number = "<<Booking::sPNR++<<endl;
    out << "From Station = "<<xyz.fromStation<<endl;
    out << "To Station = "<<xyz.toStation<<endl;
    out << "Travel Date = ";
    xyz.booking_date.print();
    out << "Reservation Date = ";
    xyz.reservation_Date.print();
    out << "Booking Class" << xyz.booked.GetName() << endl;
    out << "Fare = "<<xyz.ComputeFare()<<endl;
    return out;
}

int Blind:: ComputeFare() const{
    if(fromStation.GetName() == toStation.GetName()){
        return 0;
    }
    int distance = Railways::railways().GetDistance(fromStation,toStation);
    float baseFare = Booking::sFarePerKM*distance;
    float Tfair = booked.GetLoadFactor()*baseFare;
    Tfair-=(*this).sConcessionFactor;
    return round(Tfair);
}

ostream& operator<<(ostream& out, const Blind& xyz){
     
    out << endl;
    out << xyz.bookingMessage_<<endl;
    out << "PNR Number = "<<Booking::sPNR++<<endl;
    out << "From Station = "<<xyz.fromStation<<endl;
    out << "To Station = "<<xyz.toStation<<endl;
    out << "Travel Date = ";
    xyz.booking_date.print();
    out << "Reservation Date = ";
    xyz.reservation_Date.print();
    out << "Booking Class" << xyz.booked.GetName() << endl;
    out << "Fare = "<<xyz.ComputeFare()<<endl;
    return out;
}

int CancerPatient:: ComputeFare() const{
    if(fromStation.GetName() == toStation.GetName()){
        return 0;
    }
    int distance = Railways::railways().GetDistance(fromStation,toStation);
    float baseFare = Booking::sFarePerKM*distance;
    float Tfair = booked.GetLoadFactor()*baseFare;
    Tfair-=(*this).sConcessionFactor;
    return round(Tfair);
}

ostream& operator<<(ostream& out, const CancerPatient& xyz){
     
    out << endl;
    out << xyz.bookingMessage_<<endl;
    out << "PNR Number = "<<Booking::sPNR++<<endl;
    out << "From Station = "<<xyz.fromStation<<endl;
    out << "To Station = "<<xyz.toStation<<endl;
    out << "Travel Date = ";
    xyz.booking_date.print();
    out << "Reservation Date = ";
    xyz.reservation_Date.print();
    out << "Booking Class" << xyz.booked.GetName() << endl;
    out << "Fare = "<<xyz.ComputeFare()<<endl;
    return out;
}

int TBPatient:: ComputeFare() const{
    if(fromStation.GetName() == toStation.GetName()){
        return 0;
    }
    int distance = Railways::railways().GetDistance(fromStation,toStation);
    float baseFare = Booking::sFarePerKM*distance;
    float Tfair = booked.GetLoadFactor()*baseFare;
    Tfair-=(*this).sConcessionFactor;
    return round(Tfair);
}

ostream& operator<<(ostream& out, const TBPatient& xyz){
     
    out << endl;
    out << xyz.bookingMessage_<<endl;
    out << "PNR Number = "<<Booking::sPNR++<<endl;
    out << "From Station = "<<xyz.fromStation<<endl;
    out << "To Station = "<<xyz.toStation<<endl;
    out << "Travel Date = ";
    xyz.booking_date.print();
    out << "Reservation Date = ";
    xyz.reservation_Date.print();
    out << "Booking Class" << xyz.booked.GetName() << endl;
    out << "Fare = "<<xyz.ComputeFare()<<endl;
    return out;
}

int OpHandicapped:: ComputeFare() const{
    if(fromStation.GetName() == toStation.GetName()){
        return 0;
    }
    int distance = Railways::railways().GetDistance(fromStation,toStation);
    float baseFare = Booking::sFarePerKM*distance;
    float Tfair = booked.GetLoadFactor()*baseFare;
    Tfair-=(*this).sConcessionFactor;
    return round(Tfair);
}

ostream& operator<<(ostream& out, const OpHandicapped& xyz){
     
    out << endl;
    out << xyz.bookingMessage_<<endl;
    out << "PNR Number = "<<Booking::sPNR++<<endl;
    out << "From Station = "<<xyz.fromStation<<endl;
    out << "To Station = "<<xyz.toStation<<endl;
    out << "Travel Date = ";
    xyz.booking_date.print();
    out << "Reservation Date = ";
    xyz.reservation_Date.print();
    out << "Booking Class" << xyz.booked.GetName() << endl;
    out << "Fare = "<<xyz.ComputeFare()<<endl;
    return out;
}


// void Booking :: UnitTest(){
//     Booking btest(Station("Mumbai"), Station("Delhi"), Date(22, 5, 2021), SecondSitting::Type());
//     if(btest.ComputeFare() != 362){
//         cout<<"Date class : Error in the computeFare function  "<<endl;
//     }
//     if(btest.toStation.GetName() != "Delhi"){
//         cout<<"Date class : Error in the tostation member"<<endl;
//     }
//     if(btest.fromStation.GetName() != "Mumbai"){
//         cout<<"Date class : Error in the fromStation member"<<endl;
//     }
//     if(btest.booked.GetName() != "Second Sitting"){
//         cout<<"Date class : Error in the BookingClasses object"<<endl;
//     }
//     if(Booking::sFarePerKM != 0.50){
//         cout<<"Date class : Error in the static data member sBaseFarePerKM"<<endl;
//     }
//     if(Booking::sACcharge != 50.00){
//         cout<<"Date class : Error in the static data member sACSurcharge"<<endl;
//     }
//     if(Booking::sTaxPercent != 0.25){
//         cout<<"Date class : Error in the static data member sLuxuryTaxPercent"<<endl;
//     }
// }
 