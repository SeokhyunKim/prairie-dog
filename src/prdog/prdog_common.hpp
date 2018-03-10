#ifndef _PRDOG_COMMON_H_
#define _PRDOG_COMMON_H_

#include <prdog/prdog.hpp>

#include <list>
#include <vector>
#include <string>
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
#include <c-log/log.h>
#include <c-log/macro_define.h>

namespace prdog {

    using namespace std;

    typedef unsigned int uint;
    typedef uint32_t address_t;

};

#endif
