#include <iostream>
#include "Booking_class.h"

using namespace std;

Booking_class::Booking_class(float a, string b, bool c, bool d, int e, bool f){
    loadFactor_ = a;
    name_ = b;
    ac_notac_ = c;
    lux_notlux_ = d;
    tier_no_ = e;
    sitting_ = f;
}
 
Booking_class::~Booking_class(){}