#ifndef _PRDOG_SIMCONTEXT_HPP_
#define _PRDOG_SIMCONTEXT_HPP_

#include "prdog_common.hpp"

namespace prdog {

    class SimContext {
        public:
            SimContext();
            ~SimContext();

            real getCurTime() const { return _curTime; }
            Communicator& getCommunicator() const { return *_comm; }

        private:
            friend class Sim;

            real _curTime;
            shared_ptr<Communicator> _comm;
    };

}; // end of prdog

#endif
