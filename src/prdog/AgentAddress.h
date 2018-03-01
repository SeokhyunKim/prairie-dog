#ifndef _PRDOG_AGENTADDRESS_H_
#define _PRDOG_AGENTADDRESS_H_

#include "prdog_common.h"

namespace prdog {

    class AgentAddress {
        public:
            AgentAddress();
            AgentAddress(const AgentAddress&);
            AgentAddress(address_t);
            AgentAddress(address_t, string);

            address_t getAddress() const { return address; }
            string getName() const { return name; }

        private:
            address_t address;
            string name;
    };

}; // end of prdog

#endif
