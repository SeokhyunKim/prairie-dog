#ifndef _PRDOG_RUNNER_HPP_
#define _PRDOG_RUNNER_HPP_

#include "../etc/prdog_commons.hpp"

namespace prdog {

    class Runner {
        public:
            typedef unique_ptr<Runner> uptr;

            virtual void initialize(const map<string, real>& params) = 0;

            virtual void run(real dt) = 0;

    };

}; // end of prdog

#endif
