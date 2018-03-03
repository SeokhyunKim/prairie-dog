#ifndef _PRDOG_AGENTADDRESS_H_
#define _PRDOG_AGENTADDRESS_H_

#include "prdog_common.hpp"

namespace prdog {

    class AgentAddress {
        public:
            AgentAddress(int id);

            int getId() const { return _id; }

        private:
            HostAddress _hostAddr;
            int _id;
            string _alias;
    };

}; // end of prdog

#endif
