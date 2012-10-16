#ifndef _engine_h
#define _engine_h

#include <string>

class Engine
{
    int _id;
    int _nCylinders;
    int _nValvesPerCylinder;
    std::string _brand;

    //Engine( Engine & x ){} // disable default copy constructor

public:

    // constructor
    Engine( const std::string& brand, int nCylinders = 4, int nValvesPerCylinder = 2 ) ;

    // destructor
    virtual ~Engine() ; // { }
    
    int id() const { return _id ; }

    virtual const std::string type() const { return "Engine" ; }

    const std::string getBrand() const { return _brand ; }
    
    int getNCylinders() const { return _nCylinders ; }
    
    int getNValvesPerCylinder() const { return _nValvesPerCylinder ; }
    
    int getNValves() const ;
    
    void setBrand( const std::string& brand ) ;

    void setNCylinders( int nCylinders ) ;
    
    void setNValvesPerCylinder( int nValvesPerCylinder ) ;

    static int globalCounter ;

    std::ostream& print( std::ostream& out ) const ;

};

std::ostream &operator << ( std::ostream& out, const Engine& x ) ;

#endif

