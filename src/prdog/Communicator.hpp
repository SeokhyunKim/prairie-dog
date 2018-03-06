#ifndef _PRDOGMSG_HPP_
#define _PRDOGMSG_HPP_

#include "prdog_common.hpp"

namespace prdog {

    class Sim;


    class Communicator {
        public:
            Communicator(Sim&, real delayMean, real delayStdDev);
            ~Communicator();

            void send(AgentAddr addr, ByteVect msg);

        private:
            struct Msg {
                real sentTime;
                real delay;
                real arvTime;
                ByteVect msg;

                bool operator < (Msg& rhs) {
                    // make min-heap (make_heap makes max heap)
                    return this->arvTime > rhs.arvTime;
                }
            };
            vect<Msg> _msgHeap;

            Sim& _sim;
            std::mt19937 _mt;
            real _delayMean, _delayStddev;
            
    };

}; // end of prdog

#endif
