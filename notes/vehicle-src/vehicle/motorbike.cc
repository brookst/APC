#include "motorbike.h"
#include "logger.h"

#include <iostream>

using std::stringstream ;

MotorBike::MotorBike(
    const std::string& regPlate,
    const std::string& brand,
    const std::string& eng_brand,
    int eng_nCylinders,
    int eng_nValvesPerCylinder
): Vehicle( 2, regPlate, brand, eng_brand, eng_nCylinders, eng_nValvesPerCylinder )
{
    stringstream ss ;
    ss << "calling MotorBike " << id() ;
    logmsg( "ctor", ss ) ;
}   


MotorBike::~MotorBike()
{
    stringstream ss ;
    ss << "calling ~MotorBike " << id() ; 
    logmsg( "dtor", ss ) ;
}

