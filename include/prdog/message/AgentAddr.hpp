#ifndef _PRDOG_AGENTADDR_HPP_
#define _PRDOG_AGENTADDR_HPP_

#include "HostAddr.hpp"

namespace prdog {

    class AgentAddr {
        public:
            AgentAddr(int id) { mId = id; }

            int getId() const { return mId; }
            string getAlias() const { return mAlias; }

        private:
            HostAddr mHostAddr;
            int mId;
            string mAlias;
    };

}; // end of prdog

#endif
