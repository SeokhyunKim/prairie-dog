#ifndef _PRDOG_AGENT_HPP_
#define _PRDOG_AGENT_HPP_

#include "../etc/ParamMap.hpp"
#include "../event/Event.hpp"
#include "../message/Message.hpp"
#include "../message/StringMessage.hpp"

namespace prdog {

    class SimMediator;

    class Agent {
        public:
            typedef shared_ptr<Agent> sptr;

            virtual void initialize(const AgentAddr& selfAddr, const ParamMap& params) = 0;

            virtual void update(SimMediator&) = 0;

            virtual Event::sptr getNextEvent() = 0;

            virtual void onMessage(Message::sptr) = 0;
    };

} // end of prdog

#endif
