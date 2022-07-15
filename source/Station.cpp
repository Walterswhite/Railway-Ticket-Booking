#include <iostream>
#include "Station.h"
#include "Railways.h"

using namespace std;

Station::Station(string name):station_name_(name){}

string Station::GetName() const{
    return station_name_;
}

// string Station::GetDistance(Station a){
//     return Railways::GetDistance(*this, a);
// }

ostream& operator<<(ostream& out, const Station &xyz){
    out << xyz.station_name_;
    return out;
}

void Station :: UnitTest(){
    Station s("Mumbai");
    if(s.GetName() != "Mumbai"){
        cout<<"Station class : eerror in GetName Function"<<endl;
    }
}

Station::~Station(){}