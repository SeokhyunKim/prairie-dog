#include <prdog/event/UpdateSimEvent.hpp>
#include "../etc/prdog_internal_commons.hpp"

using namespace prdog;

string UpdateSimEvent::toString() const {
    return string("UPDATE_SIM at ") + realToStr(getTime());
}
