#include<iostream>
#include <string>
#include <sstream>
#include "Date.h"
using namespace std;

char monthNames[][4] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
"Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
char dayNames[][10] = { "Monday", "Tuesday", "Wednesday", "Thursday",
"Friday", "Saturday", "Sunday" };


Date :: Date(UINT d, UINT m, UINT y) : date_(d), month_((Month)m), year_(y)
{ 
    // cout << "ctor: "; print();
}

Date :: ~Date(){};

void Date :: print () const 
{ 
    cout << date_ << "/" << monthNames[month_ - 1] << "/" << year_ << endl; 
}


Date& Date::operator=(const Date& d) {
    date_ = d.date_;
    month_ = d.month_;
    year_ = d.year_;
    return *this;
}

bool Date::CheckLeapYear(UINT year_){
    if(year_%4 == 0){
        return true;
    }
    else {
        return false;
    }
}

int rdn(int y, int m, int d) { /* Rata Die day one is 0001-01-01 */
    if (m < 3)
        y--, m += 12;
    return 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306;
}

int Date::CalculateAge(Date dob, Date current_date){
    int year = rdn(current_date.year_, current_date.month_, current_date.date_) - rdn(dob.year_, dob.month_, dob.date_)/365;
}

bool Date::CheckSpanOfYear(Date date1, Date current_date){

    int days = rdn(current_date.year_, current_date.month_, current_date.date_) - rdn(date1.year_, date1.month_, date1.date_);
    if(days/365<0){
        return true;
    }
    else{
        return false;
    }
}

bool Date::CheckDate(){
    try
    {
        if ((*this).date_ > 31 || (*this).date_ <= 0){
            throw "BAD_DATE";
            
        }
        if ((*this).month_ > 12 || (*this).month_ < 1){
            throw "BAD_DATE";
            
        }
        if ((*this).year_ > 2099 || (*this).year_ < 1999){
            throw "BAD_DATE";
            
        }
    }
    catch(char const* e){
        cout << "Invalid Date";
    }
}

void Date::UnitTest(){
    Date d(20,02,2002);
    Date dtest = d;
    if(d.date_ != 20){
        cout<<"Date Class: Error in the date datamember "<<endl;
    }
    if(d.month_ != 02){
        cout<<"Date Class: Error in the month datamember "<<endl;
    }
    if(d.year_ != 2002){
        cout<<"Date Class: Error in the year datamember "<<endl;
    }
    if(dtest.date_ != 20){
        cout<<"Date Class: Error in the copy constructor "<<endl;
    }
    if(dtest.month_ != 02){
        cout<<"Date Class: Error in the constructor "<<endl;
    }
    if(dtest.year_ != 2002){
        cout<<"Date Class: Error in the constructor "<<endl;
    }
}