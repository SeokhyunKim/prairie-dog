#ifndef _PRDOG_DISCRETTIMERUNNER_HPP_
#define _PRDOG_DISCRETTIMERUNNER_HPP_

#include "Runner.hpp"

namespace prdog {

    class Runner;

    class DiscretTimeRunner : public Runner {
        public:
            DiscretTimeRunner();

            void initialize(const map<string, real>& params);
            void run(real dt);

        private:
            real mTimeStep;
    };

}; // end of prdog

#endif
