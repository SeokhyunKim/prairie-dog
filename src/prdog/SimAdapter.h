#ifndef _PRDOG_SIMADAPTER_H_
#define _PRDOG_SIMADAPTER_H_

#include "prdog_common.h"

namespace prdog {

    class SimAdapter {
        public:
            SimAdapter();
            ~SimAdapter();
            real getCurTime() const { return curTime; }

        private:
            real curTime;
    };

}; // end of prdog

#endif
