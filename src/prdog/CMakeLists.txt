add_library(prdog SHARED
    Sim.cpp
    SimContext.cpp
)

target_link_libraries(prdog agent communicator runner)
