#include <prdog/message/StringMessage.hpp>

using namespace prdog;

StringMessage::StringMessage(int code, real sendTime, const AgentAddr& from, const AgentAddr& to, const string& msg)
: Message(code, sendTime, from, to), mMsg(msg) {
}
