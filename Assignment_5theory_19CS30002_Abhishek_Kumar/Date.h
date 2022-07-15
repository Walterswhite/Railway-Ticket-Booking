#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;
class Date {
    enum Month { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
    enum Day { Mon, Tue, Wed, Thr, Fri, Sat, Sun };
    typedef unsigned int UINT;
public:
    UINT date_; Month month_; UINT year_;
    Date(UINT d, UINT m, UINT y);
    ~Date();
    void print() const;
    bool CheckDate();
    //bool validDate(); 
    Date& operator=(const Date& d);       // copy assignment operator
    bool CheckLeapYear(UINT year_);
    int CalculateAge(Date dob, Date current_date);
    bool CheckSpanOfYear(Date date1, Date current_date);  // return true in one year span
    static void UnitTest();
};


#endif