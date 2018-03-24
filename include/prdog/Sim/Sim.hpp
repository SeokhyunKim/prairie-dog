#ifndef _PRDOG_SIM_HPP_
#define _PRDOG_SIM_HPP_

#include "../Agent/AgentVectorCreator.hpp"
#include "../Runner/DiscretTimeRunner.hpp"
#include "../Communicator/Communicator.hpp"
#include "SimContext.hpp"

namespace prdog {

    class Sim {
        public:
            Sim(AgentVectorCreator::uptr creator,
                Runner::uptr runner = Runner::uptr(new DiscretTimeRunner));
            ~Sim();

            void initialize(map<string, real> params, Runner::uptr runner);
            void clear();

            void run(real dt);
            
            int getSums(list<string>& keys, map<string, real>& sums);
            int getVars(list<string>& keys, map<string, real>& vars);

            real getCurTime() { return mCurTime; }

            Communicator& getCommunicator() { return *mComm; }

        private:
            real mCurTime;
            vector<Agent::sptr> mAgents;
            AgentVectorCreator::uptr mAgentVectorCreator;
            Runner::uptr mRunner;
            Communicator::uptr mComm;
            SimContext::uptr mSimContext;
    };

}; // end of prdog

#endif
