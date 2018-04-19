#include <prdog/message/AgentAddr.hpp>

using namespace prdog;

string AgentAddr::toString() const {
    return mHostAddr.toString() + ": " + to_string(mId);
}
