cmake_minimum_required (VERSION 3.9.4)
project (prairie-dog)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++14" COMPILER_SUPPORTS_CXX14)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX14)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
    message("## The compiler ${CMAKE_CXX_COMPILER} supports c++14.")
elseif(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    message("## The compiler ${CMAKE_CXX_COMPILER} supports c++11.")
#elseif(COMPILER_SUPPORTS_CXX0X)
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message("## The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

include_directories("$ENV{CEREAL_HOME}/include")
message("## Cereal include directory: $ENV{CEREAL_HOME}/include")
include_directories("$ENV{BOOST_ROOT}")
message("## Boost root directory: $ENV{BOOST_ROOT}")

include_directories("include" "include/prdog")

add_subdirectory(src/prdog)

add_subdirectory(examples)
