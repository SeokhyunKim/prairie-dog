#ifndef _PRDOG_UTILS_HPP_
#define _PRDOG_UTILS_HPP_

#include "prdog_commons.hpp"
#include "../event/Event.hpp"

namespace prdog {
    using namespace std;

    // string to real
    real strToReal(const string& s);

    // real to string
    string realToStr(real v);

    // validation function. if not true, throw IllegalStateException
    void validate(bool condition, const string& msg);

    // print out event vector. mainly for debugging
    void logDebugEvents(const vector<Event::sptr>& events);

}; // end of prdog

#endif
