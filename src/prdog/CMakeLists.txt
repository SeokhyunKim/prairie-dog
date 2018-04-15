add_library(prdog SHARED
    sim/Sim.cpp
    sim/SimMediator.cpp
    sim/PeriodicUpdater.cpp
)

add_subdirectory(message)
add_subdirectory(etc)
add_subdirectory(event)

target_link_libraries(prdog message etc event clog)
#target_link_libraries(prdog agent communicator runner)
