#ifndef _PRDOG_HOSTADDR_HPP_
#define _PRDOG_HOSTADDR_HPP_

#include "../etc/prdog_commons.hpp"

namespace prdog {

    class HostAddr {
        public:
            HostAddr() {}

            string getName() const { return _name; }
            void setName(const string& name) { _name = name; }

        private:
            string _name;
    };

}; // end of prdog

#endif
