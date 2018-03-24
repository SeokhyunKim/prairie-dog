#ifndef _PRDOG_MSG_HPP_
#define _PRDOG_MSG_HPP_

#include "../Agent/AgentAddr.hpp"
#include "ByteVect.hpp"

namespace prdog {

    class Msg {
        public:
            Msg(AgentAddr from, AgentAddr to, ByteVect::sptr msg) :
                mFrom(from), mTo(to), mMsg(msg),
                mSentTime(0), mDelay(0), mArvTime(0) {}

            AgentAddr getFrom() const { return mFrom; }
            AgentAddr getTo() const { return mTo; }
            
            ByteVect::sptr getMsg() const { return mMsg; }

            void setSentTime(real t) { mSentTime = t; }
            real getSentTime() const { return mSentTime; }

            void setDelay(real d) { mDelay = d; }
            real getDelay() const { return mDelay; }

            void setArvTime(real t) { mArvTime = t; }
            real getArvTime() const { return mArvTime; }

        private:
            AgentAddr mFrom, mTo;
            real mSentTime;
            real mDelay;
            real mArvTime;
            ByteVect::sptr mMsg;
    };

}; // end of prdog

#endif
