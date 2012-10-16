#include "vstore.h"
#include "vehicle.h"

#include <iostream>
#include <sstream>

using std::stringstream ;
using std::ostream ;
using std::endl ;
using std::cerr ;


VStore::~VStore()
{
    for( _it = _stock.begin() ; _it != _stock.end() ; _it++ )
    {
        //delVehicle( _it->second ) ; // why does this give an error in valgrind ?!
        delete _it->second ; // first erase allocated memory
        _it->second = NULL ; // than set the pointer to NULL
    }
}



const Vehicle* VStore::getVehicle( int id )
{
    if( _stock.find( id ) != _stock.end() )
    {
        return _stock[ id ] ;
    }

    //stringstream err( "failed to get vehicle with id " ) ;
    //err << id ;
    //throw( err.str() ) ;

    return NULL ;
}



const Vehicle* VStore::getVehicle( const std::string& regPlate )
{
    for( _it = _stock.begin() ; _it != _stock.end() ; _it++ )
    {
        if( _it->second->getRegPlate() == regPlate )
        {
            return _it->second ;
        }
    }

    //stringstream err( "failed to get vehicle with regPlate " + regPlate ) ;
    //throw( err.str() ) ;

    return NULL ;
}



int VStore::addVehicle( const Vehicle* v )
{
    if( v == NULL )
    {
        throw( "trying to add Vehicle which is set to NULL" ) ;
        return -1 ; // should never get here
    }

    const Vehicle* p = NULL ;
    //try
    //{
    //    p = getVehicle( v->getRegPlate() ) ;
    //}
    //catch( ... ) { }

    p = getVehicle( v->getRegPlate() ) ;

    if( p != NULL )
    {
        stringstream err;
        err << "error: found vehicle with id [" << p->id() << "] already registered with regPlate " << v->getRegPlate() ;

        cerr << "warning: freeing up memory from object with id [" << v->id() << "] ("<< *v << ")" << endl ;
        delete v ;
        v = NULL ;

        throw( err.str() ) ;
        return -1 ; // should never get here
    }

    _stock[ v->id() ] = v ;

    return v->id() ;
}



int VStore::delVehicle( int id )
{
    return delVehicle( getVehicle( id ) ) ;
}



int VStore::delVehicle( const std::string& regPlate )
{
    return delVehicle( getVehicle( regPlate ) ) ;
}



int VStore::delVehicle( const Vehicle& v )
{
    return delVehicle( &v ) ;
}



int VStore::delVehicle( const Vehicle* v )
{
    if( v == NULL )
    {
        throw( "trying to delete Vehicle which is set to NULL" ) ;
        return -1 ; // should never get here
    }

    int id = v->id() ;

    if( getVehicle(id) == NULL )
    {
        throw( "trying to delete Vehicle which is not on stock" ) ;
        return -1 ; // should never get here
    }

    delete _stock[ id ] ; // first erase allocated memory
    _stock[ id ] = NULL ; // than set the pointer to NULL

    _stock.erase( id ) ; // then erase entry from vstore map

    return id ; // finally return the id from the erased object
}



// ostream operators
ostream& VStore::print( ostream& out ) //const
{
    out << endl << _name << endl << endl;

    for( _it = _stock.begin() ; _it != _stock.end() ; _it++ )
    {
        out << " * id: [" << _it->first << "] " << *_it->second << endl;
    }

    return out;
}


//ostream& operator << ( ostream& out, const VStore& x )
ostream& operator << ( ostream& out, VStore& x )
{
    return x.print( out ) ;
}

