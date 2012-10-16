#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MagVectorTests
#include "MagVector.hh"

#include <boost/test/unit_test.hpp>

// BOOST_AUTO_TEST_CASE( testFails )
// {
//   BOOST_FAIL("This test fails!");
// }

BOOST_AUTO_TEST_SUITE( MagVectorSuite )

BOOST_AUTO_TEST_CASE( testValueGet )
{
  MagVector aVector(3);
  BOOST_CHECK_MESSAGE(aVector.get(0) == 0., "Content on 0 not on default value! ");
}

BOOST_AUTO_TEST_CASE( testValueGetAllDefaultZeros )
{
  MagVector aVector(3);
  BOOST_CHECK_MESSAGE(aVector.get(0) == 0. 
                      && aVector.get(1) == 0. 
                      && aVector.get(2) == 0., 
                      "Content on 0 not on default value! ");
}

BOOST_AUTO_TEST_CASE( testSetValueAtIndex )
{
  MagVector aVector(3);
  aVector.set(0,42);
  BOOST_CHECK_MESSAGE(aVector.get(0) == 42., 
                      "Content on 0 not at 42! ");
}

BOOST_AUTO_TEST_CASE( testSetValueAtOutOfRangeIndex )
{
  MagVector aVector(3);
  BOOST_CHECK_THROW(aVector.set(4,42), std::out_of_range );
}

BOOST_AUTO_TEST_CASE( testMagnitudeOf0 )
{
  MagVector aVector(3);
  BOOST_CHECK_MESSAGE(aVector.magnitude()==0., "vector magnitude not on default" );
}

BOOST_AUTO_TEST_CASE( testMagnitudeOf4 )
{
  MagVector aVector(3);
  aVector.set(1,4);
  BOOST_CHECK_MESSAGE(aVector.magnitude()==4, "vector magnitude unequal 4" );
}

BOOST_AUTO_TEST_SUITE_END()
