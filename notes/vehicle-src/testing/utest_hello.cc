////////////////////////
// hello_world test
////////////////////////

#include "utest.h"

#include <exception>
#include <cassert>

using namespace std ;

// this should be the first line in your test
static UTest utest = UTest( "hello_world" , std::cout );

const std::string hello(void)
{
  return "Hello World!" ;
}


//=============================================================================

int main(int argc, char** argv ){
    
    try{
    
        // ----- write your tests in here -------------------------------------

        utest.log( "running a simple hello world unit test example..." );

        string test_str = hello() ;
        string expected_str = "Hello World!" ;
        string test_case  = "comparing: [" + expected_str + "] == [ " + test_str + "]"  ;

        if( test_str.compare( expected_str ) != 0 )
        {
            utest.error( test_case );
        }
        else
        {
            utest.pass( test_case );
        }

        // --------------------------------------------------------------------


    //} catch( ... ){
    } catch( exception &e ){
        utest.log( "exception caught" );
        utest.fatal_error( e.what() );
    }


    return 0;
}

//=============================================================================

