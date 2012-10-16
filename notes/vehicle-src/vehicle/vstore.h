#ifndef _vstore_h
#define _vstore_h

//#include "vehicle.h"
#include <iostream>
#include <map>

class Vehicle ; // fwd declaration of vehicle class

typedef std::map<int, const Vehicle*> VStore_map;
typedef VStore_map::iterator VStore_map_it;

class VStore {

    std::string _name ;
    VStore_map _stock ;
    VStore_map_it _it ;

public:
    
    VStore( const std::string& name ): _name( name ) { }
    
    ~VStore() ;

    const std::string type() const { return "VehicleStore" ; }

    const Vehicle* getVehicle( int id ) ;
    const Vehicle* getVehicle( const std::string& regPlate ) ;

    int addVehicle( const Vehicle* v ) ;

    int delVehicle( int id ) ;
    int delVehicle( const std::string& regPlate ) ;
    int delVehicle( const Vehicle& v ) ;
    int delVehicle( const Vehicle* v ) ;

    std::ostream& print( std::ostream& out ) ; //const ;

};

//std::ostream& operator << ( std::ostream& out, const VStore& x ) ;
std::ostream& operator << ( std::ostream& out, VStore& x ) ;

#endif

