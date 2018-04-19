#ifndef _PRDOG_PERIODICUPDATER_HPP_
#define _PRDOG_PERIODICUPDATER_HPP_

#include "../etc/prdog_internal_commons.hpp"

namespace prdog {

    class PeriodicUpdater : public Agent {
        public:
            PeriodicUpdater(real period);

            void initialize(const AgentAddr& addr, const ParamMap& params);

            void update(SimMediator&);
            
            list<Event::sptr> getNextEvents();

            void onMessage(Message::sptr);

        private:
            real mPeriod, mNextTime;
    };

}; // end of prdog

#endif
