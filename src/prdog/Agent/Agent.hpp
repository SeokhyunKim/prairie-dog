#ifndef _PRDOG_AGENT_H_
#define _PRDOG_AGENT_H_

#include <prdog_common.hpp>

namespace prdog {

    class Agent {
        public:
            virtual real getValue(const string& key) = 0;
            virtual void update(real dt, SimContext& context) = 0;
    };

}; // end of prdog

#endif
