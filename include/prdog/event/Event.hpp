#ifndef _PRDOG_EVENT_HPP_
#define _PRDOG_EVENT_HPP_

#include "../etc/prdog_commons.hpp"
#include "EventType.hpp"

namespace prdog {

    class Event {
        public:
            typedef shared_ptr<Event> sptr;

            Event() : mTime(0) {}
            Event(real t) : mTime(t) {}
            virtual ~Event() {}

            real getTime() const { return mTime; }

            virtual EventType getEventType() const = 0;

            virtual string toString() const = 0;

        protected:
            real mTime;
    };

}; // end of prdog

#endif
