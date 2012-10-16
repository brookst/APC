# very simple c++ project for testing relations
# between classes, a bit of inheritance and
# polymorphism

cmake_minimum_required(VERSION 2.8)

project( vehicle )

# project library
add_subdirectory( ./vehicle )


# --------------- ctest options ------------------------------------------------------------
# enable submission to Dart Testing Dashboard (adds option BUILD_TESTING enabled by default)
# also calls enable_testing()
#include(CTest)
#
# enable simple testing. To run tests use the ctest tool or target 'make test'
option( BUILD_TESTING "Build the testing tree." ON )
enable_testing()
# more infos under: http://cmake.org/Wiki/CMake/Testing_With_CTest
# ------------------------------------------------------------------------------------------

# project tests
if( BUILD_TESTING )
add_subdirectory( ./testing )
endif( BUILD_TESTING )

