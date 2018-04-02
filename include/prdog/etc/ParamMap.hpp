#ifndef _PRDOG_PARAMMAP_HPP_
#define _PRDOG_PARAMMAP_HPP_

#include "prdog_commons.hpp"
#include "ParamKey.hpp"

namespace prdog {

    class ParamMap : public map<string, string> {
        public:
            real getReal(const string& key) const;
            int getInt(const string& key) const;
            const string& getString(const string& key) const;
    };

}; // end of prdog

#endif
