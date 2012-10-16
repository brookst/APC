#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MagVectorTestsSuiteAndFixture
#include "MagVector.hh"
#include <boost/test/unit_test.hpp>

class MagVectorFixture
{

public:

  MagVector ThreeVector;
 MagVector ThreeVectorAll1s;
 MagVector ThreeVectorAll2s;


  MagVectorFixture(): 
    ThreeVector(3),
    ThreeVectorAll1s(3),
    ThreeVectorAll2s(3)
  { 
    BOOST_MESSAGE( "setup fixture" );
  };

  virtual ~MagVectorFixture()  { BOOST_MESSAGE( "teardown fixture" ); };


};

BOOST_FIXTURE_TEST_SUITE( MagVectorSuite, MagVectorFixture )

BOOST_AUTO_TEST_CASE( testValueGet )
{
  BOOST_CHECK_MESSAGE(ThreeVector.get(0) == 0., "Content on 0 not on default value! ");
}

BOOST_AUTO_TEST_CASE( testValueGetAllDefaultZeros )
{
  BOOST_CHECK_MESSAGE(ThreeVector.get(0) == 0. 
                      && ThreeVector.get(1) == 0. 
                      && ThreeVector.get(2) == 0., 
                      "Content on 0 not on default value! ");
}

BOOST_AUTO_TEST_CASE( testSetValueAtIndex )
{
  ThreeVector.set(0,42);
  BOOST_CHECK_MESSAGE(ThreeVector.get(0) == 42., 
                      "Content on 0 not at 42! ");
}

BOOST_AUTO_TEST_CASE( testSetValueAtOutOfRangeIndex )
{
  BOOST_CHECK_THROW(ThreeVector.set(4,42), std::out_of_range );
}

BOOST_AUTO_TEST_CASE( testMagnitudeOf0 )
{
  BOOST_CHECK_MESSAGE(ThreeVector.magnitude()==0., "vector magnitude not on default" );
}

BOOST_AUTO_TEST_CASE( testMagnitudeOf4 )
{
  ThreeVector.set(1,4);
  BOOST_CHECK_MESSAGE(ThreeVector.magnitude()==4, "vector magnitude unequal 4" );
}

BOOST_AUTO_TEST_CASE( testAdd )
{
  ThreeVectorAll1s.add(ThreeVectorAll2s);
  BOOST_CHECK_MESSAGE(ThreeVectorAll1s.get(0)==0, "adding ones and twos failed");
}

BOOST_AUTO_TEST_CASE( testAdd3and4Vector )
{
  MagVector FourVector(4);
  ThreeVectorAll1s.add(FourVector);
  BOOST_CHECK_THROW(ThreeVectorAll1s.add(FourVector);, std::logic_error );
  //BOOST_CHECK_MESSAGE(ThreeVectorAll1s.get(0)==0, "adding ones and twos failed");
}

BOOST_AUTO_TEST_SUITE_END()
