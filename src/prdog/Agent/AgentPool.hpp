#ifndef _PRDOG_AGENTPOOL_HPP_
#define _PRDOG_AGENTPOOL_HPP_

#include <prdog_common.hpp>

namespace prdog {

    class AgentPool {
        public:
            AgentPool(vector<shared_ptr<Agent> >);
            ~AgentPool();

            shared_ptr<Agent> getAgent(int id);
            Agent& getAgent(int id);

        private:
            void checkAgentIndex(int id);

        private:
            vector<shared_ptr<Agent> > _agents;
    };

}; // end of prdog

#define
