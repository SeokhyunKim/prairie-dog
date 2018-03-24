#ifndef _PRDOG_MSGBOX_HPP_
#define _PRDOG_MSGBOX_HPP_

#include <prdog/Communicator/Msg.hpp>
#include <prdog/Communicator/ByteVect.hpp>

namespace prdog {

    class Communicator;

    class MsgBox {
        public:
            typedef unique_ptr<MsgBox> uptr;
            MsgBox(int id, Communicator&);

            int getId() const { return mId; }
            list<Msg> getReceivedMsgs() const;
            void sendMsg(const AgentAddr&, const Msg&);

        private:
            friend class Communicator;

            int mId;
            list<Msg> mReceivedMsgs;
            Communicator& mComm;
    };

}; // end of prdog

#endif
