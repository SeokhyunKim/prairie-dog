#ifndef _PRDOG_SIMPLEMESSAGE_HPP_
#define _PRDOG_SIMPLEMESSAGE_HPP_

#include "Message.hpp"

namespace prdog {

    class SimpleMessage : public Message {
        public:
            SimpleMessage(int code, real sendTime, const AgentAddr& from, const AgentAddr& to, const string& msg);

            Type getMessageType() const { return STRING; }

            string getMessage() const { return mMsg; }

        protected:
            string mMsg;
    };

}; // end of prdog

#endif
