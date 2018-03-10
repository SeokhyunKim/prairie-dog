add_library(prdog SHARED
    Sim.cpp
    SimContext.cpp
)

add_subdirectory(Agent)
add_subdirectory(Communicator)
add_subdirectory(Runner)

target_link_libraries(prdog agent communicator runner)
