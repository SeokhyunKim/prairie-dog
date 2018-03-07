#include "Communicator.hpp"

using namespace prdog;

Communicator::Communicator(Sim& sim, real delayMean, real delayStddev)
    : _sim(sim), _mt((std::random_device())()),
    _delayMean(delayMean), _delayStddev(delayStddev) {
}

Communicator::~Communicator() {
}

void Communicator::send(AgentAddr addr, ByteVect msg) {
    // TODO: consider when addr._hostAddr is remote later

    //Msg newMsg;
    //newMsg.sentTime = 
    //_msgHeap.push_back
    //
}

