#include "vstore.h"
#include "car.h"
#include "motorbike.h"

#include <iostream>
#include <exception>
#include <cstdlib>

//using namespace std;
using std::string ;
using std::cout ;
using std::cerr ;
using std::endl ;

int main(void)
{
    VStore vs ( "myVehicleStore" );

    vs.addVehicle( new MotorBike( "HH-G-111", "Honda", "Kawasaki" )) ;
    vs.addVehicle( new Car( "BM-F-222", "Ferrari", "Ferrari", 12, 4 )) ;
    vs.addVehicle( new Car( "PI-A-333", "Seat", "Volkswagen", 2, 2 )) ;

    // oh ohhh.. problem here.. how to protect against this?
    // replace addVehicle with addCar/addMotorbike/addBicycle/... ?
    // than it would be possible to always create a new instance
    // of the given vehicle in the corresponding "add" method..
    //Car c( "HH-A-333", "Seat", "Volkswagen" );
    //vs.addVehicle( &c );

    //Car* c = new Car( "BM-F-222", "Ferrari", "Ferrari", 12, 4 ) ;
    //try
    //{
    //    vs.addVehicle( c ) ;
    //}
    //catch( const string& str )
    //{
    //    cerr << str << endl ;
    //    return EXIT_FAILURE ;
    //}

    cout << vs << endl ;

    try
    {
        vs.delVehicle( "BM-F-222" ) ;
    }
    //catch(...)
    //catch( const exception& e )
    catch( const string& str ) 
    {
        //cerr << e.what() << endl ;
        cerr << str << endl ;
        return EXIT_FAILURE ;
    }

    cout << vs << endl ;

    return EXIT_SUCCESS ;
}

