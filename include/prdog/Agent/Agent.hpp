#ifndef _PRDOG_AGENT_HPP_
#define _PRDOG_AGENT_HPP_

namespace prdog {

    class SimContext;

    class Agent {
        public:
            virtual void initialize(const map<string, real>& params) = 0;
            virtual real getValue(const string& key) = 0;
            virtual void update(real dt, SimContext& context) = 0;
    };

    typedef shared_ptr<Agent> AgentPtr;

}; // end of prdog

#endif
