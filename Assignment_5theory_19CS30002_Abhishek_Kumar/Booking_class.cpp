#include <iostream>
#include "Booking_class.h"

using namespace std;
  
Booking_class::Booking_class(float a, string b, bool c, bool d, int e, bool f, float g, int h, int i, int j, int k){
    loadFactor_ = a;
    name_ = b;
    ac_notac_ = c;
    lux_notlux_ = d;
    tier_no_ = e;
    sitting_ = f;
    tatkalLoadFactor_ = g;
    miniTatkalCharge_ = h;
    maxiTatkalCharge_ = i;
    miniTatkalDistance_ = j;
    reservationCharges_ = k;
}
 
Booking_class::~Booking_class(){} 