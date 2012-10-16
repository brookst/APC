#ifndef _bicycle_h
#define _bicycle_h

#include "vehicle.h"
#include <iostream>

class Bicycle : public Vehicle {

public:
    
    Bicycle(){ }

    virtual ~Bicycle(){ }

    virtual const std::string type() const { return "Bicycle"; }

};

#endif
