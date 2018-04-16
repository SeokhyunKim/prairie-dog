#ifndef _PRDOG_SIMPLEMESSAGE_HPP_
#define _PRDOG_SIMPLEMESSAGE_HPP_

#include "Message.hpp"

namespace prdog {

    class StringMessage : public Message {
        public:
            typedef shared_ptr<StringMessage> sptr;

            StringMessage(int code, real sendTime, const AgentAddr& from, const AgentAddr& to, const string& msg);

            Type getMessageType() const { return Message::Type::STRING; }

            string getMessage() const { return mMsg; }

        protected:
            string mMsg;
    };

}; // end of prdog

#endif
