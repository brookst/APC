#include "car.h"

#include <iostream>

using namespace std;

int main(void)
{
   
    Car* c = new Car( "BM-F-222", "Ferrari", "Ferrari", 12, 4 ) ;

    cout << *c << endl ;

    // comment out to create memory leak
    //delete c ;

    return 0;
}

