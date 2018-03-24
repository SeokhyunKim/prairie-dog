#include <prdog/Communicator/MsgBox.hpp>
#include <prdog/Communicator/Communicator.hpp>

using namespace prdog;

MsgBox::MsgBox(int id, Communicator& comm) : mId(id), mComm(comm) {
}

list<Msg> MsgBox::getReceivedMsgs() const {
    return mReceivedMsgs;
}

void MsgBox::sendMsg(const AgentAddr& addr, const Msg& msg) {
    mComm.send(addr, msg);
}
