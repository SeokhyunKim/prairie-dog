#ifndef _PRDOG_AGENTVECTORCREATOR_HPP_
#define _PRDOG_AGENTVECTORCREATOR_HPP_

namespace prdog {

    class AgentVectorCreator {
        public:
            virtual vector<Agent::sptr> create(map<string, real> params) = 0;
    };

}; // end of prdog

#endif
