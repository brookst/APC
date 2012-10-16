#ifndef _logger_h
#define _logger_h

#include <iostream>
#include <sstream>
#include <string>
#include <map>

// should use a standard c++ logging library here

// the following code is terrible programming (please don't even look at it !! )

typedef std::map<std::string, int> lscope;

static void logmsg( const std::string& scope, const std::string& msg )
{
    static lscope logscope;
    logscope["dtor"]   = 0 ;
    logscope["ctor"]   = 0 ;
    logscope["cctor"]  = 0 ;
    logscope["ops"]    = 0 ;

#ifndef NDEBUG
    if( logscope[ scope ] )
    {
        std::cout << "[" << scope << "]: " << msg << std::endl ;
    }
#endif

}

static void logmsg( const std::string& scope, const std::stringstream& ss )
{
    logmsg( scope, ss.str() ) ;
}

#endif

