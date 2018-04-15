#ifndef _PRDOG_INTERNAL_COMMONS_HPP_
#define _PRDOG_INTERNAL_COMMONS_HPP_

#include <prdog/etc/prdog_commons.hpp>

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
#include <stdexcept>
#include <stdint.h>

#include <cereal/archives/binary.hpp>
#include <c-log/log.h>
#include <c-log/macro_define.h>

#include "prdog_utils.hpp"
#include <prdog/agent/Agent.hpp>
#include <prdog/event/Event.hpp>
#include <prdog/event/UpdateSimEvent.hpp>
#include <prdog/message/StringMessage.hpp>
#include <prdog/etc/ParamMap.hpp>

namespace prdog {

    using namespace std;

    typedef unsigned int uint;
    typedef uint32_t address_t;

};

#endif
