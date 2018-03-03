#ifndef _PRDOG_COMMON_H_
#define _PRDOG_COMMON_H_

#include <list>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <memory>
#include <stdint.h>

#include <cereal/archives/binary.hpp>

namespace prdog {

    using namespace std;

    typedef float real;
    typedef unsigned char byte;
    typedef unsigned int uint;
    typedef uint32_t address_t;

    const int null = 0;

};

#endif
