#ifndef _car_h
#define _car_h

#include "vehicle.h"

class Car : public Vehicle {

public:
    
    Car(
        const std::string& regPlate,
        const std::string& brand,
        const std::string& eng_brand,
        int eng_nCylinders = 4,
        int eng_nValvesPerCylinder = 2
    );
    
    virtual ~Car() ;

    virtual const std::string type() const { return "Car" ; }

};

#endif

