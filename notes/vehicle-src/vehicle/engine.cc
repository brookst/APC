#include "engine.h"
#include "logger.h"
#include <iostream>
#include <sstream>

using std::ostream ;
using std::endl ;
using std::stringstream ;

int Engine::globalCounter = 0 ;

Engine::Engine(
    const std::string& brand,
    int nCylinders,
    int nValvesPerCylinder
):
    _id( globalCounter++ ),
    _nCylinders( nCylinders ),
    _nValvesPerCylinder( nValvesPerCylinder ),
    _brand( brand )
{
    stringstream ss ;
    ss << "calling Engine " << _id ;
    logmsg( "ctor", ss ) ;
}


Engine::~Engine()
{
    stringstream ss ;
    ss << "calling ~Engine " << _id ;
    logmsg( "dtor", ss ) ;
}


void Engine::setBrand( const std::string& brand )
{
    _brand = brand ;
}


void Engine::setNCylinders( int nCylinders )
{
    if( nCylinders > 0 )
    {
        _nCylinders = nCylinders ;
    }
}


void Engine::setNValvesPerCylinder( int nValvesPerCylinder )
{
    if( nValvesPerCylinder > 0 )
    {
        _nValvesPerCylinder = nValvesPerCylinder ;
    }
}


int Engine::getNValves() const
{
    return ( _nCylinders * _nValvesPerCylinder ) ;
}


// ostream operators

ostream& Engine::print( ostream& out ) const
{
    out << _brand << " engine (" << _nCylinders << " cylinders and " << getNValves() << " valves)" ;

    return out ;
}


ostream& operator << ( ostream& out, const Engine& x )
{
    return x.print( out ) ;
}

