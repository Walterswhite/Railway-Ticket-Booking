#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;
class Date {
    enum Month { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
    enum Day { Mon, Tue, Wed, Thr, Fri, Sat, Sun };
    typedef unsigned int UINT;
    UINT date_; Month month_; UINT year_;
public:
    Date(UINT d, UINT m, UINT y);
    ~Date();
    void print() const;
    //bool validDate(); 
    Date& operator=(const Date& d);       // copy assignment operator
    static void UnitTest();
};

#endif