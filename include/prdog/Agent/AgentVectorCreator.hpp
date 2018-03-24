#ifndef _PRDOG_AGENTVECTORCREATOR_HPP_
#define _PRDOG_AGENTVECTORCREATOR_HPP_

#include "Agent.hpp"

namespace prdog {

    class AgentVectorCreator {
        public:
            typedef unique_ptr<AgentVectorCreator> uptr;

            virtual vector<Agent::sptr> create(map<string, real> params) = 0;
    };

}; // end of prdog

#endif
