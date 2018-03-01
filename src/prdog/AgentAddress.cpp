#include "AgentAddress.h"

using namespace prdog;


AgentAddress::AgentAddress() {
}

AgentAddress::AgentAddress(const AgentAddress& add) {
    address = add.address;
    name = add.name;
}

AgentAddress::AgentAddress(address_t add) {
    address = add;
    name = "";
}

AgentAddress::AgentAddress(address_t _add, string _name) {
    address = _add;
    name = _name;
}
