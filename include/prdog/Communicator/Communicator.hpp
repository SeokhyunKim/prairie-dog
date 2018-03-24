#ifndef _PRDOG_COMMUNICATOR_HPP_
#define _PRDOG_COMMUNICATOR_HPP_

#include <prdog/Communicator/Msg.hpp>
#include <prdog/Communicator/MsgBox.hpp>
#include <prdog/Agent/Agent.hpp>

namespace prdog {

    class Communicator {
        public:
            typedef unique_ptr<Communicator> uptr;

            Communicator(vector<Agent::sptr>& agents);
            ~Communicator();

            void initialize(map<string, real> params);

            void send(AgentAddr addr, Msg msg);

        private:
            vector<Agent::sptr> mAgents;
            vector<MsgBox::uptr> mMsgBoxes;
            vector<Msg> mMsgHeap;
            real mDelayMean, mDelayStddev;
    };

}; // end of prdog

#endif
