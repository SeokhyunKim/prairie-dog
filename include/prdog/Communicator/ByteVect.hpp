#ifndef _PRDOG_BYTEVECT_HPP_
#define _PRDOG_BYTEVECT_HPP_

#include <vector>
#include "../etc/prdog_commons.hpp"

namespace prdog {

    class ByteVect : public vector<byte> {
        public:
            typedef shared_ptr<ByteVect> sptr;

    };

}; // end of prdog

#endif
