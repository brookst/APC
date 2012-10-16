#include "utest.h"
#include "motorbike.h"

#include <sstream>

using namespace std;

// this should be the first line in your test
static UTest utest = UTest( "utest_motorbike" , std::cout );

int main(void)
{
    try{

        // ----- write your tests in here -------------------------------------

        utest.log( "simple motorbike test" );

        MotorBike m( "HH-G-111", "Honda", "Kawasaki" );

        int test_num = m.getNWheels() ;
        int expected_num = 2 ;
        stringstream test_case;
        test_case << "testing number of wheels: [" << expected_num << "] == [" << test_num << "]"  ;

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

