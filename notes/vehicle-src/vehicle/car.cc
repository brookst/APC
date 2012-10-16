#include "car.h"
#include "logger.h"

#include <iostream>

using std::stringstream ;

Car::Car(
    const std::string& regPlate,
    const std::string& brand,
    const std::string& eng_brand,
    int eng_nCylinders,
    int eng_nValvesPerCylinder
): Vehicle( 4, regPlate, brand, eng_brand, eng_nCylinders, eng_nValvesPerCylinder )
{
    stringstream ss ;
    ss << "calling Car " << id() ;
    logmsg( "ctor", ss ) ;
}   


Car::~Car()
{ 
    stringstream ss ;
    ss << "calling ~Car " << id() ;
    logmsg( "dtor", ss ) ;
}

