#include "Railways.h"
#include "Station.h"
#include <vector>
#include <algorithm>

using namespace std;
Railways *Railways::myrailway_ = NULL;
Railways :: Railways (){};

vector <Station> Railways :: sStations = {Station("Mumbai"),Station("Dehli"),Station("Banglore"),
                                            Station("Kolkata"), Station("Chennai")};



vector <pair< pair<Station, Station> , int > > Railways :: sDistStations = {
    {{Station("Mumbai"),Station("Delhi")},1447},
    {{Station("Mumbai"),Station("Banglore")},981},
    {{Station("Mumbai"),Station("Kolkata")},2014},
    {{Station("Mumbai"),Station("Chennai")},1338},
    {{Station("Delhi"),Station("Banglore")},2150},
    {{Station("Delhi"),Station("Kolkata")},1472},
    {{Station("Delhi"),Station("Chennai")},2180},
    {{Station("Banglore"),Station("Kolkata")},1871},
    {{Station("Banglore"),Station("Chennai")},350},
    {{Station("Kolkata"),Station("Chennai")},1659}
};

int Railways :: GetDistance(const Station &s1,const Station &s2) const {
    string name1 = s1.GetName();
    string name2 = s2.GetName();
    for(auto x : Railways :: sDistStations){
        if((x.first.first.GetName() == name1 && x.first.second.GetName() == name2) || 
            (x.first.first.GetName() == name2 && x.first.second.GetName() == name1)){
            return x.second;
        }
    }
    return 0;
}

const Railways& Railways :: railways(){ 
        if (!myrailway_) {
            myrailway_ = new Railways(); 
        }
        return *myrailway_; 
}

void Railways::UnitTest(){
    Station s1("Mumbai");
    Station s2("Banglore");
    int distance = Railways::railways().GetDistance(s1,s2);
    if(distance != 981){
        cout<<"Error in the Getdistance function of the Railways class"<<endl;
    }
    for(auto x : Railways::sStations){
        if(x.GetName() == "varanasi"){
            cout<<"Error in the sStations Data member of the Railways class"<<endl;
        }
    }
}

Railways :: ~Railways(){};
