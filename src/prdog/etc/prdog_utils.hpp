#ifndef _PRDOG_UTILS_HPP_
#define _PRDOG_UTILS_HPP_

#include <prdog/etc/prdog_commons.hpp>
#include <prdog/event/Event.hpp>

namespace prdog {
    using namespace std;

    // string to real
    real strToReal(const string& s);

    // real to string
    string realToStr(real v);

    // shared_ptr casting
    template<typename S, typename T>
    shared_ptr<S> sptr_cast(shared_ptr<T> sptr) {
        return shared_ptr<S>(dynamic_cast<S*>(sptr.get()));
    }

    // validation function. if not true, throw IllegalStateException
    void validate(bool condition, const string& msg);

    // print out event vector. mainly for debugging
    void logDebugEvents(const vector<Event::sptr>& events);

}; // end of prdog

#endif
