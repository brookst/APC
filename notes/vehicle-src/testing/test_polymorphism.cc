//#include "vehicle.h"
//#include "engine.h"
#include "car.h"
#include "motorbike.h"

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    // it is not possible to create an instance of an abstract class
    //Vehicle v ;
    //cout << v << endl;

    MotorBike b( "HH-G-111", "Honda", "Kawasaki" );
    Car c( "BM-F-222", "Ferrari", "Ferrari", 12, 4 );
    
    vector<Vehicle*> v;

    v.push_back( &b );
    v.push_back( &c );

    for( unsigned int i=0; i<v.size(); i++ )
    {
        cout << "[" << v[i]->id() << "] " << *v[i] << endl;
        cout << "[" << v[i]->getEngine()->id() << "] " << *v[i]->getEngine() << endl;
    }

    v[0]->getEngine()->setBrand("Tweaked Kawasaki");
    v[0]->getEngine()->setNValvesPerCylinder( 4 );
    
    cout << *v[0] << endl ;

    return 0;
}

