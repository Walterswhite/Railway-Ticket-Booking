#include <iostream>
#include "Station.h"
#include "Railways.h"

using namespace std;

Station::Station(string name):station_name_(name){}

string Station::GetName() const{
    return station_name_;
}

int Station::GetDistance(const Station &a){
     return Railways::railways().GetDistance(*this, a);
}

ostream& operator<<(ostream& out, const Station &xyz){
    out << xyz.station_name_;
    return out;
}

void Station :: UnitTest(){
    Station s("Mumbai");
    Station s2("Banglore");
    if(s.GetName() != "Mumbai"){
        cout<<"Station class : eerror in GetName Function"<<endl;
    }
    int distance = s.GetDistance(s2);
    if(distance != 981){
        cout<<"Error in the Getdistance function of the Railways class"<<endl;
    }
}

bool Station::CheckDuplicateStation(){
    try
    {
     if(find(Railways::sStations.begin(),Railways::sStations.end(),station_name_)!=Railways::sStations.end()){}
     else{
         throw "Bad Station";
     }
    }
    catch (char const *e){
        cout << "Incorrect Name" << endl;
    }
}

Station::~Station(){}