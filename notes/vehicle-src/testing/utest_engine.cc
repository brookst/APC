#include "utest.h"
#include "engine.h"

#include <sstream>

using namespace std;

// this should be the first line in your test
static UTest utest = UTest( "utest_engine" , std::cout );

int main(void)
{
    try{

        // ----- write your tests in here -------------------------------------

        Engine e( "honda", 12, 4 );

        int test_num = e.getNValves();
        int expected_num = 48 ;
        stringstream test_case;
        test_case << "testing number of valves: [" << expected_num << "] == [" << test_num << "]"  ;

        if( test_num != expected_num )
        {
            utest.error( test_case.str() );
        }
        else
        {
            utest.pass( test_case.str() );
        }

        // --------------------------------------------------------------------


    //} catch( ... ){
    } catch( exception &e ){
        utest.log( "exception caught" );
        utest.fatal_error( e.what() );
    }

    return 0;
}

