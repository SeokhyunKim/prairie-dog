#include "../prdog_common.hpp"

using namespace prdog;

namespace std {
    static std::mt19937 sMt((std::random_device())());
};

Communicator::Communicator(vector<Agent::sptr>& agents) {
    mAgents = agents;
    mMsgBoxes.reserve(mAgents.size());
    int sz = mAgents.size();
    for (int i=0; i<sz; ++i ) {
        mMsgBoxes.push_back(MsgBox::uptr(new MsgBox(i, *this)));
    }
}

Communicator::~Communicator() {
}

void Communicator::initialize(map<string, real> params) {
    mDelayMean = params["delayMean"];
    mDelayStddev = params["delayStddev"];
}

void Communicator::send(AgentAddr addr, Msg msg) {
    // TODO: consider when addr._hostAddr is remote later
    
    // TODO: based on _delayMean and _delayStddev, calculate arvTime.
    // put into _msgHeap
    // implement method to pop messages before a give time point

}

