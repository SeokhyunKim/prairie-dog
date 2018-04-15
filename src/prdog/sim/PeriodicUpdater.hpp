#ifndef _PRDOG_PERIODICUPDATER_HPP_
#define _PRDOG_PERIODICUPDATER_HPP_

#include "../etc/prdog_internal_commons.hpp"

namespace prdog {

    class PeriodicUpdater : public Agent {
        public:
            PeriodicUpdater(real period);

            void initialize(const ParamMap& params);

            void update(SimMediator&);
            
            Event::sptr getNextEvent();

            void onMessage(Message::sptr);

        private:
            real mPeriod, mNextTime;
    };

}; // end of prdog

#endif
