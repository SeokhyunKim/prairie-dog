#ifndef _PRDOG_UPDATESIMEVENT_HPP_
#define _PRDOG_UPDATESIMEVENT_HPP_

#include "Event.hpp"

namespace prdog {

    class UpdateSimEvent : public Event {
        public:
            UpdateSimEvent() : Event() {}
            UpdateSimEvent(real t) : Event(t) {}

            EventType getEventType() const {
                return UPDATE_SIM;
            }

            string toString() const;
    };

}; // end of prdog

#endif
