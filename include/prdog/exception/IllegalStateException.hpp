#ifndef _PRDOG_ILLEGALSTATEEXCEPTION_HPP_
#define _PRDOG_ILLEGALSTATEEXCEPTION_HPP_

#include <stdexcept>
#include <string>

namespace prdog {

    using namespace std;

    class IllegalStateException : public runtime_error {
        public:
            explicit IllegalStateException(const string& msg)
                : runtime_error(msg) {}
            explicit IllegalStateException(const char* msg)
                : runtime_error(msg) {}
    };

}; // end of prdog

#endif
