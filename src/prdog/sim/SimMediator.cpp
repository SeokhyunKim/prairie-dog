#include <prdog/sim/SimMediator.hpp>
#include <prdog/sim/Sim.hpp>

using namespace prdog;

SimMediator::SimMediator(Sim& sim)
: mSim(sim), mDeltaTime(0) {
}

real SimMediator::getCurTime() const {
    return mSim.getCurTime();
}

void SimMediator::sendMessage(Message::sptr msg) {
    mSim.sendMessage(msg);
}
