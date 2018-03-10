#ifndef _PRDOG_SIMCONTEXT_HPP_
#define _PRDOG_SIMCONTEXT_HPP_

namespace prdog {

    class SimContext {
        public:
            SimContext(Sim&);
            ~SimContext();

            real getCurTime();
            Communicator& getCommunicator();

        private:
            Sim& mSim;
    };

}; // end of prdog

#endif
