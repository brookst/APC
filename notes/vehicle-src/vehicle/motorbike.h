#ifndef _motorbike_h
#define _motorbike_h

#include "vehicle.h"

class MotorBike : public Vehicle {

public:
    
    MotorBike(
        const std::string& regPlate,
        const std::string& brand,
        const std::string& eng_brand,
        int eng_nCylinders = 4,
        int eng_nValvesPerCylinder = 2
    );

    virtual ~MotorBike();

    virtual const std::string type() const { return "MotorBike"; }

};

#endif

