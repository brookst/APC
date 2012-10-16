#include "motorbike.h"
#include "car.h"

#include <iostream>

using namespace std;

int main(void)
{
    MotorBike m( "HH-G-111", "Honda", "Kawasaki" ) ;

    cout << m << endl ;
    
    Car* c = new Car( "BM-F-222", "Ferrari", "Ferrari", 12, 4 ) ;

    cout << *c << endl ;

    delete c ;

    return 0;
}

