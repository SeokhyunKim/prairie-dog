#include <prdog/prdog.hpp>
#include <iostream>

using namespace prdog;

class TestAgent : public Agent {
    public:
        void initialize(const map<string, real>& params) {
        }

        real getValue(const string& key) {
            return 0;
        }

        void update(real dt, SimContext& context) {
        }
};

class TestAgentVectorCreator : public AgentVectorCreator {
    public:
        vector<Agent::sptr> create(map<string, real> params) {
            vector<Agent::sptr> vect;
            for ( int i=0; i<3; ++i ) {
                vect.push_back(Agent::sptr(new TestAgent));
            }
            return vect;
        }

};



int main(int argc, char* argv[]) {
    using namespace std;

    prdog::Sim sim(unique_ptr<AgentVectorCreator>(new TestAgentVectorCreator));



    cout << "Hello world, I'm PrairieDog." << endl;
    return 0;
}
