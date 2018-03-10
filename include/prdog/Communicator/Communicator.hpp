#ifndef _PRDOG_COMMUNICATOR_HPP_
#define _PRDOG_COMMUNICATOR_HPP_

namespace prdog {

    class Sim;

    class Communicator {
        public:
            Communicator(Sim&);
            ~Communicator();

            void initialize(map<string, real> params);

            void send(AgentAddr addr, ByteVectPtr msg);

        private:
            struct Msg {
                real sentTime;
                real delay;
                real arvTime;
                ByteVectPtr msg;

                bool operator < (Msg& rhs) {
                    // make min-heap (make_heap makes max heap)
                    return this->arvTime > rhs.arvTime;
                }
            };
            vector<Msg> mMsgHeap;

            Sim& mSim;
            real mDelayMean, mDelayStddev;
            
    };

}; // end of prdog

#endif
