#ifndef _PRDOG_PARAMKEY_HPP_
#define _PRDOG_PARAMKEY_HPP_

#include <string>

namespace prdog {

    using namespace std;

    class ParamKey {
        public:
            static const string NUM_AGENTS;
            static const string UPDATE_PERIOD;
            static const string LOG_LEVEL;
            static const string MESSAGE_DELAY;
    };

}; // end of prdog

#endif
