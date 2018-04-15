#ifndef _PRDOG_MESSAGE_HPP_
#define _PRDOG_MESSAGE_HPP_

#include "../event/Event.hpp"
#include "AgentAddr.hpp"

namespace prdog {

    class Message : public Event {
        public:
            typedef shared_ptr<Message> sptr;
            enum Type { STRING, DATA };

            Message(int code, real sendTime, const AgentAddr& from, const AgentAddr& to);

            virtual Type getMessageType() const = 0;

            real getSendTime() const { return mSendTime; }
            real getArrivalTime() const { return getTime(); }
            void setArrivalTime(real t) { mTime = t; }

            const AgentAddr& getSender() const { return mFrom; }
            const AgentAddr& getReceiver() const { return mTo; }

            string toString() const;

        protected:
            int mMsgCode;
            real mSendTime;
            AgentAddr mFrom, mTo;
    };

}; // end of prdog

#endif
