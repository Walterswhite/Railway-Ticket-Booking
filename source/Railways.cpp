#include "Railways.h"
#include "Station.h"
#include <vector>
#include <map>

using namespace std;

Railways *Railways::sInstance = NULL;

Railways :: Railways (){};

const Railways& Railways::railways(){ 
        if (!sInstance) {
            sInstance = new Railways(); 
        }
        return *sInstance; 
}

vector <Station>  Railways::sStations = {Station("Mumbai"),Station("Dehli"),Station("Banglore"),Station("Kolkata"), Station("Chennai")};

map <pair<Station, Station>, int > Railways::sDistStations = {
    {{Station("Mumbai"), Station("Delhi")}, 1447},
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

int Railways::GetDistance(const Station &s1,const Station &s2) const {
    for(auto x : Railways :: sDistStations){
        if((x.first.first.GetName()==s1.GetName()&&x.first.second.GetName()==s2.GetName())||(x.first.first.GetName()==s2.GetName()&&x.first.second.GetName()==s1.GetName())){
            return x.second;
        }
    }
    return 0;
}

void Railways::UnitTest(){
    Station s1("Mumbai");
    Station s2("Delhi");
    int distance = Railways::railways().GetDistance(s1,s2);
    if(distance != 1447){
        cout<<"Railways class : Error in the Getdistance function"<<endl;
    }
    for(auto x : Railways::sStations){
        if(x.GetName()=="Mumbai"||x.GetName()=="Delhi"||x.GetName()=="Banglore"||x.GetName()=="Kolkata"||x.GetName()=="Chennai"){}
        else{
            cout<<"Railways class : Error in the sStations"<<endl;
        }
    }
}

Railways::~Railways(){};