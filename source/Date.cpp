#include<iostream>
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