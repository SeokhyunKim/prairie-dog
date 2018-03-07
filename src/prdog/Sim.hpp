#ifndef _PRDOG_SIM_HPP_
#define _PRDOG_SIM_HPP_

#include "Runner/DiscretTimeRunner.hpp"
#include "Agent/AgentPoolCreator.hpp"
#include "Agent/AgentPool.hpp"
#include "Communicator/Communicator.hpp"

namespace prdog {

    template<class RUNNER = DiscretTimeRunner>
    class Sim {
        public:
            Sim(unique_ptr<AgentPoolCreator> creator);
            ~Sim();

            void initialize(map<string, real> params);
            void clear();
            void run(int numSteps, real dt);
            int getSums(list<string>& keys, map<string, real>& sums);
            int getVars(list<string>& keys, map<string, real>& vars);
            real getCurTime() { return _curTime; }

        private:
            real _curTime;
            shared_ptr<AgentPool> _agentPool;
            unique_ptr<AgentPoolCreator> _agentPoolCreator;
            unique_ptr<Communicator> _comm;
            shared_ptr<SimContext> _simContext;

    };

}; // end of prdog

#endif
