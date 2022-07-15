#ifndef _TEST_H
#define _TEST_H
#include "Station.h"
#include "Date.h"
#include "Booking_Class.h"
#include "AC3Tier.h"
#include "AC2Tier.h"
#include "ACFirstClass.h"
#include "ACChairCar.h"
#include "FirstClass.h"
#include "Sleeper.h"
#include "SecondSitting.h"
#include "Sleeper.h"
#include "Booking.h"
#include "Railways.h"
#include <iostream>
using namespace std;

void BookingApplication() {
    // Bookings by different booking classes
    // <BookingClasses>::Type() returns the constant object of the respective type
    Booking b1(Station("Mumbai"), Station("Delhi"), Date(15, 2, 2021), ACFirstClass::Type());
    Booking b2(Station("Kolkata"), Station("Delhi"), Date(5, 3, 2021), AC2Tier::Type());
    Booking b3(Station("Mumbai"), Station("Kolkata"), Date(17, 3, 2021), FirstClass::Type());
    Booking b4(Station("Mumbai"), Station("Delhi"), Date(23, 3, 2021), AC3Tier::Type());
    Booking b5(Station("Chennai"), Station("Delhi"), Date(25, 4, 2021), ACChairCar::Type());
    Booking b6(Station("Chennai"), Station("Kolkata"), Date(7, 5, 2021), Sleeper::Type());
    Booking b7(Station("Mumbai"), Station("Delhi"), Date(19, 5, 2021), SecondSitting::Type());
    Booking b8(Station("Delhi"), Station("Mumbai"), Date(22, 5, 2021), SecondSitting::Type());
    // Output the bookings done where sBookings is the collection of bookings done
    vector<Booking*>::iterator it;
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it) {
        cout << *(*it);
    }
    return;
}

void UnitTestFunctions(){
    AC2Tier::UnitTest();
    AC3Tier::UnitTest();
    ACChairCar::UnitTest();
    ACFirstClass::UnitTest();
    FirstClass::UnitTest();
    SecondSitting::UnitTest();
    Sleeper::UnitTest();
    Station::UnitTest();
    Booking::UnitTest();
    Date::UnitTest();
    Railways::UnitTest();
    return;
}

void TestBookingApplication() {
    // Bookings by different booking classes
    // <BookingClasses>::Type() returns the constant object of the respective type
    Booking b1(Station("Mumbai"), Station("Mumbai"), Date(15, 2, 2021), ACFirstClass::Type());
    // Fare should be same
    Booking b2(Station("Kolkata"), Station("Delhi"), Date(5, 3, 2021), AC2Tier::Type());
    Booking b3(Station("Delhi"), Station("Kolkata"), Date(17, 3, 2021), AC2Tier::Type());
    // Type are same but Fare should be different
    Booking b4(Station("Mumbai"), Station("Delhi"), Date(23, 3, 2021), ACChairCar::Type());
    Booking b5(Station("Chennai"), Station("Delhi"), Date(25, 4, 2021), ACChairCar::Type());
    // Type are diffrent so Fair should be different
    Booking b6(Station("Chennai"), Station("Kolkata"), Date(7, 5, 2021), Sleeper::Type());
    Booking b7(Station("Chennai"), Station("Kolkata"), Date(19, 5, 2021), SecondSitting::Type());
    // Identical Bookings on same Date should be possible
    Booking b8(Station("Delhi"), Station("Mumbai"), Date(22, 5, 2021), SecondSitting::Type());
    Booking b9(Station("Delhi"), Station("Mumbai"), Date(22, 5, 2021), SecondSitting::Type());
    // Different Bookings on Same date should be possible
    Booking b10(Station("Delhi"), Station("Mumbai"), Date(22, 5, 2021), SecondSitting::Type());
    Booking b11(Station("Banglore"), Station("Mumbai"), Date(22, 5, 2021), FirstClass::Type());

    // Output the bookings done where sBookings is the collection of bookings done
    vector<Booking*>::iterator it;
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it) {
        cout << *(*it);
    }
    return;
}
#endif
