#include "AgentPool.hpp"

using namespace prdog;

AgentPool::AgentPool(vector<shared_ptr<Agent> > agents) {
    _agents.reserve(agents.size());
    copy(agents.begin(), agents.end(), _agents.begin());
    _agents.shrink_to_fit();
}

AgentPool::~AgentPool() {
    _agents.clear();
}

shared_ptr<Agent> AgentPool::getAgent(int id) {
    checkAgentIndex(id);
    return _agents[id];
}

Agent& AgentPool::getAgent(int id) {
    checkAgentIndex(id);
     return *_agents[id];
}

void AgentPool::checkAgentIndex(int id) {
    if (id<0 || id>=_agents.size()) {
        throw runtime_error("invalid getAgent index: " + to_string(id));
    }
}



