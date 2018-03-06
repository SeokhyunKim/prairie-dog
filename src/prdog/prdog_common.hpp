#ifndef _PRDOG_COMMON_H_
#define _PRDOG_COMMON_H_

#include <list>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <memory>
#include <random>
#include <exception>
#include <stdint.h>

#include <cereal/archives/binary.hpp>

namespace prdog {

    using namespace std;

    typedef float real;
    typedef unsigned char byte;
    typedef unsigned int uint;
    typedef uint32_t address_t;

    const int null = 0;
    
    typedef shared_ptr< vector<byte> > ByteVect;

};

#endif
