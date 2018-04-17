#ifndef _PRDOG_AGENTADDR_HPP_
#define _PRDOG_AGENTADDR_HPP_

#include "HostAddr.hpp"

namespace prdog {

    class AgentAddr {
        public:
            AgentAddr() : mHostAddr("localhost"), mId(-1) {}
            AgentAddr(int id) : mHostAddr("localhost") { mId = id; }

            int getId() const { return mId; }
            string getAlias() const { return mAlias; }
            string toString() const;

        private:
            HostAddr mHostAddr;
            int mId;
            string mAlias;
    };

}; // end of prdog

#endif
