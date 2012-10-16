

option( RUN_SMOKE_TESTS "Build smoke tests." ON )
option( RUN_UNIT_TESTS "Build unit tests." ON )
option( RUN_MEMORY_TESTS "Build memory tests." ON )
option( RUN_STATIC_ANALYSIS_TESTS "Run static analysis tests." ON )



# ----- check pre-requirements for running some types of tests ------
if( RUN_MEMORY_TESTS )
    find_program( valgrind_executable valgrind )
    if( NOT valgrind_executable )
        message( "valgrind not found in your system, cannot run memory tests!" )
        set( RUN_MEMORY_TESTS OFF )
    endif( NOT valgrind_executable )
endif( RUN_MEMORY_TESTS )


if( RUN_STATIC_ANALYSIS_TESTS )
    find_program( cppcheck_executable cppcheck )
    if( NOT cppcheck_executable )
        message( "cppcheck not found in your system, cannot run static code analysis test!" )
        set( RUN_STATIC_ANALYSIS_TESTS OFF )
    endif( NOT cppcheck_executable )
endif( RUN_STATIC_ANALYSIS_TESTS )
# -------------------------------------------------------------------




# ----- helper macro for adding a new vehicle test ------------------
macro( add_vehicle_test _testname )
    add_executable( ${_testname} ${ARGN} )
    target_link_libraries( ${_testname} vehicle )
endmacro()
# -------------------------------------------------------------------



# ----- helper macro for adding a new vehicle smoke test ------------
# testname is prefixed by st_
macro( add_vehicle_stest _testname )
    add_test( NAME st_${_testname} COMMAND ${_testname} )
endmacro()
# -------------------------------------------------------------------



# ----- helper macro for adding a new vehicle memory test -----------
# testname is prefixed by ut_
macro( add_vehicle_utest _testname )
    add_test( NAME ut_${_testname} COMMAND ${_testname} )
    set_tests_properties( ut_${_testname} PROPERTIES FAIL_REGULAR_EXPRESSION "TEST_FAILED" )
    set_tests_properties( ut_${_testname} PROPERTIES PASS_REGULAR_EXPRESSION "TEST_PASSED" )
endmacro()
# -------------------------------------------------------------------



# ----- helper macro for adding a new vehicle memory test -----------
# testname is prefixed by mt_
macro( add_vehicle_mtest _testname )
    get_target_property( _executable ${_testname} LOCATION )
    add_test( NAME mt_${_testname} COMMAND ${valgrind_executable} ${_executable} )
    set_tests_properties( mt_${_testname} PROPERTIES
        FAIL_REGULAR_EXPRESSION "LEAK SUMMARY"
    )
    set_tests_properties( mt_${_testname} PROPERTIES
        PASS_REGULAR_EXPRESSION "ERROR SUMMARY: 0 errors from 0 contexts"
    )
endmacro()
# -------------------------------------------------------------------




add_definitions( -Wall -ansi -pedantic )

include_directories( ${PROJECT_SOURCE_DIR}/vehicle )



# ----- add new tests from source files -----------------------------
add_vehicle_test( test_engine_constructor ./test_engine_constructor.cc )
add_vehicle_test( test_vehicle_constructor ./test_vehicle_constructor.cc )
add_vehicle_test( test_vehicle_copy ./test_vehicle_copy.cc )
add_vehicle_test( test_vstore ./test_vstore.cc )
add_vehicle_test( test_polymorphism ./test_polymorphism.cc )
add_vehicle_test( test_dlopen_engine ./test_dlopen_engine.cc )
target_link_libraries( test_dlopen_engine ${CMAKE_DL_LIBS} )
# -------------------------------------------------------------------




# ===== smoke tests =================================================

# make sure the examples run without problems

if( RUN_SMOKE_TESTS )

    add_vehicle_stest( test_engine_constructor )
    add_vehicle_stest( test_vehicle_constructor )
    add_vehicle_stest( test_vehicle_copy )
    add_vehicle_stest( test_vstore )
    add_vehicle_stest( test_polymorphism )
    add_vehicle_stest( test_dlopen_engine )

endif( RUN_SMOKE_TESTS )




# ===== unit tests ==================================================

# with unit tests it is possible to test each single method from the
# Vehicle library API (requires some effort)

if( RUN_UNIT_TESTS )

    add_vehicle_test( utest_hello ./utest_hello.cc )
    add_vehicle_utest( utest_hello )

    add_vehicle_test( utest_engine ./utest_engine.cc )
    add_vehicle_utest( utest_engine )

    add_vehicle_test( utest_motorbike ./utest_motorbike.cc )
    add_vehicle_utest( utest_motorbike )

endif( RUN_UNIT_TESTS )




# ===== memory tests ================================================

# memory tests help finding memory leaks in your project

if( RUN_MEMORY_TESTS )

    add_vehicle_test( test_memory_leak ./test_memory_leak )
    add_vehicle_mtest( test_memory_leak )
    set_tests_properties( mt_test_memory_leak PROPERTIES WILL_FAIL TRUE )

    add_vehicle_mtest( test_engine_constructor )
    add_vehicle_mtest( test_vehicle_constructor )
    add_vehicle_mtest( test_vehicle_copy )
    add_vehicle_mtest( test_vstore )
    add_vehicle_mtest( test_polymorphism )

    # due to a bug in older versions of valgrind, this test might fail..
    #add_vehicle_mtest( test_dlopen_engine )
    #set_tests_properties( mt_test_dlopen_engine PROPERTIES WILL_FAIL TRUE )

    if( RUN_UNIT_TESTS )

        add_vehicle_mtest( utest_hello )
        add_vehicle_mtest( utest_engine )
        add_vehicle_mtest( utest_motorbike )

    endif( RUN_UNIT_TESTS )

endif( RUN_MEMORY_TESTS )




# ===== static C/C++ code analysis tests ============================

# cppcheck can be helpful to find problems in your project source code

if( RUN_STATIC_ANALYSIS_TESTS )

    add_test( NAME t_cppcheck COMMAND ${cppcheck_executable} ${PROJECT_SOURCE_DIR}/vehicle )

    set_tests_properties( t_cppcheck PROPERTIES
        FAIL_REGULAR_EXPRESSION "(error)"
    )

endif( RUN_STATIC_ANALYSIS_TESTS )

