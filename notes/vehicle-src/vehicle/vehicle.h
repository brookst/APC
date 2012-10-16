#ifndef _vehicle_h
#define _vehicle_h

#include <string>

#include "engine.h"
//class Engine; // fwd declaration of engine class

class Vehicle
{
    int _id;
    int _nWheels;
    std::string _regPlate;
    std::string _brand;
    Engine* _engine;

    //Vehicle( Vehicle & x ){} // disable default copy constructor
    void delEngine(void); // helper method for removing the engine

public:

    /** constructor for unmotorized vehicles */
    Vehicle( int nWheels = 2 ) ;

    /** constructor for motorized vehicles */
    Vehicle(
        int nWheels,
        const std::string& regPlate,
        const std::string& brand,
        const std::string& eng_brand,
        int eng_nCylinders,
        int eng_nValvesPerCylinder
    );

    // copy constructor
    Vehicle( const Vehicle& x ) ;
    const Vehicle& operator = ( const Vehicle& x ) ; // operator =

    // destructor
    virtual ~Vehicle() ;

    int id() const { return _id ; }

    /** virtual function which is not implemented, therefore making the
        Vehicle class an abstract class which has to be subclassed in order
        to create new instances of Vehicles
        Note: this is not a pure abstract class (aka. interface) since there
            are implementations provided for all Vehicle methods other than type()
        Important: Note the difference between the following declarations:
            virtual const std::string type() const = 0;
            virtual const std::string type() const;

            If the = 0 part is left out the compiler will complain and throw
            undefined reference errors. The = 0 notation makes the compiler
            aware that this is an abstract class which must be subclassed in
            order to create new instances therefore making the undefined
            reference safe!
    */
    virtual const std::string type() const = 0; // { return "Vehicle" ; }
    
    int getNWheels() const { return _nWheels ; }
    
    const std::string getBrand() const { return _brand ; }
    
    Engine* getEngine() const { return _engine ; }

    void setEngine( const Engine* const engine );

    void setEngine( const Engine& engine );
    
    const std::string getRegPlate() const { return _regPlate ; }

    void setBrand( const std::string& brand ){ _brand = brand ; }

    void setRegPlate( const std::string& regPlate ){ _regPlate = regPlate ; }

    static int globalCounter;

    std::ostream& print( std::ostream& out ) const;

};

std::ostream& operator << ( std::ostream& out, const Vehicle& v ) ;

#endif

