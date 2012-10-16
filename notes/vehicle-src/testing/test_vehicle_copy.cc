#include "engine.h"
#include "motorbike.h"
#include "car.h"

#include <iostream>

using namespace std;

int main(void)
{
    MotorBike honda( "HH-G-111", "Honda", "Kawasaki" ) ;
    MotorBike harley( "HH-F-222", "Harley", "Harley" ) ;
    MotorBike harley2( harley ); // using Vehicle's copy constructor

    cout << honda << endl ;
    cout << harley << endl ;
    cout << harley2 << endl ;

    cout << "exchanging engines..." << endl ;
    //Engine e( (*honda.getEngine()) ); // create a copy of the honda engine
    Engine e = *honda.getEngine(); // create a copy of the honda engine
    cout << e << endl ;
    honda.setEngine( harley.getEngine() );
    harley.setEngine( &e );
    
    cout << honda << endl ;
    cout << harley << endl ;

    // whatchout what happens here...
    //cout << "reverting back engines..." << endl ;
    //const Engine* pe = honda.getEngine(); // no copy is done here, only pointer assignment to Honda's engine!!
    //cout << *pe << endl ; // which is currently a Harley engine..
    //honda.setEngine( harley.getEngine() ); // now Honda's engine (pointer) gets set to a new instance of type Kawasaki
    //harley.setEngine( pe ); // and the pe pointer is still pointing to Honda's engine, which is now a Kawasaki!
    //
    //cout << honda << endl ;
    //cout << harley << endl ;

    cout << "now create object on the heap..." << endl ;

    MotorBike *pp = new MotorBike( "HH-Z-111", "Ducati", "Ducati" ) ;
    MotorBike *p = new MotorBike( *pp ) ; // using Vehicle's copy constructor

    delete pp;
    pp=NULL;


    cout << *p << endl ;

    honda = harley = *p;

    cout << "after copying..." << endl ;
    cout << honda << endl ;
    cout << harley << endl ;
    cout << *p << endl ;

    delete p;
    p=NULL;

    return 0;
}

