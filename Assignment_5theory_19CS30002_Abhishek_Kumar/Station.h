#ifndef _STATION_H
#define _STATION_H

#include <iostream>
using namespace std;

class Station{
    private:
        string station_name_;
    public:
        Station(string name);
        string GetName() const;
        int GetDistance(const Station &a);
        friend ostream& operator<<(ostream& out, const Station &xyz);
        static void UnitTest();
        bool CheckDuplicateStation();
        ~Station();
};
#endif