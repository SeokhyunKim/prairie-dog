#ifndef _PRDOG_HPP_
#define _PRDOG_HPP_

#include <string>
#include <list>
#include <vector>
#include <map>
#include <memory>

namespace prdog {

    using namespace std;

    typedef float real;
    typedef char byte;

    typedef shared_ptr< vector<byte> > ByteVectPtr;

};

#include "Agent/HostAddr.hpp"
#include "Agent/AgentAddr.hpp"
#include "Agent/Agent.hpp"
#include "Agent/AgentVectorCreator.hpp"
#include "Communicator/Communicator.hpp"
#include "Runner/Runner.hpp"
#include "SimContext.hpp"
#include "Sim.hpp"

#endif
