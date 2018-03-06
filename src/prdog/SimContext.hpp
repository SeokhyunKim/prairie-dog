#ifndef _PRDOG_SIMCONTEXT_HPP_
#define _PRDOG_SIMCONTEXT_HPP_

#include "prdog_common.hpp"

namespace prdog {

    class SimContext {
        public:
            SimContext();
            ~SimContext();

            real getCurTime() const { return _curTime; }
            weak_ptr<Msg> getMsg() const { return _msg; }

        private:
            friend class Sim;

            real _curTime;
            weak_ptr<Msg> _msg;
    };

}; // end of prdog

#endif
