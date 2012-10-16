#ifndef _utest_h
#define _utest_h

#include <iostream>
//#include <cstring>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

/** Helper class for writing unit tests

  See example utest_hello.cc on how to use this class

 */


class UTest
{

    std::string _testname ;
    std::ostream& _out ;

    unsigned int _failed ;      // number of failed tests
    unsigned int _passed ;      // number of passed tests
    bool _last_test_status ;    // true if last test succeeded, false otherwise

public:


    // contructor
    UTest( const std::string& testname, std::ostream& stream=std::cout ) :
        _testname(testname), _out(stream), _failed(0), _passed(0), _last_test_status(false)
    {
        _out << std::endl << "[" << _testname << "] ";
        _out << "****************************** TEST_BEGIN ******************************" << std::endl << std::endl;
    }



    // destructor
    ~UTest()
    {
        std::stringstream sstr ;

        sstr << std::endl;
        sstr << "[" << _testname << "] number of tests PASSED : " << _passed << std::endl ;
        sstr << "[" << _testname << "] number of tests FAILED : " << _failed << std::endl ;
        sstr << std::endl;

        sstr << "[" << _testname << "] " ;
        sstr << "****************************** " ;
        sstr << ( _failed == 0 ? "TEST_PASSED" : "TEST_FAILED" ) ;
        sstr << " ******************************" ;
        sstr << std::endl << std::endl ;

        _out << sstr.str() ;
    }



    // FIXME use a standard logging library
    void log( const std::string& msg )
    {
        _out << "[" << _testname << "] " << msg << std::endl;
    }



    void pass( const std::string& msg )
    {
        _passed++;
        _last_test_status = true ;

        _out << "[" << _testname << "] last test status : " << last_test_status() << " : " << msg << std::endl;
    }



    void error( const std::string& msg )
    {
        _failed++;
        _last_test_status = false ;

        std::stringstream errmsg;
        errmsg << std::endl;
        errmsg << "[" << _testname << "] ##################### TEST_FAILED ######################" << std::endl;
        errmsg << "[" << _testname << "] ### ERROR: " << msg << std::endl;
        errmsg << "[" << _testname << "] ########################################################" << std::endl;
        errmsg << std::endl;

        _out << errmsg.str();

        // also send error to stderr
        //std::cerr << errmsg.str();
    }



    void fatal_error( const std::string& msg )
    {
        error( msg );
        _out << "FATAL ERROR OCCURRED, program will exit now !!" << std::endl ;
        exit(1);
    }



    // returns the status from the last test
    const char* last_test_status()
    {
        return ( _last_test_status ? "PASSED" : "FAILED" ) ;
    }

};

#endif

