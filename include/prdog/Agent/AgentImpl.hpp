#ifndef _PRDOG_AGENTIMPL_HPP_
#define _PRDOG_AGENTIMPL_HPP_

#include "Agent.hpp"
#include "../event/Event.hpp"

namespace prdog {

    template<typename T>
    class AgentImpl : public Agent {
        public:
            void initialize(const AgentAddr& selfAddr, const ParamMap& params) {
                mUserAgent->initialize(selfAddr, params);
            }
            
            void update(SimMediator& simMediator) {
                mUserAgent->update(simMediator);
            }

            list<Event::sptr> getNextEvents() {
                return mUserAgent->getNextEvent();
            }

            void onMessage(Message::sptr ptr) {
                mUserAgent->onMessage(ptr);
            }

            static Agent::sptr createAgent() {
                return Agent::sptr(new AgentImpl<T>());
            }

        private:
            AgentImpl() {
                mUserAgent = make_unique<T>();
            }

        private:
            unique_ptr<T> mUserAgent;
    };

}; // end of prdog

#endif
