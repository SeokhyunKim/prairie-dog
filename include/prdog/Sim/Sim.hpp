#ifndef _PRDOG_SIM_HPP_
#define _PRDOG_SIM_HPP_

#include "../agent/AgentImpl.hpp"
#include "../message/StringMessage.hpp"
#include "../event/Event.hpp"
#include "SimMediator.hpp"

namespace prdog {

    class Sim {
        public:
            Sim();
            ~Sim();

            template<typename T>
            void initialize(const ParamMap& params) {
                _initialize(params, AgentImpl<T>::createAgent);
            }

            real getCurTime() const { return mCurTime; }
            void sendMessage(Message::sptr);
            void run(real deltaT);

        private:
            typedef Agent::sptr (*CREATE_AGENT_FN)();
            void _initialize(const ParamMap& params, CREATE_AGENT_FN);
            void updateCurTime();
            void processNextEvent();

        private:
            real mCurTime;
            int mNumAgents;
            bool mStopSim;
            real mMsgDelay;
            SimMediator mSimMediator;
            vector<Agent::sptr> mAgents;
            vector<Event::sptr> mEvents;
    };

}; // end of prdog

#endif
