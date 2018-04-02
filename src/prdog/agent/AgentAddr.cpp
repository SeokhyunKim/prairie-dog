#include <prdog/agent/AgentAddr.hpp>

AgentAddr::AgentAddr(const AgentAddr& rhs) {
    mHostAddr = rhs.mHostAddr;
    mId = rhs.mId;
    mAlias = rhs.mAlias;
}
    

