#include "vehicle.h"
#include "engine.h"
#include "logger.h"

#include <iostream>
#include <sstream>

using std::stringstream ;
using std::ostream ;

int Vehicle::globalCounter = 0 ;


// constructor for unmotorized vehicles
Vehicle::Vehicle(
    int nWheels
):
    _id( globalCounter++ ),
    _nWheels( nWheels ),
    _engine( NULL )
{
    stringstream ss ;
    ss << "calling Vehicle " << _id ;
    logmsg( "ctor", ss ) ;
}



// constructor for motorized vehicles
Vehicle::Vehicle(
    int nWheels,
    const std::string& regPlate,
    const std::string& brand,
    const std::string& eng_brand,
    int eng_nCylinders,
    int eng_nValvesPerCylinder
):
    _id( globalCounter++ ),
    _nWheels( nWheels ),
    _regPlate( regPlate ),
    _brand( brand )
{
    stringstream ss ;
    ss << "calling Vehicle " << _id ;
    logmsg( "ctor", ss ) ;

    // create a new engine
    _engine = new Engine( eng_brand, eng_nCylinders, eng_nValvesPerCylinder ) ;
}



// copy constructor
// warning: _engine needs to always be initialized to NULL!!
Vehicle::Vehicle( const Vehicle &x ) : _id( globalCounter++ ), _engine(NULL)
{
    stringstream ss ;
    ss << "calling Vehicle cctor " << _id ;
    logmsg( "cctor", ss ) ;

    *this = x ; // call operator =
}



const Vehicle & Vehicle::operator = ( const Vehicle &x )
{

    stringstream ss ;
    ss << "calling Vehicle assignment operator " << _id << " = " << x.id() ;
    logmsg( "ops", ss ) ;

    _nWheels = x._nWheels ;
    _regPlate = x._regPlate ;
    _brand = x._brand ;
    //_engine = x._engine ; // this would just copy the pointer address!!
    setEngine( x._engine );

    // return back the object
    // needed when calling multiple assignments,
    // e.g. a = b = c ;
    return x ;
}



// destructor
Vehicle::~Vehicle()
{
    stringstream ss ;
    ss << "calling ~Vehicle " << _id ;
    logmsg( "dtor", ss ) ;
    
    delEngine();
}


void Vehicle::delEngine(void)
{
    if( _engine )
    {
        delete _engine ;
    }
    _engine = NULL ;
}



void Vehicle::setEngine( const Engine* const engine )
{
    if( engine == NULL )
    {
        throw( "called setEngine with NULL pointer" ) ;
        return ; // should never get here
    }
    setEngine( *engine );
    //delete engine;
    //engine = NULL;
}



void Vehicle::setEngine( const Engine& engine )
{
    delEngine();
    _engine = new Engine(engine) ; // create a new Engine object using the default copy constructor
}



// ostream operators
ostream& Vehicle::print( ostream& out ) const
{
    out << _nWheels << " wheels " << type() ;

    if( _engine )
    {
        out << " [" << _regPlate << "] of brand " << _brand << " with a " << *_engine ;
    }

    return out ;
}


ostream& operator << ( ostream& out, const Vehicle& x )
{
    return x.print( out ) ;
}

