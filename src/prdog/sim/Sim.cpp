#include <prdog/sim/Sim.hpp>
#include "PeriodicUpdater.hpp"
#include "../etc/prdog_internal_commons.hpp"

using namespace prdog;

namespace prdog {
    static const real DEFAULT_MESSAGE_DELAY = 0.1;
};

Sim::Sim()
: mCurTime(0), mNumAgents(0), mStopSim(false), mMsgDelay(DEFAULT_MESSAGE_DELAY),
  mSimMediator(*this) {
}

Sim::~Sim() {
}

void Sim::_initialize(const ParamMap& params, CREATE_AGENT_FN caFn) {
    // init log
    int logLevel = params.getInt(ParamKey::LOG_LEVEL);
    if (logLevel < 1 || logLevel > 5) {
        logLevel = (int)LL_NOTICE;
    }
    log_init((LogLevel)logLevel, "prdog", "./log");

    // create agents
    mNumAgents = params.getInt(ParamKey::NUM_AGENTS);
    if (mNumAgents <= 0) {
        throw std::invalid_argument("Tried to create 0 or negative arguments.");
    }
    LOG_NOTICE("Start Prairie-dog -------------------------------------------");
    LOG_NOTICE("Number of agents: %d", mNumAgents);
    mAgents.clear();
    mAgents.reserve(mNumAgents);
    int numAgents = mNumAgents;
    while (numAgents-- > 0) {
        mAgents.push_back((*caFn)());
    }
    LOG_NOTICE("Agent vector size: %d", mAgents.size());
    LOG_NOTICE("Calling initialize per each agent...");
    for (int i=0; i<mNumAgents; ++i) {
        mAgents[i]->initialize(AgentAddr(i), params);
    }

    // the first sim update event
    mEvents.push_back(Event::sptr(new UpdateSimEvent));

    // adding fixed time updater
    real updatePeriod = params.getReal(ParamKey::UPDATE_PERIOD);
    LOG_NOTICE("Update period: %f", updatePeriod);
    if (updatePeriod > 0) {
        mAgents.push_back(Agent::sptr(new PeriodicUpdater(updatePeriod)));
        LOG_DEBUG("PeriodicUpdater is added. mAgents.size(): %d", mAgents.size());
    }

    // set message delay
    mMsgDelay = params.getReal(ParamKey::MESSAGE_DELAY);
    if (mMsgDelay <= 0) {
        mMsgDelay = DEFAULT_MESSAGE_DELAY;
    }
    LOG_NOTICE("Message delay: %f", mMsgDelay);
}

class EventCompare {
    public:
        bool operator()(const Event::sptr& a, const Event::sptr& b) {
            return a->getTime() >= b->getTime();
        }
};

void Sim::sendMessage(Message::sptr msg) {
    // later, will consider delay based on several statistic model.
    // currently, just add the delay value given by initial parameter.
    msg->setArrivalTime(msg->getSendTime() + mMsgDelay);
    LOG_DEBUG("Send message: %s", msg->toString().c_str());
    mEvents.push_back(static_pointer_cast<Event>(msg));
    push_heap(mEvents.begin(), mEvents.end(), EventCompare());
}

void Sim::run(real deltaT) {
    if (deltaT <= 0) {
        throw std::invalid_argument("Sim::run must be called with positive deltaT.");
    }
    real targetTime = mCurTime + deltaT;
    LOG_DEBUG("target time: %f", targetTime);
    LOG_DEBUG("mEvents.size(): %d", mEvents.size());
    
    while (!mStopSim && mEvents.size() > 0 && mEvents.front()->getTime() <= targetTime) {
        updateCurTime();
        processNextEvents();

        // Update agents
        for (auto& a : mAgents) {
            a->update(mSimMediator);
            list<Event::sptr> evts = a->getNextEvents();
            for (auto& evt : evts) {
                if (evt.get() != nullptr) {
                    mEvents.push_back(evt);
                    push_heap(mEvents.begin(), mEvents.end(), EventCompare());
                }
            }
        }
    }
}

// Calculate next curTime and dt based on next event time 
void Sim::updateCurTime() {
    Event::sptr evt = mEvents.front();
    real evtTime = evt->getTime();
    validate(evtTime >= mCurTime, "event time is past of cur time.");
    real dt = evtTime - mCurTime;
    mSimMediator.setDeltaTime(dt);
    mCurTime = evtTime;
    LOG_DEBUG("Processing event: (%s)", evt->toString().c_str());
    LOG_DEBUG("Cur time: %.2f, dt: %.2f", mCurTime, dt);
}

// Do additional task according to event type
void Sim::processNextEvents() {
    while(mEvents.size() > 0) {
        Event::sptr evt = mEvents.front();
        if (evt->getTime() > mCurTime) {
            break;
        }
        switch (evt->getEventType()) {
            case EventType::MESSAGE: {
                Message::sptr msg = dynamic_pointer_cast<Message>(evt);
                const AgentAddr& rcv = msg->getReceiver();
                validate(rcv.getId()>=0 && rcv.getId()<mNumAgents,
                    "A message has an invalid receiver: (" + msg->toString() + ")");
                mAgents[rcv.getId()]->onMessage(msg);
            }
            break;
            case EventType::EXIT_SIM: {
                mStopSim = true;
            }
            break;
            // no additional task
            case EventType::UPDATE_SIM:
            break;
        }
        // Remove processed event
        pop_heap(mEvents.begin(), mEvents.end(), EventCompare());
        mEvents.pop_back();
    }
}
