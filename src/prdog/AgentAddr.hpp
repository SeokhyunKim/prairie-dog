#ifndef _PRDOG_AGENTADDR_HPP_
#define _PRDOG_AGENTADDR_HPP_

#include "prdog_common.hpp"

namespace prdog {

    class AgentAddr {
        public:
            AgentAddr(int id);

            int getId() const { return _id; }

        private:
            HostAddr _hostAddr;
            int _id;
            string _alias;
    };

}; // end of prdog

#endif
