#include <prdog/message/Message.hpp>

using namespace prdog;

Message::Message(int code, real sendTime, const AgentAddr& from, const AgentAddr& to) 
: mMsgCode(code), mSendTime(sendTime), mFrom(from), mTo(to) {

}

string Message::toString() const {
    char buf[64];
    sprintf(buf, "Message(code:%d, sendTime:%.2f)", mMsgCode, mSendTime);
    return string(buf);
}
