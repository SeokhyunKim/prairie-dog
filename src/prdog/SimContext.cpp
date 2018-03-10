#include <prdog/prdog.hpp>

using namespace prdog;

SimContext::SimContext(Sim& sim) : mSim(sim) {
}

SimContext::~SimContext() {
}

real SimContext::getCurTime() {
    return mSim.getCurTime();
}

Communicator& SimContext::getCommunicator() {
    return mSim.getCommunicator();
}
