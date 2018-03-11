#ifndef _PRDOG_SIM_HPP_
#define _PRDOG_SIM_HPP_

namespace prdog {

    class Sim {
        public:
            Sim(unique_ptr<AgentVectorCreator> creator);
            ~Sim();

            void initialize(map<string, real> params);
            void initialize(map<string, real> params, Runner::sptr runner);
            void clear();

            void run(real dt);
            
            int getSums(list<string>& keys, map<string, real>& sums);
            int getVars(list<string>& keys, map<string, real>& vars);

            real getCurTime() { return mCurTime; }

            Communicator& getCommunicator() { return *mComm; }

        private:
            real mCurTime;
            vector<Agent::sptr> mAgents;
            unique_ptr<AgentVectorCreator> mAgentVectorCreator;
            Runner::sptr mRunner;
            unique_ptr<Communicator> mComm;
            unique_ptr<SimContext> mSimContext;
    };

}; // end of prdog

#endif
