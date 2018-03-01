#ifndef _PRDOG_AGENT_H_
#define _PRDOG_AGENT_H_

#include "prdog_common.h"

namespace prdog {

    class Agent {
        public:
            virtual real getValue(const string& key) = 0;
            virtual void update(real dt, real curTime) = 0;
    };

}; // end of prdog

#endif
