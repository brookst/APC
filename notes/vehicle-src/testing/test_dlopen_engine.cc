#include "engine.h"
#include <iostream>
#include <unistd.h>
#include <dlfcn.h>

using namespace std;

int Engine::globalCounter=5;

int main()
{
    // http://pubs.opengroup.org/onlinepubs/009695399/functions/dlopen.html
    //void* libPointer = dlopen( "libvehicle.so" , RTLD_LAZY | RTLD_GLOBAL );
    //void* libPointer = dlopen( "libvehicle.so" , RTLD_NOW | RTLD_GLOBAL );
    //void* libPointer = dlopen( "libvehicle.so" , RTLD_NOW | RTLD_LOCAL );
    void* libPointer = dlopen( "libvehicle.so" , RTLD_LAZY | RTLD_LOCAL );

    if( libPointer == 0 )
    {
        cerr << "Error loading libvehicle.so: " << dlerror() << endl;
        return 1;
    }
    else
    {
        cout << "libvehicle.so loaded successfully" << endl;
    }

    Engine g ( "kawasaki", 3 );

    cout << endl;

    for( int i=0; i<3; i++ )
    {
        ++g.globalCounter;
        cout << g.globalCounter << " ";
        //sleep(1);
    }

    cout << endl;

    dlclose( libPointer );

    return 0;
}

