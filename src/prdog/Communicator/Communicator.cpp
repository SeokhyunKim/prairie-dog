#include "../prdog_common.hpp"

using namespace prdog;

namespace std {
    static std::mt19937 sMt((std::random_device())());
};

Communicator::Communicator(Sim& sim)
    : mSim(sim) {
}

Communicator::~Communicator() {
}

void Communicator::initialize(map<string, real> params) {
    mDelayMean = params["delayMean"];
    mDelayStddev = params["delayStddev"];
}

void Communicator::send(AgentAddr addr, ByteVectPtr msg) {
    // TODO: consider when addr._hostAddr is remote later
    
    // TODO: based on _delayMean and _delayStddev, calculate arvTime.
    // put into _msgHeap
    // implement method to pop messages before a give time point

}

