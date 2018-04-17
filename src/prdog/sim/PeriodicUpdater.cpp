#include "PeriodicUpdater.hpp"
#include <prdog/sim/SimMediator.hpp>

using namespace prdog;

PeriodicUpdater::PeriodicUpdater(real period)
: mPeriod(period), mNextTime(0) {
}

void PeriodicUpdater::initialize(const AgentAddr& addr, const ParamMap& params) {
}

void PeriodicUpdater::update(SimMediator& simMediator) {
    mNextTime = simMediator.getCurTime() + mPeriod;
}
            
Event::sptr PeriodicUpdater::getNextEvent() {
    return Event::sptr(new UpdateSimEvent(mNextTime));
}

void PeriodicUpdater::onMessage(Message::sptr) {
}
