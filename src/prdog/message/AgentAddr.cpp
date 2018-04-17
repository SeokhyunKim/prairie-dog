#include <prdog/message/AgentAddr.hpp>

using namespace prdog;

/*
AgentAddr::AgentAddr(const AgentAddr& rhs) {
    this->mHostAddr = rhs.mHostAddr;
    this->mId = rhs.mId;
    this->mAlias = rhs.mAlias;
}*/

string AgentAddr::toString() const {
    return mHostAddr.toString() + ": " + to_string(mId);
}
