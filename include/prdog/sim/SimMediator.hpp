#ifndef _PRDOG_SIMMEDIATOR_HPP_
#define _PRDOG_SIMMEDIATOR_HPP_

#include "../message/Message.hpp"

namespace prdog {

    class Sim;

    class SimMediator {
        public:
            SimMediator(Sim& sim);

            real getCurTime() const;

            void setDeltaTime(real t) { mDeltaTime = t; }
            real getDeltaTime() const { return mDeltaTime; }

            void sendMessage(Message::sptr);

        private:
            Sim& mSim;
            real mDeltaTime;
    };

}; // end of prdog

#endif
