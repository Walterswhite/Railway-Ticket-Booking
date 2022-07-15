#ifndef _RAILWAYS_H
#define _RAILWAYS_H
#include <vector>
#include <map>
#include <iostream>
#include "Station.h"
using namespace std;

class Railways { 
    private:
        Railways();
        static Railways *sInstance; 
    public:
        ~Railways() ;
        static const Railways& railways();
        static vector <Station>  sStations;
        static map <pair<Station, Station>, int > sDistStations; 
        int GetDistance(const Station &s1,const Station &s2) const;
        static void UnitTest();
};

#endif