#ifndef RAILWAYS_H
#define RAILWAYS_H
#include <vector>
#include <algorithm>
#include <iostream>
#include "Station.h"
using namespace std;

class Railways { 
    Railways();
    static Railways *myrailway_; 
public:
    ~Railways() ;
    static const Railways& railways();
    int GetDistance(const Station &s1,const Station &s2) const;
    static vector <Station>  sStations;
    static vector <pair< pair<Station, Station> , int > > sDistStations;
    static void UnitTest();
};

#endif