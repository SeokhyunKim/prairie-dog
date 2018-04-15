#include "prdog_utils.hpp"
#include <prdog/exception/IllegalStateException.hpp>
#include "../etc/prdog_internal_commons.hpp"

using namespace prdog;

real prdog::strToReal(const string& s) {
    double d = stod(s);
    return (real)d;
}

string prdog::realToStr(real v) {
    char buf[512];
    sprintf(buf, "%.2f", v);
    return string(buf);
}

void prdog::validate(bool condition, const string& msg) {
    if (!condition) {
        throw IllegalStateException(msg);
    }
}

void prdog::logDebugEvents(const vector<Event::sptr>& events) {
    string msg;
    for (auto& e : events) {
        msg += e->toString() + "\n";
    }
    LOG_DEBUG("\nevent vector -----------\nevents size: %d\n%s", events.size(), msg.c_str());
}
