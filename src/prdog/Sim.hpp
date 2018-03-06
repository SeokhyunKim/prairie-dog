#ifndef _PRDOG_SIM_HPP_
#define _PRDOG_SIM_HPP_

#include "prdog_common.hpp"

namespace prdog {

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
            unique_prr<Msg> _msg;
            unique_ptr<SimContext> _simContext;

    };

}; // end of prdog

#endif
