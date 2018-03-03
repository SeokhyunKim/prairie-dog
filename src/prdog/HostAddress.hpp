#ifndef _PRDOG_HOSTADDRESS_HPP_
#define _PRDOG_HOSTADDRESS_HPP_

#include "prdog_common.hpp"

namespace prdog {

    class HostAddress {
        public:
            HostAddress();

            string getName() const { return _name; }
            void setName(const string& name) { _name = name; }

        private:
            string _name;
    };

}; // end of prdog

#endif
