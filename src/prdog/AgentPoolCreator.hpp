#ifndef _PRDOG_AGENTPOOLCREATOR_HPP_
#define _PRDOG_AGENTPOOLCREATOR_HPP_

#include "prdog_common.hpp"

namespace prdog {

    class AgentPoolCreator {
        public:
            virtual shared_ptr<AgentPool> create(map<string, real> params) = 0;
    };

}; // end of prdog

#endif
