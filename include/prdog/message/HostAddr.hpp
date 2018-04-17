#ifndef _PRDOG_HOSTADDR_HPP_
#define _PRDOG_HOSTADDR_HPP_

#include "../etc/prdog_commons.hpp"

namespace prdog {

    class HostAddr {
        public:
            HostAddr() {}
            HostAddr(const string& host) : mName(host) {}

            string getName() const { return mName; }
            void setName(const string& name) { mName = name; }
            string toString() const { return getName(); }

        private:
            string mName;
    };

}; // end of prdog

#endif
