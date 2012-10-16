add_definitions( -Wall -ansi -pedantic )

# ====== library ================================

aux_source_directory( ./ vehicle_sources )
#add_library( vehicle STATIC ${vehicle_sources} )
add_library( vehicle SHARED ${vehicle_sources} )

